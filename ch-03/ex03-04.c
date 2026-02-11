#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]); /* itoa: convert n to characters in s */

int main() {
    char s[1000];
    itoa(INT_MIN, s);
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

/*  it wont handle the largest negative number as we force the negative to positive so it will be out of range by one 
    for example in a two complement number system the range is -128 to 127. So 128 cannot be represented as a positive */

void itoa(int n, char s[]) {
    int i, sign;
    sign = n;

    i = 0;
    do {
        s[i++] = getabs(n % 10) + '0'; 
    } while ((n /= 10)  != 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}