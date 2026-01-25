#include <stdio.h>

#define MAXLINE 1000  /* maximum input line size */

int getline(char line[], int maxline);
void removetrailingwhitespace(char to[], char from[]);

/* prints input line without trailing balnks and tabs */
int main(void)
{
    int len;               /* current line length */
    char line[MAXLINE];    /* current input line */
    char cleanedline[MAXLINE]; /* cleaned line saved here */

    while ((len = getline(line, MAXLINE)) > 0)
        if (len > 1) {
            removetrailingwhitespace(cleanedline, line);
            printf("%s", cleanedline);
        }

    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

/* remove trailing blanks and tabs from strings */
void removetrailingwhitespace(char to[], char from[])
{
    int i, j, c, c1, finished, newlinepresent;
    i = finished = 0;

    while ((c = from[i]) != '\0'){
        if (c == ' ' || c == '\t') {
            newlinepresent = 0;
            j = i + 1;
            while ((c1 = from[j]) == ' ' || c1 == '\t' || c1 == '\n' || c1 == '\0') {
                if (c1 == '\0') {
                    finished = 1;
                    break;
                } else if (c1 == '\n') {
                    newlinepresent = 1;
                }
                ++j;
            }
            
        }
        if (finished) 
            break;
        to[i] = c;
        ++i;
        
    }
    if (newlinepresent) {
        to[i] = '\n';
        ++i;
    }
    to[i] = '\0';
}
