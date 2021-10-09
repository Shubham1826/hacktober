#include<stdio.h>

int main() { system("cls");

    int swap1(int r, int c, int M[][c], int i, int j);          /*declaration of functions*/
    int swap2(int r, int c, int* p, int i, int j);
    int swap3(int r, int c, int** p, int i, int j);
    int swap4(int r, int c, int (*p)[], int i, int j);
    void printMatrix(int r, int c, int M[][c]);

    int r, c;
    printf("\nEnter number of rows in the matrix: ");
    scanf("%d", &r);
    printf("Enter number of columns in the matrix: ");
    scanf("%d", &c);

    if(r <= 1 || c <= 1) {                                  /*checking the size of array*/
        printf("\n\tINVALID SIZE!\n");
    }

    int M[r][c];

    printf("\nEnter elements of the Matrix:\n"
            "(with each element in a column separated with a space and each row separated with a line): \n");
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            scanf("%d", *(M + i) + j);
        }
    }

    printf("\nThe Matrix entered is:\n");
    printMatrix(r, c, M);

    int i, j;
    printf("\nEnter the row numbers that need to be interchanged(function 1): ");
    scanf("%d %d", &i, &j);
    int result = swap1(r, c, M, --i, --j);

    if(result == 0) {
        printf("Entered values are not valid row indices!\n");
    }

    printMatrix(r, c, M);

    printf("\nEnter the row numbers that need to be interchanged(function 2): ");
    scanf("%d %d", &i, &j);
    result = swap2(r, c, (int*)M, --i, --j);

    if(result == 0) {
        printf("Entered values are not valid row indices!\n");
    }

    printMatrix(r, c, M);

    printf("\nEnter the row numbers that need to be interchanged(function 3): ");
    scanf("%d %d", &i, &j);
    result = swap3(r, c, (int **)M, --i, --j);

    if(result == 0) {
        printf("Entered values are not valid row indices!\n");
    }

    printMatrix(r, c, M);

    printf("\nEnter the row numbers that need to be interchanged(function 4): ");
    scanf("%d %d", &i, &j);
    result = swap4(r, c, M, --i, --j);

    if(result == 0) {
        printf("Entered values are not valid row indices!\n");
    }

    printMatrix(r, c, M);
    return 0;
}

int swap1(int r, int c, int M[][c], int i, int j) {

    if(i < 0 || r <= i || j < 0 || r <= j) 
        return 0;

    for(int cIter = 0; cIter < c; ++cIter) {
        int temp = M[i][cIter];
        M[i][cIter] = M[j][cIter];
        M[j][cIter] = temp;
    }
    return 1;
}

int swap2(int r, int c, int* p, int i, int j) {

    if(i < 0 || r <= i || j < 0 || r <= j) 
        return 0;
    for(int cIter = 0; cIter < c; ++cIter) {
        int temp = *(p + (i*c) + cIter);
        *(p + (i*c) + cIter) = *(p + (j*c) + cIter);
        *(p + (j*c) + cIter) = temp;
    }
    return 1;
}

int swap3(int r, int c, int** p, int i, int j) {

    if(i < 0 || r <= i || j < 0 || r <= j) 
        return 0;
    for(int cIter = 0; cIter < c; ++cIter) {
      
        int temp = *((int *)p + i*c + cIter);
        *((int *)p + i*c + cIter) = *((int *)p + j*c + cIter);
        *((int *)p + j*c + cIter) = temp;
    }
    return 1;
}

int swap4(int r, int c, int (*p)[c], int i, int j)
    {

    if(i < 0 || r <= i || j < 0 || r <= j) 
        return 0;

    for(int cIter = 0; cIter < c; ++cIter) {
        int temp = p[i][cIter];
        p[i][cIter] = p[j][cIter];
        p[j][cIter] = temp;
    }
    return 1;
}

void printMatrix(int r, int c, int M[][c])              /*printing the matrix*/
    {
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}
