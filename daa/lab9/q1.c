#include <stdio.h>
#include <string.h>

void getShiftTable(int shiftTable[], char pattern[], int pLen) {
    int i;
    for(i = 0; i < pLen - 1; i++)
        shiftTable[(int) pattern[i]] = pLen -1 - i;
}

int horspool(char sentence[], char pattern[], int sLen, int pLen, int *comparisons) {
    int i, j;
    int shiftTable[127];
    for (i = 0; i < 127; i++)
        shiftTable[i] = pLen;
    getShiftTable(shiftTable,pattern,pLen);
    i  = pLen - 1;
    while (i < sLen) {
        j = 0;
        while (j < pLen && pattern[pLen - 1 - j] == sentence[i - j])
            j++;
        *comparisons = *comparisons + j + 1;
        if (j == pLen)
            return (i - pLen + 1);
        else 
            i = i + shiftTable[(int) sentence[i]];
    }
    return -1;
}

void main() {
    int res, comparisons = 0;
    char sentence[100], pattern[100];
    printf("enter the sentence: ");
    scanf("%[^\n]",sentence);
    printf("enter the pattern: ");
    scanf(" %s",pattern);
    res = horspool(sentence, pattern, strlen(sentence), strlen(pattern), &comparisons);
    if (res == -1)
        printf("pattern not found\ncomparisons: %d\n",comparisons);
    else
        printf("pattern found at index %d\ncomparisons: %d\n",res,comparisons);
}