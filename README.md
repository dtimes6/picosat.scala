# picosat.scala

bindings to picosat (a SAT solver)

PicoSAT is a popular SAT solver written by Armin Biere in pure C.

see: http://fmv.jku.at/picosat/ for more details

## Build

g++ -c -G -Wall -O3 -I$JAVA_HOME/include -I$JAVA_HOME/include/darwin com_logic_solver_SatSolver.c -o com_logic_solver_SatSolver.o
g++ -dynamiclib -G -Wall -O3 com_logic_solver_SatSolver.o picosat.o -o libpicosat.dylib

## Usage

package test

import com.logic.solver._

object TestSatSolver {

  println("Welcome to the Scala worksheet")       //> Welcome to the Scala worksheet
  
  var s = new SatSolver                           //> s  : com.logic.solver.SatSolver = com.logic.solver.SatSolver@b684286
  
  s.init()
  
  s.add_clause(Array[Int](1,-5,4))
  
  s.add_clause(Array[Int](-1, 5, 3, 4))
  
  s.add_clause(Array[Int](-3, -4))
  
  s.solve()                                       //> res0: Array[Int] = Array(1, -2, -3, -4, 5)
  
}
