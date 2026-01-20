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

int main(){
    int arr[] = {10, 20, 10, 5, 15};

    int len = sizeof(arr) / sizeof(arr[0]);
    int answer_arr[len];

    memset(answer_arr, 0, sizeof(answer_arr));

    prefixSum(arr, answer_arr, len);

    printArr(arr, len);
    printArr(answer_arr, len);

    printf("A soma dos elementos pertencentes ao range [l, r] = %d\n", answer_arr[len - 1] - answer_arr[0]);
 
    return 0;
}
