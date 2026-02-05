#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createDiffArr(const int *arr, int *diff_arr, int size){
    diff_arr[0] = arr[0];
    for (int i = 1; i < size; i += 1)
        diff_arr[i] = arr[i] - arr[i - 1];
}

void printArr(const int *arr, int size){
    for (int i = 0; i < size; i += 1)
        printf("%d ", arr[i]);

    printf("\n");
}

void setDifferenceArr(int *arr, int limite_inferior, int limite_superior, int escalar, int last_index){
    arr[limite_inferior] += escalar;

    int flag = (limite_superior + 1 > last_index) ? 1 : 0;

    if (!flag)
        arr[limite_superior + 1] -= escalar;
}

void prefixSum(const int *arr, int *ps_arr, int size){
    ps_arr[0] = arr[0];

    for (int i = 1; i < size; i += 1)
        ps_arr[i] = ps_arr[i - 1] + arr[i];
}

int main(){
    int arr[] = {1, 3, 5, 7, 9};

    int len = sizeof (arr) / sizeof (arr[0]);
    int diff_arr[len];

    memset(diff_arr, 0, sizeof (diff_arr));

    createDiffArr(arr, diff_arr, len);
    printArr(diff_arr, len);

    int flag = 0;
    int final_arr[len];
    
    memset(final_arr, 0, sizeof (final_arr));

    while (flag == 0){
        int escalar, range_ini, range_fim;

        printf("Digite o valor do escalar que deseja somar ao vetor e os indices referentes ao range da soma:\n");
        if (scanf("%d %d %d", &escalar, &range_ini, &range_fim) != 3)
            break;

        flag = (escalar == 0 || range_ini < 0 || range_ini > range_fim || range_fim > len - 1) ? 1 : 0;

        if(!flag)
            setDifferenceArr(diff_arr, range_ini, range_fim, escalar, len - 1);

        // Quando entrada inválida é detectada, reconstruímos o array final

        else prefixSum(diff_arr, final_arr, len);
    }
    printf("Array resultante:\n");
    printArr(final_arr, len);

    return 0;
}
