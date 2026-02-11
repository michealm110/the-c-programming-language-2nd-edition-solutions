#include <stdio.h>
#include <string.h>
void itob(int n, char s[], int b);

int main() {
    char s[10000];
    itob(32, s, 16);
    printf("%s\n", s);
}

void reverse(char s[]) {
    int i, j;
    i = 0;
    j = strlen(s) - 1;
    while (j>i) {
        char temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        --j;
        ++i;
    }
}

int getabs(int x) {
    if (x < 0) 
        return -x;
    else 
        return x;
}

void itob(int n, char s[], int b) {
    int i, sign;
    sign = n;
    i=0;
    do {
        int rem = getabs(n % b);
        char c = (char) rem + '0';
        if (rem > 9) {
            c = 'a' + (rem - 10);
        } 
        s[i++] = c;
    } while ((n /= b) != 0);
    if (sign < 0) 
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}