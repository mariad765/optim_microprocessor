#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define NR_MAX_numere 17

// Function to read the instruction from the user
unsigned int readInstruction() {
  unsigned int inst;
  scanf("%u", &inst);
  return inst;
}

// Function to determine the number of instructions
int getNumInstructions(unsigned int inst) {
  int N = inst >> (32 - 3);
  return N + 1;
}

// Function to determine the operator based on the instruction bits
char getOperator(unsigned int op) {
  op = op >> 30;
  char operator;
  if (op == 0)
    operator= '+';
  else if (op == 1)
    operator= '-';
  else if (op == -2)
    operator= '*';
  else if (op == -1)
    operator= '/';
  return operator;
}

// Function to calculate the dimension
int getDimension(unsigned int inst, int N) {
  int Dim = inst << (3 + 2 * N);
  Dim = Dim >> 28;
  return Dim + 1;
}

// Function to calculate the number of operands
int getNumOperands(int Dim) { return 16 / Dim; }

// Function to calculate the number of numbers that need to be decomposed
int getNumNumbers(int N, int Dim) {
  int nr_numere = ((N + 1) * Dim) / 16;
  if (((N + 1) * Dim) % 16 != 0)
    nr_numere++;
  return nr_numere;
}

// Function to read numbers from the user
void readNumbers(unsigned short *numere, int nr_numere) {
  register int i;
  for (i = 0; i < nr_numere; i++) {
    scanf("%hu", &numere[i]);
  }
}

// Function to perform the calculations
long int performCalculations(unsigned short *numere, char *vect_operatori,
                             int nr_numere, int Dim, int x) {
  unsigned short *operand = calloc(NR_MAX_numere, sizeof(unsigned short));
  long int rezult = 0;
  register int k = 0;
  register int j = 0;
  register int i = 0;
  for (i = 0; i < nr_numere; i++) {
    for (j = 0; j < x; j++) {
      operand[j] = numere[i] << (Dim * j);
      operand[j] = operand[j] >> (Dim * (x - 1));
      if ((i == 0) && (j == 0))
        rezult = operand[0];
      else {
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
  free(operand);
  return rezult;
}

int main() {

  // Read the instruction from the user
  unsigned int inst = readInstruction();

  // Determine the number of instructions
  int N = getNumInstructions(inst);

  // Allocate memory for storing numbers and operators
  unsigned short *numere = malloc(NR_MAX_numere * sizeof(unsigned short));
  char *vect_operatori = malloc(NR_MAX_numere * sizeof(char));

  // Calculate the dimension and the number of operands
  int Dim = getDimension(inst, N);
  int x = getNumOperands(Dim);

  // Calculate the number of numbers that need to be decomposed
  int nr_numere = getNumNumbers(N, Dim);

  // Read numbers from the user
  readNumbers(numere, nr_numere);

  // Perform the calculations
  long int rezult =
      performCalculations(numere, vect_operatori, nr_numere, Dim, x);

  printf("%ld\n", rezult);

  free(vect_operatori);
  free(numere);
  return 0;
}
