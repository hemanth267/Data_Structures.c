//inversion count -->offered by flipkart
#include <stdio.h>
int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left;
    int invCount = 0;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i);  // Count inversions
        }
    }
    while (i <= mid - 1) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (i = left; i <= right; i++) arr[i] = temp[i];
    return invCount;
}
int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int mid, invCount = 0;
    if (right > left) {
        mid = (left + right) / 2;
        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);
        invCount += mergeAndCount(arr, temp, left, mid + 1, right);
    }
    return invCount;
}
int countInversions(int arr[], int n) {
    int temp[n];
    return mergeSortAndCount(arr, temp, 0, n - 1);
}
int main() {
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Number of inversions: %d\n", countInversions(arr, n));
}
//1 20 6 4 5--> 5  i.e 20,6    20,4    20,5    6,4    6,5