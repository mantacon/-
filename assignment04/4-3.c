#include<stdio.h>

void printNum(int);

int main(void){
    int a = 0;
    printf("enter a natural number\n");
    scanf("%d",&a);
    printNum(a);
}

void printNum(int a){
    if(a < 1000){
        printf("%d",a);
    }else{
        printNum(a / 1000);
        printf(",%03d",a%1000);
    }
}