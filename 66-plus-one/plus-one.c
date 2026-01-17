#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i = digitsSize - 1;

    // Handle carry from the last digit
    while (i >= 0 && digits[i] == 9) {
        digits[i] = 0;
        i--;
    }

    // If all digits were 9
    if (i < 0) {
        int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
        result[0] = 1;
        for (int j = 1; j <= digitsSize; j++) {
            result[j] = 0;
        }
        *returnSize = digitsSize + 1;
        return result;
    }

    // Normal increment
    digits[i]++;
    *returnSize = digitsSize;
    return digits;
}
