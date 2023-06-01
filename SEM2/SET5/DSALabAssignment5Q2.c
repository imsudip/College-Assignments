#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap arr[i] and arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void displayArray(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, n;
    char repeat;
    
    do {
        printf("Enter the number of elements in the array: ");
        scanf("%d", &n);
    
        int arr[n];
    
        printf("Enter the elements of the array:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
    
        printf("\nMenu:\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    
        switch (choice) {
            case 1:
                bubbleSort(arr, n);
                printf("\nArray after Bubble Sort:\n");
                displayArray(arr, n);
                break;
            
            case 2:
                insertionSort(arr, n);
                printf("\nArray after Insertion Sort:\n");
                displayArray(arr, n);
                break;
            
            case 3:
                selectionSort(arr, n);
                printf("\nArray after Selection Sort:\n");
                displayArray(arr, n);
                break;
            
            default:
                printf("Invalid choice!\n");
                break;
        }
        
        printf("\nDo you want to perform another operation? (y/n): ");
        scanf(" %c", &repeat);
        printf("\n");
        
    } while (repeat == 'y' || repeat == 'Y');
    
    return 0;
}
