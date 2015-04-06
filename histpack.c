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
    ++hist[vals[x]];
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
  struct timespec start, end;

  setbuf (stdout, NULL);

  printf ("Generate input values...");
  clock_gettime (CLOCK_MONOTONIC, &start);
  init();
  clock_gettime (CLOCK_MONOTONIC, &end);
  printf (" %.5fs\n", ((double) end.tv_sec + (double) end.tv_nsec / 1000000000) - ((double) start.tv_sec + (double) start.tv_nsec / 1000000000));

  printf ("Histogram calculation...");
  clock_gettime (CLOCK_MONOTONIC, &start);
  calc();
  clock_gettime (CLOCK_MONOTONIC, &end);
  printf (" %.5fs\n", ((double) end.tv_sec + (double) end.tv_nsec / 1000000000) - ((double) start.tv_sec + (double) start.tv_nsec / 1000000000));

  printf ("Pack it and print the result:\n");
  clock_gettime (CLOCK_MONOTONIC, &start);
  printout();
  clock_gettime (CLOCK_MONOTONIC, &end);
  printf (" %.5fs\n", ((double) end.tv_sec + (double) end.tv_nsec / 1000000000) - ((double) start.tv_sec + (double) start.tv_nsec / 1000000000));
}
