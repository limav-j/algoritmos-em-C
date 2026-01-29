#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefixSum(const int *arr, int *ps_arr, int n){
    ps_arr[0] = arr[0];

    for (int i = 1; i < n; i += 1)
        ps_arr[i] = arr[i] + ps_arr[i - 1];
}

void printArr(const int *arr, int n){
    for(int i = 0; i < n; i += 1)
        printf("%d ", arr[i]);

    printf("\n");
}

int rangeSum(const int *ps_arr, int left_idx, int right_idx){
    int limite_inferior = (left_idx == 0) ? 0 : ps_arr[left_idx - 1];
    int limite_superior = ps_arr[right_idx];

    return limite_superior - limite_inferior;
}

int main(){
    int arr[] = {10, 20, 10, 5, 15};

    int len = sizeof(arr) / sizeof(arr[0]);
    int answer_arr[len];

    memset(answer_arr, 0, sizeof(answer_arr));

    prefixSum(arr, answer_arr, len);

    printArr(arr, len);
    printArr(answer_arr, len);
    
    int flag = 0;

    while (flag == 0){
        int left_index, right_index;

        printf("Digite o indice do intervalo inclusivo das somas\n");
        if (scanf("%d %d", &left_index, &right_index) != 2)
            break;

        flag = (left_index > right_index || left_index < 0 || right_index > len - 1) ? 1 : 0;

        if (!flag)
            printf("A soma dos elementos pertencentes ao range [l, r] = %d\n", rangeSum(answer_arr, left_index, right_index));
    }

    return 0;
}
