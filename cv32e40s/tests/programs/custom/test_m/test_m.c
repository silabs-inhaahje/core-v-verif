
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

unsigned int test;


int test_mul(void);
int test_mulh(void);
int test_mulhsu(void);
int test_mulhu(void);
int test_div(void);
int test_divu(void);
int test_rem(void);
int test_remu(void);

int main(int argc, char *argv[])
{
  int failures=0;
   failures += test_mul();
   failures += test_mulh();
   failures += test_mulhsu();
   failures += test_mulhu();
   failures += test_div();
   failures += test_divu();
   failures += test_rem();
   failures += test_remu();

  if(failures == 0){
    return EXIT_SUCCESS;
  }
  else {
    return EXIT_FAILURE;
  }
}


int test_mul(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, 3");  // Store 3 in t3
  __asm__ volatile("addi t4, zero, 2");  // Store 2 in t4
  __asm__ volatile("mul t5, t3, t4");    // 
  __asm__ volatile("sw t5, test, t0");   // Store t5 to test

  if (test != 6 ) {
    printf("ERROR, MUL result not as expected\n");
    failures++;
  }

  return failures;
}

int test_mulh(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, 4");  // Store 4 in t3
  __asm__ volatile("addi t4, zero, 1");  // Store 1 in t4
  __asm__ volatile("mulh t5, t3, t4");   // 
  __asm__ volatile("sw t5, test, t0");   // Store t5 to test

  if (test != 0 ) {
    printf("ERROR, MULH result not as expected\n");
    failures++;
  }

  return failures;
}

int test_mulhsu(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, 4");  // Store 4 in t3
  __asm__ volatile("addi t4, zero, 1");  // Store 1 in t4
  __asm__ volatile("mulhsu t5, t3, t4"); //
  __asm__ volatile("sw t5, test, t0");   // Store t5 to test

  if (test != 0 ) {
    printf("ERROR, MULHSU result not as expected\n");
    failures++;
  }

  return failures;
}

int test_mulhu(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, 4");  // Store 4 in t3
  __asm__ volatile("addi t4, zero, 1");  // Store 1 in t4
  __asm__ volatile("mulhu t5, t3, t4");  //
  __asm__ volatile("sw t5, test, t0");   // Store t5 to test

  if (test != 0 ) {
    printf("ERROR, MULHU result not as expected\n");
    failures++;
  }

  return failures;
}

int test_div(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, 2");  // Store 2 in t3
  __asm__ volatile("addi t4, zero, 4");  // Store 4 in t4
  __asm__ volatile("div t5, t3, t4");  //
  __asm__ volatile("sw t5, test, t0");   // Store t5 to test

  if (test != 2 ) {
    printf("ERROR, DIV result not as expected\n");
    failures++;
  }

  return failures;
}


int test_divu(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, 2");  // Store 2 in t3
  __asm__ volatile("addi t4, zero, 4");  // Store 4 in t4
  __asm__ volatile("divu t5, t3, t4");  //
  __asm__ volatile("sw t5, test, t0");   // Store t5 to test

  if (test != 2 ) {
    printf("ERROR, DIVU result not as expected\n");
    failures++;
  }

  return failures;
}

int test_rem(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, 3");  // Store 3 in t3
  __asm__ volatile("addi t4, zero, 4");  // Store 4 in t4
  __asm__ volatile("rem t5, t3, t4");  //
  __asm__ volatile("sw t5, test, t0");   // Store t5 to test

  if (test != 1 ) {
    printf("ERROR, REM result not as expected\n");
    failures++;
  }

  return failures;
}

int test_remu(void){
 int failures = 0;

  __asm__ volatile("addi t3, zero, 3");  // Store 3 in t3
  __asm__ volatile("addi t4, zero, 4");  // Store 4 in t4
  __asm__ volatile("remu t5, t3, t4");  //
  __asm__ volatile("sw t5, test, t0");   // Store t5 to test

  if (test != 1 ) {
    printf("ERROR, REMU result not as expected\n");
    failures++;
  }

  return failures;
}
















