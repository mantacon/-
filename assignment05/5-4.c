#include<stdio.h>

int getInverseMatrix(double matrix[], double inverseMatrix[]);

int main(void){
    double matrix[2][2];
    double inverseMatrix[2][2];
    printf("2~2s—ñ‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("matrix[%d][%d] = ",i,j);
            scanf("%lf",&matrix[i][j]);
        }
    }
    printf("s—ñ\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%lf     ",matrix[i][j]);
        }
        printf("\n");
    }
    if(getInverseMatrix((double *)matrix, (double *)inverseMatrix) == 0){
        printf("‹ts—ñ‚Í‘¶İ‚µ‚È‚¢\n");
    }else{
        printf("‚Ì‹ts—ñ‚Í\n");
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                printf("%lf     ",inverseMatrix[i][j]);
            }   
            printf("\n");
        }
    }


}

int getInverseMatrix(double matrix[], double inverseMatrix[]){
    double determinant = matrix[0]*matrix[3] - matrix[1]*matrix[2];
    if (determinant == 0) return 0;
    inverseMatrix[0] = matrix[3] / determinant;
    inverseMatrix[1] = -1 * matrix[1] / determinant;
    inverseMatrix[2] = -1 * matrix[2] / determinant;
    inverseMatrix[3] = matrix[0] / determinant;
    return 1;
}