#include <stdio.h>
#include <math.h>
#define NR_MAX_numere 17

int main()
{

    unsigned int inst;                    // instructiunea
    scanf("%u", &inst);                   // se citeste instructiunea
    int N;                                // numarul de instructiuni
    int op;                               // variabila pentru decidere operatori
    unsigned short numere[NR_MAX_numere]; // vector stocare numere de descompus pt operanzi
    char vect_operatori[NR_MAX_numere];   // vector n care retinem operatorii

    N = inst >> (32 - 3); // shifteaza bitii
    N = N + 1;            // numarul relevant pt primii 3 biti
   // printf("%d", N);      // afiseaza numarul de op

    for (int i = 0; i < N; i++)
    {
        op = inst << (3 + 2 * i); // shiftare pentru a selecta bitii 2 cate 2
        op = op >> 30;
        if (op == 0) // conditiile pentru decidere op
        {
            //printf(" +");
            vect_operatori[i] = '+';
        }

        if (op == 1)
        {
            vect_operatori[i] = '-';
           // printf(" -");
        }

        if (op == -2)
        {
            vect_operatori[i] = '*';
          //  printf(" *");
        }
        if (op == -1)
        {
            vect_operatori[i] = '/';
           // printf(" /");
        }
    }

    unsigned int Dim = 0; // dimensiunea
    Dim = inst << (3 + 2 * N);
    Dim = Dim >> 28;
    Dim++;
    // printf(" %u\n", Dim);
    // cod task 2
    int x;
    x = 16 / Dim;      // numarul de operanzi
    int nr_numere = 0; // numerele care trebuie descompuse pt aflare operanzi
    unsigned short operand[NR_MAX_numere];
    if (((N + 1) * Dim) % 16 == 0)
    {
        nr_numere = ((N + 1) * Dim) / 16;
    }
    else if (((N + 1) * Dim) % 16 != 0)
    {
        nr_numere = (((N + 1) * Dim) / 16) + 1;
    }
    long int rezult = 0;
    // printf("Operand 0:%hu\n", rezult);
    int k = 0;
    for (int i = 0; i < nr_numere; i++)
    {
        scanf("%hu", &numere[i]);
        for (int j = 0; j < x; j++)
        {
            operand[j] = numere[i] << (Dim * j);
            operand[j] = operand[j] >> (Dim * (x - 1));
            if ((i == 0) && (j == 0))
            {
                rezult = operand[0];
            }
            else
               { rezult = rezult;

            switch (vect_operatori[k])
            {
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
               // printf("\nrezultat=%ld\n", rezult);
          

          //  printf("OPERAND: %hu\n ", operand[j]); // afisam operanzii
        }
    }
   
    printf("%ld\n", rezult);

    return 0;
}