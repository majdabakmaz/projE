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

   float t;
   cmplx_t in1[200];
   int i;
   for(t=0; t<1; t+=0.005){
      i=(int)(t/0.005);
      in1[i][0]=sin(2*PI*50*t);
      in1[i][1]=0;
   }

   for(int k = 0; k<200; k++){
      printf("in1[%d] = %f + %fi\n ", k, in1[k][0], in1[k][1]);
   }


   cmplx_t out[200];
   cmplx_dft(in1, out, 200);

   int fd = open("dft.bin",O_RDWR |O_CREAT, 0644 );

   for(int j=0; j<200; j++){
      void *a = (void *) &out[j][0];
      int vrijednost_ieee = *((int *) a);
      write_word(fd,vrijednost_ieee);

      void *b = (void *) &out[j][1];
      vrijednost_ieee = *((int *) b);
      write_word(fd,vrijednost_ieee);
      
   }

   close(fd);
}