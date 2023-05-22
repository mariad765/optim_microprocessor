#include <math.h>
#include <stdio.h>
#define NR_MAX_numere 17

int main() {

  unsigned int inst;  // instruction
  scanf("%u", &inst); // read instruction
  int N;              // number of instructions
  int op;             // var for deciding operators
  // Vector for storing numbers to be decomposed for operands.
  // Dynamically allocate memory for numere.
  unsigned short *numere = malloc(NR_MAX_numere * sizeof(unsigned short));

  // Dynamically allocate memory for vect_operatori.
  char *vect_operatori = malloc(NR_MAX_numere * sizeof(char));

  N = inst >> (32 - 3); // shift bits
  N = N + 1;            // Relevant number for the first 3 bits.

  for (int i = 0; i < N; i++) {
    op = inst << (3 + 2 * i); // Shifting to select bits in pairs of 2.
    op = op >> 30;
    if (op == 0) // Conditions for deciding the operation.
    {

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

  unsigned int Dim = 0; // dimension
  Dim = inst << (3 + 2 * N);
  Dim = Dim >> 28;
  Dim++;

  int x;
  x = 16 / Dim;      // number of operands.
  int nr_numere = 0; // numbers that need to be decomposed to find the operands.
  unsigned short operand *= calloc(NR_MAX_numere, sizeof(unsigned short));
  if (((N + 1) * Dim) % 16 == 0) {
    nr_numere = ((N + 1) * Dim) / 16;
  } else if (((N + 1) * Dim) % 16 != 0) {
    nr_numere = (((N + 1) * Dim) / 16) + 1;
  }
  long int rezult = 0;

  int k = 0;
  for (int i = 0; i < nr_numere; i++) {
    scanf("%hu", &numere[i]);
    for (int j = 0; j < x; j++) {
      operand[j] = numere[i] << (Dim * j);
      operand[j] = operand[j] >> (Dim * (x - 1));
      if ((i == 0) && (j == 0)) {
        rezult = operand[0];
      } else {
        rezult = rezult;

        switch (vect_operatori[k]) {
        case '+':
          rezult = operand[j] + rezult;
          break;
        case '-':
          rezult = rezult - operand[j];
          break;
        case '*':
          rezult = rezult * operand[j];
          break;
        case '/':
          rezult = rezult / operand[j];
          break;
        }

        k++;
      }
    }
  }

  printf("%ld\n", rezult);
  free(vect_operatori);
  free(numere);
  free(operand);
  return 0;
}