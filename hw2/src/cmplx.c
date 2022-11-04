
#define _USE_MATH_DEFINES
#include <math.h>

typedef float cmplx_t[2];



void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c) {
   *c = (*a) * (*b) - (*(a + 1)) * (*(b + 1));
   *(c + 1) = (*a) * (*(b + 1)) + (*(a + 1)) * (*b);
}

void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c) {
   float div = (*b) * (*b) + (*(b + 1)) * (*(b + 1));
   *c = (1 / div) * ((*a) * (*b) + (*(a + 1)) * (*(b + 1)));
   *(c + 1) = (1 / div) * (-(*a) * (*(b + 1)) + (*(a + 1)) * (*b));
}

double cmplx_mag(cmplx_t a) { return sqrt(pow(*a, 2) + pow(*(a + 1), 2)); }

double cmplx_phs(cmplx_t a) { return atan((*(a + 1)) / (*a)); }

double cmplx_real(double mag, double phs) { return mag * cos(phs); }

double cmplx_imag(double mag, double phs) { return mag * sin(phs); }

void cmplx_dft(cmplx_t *input, cmplx_t *output, int N) {
   int k;
   int n;
   cmplx_t membk;
   for (k = 0; k < N; k++) {
      *membk = 0;
      *(membk + 1) = 0;
      cmplx_t e;
      cmplx_t rez;

      for (n = 0; n < N; n++) {

         e[0] = cos((k * n * 2 * M_PI) / N);
         e[1] = -sin((k * n * 2 * M_PI) / N);

         cmplx_mul(*(input + n), e, rez);

         *membk += rez[0];
         *(membk + 1) += rez[1];
      }

      output[k][0] = *membk;
      output[k][1] = *(membk + 1);
   }
}

void cmplx_idft(cmplx_t *input, cmplx_t *output, int N) {
   int k;
   int n;
   cmplx_t membk;
   for (k = 0; k < N; k++) {
      *membk = 0;
      *(membk + 1) = 0;
      cmplx_t e;
      cmplx_t rez;

      for (n = 0; n < N; n++) {

         e[0] = cos((k * n * 2 * M_PI) / N);
         e[1] = sin((k * n * 2 * M_PI) / N);

         cmplx_mul(*(input + n), e, rez);

         *membk += rez[0] / 10;
         *(membk + 1) += rez[1] / 10;
      }

      output[k][0] = *membk;
      output[k][1] = *(membk + 1);
   }
}

