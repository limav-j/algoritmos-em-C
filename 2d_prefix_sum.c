#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix_sum_2d_algo(int num_lin, int num_col, const int original_matr[num_lin][num_col], int pre_sum_2d[num_lin][num_col]){
    for (int i = 0; i < num_lin; i += 1){
        for (int j = 0; j < num_col; j += 1){
            int l_sup = (i > 0) ? pre_sum_2d[i - 1][j] : 0;
            int c_esq = (j > 0) ? pre_sum_2d[i][j - 1] : 0;
            int excedente = (i > 0 && j > 0) ? pre_sum_2d[i - 1][j - 1] : 0;

            pre_sum_2d[i][j] = original_matr[i][j] + l_sup + c_esq - excedente;
        }
    }
}

void print_matr(int num_lin, int num_col, const int matr[num_lin][num_col]){
    for (int i = 0; i < num_lin; i += 1){
        for (int j = 0; j < num_col; j += 1)
            printf("%d ", matr[i][j]);

        printf("\n");
    }

    printf("\n");
}

int main(){
    int matr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    
    int num_lin = sizeof (matr) / sizeof (matr[0]);
    int num_col = sizeof (matr[0]) / sizeof (matr[0][0]);

    int prefix_sum_2d[num_lin][num_col];
    
    memset(prefix_sum_2d, 0, sizeof (prefix_sum_2d));

    prefix_sum_2d_algo(num_lin, num_col, matr, prefix_sum_2d);

    print_matr(num_lin, num_col, matr);
    print_matr(num_lin, num_col, prefix_sum_2d);

    return 0;
}
