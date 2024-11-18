#include "matrix.h"


void get_every_fifth_student(const matrix_t *matrix, long results[RESULTS_LEN]) {
    // TODO Not Yet Implemented (j % 5)
    // loop unrolling
    long row = matrix->nrows;
    long col = matrix->ncols;
    int j = 0;
    long h0 = 0;
    long h1 = 0;
    long h2 = 0;
    long h3 = 0;
    long h4 = 0; //if fail double check here!!!
    long q = 0;
    int* dataM = (matrix)->data;


    for (int i = 0; i < row; i++) {
        for (j = 0; j < col - 4; j+= 5) {  
            h0 += dataM[i * col + j];    // MGET(matrix, i, j); // results[0] += MGET(matrix, i, j);
            h1 += dataM[i * col + j + 1];;
            h2 += dataM[i * col + j + 2];;
            h3 += dataM[i * col + j + 3];;
            h4 += dataM[i * col + j + 4];;
        }
        for ( ; j < col; j++){
            //doesnt matter how slow it is, rarely runned
            q = j % 5;
            results[q] += dataM[i * col + j];     //MGET(matrix, i, j);

        }
    }
    results[0] += h0;
    results[1] += h1;
    results[2] += h2;
    results[3] += h3;
    results[4] += h4;

}




long get_every_student(const matrix_t *matrix) {
    // TODO Not Yet Implemented
    
    long row = matrix->nrows;
    long col = matrix->ncols;
    int j = 0;
    long h0 = 0;
    long h1 = 0;
    long h2 = 0;
    long h3 = 0;
    long h4 = 0; //if fail double check here!!!
    long sum = 0;
    int* dataM = (matrix)->data;
    long temp = 0;

    // dataM[i * col + j]

    // go a differ


    for (int i = 0; i < row; i++) {

        temp = i * col;

        for (j = 0; j < col - 4; j+= 5) {  
            h0 += dataM[temp + j];   // MGET(matrix, i, j); // results[0] += MGET(matrix, i, j);
            h1 += dataM[temp + j + 1];    // MGET(matrix, i, j + 1);
            h2 += dataM[temp + j + 2];
            h3 += dataM[temp + j + 3];
            h4 += dataM[temp + j + 4];
            // h0 += dataM[i * col + j];   // MGET(matrix, i, j); // results[0] += MGET(matrix, i, j);
            // h1 += dataM[i * col + j + 1];    // MGET(matrix, i, j + 1);
            // h2 += dataM[i * col + j + 2];
            // h3 += dataM[i * col + j + 3];
            // h4 += dataM[i * col + j + 4];
        }
        for ( ; j < col; j++){
            h0 += dataM[i * col + j]; // MGET(matrix, i, j);
        }
    }


    sum += h0 + h1 + h2 + h3 + h4;

    return sum;
}
