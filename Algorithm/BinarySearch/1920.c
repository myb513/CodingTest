#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)


int binarySearch(int arr[], int N, int target) {
    int low = 0;
    int high = N - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return 1;  // 타겟을 찾았을 때
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return 0;  // 타겟을 찾지 못했을 때
}

int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 < num2) {
        return -1;
    }
    else if (num1 > num2) {
        return 1;
    }
    return 0;
}


int main() {
    int N;
    scanf("%d", &N);

    int* arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // 배열을 오름차순으로 정렬
    qsort(arr, N, sizeof(int), compare);

    
    int M;
    scanf("%d", &M);

  

    for (int i = 0; i < M; i++) {
        int target;
        scanf("%d", &target);
        int found = binarySearch(arr, N, target);
        printf("%d ", found);
    }

    free(arr);

    return 0;
}
