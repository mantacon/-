#include<stdio.h>

typedef struct{
    int gcd;
    int x;
    int y;
}structGCD;

structGCD GCD3(int, int);

int main(void){
    int a = 0;
    int b = 0;
printf("enter two natural numbers\n");
    scanf("%d",&a);
    scanf("%d",&b);
    structGCD result = GCD3(a,b);
    printf("GCD(%d,%d) = %d\n", a, b, result.gcd);
    printf("(x,y) = (%d,%d)",result.x, result.y);
    return 0;
}

structGCD GCD3(int a, int b) {
    structGCD str1;

    if (b == 0) {
        str1.gcd = a;
        str1.x   = 1;
        str1.y   = 0;
        return str1;
    }

    structGCD str2 = GCD3(b, a % b);

    str1.gcd = str2.gcd;
    str1.x   = str2.y;
    str1.y   = str2.x - (a / b) * str2.y;

    return str1;
}