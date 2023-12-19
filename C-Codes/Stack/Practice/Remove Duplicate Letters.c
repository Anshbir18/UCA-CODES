// https://leetcode.com/problems/remove-duplicate-letters/description/

#include <stdio.h>
#include <stdbool.h>

char* removeDuplicateLetters(char* s) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }

    char* result = (char*)malloc((n + 1) * sizeof(char));
    int resultIndex = 0;

    int taken[26] = {0};  // O(1) space
    int lastIndex[26] = {0};  // O(1) space

    for (int i = 0; i < n; i++) {
        char ch = s[i];
        lastIndex[ch - 'a'] = i;
    }

    for (int i = 0; i < n; i++) {
        int idx = s[i] - 'a';

        if (taken[idx] == 1) {
            continue;
        }

        while (resultIndex > 0 && s[i] < result[resultIndex - 1] && lastIndex[result[resultIndex - 1] - 'a'] > i) {
            taken[result[resultIndex - 1] - 'a'] = 0;
            resultIndex--;
        }

        result[resultIndex++] = s[i];
        taken[idx] = 1;
    }

    result[resultIndex] = '\0';

    return result;
}
