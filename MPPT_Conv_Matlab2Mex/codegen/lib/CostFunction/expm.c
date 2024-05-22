/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: expm.c
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 21-May-2024 21:38:08
 */

/* Include Files */
#include "expm.h"
#include "log2.h"
#include "mpower.h"
#include "rt_nonfinite.h"
#include "xzsteqr.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static int getExpmParams(const double A[4], double A2[4], double A4[4],
                         double A6[4], double *s);

static void recomputeBlockDiag(const double A[4], double F[4], int blockFormat);

static double rt_powd_snf(double u0, double u1);

/* Function Definitions */
/*
 * Arguments    : const double A[4]
 *                double A2[4]
 *                double A4[4]
 *                double A6[4]
 *                double *s
 * Return Type  : int
 */
static int getExpmParams(const double A[4], double A2[4], double A4[4],
                         double A6[4], double *s)
{
  double c_y[4];
  double dv[4];
  double b_s;
  double b_y;
  double d;
  double d6;
  double d8;
  double eta1;
  double eta3;
  double y;
  int eint;
  int j;
  int m;
  int s_tmp;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T guard3;
  boolean_T guard4;
  *s = 0.0;
  for (j = 0; j < 2; j++) {
    d = A[j + 2];
    A2[j] = A[j] * A[0] + d * A[1];
    A2[j + 2] = A[j] * A[2] + d * A[3];
  }
  for (j = 0; j < 2; j++) {
    d = A2[j + 2];
    b_y = A2[j] * A2[0] + d * A2[1];
    A4[j] = b_y;
    d = A2[j] * A2[2] + d * A2[3];
    A4[j + 2] = d;
    A6[j] = b_y * A2[0] + d * A2[1];
    A6[j + 2] = b_y * A2[2] + d * A2[3];
  }
  y = 0.0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 2)) {
    s_tmp = j << 1;
    b_s = fabs(A6[s_tmp]) + fabs(A6[s_tmp + 1]);
    if (rtIsNaN(b_s)) {
      y = rtNaN;
      exitg1 = true;
    } else {
      if (b_s > y) {
        y = b_s;
      }
      j++;
    }
  }
  d6 = rt_powd_snf(y, 0.16666666666666666);
  y = 0.0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 2)) {
    s_tmp = j << 1;
    b_s = fabs(A4[s_tmp]) + fabs(A4[s_tmp + 1]);
    if (rtIsNaN(b_s)) {
      y = rtNaN;
      exitg1 = true;
    } else {
      if (b_s > y) {
        y = b_s;
      }
      j++;
    }
  }
  eta1 = fmax(rt_powd_snf(y, 0.25), d6);
  guard1 = false;
  guard2 = false;
  guard3 = false;
  guard4 = false;
  if (eta1 <= 0.01495585217958292) {
    dv[0] = 0.19285012468241128 * fabs(A[0]);
    dv[1] = 0.19285012468241128 * fabs(A[1]);
    dv[2] = 0.19285012468241128 * fabs(A[2]);
    dv[3] = 0.19285012468241128 * fabs(A[3]);
    mpower(dv, 7.0, c_y);
    y = 0.0;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j < 2)) {
      s_tmp = j << 1;
      b_s = fabs(c_y[s_tmp]) + fabs(c_y[s_tmp + 1]);
      if (rtIsNaN(b_s)) {
        y = rtNaN;
        exitg1 = true;
      } else {
        if (b_s > y) {
          y = b_s;
        }
        j++;
      }
    }
    b_y = 0.0;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j < 2)) {
      s_tmp = j << 1;
      b_s = fabs(A[s_tmp]) + fabs(A[s_tmp + 1]);
      if (rtIsNaN(b_s)) {
        b_y = rtNaN;
        exitg1 = true;
      } else {
        if (b_s > b_y) {
          b_y = b_s;
        }
        j++;
      }
    }
    if (fmax(ceil(b_log2(2.0 * (y / b_y) / 2.2204460492503131E-16) / 6.0),
             0.0) == 0.0) {
      m = 3;
    } else {
      guard4 = true;
    }
  } else {
    guard4 = true;
  }
  if (guard4) {
    if (eta1 <= 0.253939833006323) {
      dv[0] = 0.12321872304378752 * fabs(A[0]);
      dv[1] = 0.12321872304378752 * fabs(A[1]);
      dv[2] = 0.12321872304378752 * fabs(A[2]);
      dv[3] = 0.12321872304378752 * fabs(A[3]);
      mpower(dv, 11.0, c_y);
      y = 0.0;
      j = 0;
      exitg1 = false;
      while ((!exitg1) && (j < 2)) {
        s_tmp = j << 1;
        b_s = fabs(c_y[s_tmp]) + fabs(c_y[s_tmp + 1]);
        if (rtIsNaN(b_s)) {
          y = rtNaN;
          exitg1 = true;
        } else {
          if (b_s > y) {
            y = b_s;
          }
          j++;
        }
      }
      b_y = 0.0;
      j = 0;
      exitg1 = false;
      while ((!exitg1) && (j < 2)) {
        s_tmp = j << 1;
        b_s = fabs(A[s_tmp]) + fabs(A[s_tmp + 1]);
        if (rtIsNaN(b_s)) {
          b_y = rtNaN;
          exitg1 = true;
        } else {
          if (b_s > b_y) {
            b_y = b_s;
          }
          j++;
        }
      }
      if (fmax(ceil(b_log2(2.0 * (y / b_y) / 2.2204460492503131E-16) / 10.0),
               0.0) == 0.0) {
        m = 5;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }
  }
  if (guard3) {
    mpower(A4, 2.0, c_y);
    y = 0.0;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j < 2)) {
      s_tmp = j << 1;
      b_s = fabs(c_y[s_tmp]) + fabs(c_y[s_tmp + 1]);
      if (rtIsNaN(b_s)) {
        y = rtNaN;
        exitg1 = true;
      } else {
        if (b_s > y) {
          y = b_s;
        }
        j++;
      }
    }
    d8 = rt_powd_snf(y, 0.125);
    eta3 = fmax(d6, d8);
    if (eta3 <= 0.95041789961629319) {
      dv[0] = 0.090475336558796943 * fabs(A[0]);
      dv[1] = 0.090475336558796943 * fabs(A[1]);
      dv[2] = 0.090475336558796943 * fabs(A[2]);
      dv[3] = 0.090475336558796943 * fabs(A[3]);
      mpower(dv, 15.0, c_y);
      y = 0.0;
      j = 0;
      exitg1 = false;
      while ((!exitg1) && (j < 2)) {
        s_tmp = j << 1;
        b_s = fabs(c_y[s_tmp]) + fabs(c_y[s_tmp + 1]);
        if (rtIsNaN(b_s)) {
          y = rtNaN;
          exitg1 = true;
        } else {
          if (b_s > y) {
            y = b_s;
          }
          j++;
        }
      }
      b_y = 0.0;
      j = 0;
      exitg1 = false;
      while ((!exitg1) && (j < 2)) {
        s_tmp = j << 1;
        b_s = fabs(A[s_tmp]) + fabs(A[s_tmp + 1]);
        if (rtIsNaN(b_s)) {
          b_y = rtNaN;
          exitg1 = true;
        } else {
          if (b_s > b_y) {
            b_y = b_s;
          }
          j++;
        }
      }
      if (fmax(ceil(b_log2(2.0 * (y / b_y) / 2.2204460492503131E-16) / 14.0),
               0.0) == 0.0) {
        m = 7;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }
  }
  if (guard2) {
    if (eta3 <= 2.097847961257068) {
      dv[0] = 0.071467735648795785 * fabs(A[0]);
      dv[1] = 0.071467735648795785 * fabs(A[1]);
      dv[2] = 0.071467735648795785 * fabs(A[2]);
      dv[3] = 0.071467735648795785 * fabs(A[3]);
      mpower(dv, 19.0, c_y);
      y = 0.0;
      j = 0;
      exitg1 = false;
      while ((!exitg1) && (j < 2)) {
        s_tmp = j << 1;
        b_s = fabs(c_y[s_tmp]) + fabs(c_y[s_tmp + 1]);
        if (rtIsNaN(b_s)) {
          y = rtNaN;
          exitg1 = true;
        } else {
          if (b_s > y) {
            y = b_s;
          }
          j++;
        }
      }
      b_y = 0.0;
      j = 0;
      exitg1 = false;
      while ((!exitg1) && (j < 2)) {
        s_tmp = j << 1;
        b_s = fabs(A[s_tmp]) + fabs(A[s_tmp + 1]);
        if (rtIsNaN(b_s)) {
          b_y = rtNaN;
          exitg1 = true;
        } else {
          if (b_s > b_y) {
            b_y = b_s;
          }
          j++;
        }
      }
      if (fmax(ceil(b_log2(2.0 * (y / b_y) / 2.2204460492503131E-16) / 18.0),
               0.0) == 0.0) {
        m = 9;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
  }
  if (guard1) {
    double T[4];
    d = A6[0];
    b_y = A6[1];
    eta1 = A6[2];
    d6 = A6[3];
    for (j = 0; j < 2; j++) {
      y = A4[j + 2];
      b_s = A4[j];
      c_y[j] = b_s * d + y * b_y;
      c_y[j + 2] = b_s * eta1 + y * d6;
    }
    y = 0.0;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j < 2)) {
      s_tmp = j << 1;
      b_s = fabs(c_y[s_tmp]) + fabs(c_y[s_tmp + 1]);
      if (rtIsNaN(b_s)) {
        y = rtNaN;
        exitg1 = true;
      } else {
        if (b_s > y) {
          y = b_s;
        }
        j++;
      }
    }
    *s = fmax(ceil(b_log2(fmin(eta3, fmax(d8, rt_powd_snf(y, 0.1))) /
                          5.3719203511481517)),
              0.0);
    eta1 = rt_powd_snf(2.0, *s);
    d = A[0] / eta1;
    T[0] = d;
    dv[0] = 0.05031554467093536 * fabs(d);
    d = A[1] / eta1;
    T[1] = d;
    dv[1] = 0.05031554467093536 * fabs(d);
    d = A[2] / eta1;
    T[2] = d;
    dv[2] = 0.05031554467093536 * fabs(d);
    d = A[3] / eta1;
    T[3] = d;
    dv[3] = 0.05031554467093536 * fabs(d);
    mpower(dv, 27.0, c_y);
    y = 0.0;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j < 2)) {
      s_tmp = j << 1;
      b_s = fabs(c_y[s_tmp]) + fabs(c_y[s_tmp + 1]);
      if (rtIsNaN(b_s)) {
        y = rtNaN;
        exitg1 = true;
      } else {
        if (b_s > y) {
          y = b_s;
        }
        j++;
      }
    }
    b_y = 0.0;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j < 2)) {
      s_tmp = j << 1;
      b_s = fabs(T[s_tmp]) + fabs(T[s_tmp + 1]);
      if (rtIsNaN(b_s)) {
        b_y = rtNaN;
        exitg1 = true;
      } else {
        if (b_s > b_y) {
          b_y = b_s;
        }
        j++;
      }
    }
    *s += fmax(ceil(b_log2(2.0 * (y / b_y) / 2.2204460492503131E-16) / 26.0),
               0.0);
    if (rtIsInf(*s)) {
      y = 0.0;
      j = 0;
      exitg1 = false;
      while ((!exitg1) && (j < 2)) {
        s_tmp = j << 1;
        b_s = fabs(A[s_tmp]) + fabs(A[s_tmp + 1]);
        if (rtIsNaN(b_s)) {
          y = rtNaN;
          exitg1 = true;
        } else {
          if (b_s > y) {
            y = b_s;
          }
          j++;
        }
      }
      eta1 = y / 5.3719203511481517;
      if ((!rtIsInf(eta1)) && (!rtIsNaN(eta1))) {
        eta1 = frexp(eta1, &eint);
      } else {
        eint = 0;
      }
      *s = eint;
      if (eta1 == 0.5) {
        *s = (double)eint - 1.0;
      }
    }
    m = 13;
  }
  return m;
}

