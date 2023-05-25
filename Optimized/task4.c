#include "Funtions.h"
#include <math.h>
#include <stdio.h>

void read_nums(unsigned short *numere, int nr_numere) {
    for (int i = 0; i < nr_numere; i++) {
        scanf("%hu", &numere[i]);
    }
}

int main() {

    unsigned int inst = 0;  // instruction
    scanf("%u", &inst);
    int N = get_number_of_instruction(inst);
    // number of instructions

    unsigned short *numere = calloc(NR_MAX_numere, sizeof(unsigned short));
    char *vect_operatori = calloc(NR_MAX_numere, sizeof(char));

    initialize_operators(vect_operatori, inst, N);
    unsigned int Dim = get_dimension(inst, N);

    // numbers that need to be operated on to figure out the operands
    int nr_numere = get_nr_of_op(Dim, N);
    unsigned short *operand = calloc(NR_MAX_numere, sizeof(unsigned short));
    long int rezult = 0;

    read_nums(numere, nr_numere);  // reading the original numbers
    if (16 % Dim == 0) {
        for (int i = 0; i <= N; i++) {
            operand[i] = numere[i * Dim / 16];  // calculating each operand
            operand[i] = operand[i] << (Dim * (i % (16 / Dim)));
            operand[i] = operand[i] >> (16 - Dim);
        }
    }
    int i = 0;
    while (i <= N) {  // we are using the same loop to calculate the result
        if (vect_operatori[i] == '*') {  // having the order of operations in mind
            operand[i] *= operand[i + 1];
            int j = i + 1;  //           we take care of multiplication and
            while (j <= N) {  //          division first
                operand[j] = operand[j + 1];
                vect_operatori[j - 1] = vect_operatori[j];
                j++;
            }
            N--;
        } else if (vect_operatori[i] == '/') {
            operand[i] /= operand[i + 1];
            int j = i + 1;
            while (j <= N) {
                operand[j] = operand[j + 1];
                vect_operatori[j - 1] = vect_operatori[j];
                j++;
            }
            N--;
        } else {
            i++;
        }
    }
    for (int i = 0; i < N; i++) {  // and then we finish up with addidion and subtraction
        if (vect_operatori[i] == '+') operand[i + 1] += operand[i];
        if (vect_operatori[i] == '-') operand[i + 1] = operand[i] - operand[i + 1];
    }
    printf("%d\n", operand[--i]);
    free_memory(operand, numere, vect_operatori);
    return 0;
}
