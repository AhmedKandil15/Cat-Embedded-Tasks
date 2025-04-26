#include <iostream>
#include <stdio.h>

int binarySearch(int arr[], int size, int target, int *steps) {
    int left = 0;
    int right = size - 1;
    *steps = 0;
    while (left <= right) {
        (*steps)++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int size, target, index, steps;
    printf("Enter the number of elements in the sorted array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d sorted integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target value to search: ");
    scanf("%d", &target);
    index = binarySearch(arr, size, target, &steps);
    if (index != -1)
        printf("Target %d found at index %d.\n", target, index);
    else
        printf("Target %d not found in the array.\n", target);

    printf("Binary search completed in %d step(s).\n", steps);
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.