/*
 * Arguments    : const double A[4]
 *                double F[4]
 *                int blockFormat
 * Return Type  : void
 */
static void recomputeBlockDiag(const double A[4], double F[4], int blockFormat)
{
  if (blockFormat == 1) {
    double avg;
    double expa;
    double sinchdelta;
    expa = exp(A[0]);
    sinchdelta = exp(A[3]);
    avg = (A[0] + A[3]) / 2.0;
    if (fmax(avg, fabs(A[0] - A[3]) / 2.0) < 709.782712893384) {
      double delta;
      delta = (A[3] - A[0]) / 2.0;
      if (delta == 0.0) {
        delta = 1.0;
      } else {
        delta = sinh(delta) / delta;
      }
      F[2] = A[2] * exp(avg) * delta;
    } else {
      F[2] = A[2] * (sinchdelta - expa) / (A[3] - A[0]);
    }
    F[0] = expa;
    F[3] = sinchdelta;
  } else {
    double delta;
    double expa;
    double sinchdelta;
    delta = sqrt(fabs(A[1] * A[2]));
    expa = exp(A[0]);
    if (delta == 0.0) {
      sinchdelta = 1.0;
    } else {
      sinchdelta = sin(delta) / delta;
    }
    F[0] = expa * cos(delta);
    F[1] = expa * A[1] * sinchdelta;
    F[2] = expa * A[2] * sinchdelta;
    F[3] = F[0];
  }
}

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_powd_snf(double u0, double u1)
{
  double y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    double d;
    double d1;
    d = fabs(u0);
    d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }
  return y;
}

