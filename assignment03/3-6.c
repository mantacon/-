#include<stdio.h>
#include<math.h>

#define M_PI 3.14159265358979323846
#define maxX(vec1,vec2) do{\
    if(vec1.x>vec2.x){\
        printf("ç≈ëÂxç¿ïW:%d\n",vec1.x);\
    }else{\
        printf("ç≈ëÂxç¿ïW:%d\n",vec2.x);\
    }\
}while(0)

typedef struct{
    int x;
    int y;
    int z;
}strVec;

double vecDotProduct(strVec,strVec);

int main(void){
    strVec vec1={1,3,5};
    strVec vec2={2,4,6};
    printf("Vector1:(%d,%d,%d)\n",vec1.x,vec1.y,vec1.z);
    printf("Vector2:(%d,%d,%d)\n",vec2.x,vec2.y,vec2.z);
    maxX(vec1,vec2);
}