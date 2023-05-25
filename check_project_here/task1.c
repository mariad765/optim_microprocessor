#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_operators(int operators) {
  if (operators == 0)
    printf(" +");
  else if (operators == 1)
    printf(" -");
  else if (operators == -2)
    printf(" *");
  else if (operators == -1)
    printf(" /");
}

int main() {
  struct timespec start_time, end_time;
  double execution_time;

  clock_gettime(CLOCK_MONOTONIC, &start_time);

  unsigned int instructions = 0;
  scanf("%u", &instructions);                // scanning the instruction
  int numberOfOperations = 0, operators = 0; // declaring the
  // number of operations and their types

  numberOfOperations = instructions >> (32 - 3); // shifting the first 3 bits
  numberOfOperations++;             // calculating the number of operations
  printf("%d", numberOfOperations); // printing it
  register int i;
  for (i = 0; i < numberOfOperations; i++) { // going through the operations
    operators = instructions
                << (3 + 2 * i);  // shifting to analyze 2 bits at a time
    operators = operators >> 30; // getting to the value we are interested in
    print_operators(operators);  // printing the operation
  }
  unsigned int dimension = 0; // declaring the dimension of each operator
  dimension = instructions << (3 + 2 * numberOfOperations);
  dimension = dimension >> 28;
  dimension++;
  printf(" %u\n", dimension); // and finally printing it

  clock_gettime(CLOCK_MONOTONIC, &end_time);
  execution_time = (end_time.tv_sec - start_time.tv_sec) +
                   (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

  FILE *output_file = fopen("execution_time_task1.txt", "w");
  if (output_file == NULL) {
    printf("Error opening the output file.\n");
    return 1;
  }

  fprintf(output_file, "Execution time: %.7f seconds\n", execution_time);
  fclose(output_file);
  return 0;
}
