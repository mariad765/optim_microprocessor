#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NR_MAX_numere 17

int get_number_of_instruction(unsigned int inst) {
  int N = 0;
  N = inst >> (32 - 3);
  N = N + 1; // get number of instructions
  return N;
}

void initialize_operators(char *vect_operatori, unsigned int inst, int N) {
  int op = 0;
  memset(vect_operatori, '+', NR_MAX_numere);
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
  Dim = inst << (3 + 2 * N);
  Dim = Dim >> 28;
  Dim++;
  return Dim;
}

int get_nr_of_op(int Dim, int N) {
  int nr = 0;
  if (((N + 1) * Dim) % 16 == 0) {
    nr = ((N + 1) * Dim) / 16;
  } else if (((N + 1) * Dim) % 16 != 0) {
    nr = (((N + 1) * Dim) / 16) + 1;
  }
  return nr;
}
long int get_result(int nr_numere, int dimension, unsigned short *numere,
                    unsigned short *operand, int x) {
  long int rezult = 0;

  int k = 0;
  for (int i = 0; i < nr_numere; i++) {
    scanf("%hu", &numere[i]);
    for (int j = 0; j < x; j++) {
      operand[j] = numere[i] << (dimension * j);
      operand[j] = operand[j] >> (dimension * (x - 1));
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
  return result;
}

void free_memory(unsigned short *operand, unsigned short *numere,
                 char *vect_operatori) {
  free(operand);
  free(numere);
  free(vect_operatori);
}

int main() {

  unsigned int inst = 0;
  scanf("%u", &inst);

  int N = 0;
  N = get_number_of_instruction(inst);

  unsigned short *numere = calloc(NR_MAX_numere, sizeof(unsigned short));
  char *vect_operatori = calloc(NR_MAX_numere, sizeof(char));

  initialize_operators(vect_operatori, inst, N);

  unsigned int dimension = get_dimension(inst, N);

  int x;
  x = 16 / dimension;

  // nr_numere is a variable used to store the number of unsigned short numbers
  // (operands) that need to be read from the input
  int nr_numere = get_nr_of_op(dimension, N);

  unsigned short *operand = calloc(NR_MAX_numere, sizeof(unsigned short));

  long int rezult = get_result(nr_numere, dimension, numere, operand, x);
  printf("%ld\n", rezult);

  free_memory(operand, numere, vect_operatori);

  return 0;
}