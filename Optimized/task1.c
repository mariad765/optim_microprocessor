#include <stdio.h>
#include <math.h>

int main()
{
    
    unsigned int inst;  // instructiunea
    scanf("%u", &inst); // se citeste instructiunea
    int N;  // numarul de instructiuni
    int op;  // variabila pentru decidere operatori

    N = inst >> (32 - 3);  //shifteaza bitii 
    N = N + 1;  // numarul relevant pt primii 3 biti
    printf("%d", N);  //afiseaza numarul de op

    for (int i = 0; i < N; i++)
    {
        op = inst << (3 + 2 * i);  //shiftare pentru a selecta bitii 2 cate 2
        op = op >> 30;
        if (op == 0)  // conditiile pentru decidere op
            printf(" +");
        if (op == 1)
            printf(" -");
        if (op == -2)
        {
            printf(" *");
        }
        if (op == -1)
        {
            printf(" /");
        }
    }
   unsigned int Dim=0;  //dimensiunea
   Dim= inst << (3 + 2 * N);
    Dim = Dim >> 28;
    Dim++;
    printf(" %u\n", Dim);


    return 0;
}