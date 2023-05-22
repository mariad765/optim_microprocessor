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
                          // printf("%d", N);      // afiseaza numarul de o
    for (int i = 0; i < N; i++)
    {
        op = inst << (3 + 2 * i); // shiftare pentru a selecta bitii 2 cate 2
        op = op >> 30;
        if (op == 0) // conditiile pentru decidere op
        {
            //  printf(" +");
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
            //  printf(" /");
        }
    }

    unsigned int Dim = 0; // dimensiunea
    Dim = inst << (3 + 2 * N);
    Dim = Dim >> 28;
    Dim++;
    // printf(" %u\n", Dim);
    //  cod task 2
    //  int x;
    //  if (16 % Dim == 0)
    //      x = 16 / Dim; // numarul de operanzi
    //  // else
    //  //     x = 16 / Dim + 1;
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

    for (int i = 0; i < nr_numere; i++)
    {
        scanf("%hu", &numere[i]);
    }
    for (int i = 0; i < N + 1; i++)
    {
        operand[i] = 0;
    }
    int k = 1;
    int p = 0;
    if (Dim > 8)
    {

        for (int i = 0; i < nr_numere; i++)
        {
            int mask = 1 << 15;
            for (int j = k; j <= Dim; j++)
            {
                if (mask & numere[i])
                {

                    operand[i] += 1 << Dim - j;
                }
                mask = mask >> 1;
            }

            // printf("OPERAND: %hu\n ", operand[i]); // afisam operanzii

            if (i == 0)
            {
                rezult = operand[0];
            }
            else
            {
                rezult = rezult;

                switch (vect_operatori[p])
                {
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
                for (k = 1; k <= (i + 1) * (16 - Dim); k++)
                {
                    if (mask & numere[i])
                    {
                        operand[i + 1] += 1 << Dim - k;
                    }
                    mask = mask >> 1;
                }
            }

            // printf("OPERAND: %hu\n ", operand[i + 1]); // afisam operanzii

            // printf("\n%d\n",k);
            // printf("OPERAND: %hu\n ", operand[i+1]); // afisam operanzii

            // Dim = 2 * Dim - 16;

            // if ((i == 0) && (j == 0))
            // {
            //     rezult = operand[0];
            // }
            // else
            // {
            //     rezult = rezult;

            //     switch (vect_operatori[k])
            //     {
            //     case '+':
            //         rezult = operand[j] + rezult;
            //         break;
            //     case '-':
            //         rezult = rezult - operand[j];
            //         break;
            //     case '*':
            //         rezult = rezult * operand[j];
            //         break;
            //     case '/':
            //         rezult = rezult / operand[j];
            //         break;
            //     }

            //     k++;
            // }
            // printf("\nrezultat=%ld\n", rezult);
        }
    }
    if (Dim < 8)
    {
        int necitit = 0;
        int g = 1;
        for (int i = 0; i < nr_numere; i++)
        {

            int mask = 1 << 15;
            if (necitit == 1)
            {
                for (int j = 0; j < 5; j++)
                {

                    if (mask & numere[i])
                    {
                        operand[g] += 1 << (Dim - 2 - j - 1);
                    }
                    mask = mask >> 1;
                }
                g++;
                necitit = 0;
                // printf("aleluia");
            }

            for (int j = 0; j < 7; j++)
            {

                if (mask & numere[i])
                {
                    operand[g] += 1 << (Dim - j - 1);
                }
                mask = mask >> 1;
            }
            // printf("this is operrand %hu\n", operand[g]);
            g++;
            if (g * Dim < 16)
            {
                for (int j = 0; j < 7; j++)
                {

                    if (mask & numere[i])
                    {
                        operand[g] += 1 << (Dim - j - 1);
                    }
                    mask = mask >> 1;
                }
                //  printf("this is operrand %hu\n", operand[g]);
                g++;
                // printf("%d\n", g);
            }

            if (((i + 1) * 16 - g * 7) < 0)
            {
                // printf("merge");
                for (int j = 0; j < 2; j++)
                {

                    if (mask & numere[i])
                    {
                        operand[g] += 1 << (Dim - j - 1);
                    }
                    mask = mask >> 1;
                }

                necitit = 1;
            }
        }

        // printf("OPERAND: %hu\n ", operand[2]); // afisam operanzii
        // printf("OPERAND: %hu\n ", operand[1]);
        // printf("OPERAND: %hu\n ", operand[3]);
        p = 0;
        for (int i = 0; i <= N; i++)
        {
            if (i == 0)
            {
                rezult = operand[1];
            }
            else
            {
                rezult = rezult;

                switch (vect_operatori[p])
                {
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