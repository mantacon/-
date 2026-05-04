#include<stdio.h>

typedef struct{
    double x;
    double y;
    double z;
}strVec;

strVec crossProduct(strVec, strVec);

int main(void){
    strVec vec1={1,3,5};
    strVec vec2={2,4,6};
    printf("Vector A:(%lf,%lf,%lf)\n",vec1.x, vec1.y, vec1.z);
    printf("Vector B:(%lf,%lf,%lf)\n",vec2.x, vec2.y, vec2.z);
    strVec crossPro = crossProduct(vec1, vec2);
}

strVec crossProduct(strVec vec1,strVec vec2){
    strVec crossPro = {vec1.y*vec2.z - vec1.z*vec2.y, vec1.z*vec2.x - vec1.x*vec2.z, vec1.x*vec2.y - vec1.y*vec2.x};
    return crossPro;
}