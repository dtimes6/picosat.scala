package logic.solver

object SatSolver {
  var setup = false;
  def env() = {
    if (!setup) {
      System.load("libpicosat.dylib");
    }
  }
}

class SatSolver {
  SatSolver.env;
  @native def init();
  @native def reset();
  @native def add_clause(lits:Array[Int]);
  @native def solve():Array[Int];
  @native def assmue(lit:Int);
}
