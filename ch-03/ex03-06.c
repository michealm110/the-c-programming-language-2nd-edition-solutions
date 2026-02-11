#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[], int width); /* itoa: convert n to characters in s */

int main() {
    char s[1000];
    itoa(INT_MIN, s, 20);
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

void itoa(int n, char s[], int width) {
    int i, sign, j;
    sign = n;

    i = 0;
    do {
        s[i++] = getabs(n % 10) + '0'; 
    } while ((n /= 10)  != 0);

    if (sign < 0)
        s[i++] = '-';

    for ( j=i; j<width; j++)
        s[j] = ' ';

    s[j] = '\0';
    reverse(s);

    int padding = width - strlen(s);
    
}