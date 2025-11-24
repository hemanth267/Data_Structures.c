#include <stdio.h>
// Function to perform binary search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // Check if the target is at mid
        if (arr[mid] == target)
            return mid; 
        // If target is greater, ignore the left half
        if (arr[mid] < target)
            left = mid + 1;
        // If target is smaller, ignore the right half
        else
            right = mid - 1;
    }
    return -1; // Target not found
}
int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91}; // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate array size
    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target);
    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
}
/*Enter the element to search: 23
Element found at index 5*/