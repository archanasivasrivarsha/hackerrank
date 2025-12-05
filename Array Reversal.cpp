#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);   // Read size of array
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);   // Read array elements
    }
    
    // Print array in reverse order
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

