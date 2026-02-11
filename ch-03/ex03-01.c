#include <stdio.h>
#include <time.h>

int binsearch(int low, int v[], int n);
int kandrbinsearch(int low, int v[], int n);

int main() {
    int beforebin, afterbin, timeforoursearch;
    int beforekandrbin, afterkandrbin, timeforkandrsearch;
    int n, index, target;
    int v[1000000];
    for (int i=0; i<1000000; ++i) {
        v[i] = i;
    }

    
    n = sizeof(v) / sizeof(v[0]);
    target = 1000000-55;

    beforebin = clock();
    index = binsearch(target, v, n);
    afterbin = clock();
    timeforoursearch = afterbin - beforebin;

    beforekandrbin = clock();
    index = kandrbinsearch(target, v, n);
    afterkandrbin = clock();
    timeforkandrsearch = afterkandrbin - beforekandrbin;

    printf("target found at index %d\n", index);
    printf("Our binary search algorithm took %d units\n", timeforoursearch);
    printf("K and R's binary search algorithm took %d units\n", timeforkandrsearch);
}

int kandrbinsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else 
            return mid;
    }
    return -1;
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low < high) {
        mid = (low+high) / 2;
        if (x <= v[mid])
            high = mid ;
        else 
            low = mid+1;
    }
    if (v[low] == x)
        return low;
    else 
        return -1;
}