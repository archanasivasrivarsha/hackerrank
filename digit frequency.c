include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[1000];   // assuming max length of input string
    int freq[10] = {0};  // frequency array for digits 0-9
    
    // Read input string
    scanf("%s", str);
    
    // Traverse the string
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            freq[str[i] - '0']++;  // increment corresponding digit count
        }
    }
    
    // Print frequencies
    for (int i = 0; i < 10; i++) {
        printf("%d ", freq[i]);
    }
    printf("\n");
    
    return 0;
}

