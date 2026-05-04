#include<stdio.h>

int printNum2(unsigned int);

int main(void){
    unsigned int a = 0;
    printf("enter a natural number\n");
    scanf("%u",&a);
    printNum2(a);
}

int printNum2(unsigned int a){
    unsigned int temp[4] = {0};
    int i=0;
    for(;a > 0;i++){
        temp[i] = a%1000;
        a/=1000;
    }
    printf("%u",temp[i-1]);
    i-=1;
    for(;i>0;i--){
        printf(",%03u",temp[i-1]);
    }
}