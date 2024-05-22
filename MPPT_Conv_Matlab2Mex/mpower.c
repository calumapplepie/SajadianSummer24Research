/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: mpower.c
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 21-May-2024 22:00:04
 */

/* Include Files */
#include "mpower.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const double a[4]
 *                double b
 *                double c[4]
 * Return Type  : void
 */
void mpower(const double a[4], double b, double c[4])
{
  double e;
  int b_n;
  int nbitson;
  e = fabs(b);
  if (e <= 2.147483647E+9) {
    double b_a[4];
    int n;
    int nb;
    b_a[0] = a[0];
    b_a[1] = a[1];
    b_a[2] = a[2];
    b_a[3] = a[3];
    n = (int)e;
    b_n = (int)e;
    nbitson = 0;
    nb = -2;
    while (b_n > 0) {
      nb++;
      if ((b_n & 1) != 0) {
        nbitson++;
      }
      b_n >>= 1;
    }
    if ((int)e <= 2) {
      if (b == 2.0) {
        for (b_n = 0; b_n < 2; b_n++) {
          double d;
          d = a[b_n + 2];
          c[b_n] = a[b_n] * a[0] + d * a[1];
          c[b_n + 2] = a[b_n] * a[2] + d * a[3];
        }
      } else {
        c[1] = 0.0;
        c[2] = 0.0;
        c[0] = 1.0;
        c[3] = 1.0;
      }
    } else {
      double aBuffer[4];
      double cBuffer[4];
      double d;
      double d1;
      double d2;
      double d3;
      double d4;
      boolean_T aBufferInUse;
      boolean_T cBufferInUse;
      boolean_T firstmult;
      firstmult = true;
      aBufferInUse = false;
      cBufferInUse = ((nbitson & 1) == 0);
      for (nbitson = 0; nbitson <= nb; nbitson++) {
        if ((n & 1) != 0) {
          if (firstmult) {
            firstmult = false;
            if (cBufferInUse) {
              if (aBufferInUse) {
                cBuffer[0] = aBuffer[0];
                cBuffer[1] = aBuffer[1];
                cBuffer[2] = aBuffer[2];
                cBuffer[3] = aBuffer[3];
              } else {
                cBuffer[0] = b_a[0];
                cBuffer[1] = b_a[1];
                cBuffer[2] = b_a[2];
                cBuffer[3] = b_a[3];
              }
            } else if (aBufferInUse) {
              c[0] = aBuffer[0];
              c[1] = aBuffer[1];
              c[2] = aBuffer[2];
              c[3] = aBuffer[3];
            } else {
              c[0] = b_a[0];
              c[1] = b_a[1];
              c[2] = b_a[2];
              c[3] = b_a[3];
            }
          } else {
            if (aBufferInUse) {
              if (cBufferInUse) {
                d = aBuffer[0];
                e = aBuffer[1];
                d1 = aBuffer[2];
                d2 = aBuffer[3];
                for (b_n = 0; b_n < 2; b_n++) {
                  d3 = cBuffer[b_n + 2];
                  d4 = cBuffer[b_n];
                  c[b_n] = d4 * d + d3 * e;
                  c[b_n + 2] = d4 * d1 + d3 * d2;
                }
              } else {
                d = aBuffer[0];
                e = aBuffer[1];
                d1 = aBuffer[2];
                d2 = aBuffer[3];
                for (b_n = 0; b_n < 2; b_n++) {
                  d3 = c[b_n + 2];
                  d4 = c[b_n];
                  cBuffer[b_n] = d4 * d + d3 * e;
                  cBuffer[b_n + 2] = d4 * d1 + d3 * d2;
                }
              }
            } else if (cBufferInUse) {
              d = b_a[0];
              e = b_a[1];
              d1 = b_a[2];
              d2 = b_a[3];
              for (b_n = 0; b_n < 2; b_n++) {
                d3 = cBuffer[b_n + 2];
                d4 = cBuffer[b_n];
                c[b_n] = d4 * d + d3 * e;
                c[b_n + 2] = d4 * d1 + d3 * d2;
              }
            } else {
              d = b_a[0];
              e = b_a[1];
              d1 = b_a[2];
              d2 = b_a[3];
              for (b_n = 0; b_n < 2; b_n++) {
                d3 = c[b_n + 2];
                d4 = c[b_n];
                cBuffer[b_n] = d4 * d + d3 * e;
                cBuffer[b_n + 2] = d4 * d1 + d3 * d2;
              }
            }
            cBufferInUse = !cBufferInUse;
          }
        }
        n >>= 1;
        if (aBufferInUse) {
          for (b_n = 0; b_n < 2; b_n++) {
            d = aBuffer[b_n + 2];
            b_a[b_n] = aBuffer[b_n] * aBuffer[0] + d * aBuffer[1];
            b_a[b_n + 2] = aBuffer[b_n] * aBuffer[2] + d * aBuffer[3];
          }
        } else {
          for (b_n = 0; b_n < 2; b_n++) {
            d = b_a[b_n + 2];
            aBuffer[b_n] = b_a[b_n] * b_a[0] + d * b_a[1];
            aBuffer[b_n + 2] = b_a[b_n] * b_a[2] + d * b_a[3];
          }
        }
        aBufferInUse = !aBufferInUse;
      }
      if (firstmult) {
        if (aBufferInUse) {
          c[0] = aBuffer[0];
          c[1] = aBuffer[1];
          c[2] = aBuffer[2];
          c[3] = aBuffer[3];
        } else {
          c[0] = b_a[0];
          c[1] = b_a[1];
          c[2] = b_a[2];
          c[3] = b_a[3];
        }
      } else if (aBufferInUse) {
        d = aBuffer[0];
        e = aBuffer[1];
        d1 = aBuffer[2];
        d2 = aBuffer[3];
        for (b_n = 0; b_n < 2; b_n++) {
          d3 = cBuffer[b_n + 2];
          d4 = cBuffer[b_n];
          c[b_n] = d4 * d + d3 * e;
          c[b_n + 2] = d4 * d1 + d3 * d2;
        }
      } else {
        d = b_a[0];
        e = b_a[1];
        d1 = b_a[2];
        d2 = b_a[3];
        for (b_n = 0; b_n < 2; b_n++) {
          d3 = cBuffer[b_n + 2];
          d4 = cBuffer[b_n];
          c[b_n] = d4 * d + d3 * e;
          c[b_n + 2] = d4 * d1 + d3 * d2;
        }
      }
    }
  } else {
    double b_a[4];
    boolean_T firstmult;
    b_a[0] = a[0];
    b_a[1] = a[1];
    b_a[2] = a[2];
    b_a[3] = a[3];
    firstmult = true;
    double ed2;
    int exitg1;
    do {
      double cBuffer[4];
      double d;
      exitg1 = 0;
      ed2 = floor(e / 2.0);
      if (2.0 * ed2 != e) {
        if (firstmult) {
          c[0] = b_a[0];
          c[1] = b_a[1];
          c[2] = b_a[2];
          c[3] = b_a[3];
          firstmult = false;
        } else {
          double d1;
          double d2;
          d = b_a[0];
          e = b_a[1];
          d1 = b_a[2];
          d2 = b_a[3];
          for (b_n = 0; b_n < 2; b_n++) {
            double d3;
            double d4;
            d3 = c[b_n + 2];
            d4 = c[b_n];
            cBuffer[b_n] = d4 * d + d3 * e;
            cBuffer[b_n + 2] = d4 * d1 + d3 * d2;
          }
          c[0] = cBuffer[0];
          c[1] = cBuffer[1];
          c[2] = cBuffer[2];
          c[3] = cBuffer[3];
        }
      }
      if (ed2 == 0.0) {
        exitg1 = 1;
      } else {
        e = ed2;
        for (b_n = 0; b_n < 2; b_n++) {
          d = b_a[b_n + 2];
          cBuffer[b_n] = b_a[b_n] * b_a[0] + d * b_a[1];
          cBuffer[b_n + 2] = b_a[b_n] * b_a[2] + d * b_a[3];
        }
        b_a[0] = cBuffer[0];
        b_a[1] = cBuffer[1];
        b_a[2] = cBuffer[2];
        b_a[3] = cBuffer[3];
      }
    } while (exitg1 == 0);
  }
}

/*
 * File trailer for mpower.c
 *
 * [EOF]
 */
