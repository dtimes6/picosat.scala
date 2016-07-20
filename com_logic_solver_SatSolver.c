#include "com_logic_solver_SatSolver.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "picosat.h"

#ifdef __cplusplus
}
#endif

static PicoSAT* picosat = NULL;

JNIEXPORT void
JNICALL Java_com_logic_solver_SatSolver_init
(JNIEnv *env, jobject obj) {
    if (!picosat)
        picosat = picosat_init();
}

JNIEXPORT void
JNICALL Java_com_logic_solver_SatSolver_reset
(JNIEnv *env, jobject obj) {
    if (picosat)
        picosat_reset(picosat);
}

JNIEXPORT void
JNICALL Java_com_logic_solver_SatSolver_add_1clause
(JNIEnv *env, jobject obj, jintArray array) {
    jsize len  = env->GetArrayLength(array);
    if (len == 0) return;
    jint* head = env->GetIntArrayElements(array, 0);
    for (jsize i = 0; i < len; ++i) {
        picosat_add(picosat, head[i]);
    }
    picosat_add(picosat, 0);
    env->ReleaseIntArrayElements(array, head, 0);
}

JNIEXPORT jintArray
JNICALL Java_com_logic_solver_SatSolver_solve
(JNIEnv *env, jobject obj) {
    jintArray ret;
    jint* tmp;
    jsize len = 0;
    int res = picosat_sat(picosat, -1);
    switch (res) {
    case PICOSAT_SATISFIABLE: {
        int max_idx = picosat_variables(picosat);
        tmp = new jint[max_idx];
        for (int i = 1; i <= max_idx; ++i) {
            tmp[i - 1] = picosat_deref(picosat, i) * i;
        }
        len = max_idx;
    } break;
    case PICOSAT_UNSATISFIABLE:
    case PICOSAT_UNKNOWN:
        tmp = NULL;
    }
    ret = env->NewIntArray(len);
    env->SetIntArrayRegion(ret,0,len,tmp);
    if (tmp) {
        delete [] tmp;
    }
    return ret;
}
