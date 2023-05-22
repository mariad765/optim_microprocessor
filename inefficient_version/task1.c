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

int main() {
    unsigned int inst = zero;
    int N = zero, i = zero, dim = zero;
    int binary[thirtythree] = {zero};
    scanf("%u", &inst);
    for (i = zero; i < thirtytwo; i++) {
        binary[i] = (int)(inst % (unsigned int)two);
        inst /= two;
    }
    binary[thirtytwo] = zero;
    // for (i = 31; i >= 0; i--)
        // printf("%c", binary[i]);
    // printf("\n");
    N = four * binary[thirtyone] + two * binary[thirty] + binary[twentynine] + one;
    printf("%d ", N);
    for (i = zero; i < N; i++) {
        if (binary[twentyeight - two * i] == zero && binary[twentyseven - two * i] == zero) printf("+ ");
        if (binary[twentyeight - two * i] == zero && binary[twentyseven - two * i] == one) printf("- ");
        if (binary[twentyeight - two * i] == one && binary[twentyseven - two * i] == zero) printf("* ");
        if (binary[twentyeight - two * i] == one && binary[twentyseven - two * i] == one) printf("/ ");
    }
    dim = eight * binary[twentyeight - two * i] + four * binary[twentyseven - two * i]
     + two * binary[twentysix - two * i] + binary[twentyfive - two * i] + one;
    printf("%d\n", dim);
    return 0;
}
