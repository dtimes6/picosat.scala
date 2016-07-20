# picosat.scala

package test

import com.logic.solver._

object TestSatSolver {
  println("Welcome to the Scala worksheet")       //> Welcome to the Scala worksheet
  
  var s = new SatSolver                           //> s  : com.relicfragments.logic.solver.SatSolver = com.relicfragments.logic.so
                                                  //| lver.SatSolver@b684286
  s.init()
  s.add_clause(Array[Int](1,-5,4))
  s.add_clause(Array[Int](-1, 5, 3, 4))
  s.add_clause(Array[Int](-3, -4))
  s.solve()                                       //> res0: Array[Int] = Array(1, -2, -3, -4, 5)
}
