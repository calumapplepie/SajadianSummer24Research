/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzsteqr.c
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 21-May-2024 22:00:04
 */

/* Include Files */
#include "xzsteqr.h"
#include "xdlaev2.h"
#include "xzlartg.h"
#include "xzlascl.h"
#include <math.h>

/* Function Declarations */
static double rt_hypotd(double u0, double u1);

/* Function Definitions */
/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_hypotd(double u0, double u1)
{
  double a;
  double b;
  double y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = b * sqrt(a * a + 1.0);
  } else if (a > b) {
    b /= a;
    y = a * sqrt(b * b + 1.0);
  } else {
    y = a * 1.4142135623730951;
  }
  return y;
}

/*
 * Arguments    : double d[2]
 *                double e
 *                double z[4]
 * Return Type  : int
 */
int xzsteqr(double d[2], double e, double z[4])
{
  double work[2];
  double s;
  double temp;
  int i;
  int info;
  int jtot;
  int l1;
  info = 0;
  work[0] = 0.0;
  work[1] = 0.0;
  jtot = 0;
  l1 = 1;
  int exitg1;
  do {
    exitg1 = 0;
    if (l1 > 2) {
      if (d[1] < d[0]) {
        double p;
        p = d[1];
        d[1] = d[0];
        d[0] = p;
        temp = z[0];
        z[0] = z[2];
        z[2] = temp;
        temp = z[1];
        z[1] = z[3];
        z[3] = temp;
      }
      exitg1 = 1;
    } else {
      double tst;
      int l;
      int lend;
      int lsv;
      int m;
      boolean_T exitg2;
      if (l1 > 1) {
        e = 0.0;
      }
      m = l1;
      exitg2 = false;
      while ((!exitg2) && (m < 2)) {
        tst = fabs(e);
        if (tst == 0.0) {
          exitg2 = true;
        } else if (tst <= sqrt(fabs(d[0])) * sqrt(fabs(d[1])) *
                              2.2204460492503131E-16) {
          e = 0.0;
          exitg2 = true;
        } else {
          m = 2;
        }
      }
      l = l1;
      lsv = l1;
      lend = m;
      l1 = m + 1;
      if (m != l) {
        double anorm;
        int iscale;
        int n;
        int n_tmp;
        n_tmp = m - l;
        n = n_tmp - 1;
        if (n_tmp + 1 <= 0) {
          anorm = 0.0;
        } else {
          anorm = fabs(d[(l + n_tmp) - 1]);
          for (i = 0; i <= n; i++) {
            tst = fabs(d[l - 1]);
            if (tst > anorm) {
              anorm = tst;
            }
            tst = fabs(e);
            if (tst > anorm) {
              anorm = tst;
            }
          }
        }
        iscale = 0;
        if (anorm != 0.0) {
          if (anorm > 2.2346346549904327E+153) {
            iscale = 1;
            xzlascl(anorm, 2.2346346549904327E+153, n_tmp + 1, d, l);
            b_xzlascl(anorm, 2.2346346549904327E+153, n_tmp, &e);
          } else if (anorm < 3.02546243347603E-123) {
            iscale = 2;
            xzlascl(anorm, 3.02546243347603E-123, n_tmp + 1, d, l);
            b_xzlascl(anorm, 3.02546243347603E-123, n_tmp, &e);
          }
          if (fabs(d[m - 1]) < fabs(d[l - 1])) {
            lend = lsv;
            l = m;
          }
          if (lend > l) {
            int exitg4;
            do {
              exitg4 = 0;
              if (l != 2) {
                m = 1;
                tst = fabs(e);
                if (tst * tst >
                    4.9303806576313238E-32 * fabs(d[0]) * fabs(d[1]) +
                        2.2250738585072014E-308) {
                  m = 2;
                } else {
                  e = 0.0;
                }
              } else {
                m = 2;
              }
              if (m == l) {
                l++;
                if (l > 2) {
                  exitg4 = 1;
                }
              } else if (m == l + 1) {
                double c;
                d[0] = xdlaev2(d[0], e, d[1], &d[1], &work[0], &work[1]);
                tst = work[0];
                c = work[1];
                for (i = 0; i >= 0; i--) {
                  if ((work[0] != 1.0) || (work[1] != 0.0)) {
                    double b;
                    s = z[2];
                    temp = s;
                    b = z[0];
                    s = tst * s - c * b;
                    z[2] = s;
                    b = c * temp + tst * b;
                    z[0] = b;
                    s = z[3];
                    temp = s;
                    b = z[1];
                    s = tst * s - c * b;
                    z[3] = s;
                    b = c * temp + tst * b;
                    z[1] = b;
                  }
                }
                e = 0.0;
                exitg4 = 1;
              } else if (jtot == 60) {
                exitg4 = 1;
              } else {
                double b;
                double c;
                double g;
                double p;
                int b_i;
                jtot++;
                tst = d[l - 1];
                g = (d[1] - tst) / (2.0 * e);
                c = rt_hypotd(g, 1.0);
                if (g < 0.0) {
                  c = -c;
                }
                g = (d[m - 1] - tst) + e / (g + c);
                tst = 1.0;
                c = 1.0;
                p = 0.0;
                b_i = m - 1;
                for (i = b_i; i >= 1; i--) {
                  b = c * e;
                  c = xzlartg(g, tst * e, &s, &temp);
                  tst = s;
                  if (m - 1 != 1) {
                    /* Check node always fails. would cause program termination
                     * and was eliminated */
                  }
                  g = d[1] - p;
                  temp = (d[0] - g) * s + 2.0 * c * b;
                  p = s * temp;
                  d[1] = g + p;
                  g = c * temp - b;
                  work[0] = c;
                  work[1] = -s;
                }
                for (i = b_i; i >= 1; i--) {
                  if ((work[0] != 1.0) || (work[1] != 0.0)) {
                    s = z[2];
                    temp = s;
                    b = z[0];
                    s = work[0] * s - b * work[1];
                    z[2] = s;
                    b = work[1] * temp + work[0] * b;
                    z[0] = b;
                    s = z[3];
                    temp = s;
                    b = z[1];
                    s = work[0] * s - work[1] * b;
                    z[3] = s;
                    b = work[1] * temp + work[0] * b;
                    z[1] = b;
                  }
                }
                d[0] -= p;
                e = g;
              }
            } while (exitg4 == 0);
          } else {
            int exitg3;
            do {
              exitg3 = 0;
              if (l != lend) {
                m = l;
                exitg2 = false;
                while ((!exitg2) && (m > lend)) {
                  tst = fabs(e);
                  if (tst * tst <=
                      4.9303806576313238E-32 * fabs(d[1]) * fabs(d[0]) +
                          2.2250738585072014E-308) {
                    exitg2 = true;
                  } else {
                    m = 1;
                  }
                }
              } else {
                m = lend;
              }
              if (m > lend) {
                e = 0.0;
              }
              if (m == l) {
                l--;
                if (l < lend) {
                  exitg3 = 1;
                }
              } else if (m == l - 1) {
                double c;
                d[0] = xdlaev2(d[0], e, d[l - 1], &s, &work[0], &work[1]);
                d[l - 1] = s;
                n = ((l - 2) << 1) - 1;
                tst = work[0];
                c = work[1];
                for (i = 0; i < 1; i++) {
                  if ((work[0] != 1.0) || (work[1] != 0.0)) {
                    temp = z[n + 3];
                    z[n + 3] = tst * temp - c * z[n + 1];
                    z[n + 1] = c * temp + tst * z[n + 1];
                    temp = z[n + 4];
                    z[n + 4] = tst * temp - c * z[n + 2];
                    z[n + 2] = c * temp + tst * z[n + 2];
                  }
                }
                e = 0.0;
                exitg3 = 1;
              } else if (jtot == 60) {
                exitg3 = 1;
              } else {
                double c;
                double g;
                double p;
                int b_i;
                jtot++;
                tst = d[l - 1];
                g = (d[0] - tst) / (2.0 * e);
                c = rt_hypotd(g, 1.0);
                if (g < 0.0) {
                  c = -c;
                }
                g = (d[m - 1] - tst) + e / (g + c);
                tst = 1.0;
                c = 1.0;
                p = 0.0;
                b_i = l - 1;
                for (i = m; i <= b_i; i++) {
                  double b;
                  b = c * e;
                  c = xzlartg(g, tst * e, &s, &temp);
                  tst = s;
                  if (m != 1) {
                    /* Check node always fails. would cause program termination
                     * and was eliminated */
                  }
                  g = d[0] - p;
                  temp = (d[1] - g) * s + 2.0 * c * b;
                  p = s * temp;
                  d[0] = g + p;
                  g = c * temp - b;
                  work[0] = c;
                  work[1] = s;
                }
                n = ((m - 1) << 1) - 1;
                b_i = l - m;
                for (i = 0; i < b_i; i++) {
                  tst = work[m - 1];
                  if ((tst != 1.0) || (work[1] != 0.0)) {
                    temp = z[n + 3];
                    z[n + 3] = tst * temp - work[1] * z[n + 1];
                    z[n + 1] = work[1] * temp + tst * z[n + 1];
                    temp = z[n + 4];
                    z[n + 4] = tst * temp - work[1] * z[n + 2];
                    z[n + 2] = work[1] * temp + tst * z[n + 2];
                  }
                }
                d[l - 1] -= p;
                e = g;
              }
            } while (exitg3 == 0);
          }
          if (iscale == 1) {
            xzlascl(2.2346346549904327E+153, anorm, n_tmp + 1, d, lsv);
            b_xzlascl(2.2346346549904327E+153, anorm, n_tmp, &e);
          } else if (iscale == 2) {
            xzlascl(3.02546243347603E-123, anorm, n_tmp + 1, d, lsv);
            b_xzlascl(3.02546243347603E-123, anorm, n_tmp, &e);
          }
          if (jtot >= 60) {
            if (e != 0.0) {
              info = 1;
            }
            exitg1 = 1;
          }
        }
      }
    }
  } while (exitg1 == 0);
  return info;
}

/*
 * File trailer for xzsteqr.c
 *
 * [EOF]
 */
