#include <stdio.h>

#define MAXLENGTH 1000 /* Max lenght of lines inputted */

int returnline(char line[], int max);
void reverse(char s[], char reverseds[], int len);

/* Prints reversed input line */
int main(void) {
    char line[MAXLENGTH];
    char reversedline[MAXLENGTH];
    int len;

    while ((len = returnline(line, MAXLENGTH))) {
        reverse(line, reversedline, len); 
        printf("%s", reversedline);
    }
    return 0;
}

/* Parses one line from the input */
int returnline(char line[], int lim) {
    int c, i;
    for(i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    
    if (c == '\n'){
        line[i] = '\n';
        ++i;
    }
    line[i] = '\0';
    return i;
}
/* Reverses the inputted character sring */
void reverse(char s[], char reverseds[], int len) {
    int i;
    if (s[len-1] == '\n') {
        for (i=0; i<len-1; ++i)
            reverseds[len-2-i] = s[i];
        reverseds[i] = '\n';
        ++i;
    } else 
        for (i=0; i<len; ++i)
            reverseds[len-1-i] = s[i];
    
    reverseds[i] = '\0';
}