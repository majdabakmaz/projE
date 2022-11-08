
#include "cmplx.h"
#include "io.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>

#define PI 3.14159265


int main(void) {
    int fd = open("dft.bin",O_RDWR |O_CREAT, 0644 );
   
   fd = open("dft.bin",O_RDWR |O_CREAT, 0644 );
   cmplx_t in2[200];
   cmplx_t out2[200];
   int vrijednost_ieee;

   for(int j=0; j<200; j++){
      vrijednost_ieee = read_word(fd);
      void *a = (void *) &vrijednost_ieee;
      float vrijednostRe = *((float *) a);
      in2[j][0]=vrijednostRe;

      vrijednost_ieee = read_word(fd);
      void *b = (void *) &vrijednost_ieee;
      float vrijednostIm = *((float *) b);
      in2[j][1]=vrijednostIm;
   }

   cmplx_idft(in2, out2, 200);

   for(int k = 0; k<200; k++){
      printf("out2[%d] = %f + %fi\n ", k, out2[k][0], out2[k][1]);
   }

}


