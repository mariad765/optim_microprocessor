#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NR_MAX_numere 17

#ifndef UTIL_H
#define UTIL_H

extern void free_memory(unsigned short *operand, unsigned short *numere,
                        char *vect_operatori) {
  free(operand);
  free(numere);
  free(vect_operatori);
}

extern int get_number_of_instruction(unsigned int inst) {
  int N = 0;
  N = inst >> (32 - 3);
  N = N + 1; // get number of instructions
  return N;
}

extern void initialize_operators(char *vect_operatori, unsigned int inst,
                                 int N) {
  int op = 0;
  /* Iteration 1:
The loop iterates N times, where N is the number of instructions.
In each iteration, the code extracts the operator from the instruction and
stores it in the vect_operatori array based on the value of op. The variable
op is calculated using bitwise operations to shift and
extract the relevant  bits  from the instruction.  */
  for (int i = 0; i < N; i++) {
    op = inst << (3 + 2 * i);
    op = op >> 30;
    if (op == 0) {

      vect_operatori[i] = '+';
    }

    if (op == 1) {
      vect_operatori[i] = '-';
    }

    if (op == -2) {
      vect_operatori[i] = '*';
    }
    if (op == -1) {
      vect_operatori[i] = '/';
    }
  }
}

unsigned int get_dimension(unsigned int inst, int N) {
  unsigned int Dim = 0;
  /* calculate the variable Dim,which represents the size
    information extracted from the instruction.The size information is extracted
    using bitwise operations to shift and extract the relevant bits from the
    instruction. */
  Dim = inst << (3 + 2 * N);
  Dim = Dim >> 28;
  Dim++;
  return Dim;
}

int get_nr_of_op(int Dim, int N) {
  int nr = 0;
  /*The variable nr_numere is determined based on the size (Dim) and the number
of elements to be read. If the total number of bits needed to represent all the
elements ((N + 1) * Dim) is divisible by 16, then nr_numere is set to (N + 1) *
Dim / 16. If the total number of bits is not divisible by 16, then nr_numere is
set to ((N + 1) * Dim / 16) + 1.*/
  if (((N + 1) * Dim) % 16 == 0) {
    nr = ((N + 1) * Dim) / 16;
  } else if (((N + 1) * Dim) % 16 != 0) {
    nr = (((N + 1) * Dim) / 16) + 1;
  }
  return nr;
}
#endif /*  UTIL_H  */