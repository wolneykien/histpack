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

void printout ()
{
  int x, n;
  uint32_t res[16];

  memset (res, 16, sizeof (uint32_t));

  for (x = 0; x < 65536; x++)
  {
    for (n = 0; n < 16; n++)
    {
      if ((x & (0x0001 << n)) != 0)
      {
        res[n] += hist[n];
      }
    }
  }

  for (n = 0; n < 16; n++)
  {
    printf ("F%i = %u\n", n, res[n]);
  }
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
