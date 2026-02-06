/* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos = 0;  // position for next non-zero element

    // Move non-zero elements forward
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            int temp = arr[pos];
            arr[pos] = arr[i];
            arr[i] = temp;
            pos++;
        }
    }

    // Print updated array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
