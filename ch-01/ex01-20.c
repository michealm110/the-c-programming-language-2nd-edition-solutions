#include <stdio.h>

#define MAXLENGTH 1000
#define N         4

int returnline(char line[], int lim);
void detabline(char line[], char detabbedline[], int len);

int main(void) {
    int len, i, c;
    char line[MAXLENGTH];
    char detabbedline[MAXLENGTH];

    while ((len = returnline(line, MAXLENGTH))) {
        detabline(line, detabbedline, len);
        printf("%s", detabbedline);
    }
    
}

void detabline(char line[], char detabbedline[], int len) {
    int i, c, buffer, tempbuffer, spacestilltabstop, col;
    buffer = 0;
    spacestilltabstop = N;
    for (i=0; i<len; ++i) {
        if ((c=line[i]) == '\t') {
            for (int j=i+buffer; j<i+buffer+spacestilltabstop; ++j) {
                detabbedline[j] = ' ';
            }
            buffer += (spacestilltabstop-1);
            spacestilltabstop=1;
        } else {
            detabbedline[i+buffer] = c;
        }
        if (spacestilltabstop == 1)
            spacestilltabstop = N;
        else
            --spacestilltabstop;
    }
    detabbedline[i+buffer] = '\0';
}

int returnline(char line[], int lim) {
    int i, c;

    for (i = 0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) 
        line[i] = c;

    if (c=='\n') {
        line[i] = '\n';
        ++i;
    }

    line[i] = '\0';

    return i;
}