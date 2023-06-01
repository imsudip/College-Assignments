#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key) {
            return mid;
        }
        
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int choice, n, key, result;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nMenu:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("\nEnter the key to search: ");
            scanf("%d", &key);
            
            result = linearSearch(arr, n, key);
            if (result == -1) {
                printf("Element not found in the array.\n");
            } else {
                printf("Element found at index %d.\n", result);
            }
            break;
            
        case 2:
            printf("\nEnter the key to search: ");
            scanf("%d", &key);
            
            result = binarySearch(arr, 0, n - 1, key);
            if (result == -1) {
                printf("Element not found in the array.\n");
            } else {
                printf("Element found at index %d.\n", result);
            }
            break;
            
        default:
            printf("Invalid choice!\n");
            break;
    }
    
    return 0;
}
