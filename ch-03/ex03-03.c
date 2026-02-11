#include <stdio.h>
#include <stdbool.h>

void expand(char s1[], char s2[]);

int main(void) {
    char s1[] = "a--d";
    char s2[10000];
    expand(s1, s2);
    printf("%s", s2);
}

char isvalid(char c) {
    if (c >= 'A' && c <= 'Z')
        return 'Z';
    else if (c >= 'a' && c <= 'z')
        return 'z';
    else if (c >= '0' && c <= '9')
        return '9';
    else 
        return 0;
}

void expand(char s1[], char s2[]) {
    int i, s2i, c;
    bool waspreviousexpanded = false;
    s2i=0;
    
    for (i=0; s1[i] != '\0'; ++i, s2i++) {
        if ((c = isvalid(s1[i])) && (s1[i+1] == '-') && (s1[i+2] > s1[i] && s1[i+2] <= c)) {
            if (waspreviousexpanded) {
                ;
            } else {
                s2[s2i] = s1[i];
                ++s2i;
            }
            for (int j=s1[i]+1; j < s1[i+2]; j++, s2i++) {
                s2[s2i] = (char) j;
            }
            s2[s2i] = s1[i+2];
            i++;
            waspreviousexpanded=true;
            
        } else {
            if (waspreviousexpanded) {
                waspreviousexpanded = false;
                --s2i;
            }else {
                s2[s2i] = s1[i]; 
            }
        }
    }
    s2[s2i] = '\0';
}

