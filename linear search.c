#include <stdio.h>
// Function to perform Linear Search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) { // If key is found
            return i; // Return the index
        }
    }
    return -1; // Return -1 if key is not found
}
int main() {
    int arr[] = {10, 25, 30, 45, 50, 60}; // Sample array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate array size
    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int result = linearSearch(arr, size, key);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array.\n");
    return 0;
}
/*Enter the element to search: 45
Element found at index 38*/
