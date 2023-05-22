#include <stdio.h>
#define zero 0
#define one 1
#define two 2
#define three 3
#define four 4
#define five 5
#define six 6
#define seven 7
#define eight 8
#define nine 9
#define ten 10
#define eleven 11
#define twelve 12
#define thirteen 13
#define fourteen 14
#define fifteen 15
#define sixteen 16
#define seventeen 17
#define eighteen 18
#define nineteen 19
#define twenty 20
#define twentyone 21
#define twentytwo 22
#define twentythree 23
#define twentyfour 24
#define twentyfive 25
#define twentysix 26
#define twentyseven 27
#define twentyeight 28
#define twentynine 29
#define thirty 30
#define thirtyone 31
#define thirtytwo 32
#define thirtythree 33

int topowof(int a, int n) {
    int q = one;
    for (int i = zero; i < n; i++)q *= a;
    return q;
}
int main() {
    unsigned int inst = zero;
    int N = zero, i = zero, dim = zero, m = zero;
    int binary[thirtythree] = {zero};
    char operations[twentyone] = "";
    scanf("%u", &inst);
    for (i = zero; i < thirtytwo; i++) {
        binary[i] = (int)(inst % (unsigned int)two);
        inst /= (unsigned int)two;
    }
    // for (i = 31; i >= 0; i--)
        // printf("%c", binary[i]);
    // printf("\n");
    N = four * binary[thirtyone] + two * binary[thirty] + binary[twentynine] + one;
    // printf("%d ", N);
    for (i = zero; i < N; i++) {
        if (binary[twentyeight - two * i] == zero && binary[twentyseven - two * i] == zero) {
            // printf("+ ");
            operations[m++] = '+';
        }
        if (binary[twentyeight - two * i] == zero && binary[twentyseven - two * i] == one) {
            // printf("- ");
            operations[m++] = '-';
        }
        if (binary[twentyeight - two * i] == one && binary[twentyseven - two * i] == zero) {
            // printf("* ");
            operations[m++] = '*';
        }
        if (binary[twentyeight - two * i] == one && binary[twentyseven - two * i] == one) {
            // printf("/ ");
            operations[m++] = '/';
        }
    }
    operations[m] = zero;
    dim = eight * (binary[twentyeight - two * i]) + four * (binary[twentyseven - two * i])
     + two * (binary[twentysix - two * i]) + (binary[twentyfive - two * i]) + one;
    // printf("%d\n", dim);
    int NumOfInts = zero;
    NumOfInts = ((N + one) * dim) / sixteen;
    if (((N + one) * dim) % sixteen) NumOfInts++;
    // printf("Numere de introdus = %d\nIntroduceti numar: ", NumOfInts);
    int binaryOperand[ten * sixteen] = {zero};
    for (i = zero; i < NumOfInts; i++) {
        scanf("%u", &inst);
        for (int j = zero; j < sixteen; j++) {
            binaryOperand[i * sixteen + fifteen - j] = (int)(inst % (unsigned int)two);
            inst /= (unsigned int)two;
        }
    }
    /**
    for (i = 0; i < NumOfInts; i++) {
        for (int j = 0; j < 16 / dim; j++) {
            for (int k = 0; k < dim; k++)
                printf("%d", binaryOperand[i][15 - dim * j - k]);
            printf(" ");
        }
        printf("\n");
    }*/
    // for (i = zero; i < NumOfInts * sixteen; i++)printf("%d", binaryOperand[i]);
    // printf("\n");
    int operand[twentyone] = {zero}, q = zero;
    for (i = zero; i <= N; i++) {
        for (int j = zero; j < dim; j++) {
                // printf("%d", binaryOperand[i * dim + j]);
                operand[q] += topowof(two, dim - one - j) * binaryOperand[i * dim + j];
        }
        // printf(" ");
        q++;
    }
    /*
    printf("\nOperanzii: ");
    for (i = 0; i < NumOfInts * (16 / dim); i++)
        printf("%d %c", operand[i], operations[i]);
    printf("%d\n", operand[i]);
    */
    i = zero;
    while (i <= N) {
            if (operations[i] == '*') {
                operand[i] *= operand[i + one];
                int j = i + one;
                while (j <= N) {
                    operand[j] = operand[j + one];
                    operations[j - one] = operations[j];
                    j++;
                }
                N--;
            } else if (operations[i] == '/') {
                operand[i] /= operand[i + one];
                int j = i + one;
                while (j <= N) {
                    operand[j] = operand[j + one];
                    operations[j - one] = operations[j];
                    j++;
                }
                N--;
            } else {
                i++;
            }
    }
        for (int i = zero; i < N; i++) {
            if (operations[i] == '+') operand[i + one] += operand[i];
            if (operations[i] == '-') operand[i + one] = operand[i] - operand[i + one];
        }
    printf("%d\n", operand[--i]);
    return 0;
}
