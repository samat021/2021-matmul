#include "matrix.h"


//when you are in a loop, first the cache is empty. 


//B is taking the most time, so do B transpose to help with to make it faster

void matmul_student(const matrix_t *A, const matrix_t *B, matrix_t *C) {
    // TODO Not Yet Implemented
    //takes less time b/c it doens't 
    //dereference every time the loop is called
    long row = A->nrows;
    long colA = A->ncols;
    long colB = B->ncols;
    long colC = (C)->ncols;

    int* dataC = (C)->data;
    int* dataB = (B)->data;
    int* dataA = (A)->data;

    long mulC = 0;
    long mulB = 0;

    int j = 0;
    int k = 0;
    int a = 0;

    // dataB[ i* colB + j]     MGET(B, j, k);

    for (int i = 0; i < row; i++) {
        for (j = 0; j < colA; j++) {
 
            a = dataA[i* colA + j];    // int a = MGET(A, i, j);  

            mulC = i * colC;
            mulB = j * colB;

            for (k = 0; k < colB - 4; k += 5) {
                dataC[mulC+ k] += a * dataB[mulB + k];
                dataC[mulC+ k + 1] += a * dataB[mulB + k + 1];
                dataC[mulC+ k + 2] += a * dataB[mulB + k + 2];
                dataC[mulC+ k + 3] += a * dataB[mulB + k + 3];
                dataC[mulC+ k + 4] += a * dataB[mulB + k + 4];

                // // previous code!
                // dataC[i * colC + k] += a * dataB[j * colB + k];
                // dataC[i * colC + k + 1] += a * dataB[j * colB + k + 1];
                // dataC[i * colC + k + 2] += a * dataB[j * colB + k + 2];
                // dataC[i * colC + k + 3] += a * dataB[j * colB + k + 3];
                // dataC[i * colC + k + 4] += a * dataB[j * colB + k + 4];
            }
            for (; k < colB; k++){
                dataC[mulC+ k] += a * dataB[mulB + k];
                // dataC[i * colC + k] += a * dataB[j * colB + k];
                
            }


        }


    }


}
