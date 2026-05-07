#include<stdio.h>

int getInverseMatrix(int matrix[], int inverseMatrix[]);

int main(void){
    int matrix[2][2];
    int inverseMatrix[2][2];
    printf("2×2行列の値を入力してください\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("matrix[%d][%d]",i,j);
            scanf("%d",&matrix[i*2+j]);
        }
    }
    printf("行列\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%lf",matrix[i*2+j]);
        }
        printf("\n");
    }
    if(getInverseMatrix(matrix, inverseMatrix) == 0){
        printf("逆行列は存在しない\n");
    }else{
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                printf("%lf",inverseMatrix[i*2+j]);
            }   
            printf("\n");
        }
    }


}

int getInverseMatrix(int matrix[], int inverseMatrix[]){
    int determinant = matrix[0]*matrix[3] - matrix[1]*matrix[2];
    if (determinant == 0) return 0;
    inverseMatrix[0] = matrix[3] / determinant;
    inverseMatrix[1] = -1 * matrix[1] / determinant;
    inverseMatrix[2] = -1 * matrix[2] / determinant;
    inverseMatrix[3] = matrix[0] / determinant;
    return 1;
}