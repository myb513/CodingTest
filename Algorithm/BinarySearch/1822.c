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
    int nA, nB;
    scanf("%d %d", &nA, &nB);

    int* A = (int*)malloc(nA * sizeof(int));
    for (int i = 0; i < nA; i++) {
        scanf("%d", &A[i]);
    }

    int* B = (int*)malloc(nB * sizeof(int));
    for (int i = 0; i < nB; i++) {
        scanf("%d", &B[i]);
    }

    // 집합 A를 오름차순으로 정렬
    qsort(A, nA, sizeof(int), compare);
    qsort(B, nB, sizeof(int), compare);

    // 집합 A에 속하면서 집합 B에 속하지 않는 원소 찾기
    int* result = (int*)malloc(nA * sizeof(int));
    int count = 0;
    for (int i = 0; i < nA; i++) {
        if (!binarySearch(B, nB, A[i])) {
            result[count++] = A[i];
        }
    }

    // 결과 출력
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }

    free(A);
    free(B);
    free(result);

    return 0;
}
