#include <stdio.h>
int main(void) {
  printf("Counting digits, whitespace and other characters\n"
         "until EOF or Ctrl+D is given.\n\n");
  int c, white=0, other=0;
  int zero=0, one=0, two=0, three=0, four=0, // :(
      five=0, six=0, seven=0, eight=0, nine=0;
  while((c=getchar()) != EOF){
    switch(c) {                    // Very ugly!
      case '0': zero++; break;
      case '1': one++; break;
      case '2': two++; break;
      case '3': three++; break;
      case '4': four++; break;
      case '5': five++; break;
      case '6': six++; break;
      case '7': seven++; break;
      case '8': eight++; break;
      case '9': nine++; break;
      case ' ': case '\n': case '\t': white++; break;
      default: other++; break;
    }
  }
  printf("Digits:\n");
  printf("Zeros:\t%d\n", zero); // Oh my God!
  printf("Ones:\t%d\n", one);
  printf("Twos:\t%d\n", two);
  printf("Threes:\t%d\n", three);
  printf("Fours:\t%d\n", four);
  printf("Fives:\t%d\n", five);
  printf("Sixs:\t%d\n", six);
  printf("Sevens:\t%d\n", seven);
  printf("Eights:\t%d\n", eight);
  printf("Nines:\t%d\n", nine);
  printf("White spaces: %d, others: %d\n", white, other);
  return 0;
}
