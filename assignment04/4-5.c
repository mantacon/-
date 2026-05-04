#include<stdio.h>

int GCD(int, int);
int GCD2(int array[], int num);

int main(void){
    int array[100];
    printf("3個以上の自然数を入力してください\n");
    printf("(0以下の入力で終了、0以下が入力される直前までのすべての自然数の最大公約数を表示します)\n");
    int i=0;
    for(;;i++){
        printf("%d個目の自然数: ",i+1);
        scanf("%d",&array[i]);
        if (array[i] == 0) break;
    }
    printf("0以下が入力される直前までのすべての自然数の最大公約数は%d",GCD2(array,i));
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
int GCD2(int array[], int num){
    int a=array[0];
    for(int i=0;i<num-1;i++){
        a=GCD(a,array[i+1]);
    }
    return a;
}