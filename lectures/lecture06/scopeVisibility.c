int main(void) {
  int i = 0;        // int i is in scope and visible
  {                 // nested block
    double i = 2.14;// i is local name in the nested block
    i += 1;         // double i is in scope and visible;
                    // int i is also in scope but hidden
  }
                    // double i is out of scope
  i += 2;           // int i is visible and = 2
}
// int i and double i are both out of scope
