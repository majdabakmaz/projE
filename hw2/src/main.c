
#include "cmplx.h"
#include "io.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>




int main(void) {

   
    cmplx_t a;
    cmplx_t b;
    cmplx_t c;
   a[0] = 1;
   a[1] = 2;
   b[0] = 1;
   b[1] = 3;
   printf("%f, %fi\n", a[0], a[1]);
   printf("%f, %fi\n", b[0], b[1]);
   cmplx_div(a, b, c);
   printf("%f, %fi\n", c[0], c[1]);
   printf("length of a: %f\n", cmplx_mag(a));
   printf("phase of a: %f\n", cmplx_phs(a));
   printf("a= %f + %fi\n", cmplx_real(cmplx_mag(a), cmplx_phs(a)),
          cmplx_imag(cmplx_mag(a), cmplx_phs(a)));

   cmplx_t inp[10];

   for (int i = 0; i < 10; i++) {
      inp[i][0] = 1 * i;
      inp[i][1] = 2 * i;
   }

   for (int i = 0; i < 10; i++) {
      printf("inp[%d]= %f + %fi\n", i, **(inp + i), *(*(inp + i) + 1));
   }
   printf("\n");

   cmplx_t out[10];
   cmplx_dft(inp, out, 10);
   for (int i = 0; i < 10; i++) {
      printf("out[%d]= %f + %fi\n", i, **(out + i), *(*(out + i) + 1));
   }
   cmplx_t out2[10];
   cmplx_idft(out, out2, 10);
   printf("\n");
   for (int i = 0; i < 10; i++) {
      printf("out2[%d]= %f + %fi\n", i, **(out2 + i), *(*(out2 + i) + 1));
   }
   //////////////////
   int file;

   file = open("rnd.bin",  O_RDWR | O_APPEND);

    
    short int cc = 4;
    write_half(file, cc);

    short int d = read_half(file);
    printf("%hd\n", d);

    close(file);



   return 0;
}