/*
 * Arguments    : double A[4]
 *                double F[4]
 * Return Type  : void
 */
void expm(double A[4], double F[4])
{
  double mul;
  double s;
  int i;
  int r1;
  int r2;
  boolean_T recomputeDiags;
  recomputeDiags = true;
  for (r1 = 0; r1 < 4; r1++) {
    if (recomputeDiags) {
      mul = A[r1];
      if (rtIsInf(mul) || rtIsNaN(mul)) {
        recomputeDiags = false;
      }
    } else {
      recomputeDiags = false;
    }
  }
  if (!recomputeDiags) {
    F[0] = rtNaN;
    F[1] = rtNaN;
    F[2] = rtNaN;
    F[3] = rtNaN;
  } else {
    int exitg1;
    boolean_T exitg2;
    recomputeDiags = true;
    r1 = 0;
    exitg2 = false;
    while ((!exitg2) && (r1 < 2)) {
      r2 = 0;
      do {
        exitg1 = 0;
        if (r2 < 2) {
          if ((r2 != r1) && (!(A[r2 + (r1 << 1)] == 0.0))) {
            recomputeDiags = false;
            exitg1 = 1;
          } else {
            r2++;
          }
        } else {
          r1++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);
      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
    if (recomputeDiags) {
      F[1] = 0.0;
      F[2] = 0.0;
      F[0] = exp(A[0]);
      F[3] = exp(A[3]);
    } else {
      recomputeDiags = true;
      r1 = 0;
      exitg2 = false;
      while ((!exitg2) && (r1 < 2)) {
        r2 = 0;
        do {
          exitg1 = 0;
          if (r2 <= r1) {
            if (!(A[r2 + (r1 << 1)] == A[r1 + (r2 << 1)])) {
              recomputeDiags = false;
              exitg1 = 1;
            } else {
              r2++;
            }
          } else {
            r1++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);
        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
      if (recomputeDiags) {
        double A2[4];
        double b_A6[4];
        double W[2];
        double a22;
        double anrm;
        double cfrom1;
        double cfromc;
        double d;
        A2[0] = A[0];
        A2[1] = A[1];
        A2[2] = A[2];
        A2[3] = A[3];
        anrm = 0.0;
        r1 = 0;
        exitg2 = false;
        while ((!exitg2) && (r1 < 2)) {
          r2 = 0;
          do {
            exitg1 = 0;
            if (r2 <= r1) {
              d = fabs(A[r2 + (r1 << 1)]);
              if (rtIsNaN(d)) {
                anrm = rtNaN;
                exitg1 = 1;
              } else {
                if (d > anrm) {
                  anrm = d;
                }
                r2++;
              }
            } else {
              r1++;
              exitg1 = 2;
            }
          } while (exitg1 == 0);
          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
        if (rtIsInf(anrm) || rtIsNaN(anrm)) {
          W[0] = rtNaN;
          W[1] = rtNaN;
          A2[0] = rtNaN;
          A2[1] = rtNaN;
          A2[2] = rtNaN;
          A2[3] = rtNaN;
        } else {
          boolean_T guard1;
          recomputeDiags = false;
          guard1 = false;
          if ((anrm > 0.0) && (anrm < 1.0010415475915505E-146)) {
            recomputeDiags = true;
            anrm = 1.0010415475915505E-146 / anrm;
            guard1 = true;
          } else if (anrm > 9.9895953610111751E+145) {
            recomputeDiags = true;
            anrm = 9.9895953610111751E+145 / anrm;
            guard1 = true;
          }
          if (guard1) {
            boolean_T notdone;
            d = anrm;
            cfromc = 1.0;
            notdone = true;
            while (notdone) {
              cfrom1 = cfromc * 2.0041683600089728E-292;
              a22 = d / 4.9896007738368E+291;
              if ((fabs(cfrom1) > d) && (d != 0.0)) {
                mul = 2.0041683600089728E-292;
                cfromc = cfrom1;
              } else if (a22 > fabs(cfromc)) {
                mul = 4.9896007738368E+291;
                d = a22;
              } else {
                mul = d / cfromc;
                notdone = false;
              }
              A2[0] *= mul;
              A2[1] *= mul;
              A2[2] *= mul;
              A2[3] *= mul;
            }
          }
          d = A2[1];
          W[0] = A2[0];
          W[1] = A2[3];
          A2[2] = 0.0;
          A2[0] = 1.0;
          A2[1] = 0.0;
          A2[3] = 1.0;
          r1 = xzsteqr(W, d, A2);
          if (r1 != 0) {
            W[0] = rtNaN;
            W[1] = rtNaN;
            A2[0] = rtNaN;
            A2[1] = rtNaN;
            A2[2] = rtNaN;
            A2[3] = rtNaN;
          } else if (recomputeDiags) {
            d = 1.0 / anrm;
            W[0] *= d;
            W[1] *= d;
          }
        }
        d = exp(W[0]);
        F[0] = A2[0] * d;
        F[1] = A2[1] * d;
        d = exp(W[1]);
        F[2] = A2[2] * d;
        F[3] = A2[3] * d;
        mul = A2[0];
        anrm = A2[2];
        d = A2[1];
        a22 = A2[3];
        for (r2 = 0; r2 < 2; r2++) {
          cfromc = F[r2 + 2];
          cfrom1 = F[r2];
          b_A6[r2] = cfrom1 * mul + cfromc * anrm;
          b_A6[r2 + 2] = cfrom1 * d + cfromc * a22;
        }
        F[0] = b_A6[0];
        F[1] = b_A6[1];
        F[2] = b_A6[2];
        F[3] = b_A6[3];
        b_A6[0] = (F[0] + F[0]) / 2.0;
        d = (F[1] + F[2]) / 2.0;
        b_A6[3] = (F[3] + F[3]) / 2.0;
        F[0] = b_A6[0];
        F[1] = d;
        F[2] = d;
        F[3] = b_A6[3];
      } else {
        double A2[4];
        double A4[4];
        double A6[4];
        double U[4];
        double V[4];
        double b_A6[4];
        double a22;
        double anrm;
        double cfrom1;
        double cfromc;
        double d;
        int blockFormat;
        recomputeDiags = true;
        if (A[1] != 0.0) {
          if (A[0] != A[3]) {
            recomputeDiags = false;
          } else {
            if (rtIsNaN(A[1])) {
              mul = rtNaN;
            } else if (A[1] < 0.0) {
              mul = -1.0;
            } else {
              mul = (A[1] > 0.0);
            }
            if (rtIsNaN(A[2])) {
              s = rtNaN;
            } else if (A[2] < 0.0) {
              s = -1.0;
            } else {
              s = (A[2] > 0.0);
            }
            if (mul * s != -1.0) {
              recomputeDiags = false;
            }
          }
        }
        r1 = getExpmParams(A, A2, A4, A6, &s);
        if (s != 0.0) {
          d = rt_powd_snf(2.0, s);
          cfromc = rt_powd_snf(2.0, 2.0 * s);
          a22 = rt_powd_snf(2.0, 4.0 * s);
          cfrom1 = rt_powd_snf(2.0, 6.0 * s);
          A[0] /= d;
          A2[0] /= cfromc;
          A4[0] /= a22;
          A6[0] /= cfrom1;
          A[1] /= d;
          A2[1] /= cfromc;
          A4[1] /= a22;
          A6[1] /= cfrom1;
          A[2] /= d;
          A2[2] /= cfromc;
          A4[2] /= a22;
          A6[2] /= cfrom1;
          A[3] /= d;
          A2[3] /= cfromc;
          A4[3] /= a22;
          A6[3] /= cfrom1;
        }
        if (recomputeDiags) {
          if (A[1] == 0.0) {
            blockFormat = 1;
          } else {
            blockFormat = 2;
          }
        }
        if (r1 == 3) {
          mul = A2[0] + 60.0;
          anrm = A2[1];
          d = A2[2];
          a22 = A2[3] + 60.0;
          for (r2 = 0; r2 < 2; r2++) {
            cfromc = A[r2 + 2];
            cfrom1 = A[r2];
            b_A6[r2] = cfrom1 * mul + cfromc * anrm;
            b_A6[r2 + 2] = cfrom1 * d + cfromc * a22;
          }
          U[0] = b_A6[0];
          V[0] = 12.0 * A2[0];
          U[1] = b_A6[1];
          V[1] = 12.0 * A2[1];
          U[2] = b_A6[2];
          V[2] = 12.0 * A2[2];
          U[3] = b_A6[3];
          V[3] = 12.0 * A2[3];
          d = 120.0;
        } else if (r1 == 5) {
          mul = (A4[0] + 420.0 * A2[0]) + 15120.0;
          anrm = A4[1] + 420.0 * A2[1];
          d = A4[2] + 420.0 * A2[2];
          a22 = (A4[3] + 420.0 * A2[3]) + 15120.0;
          for (r2 = 0; r2 < 2; r2++) {
            cfromc = A[r2 + 2];
            cfrom1 = A[r2];
            b_A6[r2] = cfrom1 * mul + cfromc * anrm;
            b_A6[r2 + 2] = cfrom1 * d + cfromc * a22;
          }
          U[0] = b_A6[0];
          V[0] = 30.0 * A4[0] + 3360.0 * A2[0];
          U[1] = b_A6[1];
          V[1] = 30.0 * A4[1] + 3360.0 * A2[1];
          U[2] = b_A6[2];
          V[2] = 30.0 * A4[2] + 3360.0 * A2[2];
          U[3] = b_A6[3];
          V[3] = 30.0 * A4[3] + 3360.0 * A2[3];
          d = 30240.0;
        } else if (r1 == 7) {
          mul = ((A6[0] + 1512.0 * A4[0]) + 277200.0 * A2[0]) + 8.64864E+6;
          anrm = (A6[1] + 1512.0 * A4[1]) + 277200.0 * A2[1];
          d = (A6[2] + 1512.0 * A4[2]) + 277200.0 * A2[2];
          a22 = ((A6[3] + 1512.0 * A4[3]) + 277200.0 * A2[3]) + 8.64864E+6;
          for (r2 = 0; r2 < 2; r2++) {
            cfromc = A[r2 + 2];
            cfrom1 = A[r2];
            b_A6[r2] = cfrom1 * mul + cfromc * anrm;
            b_A6[r2 + 2] = cfrom1 * d + cfromc * a22;
          }
          U[0] = b_A6[0];
          V[0] = (56.0 * A6[0] + 25200.0 * A4[0]) + 1.99584E+6 * A2[0];
          U[1] = b_A6[1];
          V[1] = (56.0 * A6[1] + 25200.0 * A4[1]) + 1.99584E+6 * A2[1];
          U[2] = b_A6[2];
          V[2] = (56.0 * A6[2] + 25200.0 * A4[2]) + 1.99584E+6 * A2[2];
          U[3] = b_A6[3];
          V[3] = (56.0 * A6[3] + 25200.0 * A4[3]) + 1.99584E+6 * A2[3];
          d = 1.729728E+7;
        } else if (r1 == 9) {
          mul = A2[0];
          anrm = A2[1];
          d = A2[2];
          a22 = A2[3];
          for (r2 = 0; r2 < 2; r2++) {
            cfromc = A6[r2 + 2];
            cfrom1 = A6[r2];
            V[r2] = cfrom1 * mul + cfromc * anrm;
            V[r2 + 2] = cfrom1 * d + cfromc * a22;
          }
          mul = (((V[0] + 3960.0 * A6[0]) + 2.16216E+6 * A4[0]) +
                 3.027024E+8 * A2[0]) +
                8.8216128E+9;
          anrm = ((V[1] + 3960.0 * A6[1]) + 2.16216E+6 * A4[1]) +
                 3.027024E+8 * A2[1];
          d = ((V[2] + 3960.0 * A6[2]) + 2.16216E+6 * A4[2]) +
              3.027024E+8 * A2[2];
          a22 = (((V[3] + 3960.0 * A6[3]) + 2.16216E+6 * A4[3]) +
                 3.027024E+8 * A2[3]) +
                8.8216128E+9;
          for (r2 = 0; r2 < 2; r2++) {
            cfromc = A[r2 + 2];
            cfrom1 = A[r2];
            b_A6[r2] = cfrom1 * mul + cfromc * anrm;
            b_A6[r2 + 2] = cfrom1 * d + cfromc * a22;
          }
          U[0] = b_A6[0];
          V[0] = ((90.0 * V[0] + 110880.0 * A6[0]) + 3.027024E+7 * A4[0]) +
                 2.0756736E+9 * A2[0];
          U[1] = b_A6[1];
          V[1] = ((90.0 * V[1] + 110880.0 * A6[1]) + 3.027024E+7 * A4[1]) +
                 2.0756736E+9 * A2[1];
          U[2] = b_A6[2];
          V[2] = ((90.0 * V[2] + 110880.0 * A6[2]) + 3.027024E+7 * A4[2]) +
                 2.0756736E+9 * A2[2];
          U[3] = b_A6[3];
          V[3] = ((90.0 * V[3] + 110880.0 * A6[3]) + 3.027024E+7 * A4[3]) +
                 2.0756736E+9 * A2[3];
          d = 1.76432256E+10;
        } else {
          U[0] = (3.352212864E+10 * A6[0] + 1.05594705216E+13 * A4[0]) +
                 1.1873537964288E+15 * A2[0];
          U[1] = (3.352212864E+10 * A6[1] + 1.05594705216E+13 * A4[1]) +
                 1.1873537964288E+15 * A2[1];
          U[2] = (3.352212864E+10 * A6[2] + 1.05594705216E+13 * A4[2]) +
                 1.1873537964288E+15 * A2[2];
          U[3] = (3.352212864E+10 * A6[3] + 1.05594705216E+13 * A4[3]) +
                 1.1873537964288E+15 * A2[3];
          U[0] += 3.238237626624E+16;
          U[3] += 3.238237626624E+16;
          mul = (A6[0] + 16380.0 * A4[0]) + 4.08408E+7 * A2[0];
          anrm = (A6[1] + 16380.0 * A4[1]) + 4.08408E+7 * A2[1];
          d = (A6[2] + 16380.0 * A4[2]) + 4.08408E+7 * A2[2];
          a22 = (A6[3] + 16380.0 * A4[3]) + 4.08408E+7 * A2[3];
          for (r2 = 0; r2 < 2; r2++) {
            cfromc = A6[r2 + 2];
            cfrom1 = A6[r2];
            V[r2] = (cfrom1 * mul + cfromc * anrm) + U[r2];
            V[r2 + 2] = (cfrom1 * d + cfromc * a22) + U[r2 + 2];
          }
          mul = V[0];
          anrm = V[1];
          d = V[2];
          a22 = V[3];
          for (r2 = 0; r2 < 2; r2++) {
            cfromc = A[r2 + 2];
            cfrom1 = A[r2];
            U[r2] = cfrom1 * mul + cfromc * anrm;
            U[r2 + 2] = cfrom1 * d + cfromc * a22;
          }
          mul = (182.0 * A6[0] + 960960.0 * A4[0]) + 1.32324192E+9 * A2[0];
          anrm = (182.0 * A6[1] + 960960.0 * A4[1]) + 1.32324192E+9 * A2[1];
          d = (182.0 * A6[2] + 960960.0 * A4[2]) + 1.32324192E+9 * A2[2];
          a22 = (182.0 * A6[3] + 960960.0 * A4[3]) + 1.32324192E+9 * A2[3];
          for (r2 = 0; r2 < 2; r2++) {
            cfromc = A6[r2 + 2];
            cfrom1 = A6[r2];
            V[r2] =
                (((cfrom1 * mul + cfromc * anrm) + 6.704425728E+11 * cfrom1) +
                 1.29060195264E+14 * A4[r2]) +
                7.7717703038976E+15 * A2[r2];
            V[r2 + 2] =
                (((cfrom1 * d + cfromc * a22) + 6.704425728E+11 * cfromc) +
                 1.29060195264E+14 * A4[r2 + 2]) +
                7.7717703038976E+15 * A2[r2 + 2];
          }
          d = 6.476475253248E+16;
        }
        V[0] += d;
        V[3] += d;
        V[0] -= U[0];
        U[0] *= 2.0;
        V[1] -= U[1];
        U[1] *= 2.0;
        V[2] -= U[2];
        U[2] *= 2.0;
        V[3] -= U[3];
        U[3] *= 2.0;
        if (fabs(V[1]) > fabs(V[0])) {
          r1 = 1;
          r2 = 0;
        } else {
          r1 = 0;
          r2 = 1;
        }
        d = V[r2] / V[r1];
        cfromc = V[r1 + 2];
        a22 = V[r2 + 2] - d * cfromc;
        mul = (U[r2] - U[r1] * d) / a22;
        F[1] = mul;
        F[0] = (U[r1] - mul * cfromc) / V[r1];
        anrm = U[r1 + 2];
        mul = (U[r2 + 2] - anrm * d) / a22;
        F[2] = (anrm - mul * cfromc) / V[r1];
        F[0]++;
        F[3] = mul + 1.0;
        if (recomputeDiags) {
          recomputeBlockDiag(A, F, blockFormat);
        }
        r2 = (int)s;
        for (r1 = 0; r1 < r2; r1++) {
          for (i = 0; i < 2; i++) {
            mul = F[i + 2];
            b_A6[i] = F[i] * F[0] + mul * F[1];
            b_A6[i + 2] = F[i] * F[2] + mul * F[3];
          }
          F[0] = b_A6[0];
          F[1] = b_A6[1];
          F[2] = b_A6[2];
          F[3] = b_A6[3];
          if (recomputeDiags) {
            A[0] *= 2.0;
            A[1] *= 2.0;
            A[2] *= 2.0;
            A[3] *= 2.0;
            recomputeBlockDiag(A, F, blockFormat);
          }
        }
      }
    }
  }
}

/*
 * File trailer for expm.c
 *
 * [EOF]
 */
