#include <stdio.h>

// Solution to Exercise 1-13

#define IN     1
#define OUT    0
#define MAXLEN 20

int main(void)
{
  int c, state, prevstate, lword, countforoutofboundswords, longestword, modeoflengthofwords;
  prevstate = OUT;
  lword = countforoutofboundswords = modeoflengthofwords = 0;
  int lengthofwords[MAXLEN];

  for (int i = 0; i<MAXLEN; i++) lengthofwords[i] = 0;

  while ((c = getchar()) != EOF) {

    if (c == '\t' || c == '\n' || c == ' ') {
      state = OUT;
    }
    else {
      state = IN;
    }

    if (state == IN) {
      ++lword;
    } else if (prevstate == IN) {
      if (lword > MAXLEN) {
        ++countforoutofboundswords;
      } else {
        ++lengthofwords[lword-1];
      }
      lword = 0;
    }

    prevstate = state;
  }
  if (prevstate == IN) {
    if (lword > MAXLEN) {
      ++countforoutofboundswords;
    } else {
     ++lengthofwords[lword-1];
    }
  }



  for (int i = 0; i < MAXLEN; i++) {
    if (lengthofwords[i] > modeoflengthofwords) {
      modeoflengthofwords = lengthofwords[i];
    }
  }
  if (countforoutofboundswords > modeoflengthofwords) {
    modeoflengthofwords = countforoutofboundswords;
  }




  for (int i = modeoflengthofwords; i > 0; i--) {
    printf("%d|", i);
    for (int j = 0; j < MAXLEN; j++) {

      if (lengthofwords[j] >= i)
        printf("    #");
      else
        printf("     ");
    }
    if (countforoutofboundswords >= i)
      printf("    #");
    else
      printf("     ");
    printf("\n");
  }

  for (int i = 0; i < 2; i++) {
    if (i==0) printf("  ");
    else printf("  ");
    for (int j = 1; j < MAXLEN + 1; j++) {
      if (i == 0) {
        printf("-----");
        if (j == MAXLEN) {
          printf("-----");
          printf("\n");
        }
      }
      else if (i == 1) {
        printf("%5d", j);
        if (j == MAXLEN) {
          printf("  21+");
        }
      }
    }
  }
  printf("\n");
  printf("                                            word length\n");
}
