#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
    // 1. Find longest non-increasing suffix
    int i = n - 2;
    while (i >= 0 && strcmp(s[i], s[i + 1]) >= 0)
        i--;

    // If no pivot, permutation is final
    if (i < 0)
        return 0;

    // 2. Find rightmost element greater than s[i]
    int j = n - 1;
    while (strcmp(s[j], s[i]) <= 0)
        j--;

    // 3. Swap pivot with successor
    char *tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;

    // 4. Reverse the suffix
    int l = i + 1, r = n - 1;
    while (l < r)
    {
        tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }

    return 1;
}




int main()
