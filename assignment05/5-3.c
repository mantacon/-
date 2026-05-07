#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define asize 10000
#define bsize 6

void countA(int a[], int b[]);

int main(void){
  srand((unsigned int)time(NULL));
  int a[asize];
  int b[bsize];
  for(int i=0;i<asize;i++){
    a[i] = rand() % 6;
  }
  countA(a,b);
  for(int i=0;i<bsize;i++){
    printf("%d‚Ì”  %d\n",i,b[i]);
  }
}

void countA(int a[], int b[]){
  for(int i=0;i<asize;i++){
    switch(a[i]){
      case 0:
        b[0]++;
        break;
      case 1:
        b[1]++;
        break;
      case 2:
        b[2]++;
        break;
      case 3:
        b[3]++;
        break;
      case 4:
        b[4]++;
        break;
      case 5:
        b[5]++;
        break;
    }
  }
}

