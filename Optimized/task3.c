#include "Functions.h"
#include <math.h>
#include <stdio.h>

void read_nums(unsigned short *numere, int nr_numere) {
  for (int i = 0; i < nr_numere; i++) {
    scanf("%hu", &numere[i]);
  }
}

void init_op(unsigned short *operand, int N) {
  for (int i = 0; i < N + 1; i++) {
    operand[i] = 0;
  }
}
void case_dimmention_g_half_num_bits(int Dim, int nr_numere,
                                     unsigned short *numere,
                                     unsigned short *operand,
                                     char *vect_operatori) {
  /* 6 (if Dim > 8):

  This iteration processes the numbers and performs the corresponding
  operations. It iterates over the nr_numere (number of elements) and performs
  the following steps: It initializes a mask to the leftmost bit (1 << 15). It
  iterates over each bit of the current number (numere[i]) using the variable
  j. It checks if the current bit of the number is set using the bitwise AND
  operation with the mask. If the bit is set, it calculates the operand value
  by shifting 1 left by the difference between Dim and j and adds it to the
  operand array. It updates the result (rezult) based on the operator
  (vect_operatori[p]) and the current operand value. Finally, it increments
  the p variable to move to the next operator. */

  int k = 1;
  int p = 0;
  if (Dim > 8) {
    for (int i = 0; i < nr_numere; i++) {
      int mask = 1 << 15;
      for (int j = k; j <= Dim; j++) {
        if (mask & numere[i]) {

          operand[i] += 1 << Dim - j;
        }
        mask = mask >> 1;
      }

      if (i == 0) {
        rezult = operand[0];
      } else {
        rezult = rezult;

        switch (vect_operatori[p]) {
        case '+':
          rezult = operand[i] + rezult;
          break;
        case '-':
          rezult = rezult - operand[i];
          break;
        case '*':
          rezult = rezult * operand[i];
          break;
        case '/':
          rezult = rezult / operand[i];
          break;
        }

        p++;
      }

      {
        for (k = 1; k <= (i + 1) * (16 - Dim); k++) {
          if (mask & numere[i]) {
            operand[i + 1] += 1 << Dim - k;
          }
          mask = mask >> 1;
        }
      }
    }
  }
}

case_dimension_l_half_num_bits(int Dim, int nr_numere, unsigned short *numere,
                               unsigned short *operand) {
  /*(if Dim < 8):

  This iteration processes the numbers and performs the corresponding operations
  when Dim is less than 8. It follows a different logic to extract the bits and
  calculate the operand values. It iterates over the nr_numere (number of
  elements) and performs the following steps: It initializes a mask to the
  leftmost bit (1 << 15). It checks if there is any remaining bit from the
  previous number that needs to be read (necitit == 1). If there is, it reads
  the remaining bits from the current number (numere[i]) and calculates the
  operand value accordingly. If there is no remaining bit, it reads the bits
  from the current number and calculates the operand value based on Dim. It
  updates the result (rezult) based on the operator (vect_operatori[p]) and the
  current operand value. Finally, it increments the p variable to move to the
  next operator.*/
  if (Dim < 8) {
    int necitit = 0;
    int g = 1;
    for (int i = 0; i < nr_numere; i++) {

      int mask = 1 << 15;
      if (necitit == 1) {
        for (int j = 0; j < 5; j++) {

          if (mask & numere[i]) {
            operand[g] += 1 << (Dim - 2 - j - 1);
          }
          mask = mask >> 1;
        }
        g++;
        necitit = 0;
      }

      for (int j = 0; j < 7; j++) {

        if (mask & numere[i]) {
          operand[g] += 1 << (Dim - j - 1);
        }
        mask = mask >> 1;
      }

      g++;
      if (g * Dim < 16) {
        for (int j = 0; j < 7; j++) {

          if (mask & numere[i]) {
            operand[g] += 1 << (Dim - j - 1);
          }
          mask = mask >> 1;
        }

        g++;
      }

      if (((i + 1) * 16 - g * 7) < 0) {

        for (int j = 0; j < 2; j++) {

          if (mask & numere[i]) {
            operand[g] += 1 << (Dim - j - 1);
          }
          mask = mask >> 1;
        }

        necitit = 1;
      }
    }
  }
}

int main() {

  unsigned int inst; // instruction
  scanf("%u", &inst);
  int N;  // number of instructions
  int op; // ver deciding operatiors

  unsigned short *numere = calloc(NR_MAX_numere, sizeof(unsigned short));
  char *vect_operatori = calloc(NR_MAX_numere, sizeof(char));

  N = get_number_of_instruction(inst);

  initialize_operators(vect_operatori, inst, N);

  unsigned int Dim = get_dimension(inst, N);

  // numbers that needs to be operated on to figure out the operands
  int nr_numere = get_nr_of_op((Dim, N));

  unsigned short *operand = calloc(NR_MAX_numere, sizeof(unsigned short));

  long int rezult = 0;

  read_nums(numere, nr_numere);
  init_op(operand, N);

  case_dimmention_g_half_num_bits(Dim, nr_numere, numere, operand,
                                  vect_operatori);
  case_dimension_l_half_num_bits(Dim, nr_numere, numere, operand);

  if (Dim < 8) {
    int necitit = 0;
    int g = 1;
    for (int i = 0; i < nr_numere; i++) {

      int mask = 1 << 15;
      if (necitit == 1) {
        for (int j = 0; j < 5; j++) {

          if (mask & numere[i]) {
            operand[g] += 1 << (Dim - 2 - j - 1);
          }
          mask = mask >> 1;
        }
        g++;
        necitit = 0;
      }

      for (int j = 0; j < 7; j++) {

        if (mask & numere[i]) {
          operand[g] += 1 << (Dim - j - 1);
        }
        mask = mask >> 1;
      }

      g++;
      if (g * Dim < 16) {
        for (int j = 0; j < 7; j++) {

          if (mask & numere[i]) {
            operand[g] += 1 << (Dim - j - 1);
          }
          mask = mask >> 1;
        }

        g++;
      }

      if (((i + 1) * 16 - g * 7) < 0) {

        for (int j = 0; j < 2; j++) {

          if (mask & numere[i]) {
            operand[g] += 1 << (Dim - j - 1);
          }
          mask = mask >> 1;
        }

        necitit = 1;
      }
    }

    p = 0;
    for (int i = 0; i <= N; i++) {
      if (i == 0) {
        rezult = operand[1];
      } else {
        rezult = rezult;

        switch (vect_operatori[p]) {
        case '+':
          rezult = operand[i + 1] + rezult;
          break;
        case '-':
          rezult = rezult - operand[i + 1];
          break;
        case '*':
          rezult = rezult * operand[i + 1];
          break;
        case '/':
          rezult = rezult / operand[i + 1];
          break;
        }
        p++;
      }
    }
  }

  printf("%ld\n", rezult);

  return 0;
}