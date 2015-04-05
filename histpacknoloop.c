#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define BUFSIZE 100000000

uint16_t vals[BUFSIZE];
uint16_t hist[65536];

void init ()
{
  long x;
  srandom (time (NULL) + getpid ());

  
  for (x = 0; x < BUFSIZE; x++)
  {
    vals[x] = random();
  }
}

void calc ()
{
  long x;
  memset (hist, 65536, sizeof (uint16_t));
  for (x = 0; x < BUFSIZE; x++)
  {
    hist[vals[x]]++;
  }
}

uint16_t fn0 (uint16_t *hist);
uint16_t fn1 (uint16_t *hist);
uint16_t fn2 (uint16_t *hist);
uint16_t fn3 (uint16_t *hist);
uint16_t fn4 (uint16_t *hist);
uint16_t fn5 (uint16_t *hist);
uint16_t fn6 (uint16_t *hist);
uint16_t fn7 (uint16_t *hist);
uint16_t fn8 (uint16_t *hist);
uint16_t fn9 (uint16_t *hist);
uint16_t fn10 (uint16_t *hist);
uint16_t fn11 (uint16_t *hist);
uint16_t fn12 (uint16_t *hist);
uint16_t fn13 (uint16_t *hist);
uint16_t fn14 (uint16_t *hist);
uint16_t fn15 (uint16_t *hist);

void printout ()
{
  printf ("F0 = %u\n", fn0(&hist[0]));
  printf ("F1 = %u\n", fn1(&hist[0]));
  printf ("F2 = %u\n", fn2(&hist[0]));
  printf ("F3 = %u\n", fn3(&hist[0]));
  printf ("F4 = %u\n", fn4(&hist[0]));
  printf ("F5 = %u\n", fn5(&hist[0]));
  printf ("F6 = %u\n", fn6(&hist[0]));
  printf ("F7 = %u\n", fn7(&hist[0]));
  printf ("F8 = %u\n", fn8(&hist[0]));
  printf ("F9 = %u\n", fn9(&hist[0]));
  printf ("F10 = %u\n", fn10(&hist[0]));
  printf ("F11 = %u\n", fn11(&hist[0]));
  printf ("F12 = %u\n", fn12(&hist[0]));
  printf ("F13 = %u\n", fn13(&hist[0]));
  printf ("F14 = %u\n", fn14(&hist[0]));
  printf ("F15 = %u\n", fn15(&hist[0]));
}

void main (int argc, char **argv)
{
  clock_t start;

  setbuf(stdout, NULL);

  printf ("Generate input values...");
  start = clock();  
  init();
  printf (" %.4fs\n", ((double) (clock() - start)) / CLOCKS_PER_SEC);

  printf ("Histogram calculation...");
  start = clock();
  calc();
  printf (" %.4fs\n", ((double) (clock() - start)) / CLOCKS_PER_SEC);

  printf ("Pack it and print the result:\n");
  start = clock();
  printout();
  printf ("    %.4fs\n", ((double) (clock() - start)) / CLOCKS_PER_SEC);
}
