#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int freq[256] = {0};   // ASCII character frequency
    int left = 0, right = 0;
    int maxLen = 0;
    int n = strlen(s);

    while (right < n) {
        freq[(unsigned char)s[right]]++;

        // If duplicate exists, shrink window
        while (freq[(unsigned char)s[right]] > 1) {
            freq[(unsigned char)s[left]]--;
            left++;
        }

        int currLen = right - left + 1;
        if (currLen > maxLen)
            maxLen = currLen;

        right++;
    }

    return maxLen;
}
