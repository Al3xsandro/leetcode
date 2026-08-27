#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

// bool isPalindromeWithoutCast(int x)
// {
//     return false;
// }

bool isPalindromeWithCast(int x)
{
    char str[12];
    int len = snprintf(str, sizeof str, "%d", x);

    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    bool isPalindrome = isPalindromeWithCast(-121);

    printf("resultado: -> %d\n", isPalindrome);

    return 0;
}