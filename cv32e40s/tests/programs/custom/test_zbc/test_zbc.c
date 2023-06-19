
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

unsigned int test;


int test_clmul(void);
int test_clmulh(void);
int test_clmulr(void);

int main(int argc, char *argv[])
{
  int failures=0;
  // failures += test_clmul();
  // failures += test_clmulh();
   failures += test_clmulr();

  if(failures == 0){
    return EXIT_SUCCESS;
  }
  else {
    return EXIT_FAILURE;
  }
}


int test_clmul(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, 4");  // Store 4 in t3
  __asm__ volatile("addi t4, zero, 1");  // Store 1 in t4
  __asm__ volatile("clmul t5, t3, t4");  // Carry-less multiply (low-part)
  __asm__ volatile("sw t5, test, t0");   // Store t5 to test

  if (test != 4 ) {
    printf("ERROR, CLMUL result not as expected\n");
    failures++;
  }

  return failures;
}

int test_clmulh(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, 4");  // Store 4 in t3
  __asm__ volatile("addi t4, zero, 1");  // Store 1 in t4
  __asm__ volatile("clmulh t5, t3, t4"); // Carry-less multiply (high-part)
  __asm__ volatile("sw t5, test, t0");   // Store t5 to test

  if (test != 0 ) {
    printf("ERROR, CLMULH result not as expected\n");
    failures++;
  }

  return failures;
}

int test_clmulr(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, 4"); // Store -7 in t3
  __asm__ volatile("addi t4, zero, 1");  // Store 1 in t4
  __asm__ volatile("clmulr t5, t3, t4");    // Find min
  __asm__ volatile("sw t5, test, t0");   // Store t5 to test

  if (test != 0 ) {
    printf("ERROR, CLMULR result not as expected\n");
    failures++;
  }

  return failures;
}















