#include <stdio.h>

// Function to perform Binary Search
int binarySearch(int searchList[], int size, int key) {
    if (searchList == NULL || size == 0) {
        return -1; // Return NULL equivalent (-1) if list is empty or invalid
    }

    int start = 0, end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        printf("Middle value: %d\n", searchList[mid]);  // print middle value

        if (searchList[mid] == key) {
            printf("Found at index: %d\n", mid);
            return mid; // found
        } 
        else if (key > searchList[mid]) {
            printf("Searching right half. New start = %d\n", mid + 1);
            start = mid + 1; // search in right half
        } 
        else {
            printf("Searching left half. New end = %d\n", mid - 1);
            end = mid - 1; // search in left half
        }
    }

    return -1; // not found
}

int main() {
    int searchList[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(searchList) / sizeof(searchList[0]);
    int key;

    printf("Enter the value to search: ");
    scanf("%d", &key);

    int result = binarySearch(searchList, size, key);

    if (result == -1)
        printf("NULL (Value not found)\n");
    else
        printf("Value found at index %d\n", result);

    return 0;
}