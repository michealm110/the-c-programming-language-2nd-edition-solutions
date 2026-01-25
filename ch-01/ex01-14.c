#include <stdio.h>

// Solution to Exercise 1-14

#define MAXCHARS  95
#define LOWCHAR   32
#define HIGHCHAR  128
#define CHARTSIZE 20

int main(void) {
    int c, frequencyofchars[MAXCHARS], modeoffrequencyofchars;
    modeoffrequencyofchars = 0;

    for (int i = 0; i < MAXCHARS; i++) frequencyofchars[i] = 0;
    while ((c = getchar()) != EOF) {
        if (c < HIGHCHAR && c >= LOWCHAR) ++frequencyofchars[c - 32];
    }

    for (int i =0; i<MAXCHARS; i++) {
        if (frequencyofchars[i] > modeoffrequencyofchars) modeoffrequencyofchars = frequencyofchars[i];
    }

    int numofcharts = (MAXCHARS / CHARTSIZE) + 1;
    int sizeoffinalchart = MAXCHARS % CHARTSIZE;

    for (int chart = 0; chart < numofcharts; chart++) {
        int sizeofcurrentchart;
        if (chart != numofcharts-1) sizeofcurrentchart = CHARTSIZE;
        else sizeofcurrentchart = sizeoffinalchart;
        for (int i=modeoffrequencyofchars; i>0; i-- ) {
            printf("%d|", i);
            int buffer = CHARTSIZE*chart;
            for (int j = buffer; j < sizeofcurrentchart + buffer; j++) {
                if(frequencyofchars[j] >= i) {
                    printf(" # ");
                } else {
                    printf("   ");
                }
            }
            printf("\n");
        }
        
        for (int i = 0; i < 2; i++) {
            printf("  ");
            for (int j = 0; j < sizeofcurrentchart; j++) {
                if (i == 0) printf("---");
                else {
                    int index = (CHARTSIZE * chart) + j;
                    printf(" %c ", index + LOWCHAR);
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}