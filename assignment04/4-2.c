#include<stdio.h>

int GCD(int, int);

int main(void){
    int a = 0;
    int b = 0;
printf("enter two natural numbers\n");
    scanf("%d",&a);
    scanf("%d",&b);
    printf("GCD(%d,%d) = %d", a, b, GCD(a, b));
    return 0;
}

int GCD(int a, int b){
    if(a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (a%b == 0) return b;
    GCD(b, a%b);
}