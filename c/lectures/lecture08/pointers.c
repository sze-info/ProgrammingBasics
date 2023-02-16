#include <stdio.h>

int main(void) {
  int i=3, *pi1, *pi2;
  pi1 = pi2 = &i; // OK
  double d=1.5;
  double* pd = &d; // initialization
  // pd = &12.34;
  // error: lvalue required as unary '&' operand
  // A literal does not have a memory address, meaningless
  // pd = pi1; warning: assignment from 
  //                    incompatible pointer type
  void *pv;
  pv = pi1; // OK
  pi1 = pv; // OK, but did pv really address an int?
  pv = NULL; // OK
  return 0;
}

