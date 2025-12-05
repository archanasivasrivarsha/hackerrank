#include <stdio.h>

// Helper function to return maximum of two numbers
int max(int x, int y) {
    if (x > y)
        return x;
    else
        return y;
}

// Function to return maximum of four numbers
int max_of_four(int a, int b, int c, int d) {
    int m1 = max(a, b);
    int m2 = max(c, d);
    return max(m1, m2);
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int result = max_of_four(a, b, c, d);
    printf("%d\n", result);
    return 0;
}

