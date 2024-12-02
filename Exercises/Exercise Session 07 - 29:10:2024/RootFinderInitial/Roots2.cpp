//============================================================================
// Name        : Roots.cpp
// Author      : Danilo
// Version     :
// Copyright   :
// Description : Roots finders
//============================================================================
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

#include "rootfinding.hpp"
#include "Function.hpp"
#include "Bisection.hpp"
#include "Newton.hpp"
#include "Robust.hpp"

using std::cout; using std::endl;
using std::vector;

int main() {

	  int nit_bis;
	  int nit_newt;
	  vector<double> coeffs;


	  Function f({-0.5, 0., 1.});
      f.print();

	  Bisection bis(f,0., 1., 1e-8, INCREMENT, 100);
	  cout << "Bisection" << endl;
	  cout << bis.find_root(nit_bis);

	  cout << '\t' << nit_bis << endl;

	  Newton nw(f,.1,1e-8,INCREMENT,100);

	  cout << "Newton" << endl;
	  cout << nw.find_root(nit_newt);
	  cout << '\t' << nit_newt << endl;

	  Robust rob(f,0., 1., 1e-8, 1e4,INCREMENT, 100);
	  cout << "Robust" << endl;
	  cout << rob.find_root(nit_bis,nit_newt);
	  cout << '\t' << nit_bis
	       << " "  << nit_newt << endl;

	  return 0;
}
