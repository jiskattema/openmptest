#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int slow_function_with_mp() {
  double stuff[1000];
  long i;

#pragma omp parallel for private(i) shared(stuff)
  for (i=0; i<9999999; i++) {
    stuff[i % 1000] = sin(i*i);
  }
}

void main(int argc, char **argv) {
  double start, end;

  int i;
  for (i=0; i<100; i++) {
    omp_set_num_threads(i % 10);
    start = omp_get_wtime();
    slow_function_with_mp();
    end = omp_get_wtime();
    printf( "Threads: %03i Duration: %lf\n", i % 10, (end - start) * 0.01);
  }

  exit(EXIT_SUCCESS);
}
