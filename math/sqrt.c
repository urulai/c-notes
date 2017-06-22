/*                Compile using gcc                */
/*   gcc -Wall -D_TEST_MODE -o out sqrt.c -lm    */

/*  gcc command also includes -D option to choose _TEST_MODE   */
#include <stdio.h>
#include <math.h>
#include <complex.h>

int main(void)
{
  
  #ifdef _TEST_MODE
    int N = 2;
    printf("sqrt(%d) -> %f.\n", N, sqrt(N));
    
    complex double z = 1.0 + 0.5*I;
    printf("Phase(%f), real(%f), imag(%f), abs(%f).\n", carg(z), creal(z), cimag(z), cabs(z));
  #endif

	return 0;
}


