/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzlartg.c
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 21-May-2024 22:00:04
 */

/* Include Files */
#include "xzlartg.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double f
 *                double g
 *                double *sn
 *                double *r
 * Return Type  : double
 */
double xzlartg(double f, double g, double *sn, double *r)
{
  double cs;
  double f1;
  f1 = fabs(f);
  *r = fabs(g);
  if (g == 0.0) {
    cs = 1.0;
    *sn = 0.0;
    *r = f;
  } else if (f == 0.0) {
    cs = 0.0;
    if (g >= 0.0) {
      *sn = 1.0;
    } else {
      *sn = -1.0;
    }
  } else if ((f1 > 1.4916681462400413E-154) && (f1 < 4.7403759540545887E+153) &&
             (*r > 1.4916681462400413E-154) && (*r < 4.7403759540545887E+153)) {
    *r = sqrt(f * f + g * g);
    cs = f1 / *r;
    if (f < 0.0) {
      *r = -*r;
    }
    *sn = g / *r;
  } else {
    double gs;
    double u;
    u = fmin(4.49423283715579E+307,
             fmax(2.2250738585072014E-308, fmax(f1, *r)));
    f1 = f / u;
    gs = g / u;
    *r = sqrt(f1 * f1 + gs * gs);
    cs = fabs(f1) / *r;
    if (f < 0.0) {
      *r = -*r;
    }
    *sn = gs / *r;
    *r *= u;
  }
  return cs;
}

/*
 * File trailer for xzlartg.c
 *
 * [EOF]
 */
