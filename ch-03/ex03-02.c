#include <stdio.h>

void escape(char s[], char t[]);
void normalising(char s[], char t[]);

int main() {
    char t[] = "hello\thow are you\n";
    char s[10000];
    escape(s,t);
    normalising(t, s);
    printf("%s", t);
}

void escape(char s[], char t[]) {
    int i, si;

    si = 0;
    for (i=0; t[i] != '\0'; ++i) {  
        switch (t[i]) {
            case '\n': 
                s[si] = '\\';
                si++;
                s[si] = 'n';
                break;
            case '\t':
                s[si] = '\\';
                si++;
                s[si] = 't';
                break;
            default:
                s[si] = t[i];
                break;
        }
        ++si;
    }
    s[si] = '\0';
}

void normalising(char out[], char in[]) {
    int i, si;

    si = 0;
    for (i=0; in[i]!='\0'; ++i) {
        switch (in[i]) {
            case '\\':
                if (in[i+1] == 'n') {
                    out[si] = '\n';
                    i++;
                } else if (in[i+1] == 't') {
                    out[si] = '\t';
                    i++;
                } else {
                    out[si] = in[i];
                }
                break;
            default:
                out[si] = in[i];
                break;
        }
        ++si;
    }
    out[si] = '\0';
}
