#include "sorting_algorithms.c"

void measureExecutionTime(void (*sortFunc)(int[], int), int arr[], int n, const char *sortName) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    sortFunc(arr, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%s took %f seconds to execute \n", sortName, cpu_time_used);
}

int main() {
    int n = 1000; // Example size, adjust as needed
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Random numbers
    }

    int *arrCopy = (int *)malloc(n * sizeof(int));
    memcpy(arrCopy, arr, n * sizeof(int));
    measureExecutionTime(selectionSort, arrCopy, n, "Selection Sort");

    memcpy(arrCopy, arr, n * sizeof(int));
    measureExecutionTime(insertionSort, arrCopy, n, "Insertion Sort");

    memcpy(arrCopy, arr, n * sizeof(int));
    measureExecutionTime(mergeSort, arrCopy, 0, n - 1, "Merge Sort");

    free(arr);
    free(arrCopy);
    return 0;
} 