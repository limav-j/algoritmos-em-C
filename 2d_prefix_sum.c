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

int range_sum_2d(int num_lin, int num_col, const int ps_matr[num_lin][num_col], int right_idx_i, int right_idx_j, int left_idx_i, int left_idx_j){
    int total = ps_matr[right_idx_i][right_idx_j];
    
    int l_sup = (left_idx_i == 0) ? 0 : ps_matr[left_idx_i - 1][right_idx_j];
    int c_esq = (left_idx_j == 0) ? 0 : ps_matr[right_idx_i][left_idx_j - 1];
    int overlap = (left_idx_i == 0 || left_idx_j == 0) ? 0 : ps_matr[left_idx_i - 1][left_idx_j - 1];

    return total + overlap - l_sup - c_esq;
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

    int flag = 0;

    while (flag == 0){
        int left_i, left_j, right_i, right_j;

        printf("Digite o indice do intervalo inclusivo das somas\n");
        if (scanf("%d %d %d %d", &left_i, &left_j, &right_i, &right_j) != 4)
            break;

        flag = (left_i < 0 || left_i > right_i || right_i > num_lin - 1) ? 1 : 0;

        if (!flag){
            flag = (left_j < 0 || left_j > right_j || right_j > num_col - 1) ? 1 : 0;

            if (!flag)
                printf("A soma dos valores nessa área é de %d\n", range_sum_2d(num_lin, num_col, prefix_sum_2d, right_i, right_j, left_i, left_j)); 
        }
    }

    return 0;
}
