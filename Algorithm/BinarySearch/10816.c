#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int binarySearch(int arr[], int N, int target) {
	int low = 0;
	int high = N;
	int count = 0;

	while (low < high) {
		int mid = (low + high) / 2;
		if (arr[mid] < target) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	int lowerbound = low;

	low = 0;
	high = N;
	while (low < high) {
		int mid = (low + high) / 2;
		if (arr[mid] <= target) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	int upperbound = low;

	count = upperbound - lowerbound;

	return count;
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

int main(void) {


	int N;
	scanf("%d", &N);
	int* arr = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, N, sizeof(int), compare);

	int M;

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int target;
		int count;
		scanf("%d", &target);
		count = binarySearch(arr, N, target);
		printf("%d ", count);
	}

	free(arr);

	return 0;

}
