/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: expm.c
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 21-May-2024 22:00:04
 */

/* Include Files */
#include "expm.h"
#include "mpower.h"
#include "xzsteqr.h"
#include <math.h>

/* Function Declarations */
static int getExpmParams(const double A[4], double A2[4], double A4[4],
                         double A6[4], double *s);

static void recomputeBlockDiag(const double A[4], double F[4], int blockFormat);

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
  double dv[4];
  double y[4];
  double a;
  double b_a;
  double b_s;
  double d;
  double d1;
  double d2;
  double d3;
  double d6;
  double d8;
  double eta1;
  int b_eint;
  int c_eint;
  int d_eint;
  int e_eint;
  int eint;
  int f_eint;
  int i;
  int m;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T guard3;
  boolean_T guard4;
  *s = 0.0;
  for (i = 0; i < 2; i++) {
    d = A[i + 2];
    A2[i] = A[i] * A[0] + d * A[1];
    A2[i + 2] = A[i] * A[2] + d * A[3];
  }
  for (i = 0; i < 2; i++) {
    d = A2[i + 2];
    d1 = A2[i] * A2[0] + d * A2[1];
    A4[i] = d1;
    d = A2[i] * A2[2] + d * A2[3];
    A4[i + 2] = d;
    A6[i] = d1 * A2[0] + d * A2[1];
    A6[i + 2] = d1 * A2[2] + d * A2[3];
  }
  a = 0.0;
  b_a = 0.0;
  b_s = fabs(A4[0]) + fabs(A4[1]);
  if (b_s > 0.0) {
    a = b_s;
  }
  b_s = fabs(A6[0]) + fabs(A6[1]);
  if (b_s > 0.0) {
    b_a = b_s;
  }
  b_s = fabs(A4[2]) + fabs(A4[3]);
  if (b_s > a) {
    a = b_s;
  }
  b_s = fabs(A6[2]) + fabs(A6[3]);
  if (b_s > b_a) {
    b_a = b_s;
  }
  d6 = pow(b_a, 0.16666666666666666);
  eta1 = fmax(pow(a, 0.25), d6);
  guard1 = false;
  guard2 = false;
  guard3 = false;
  guard4 = false;
  if (eta1 <= 0.01495585217958292) {
    d = fabs(A[0]);
    dv[0] = 0.19285012468241128 * d;
    d1 = fabs(A[1]);
    dv[1] = 0.19285012468241128 * d1;
    d2 = fabs(A[2]);
    dv[2] = 0.19285012468241128 * d2;
    d3 = fabs(A[3]);
    dv[3] = 0.19285012468241128 * d3;
    mpower(dv, 7.0, y);
    b_a = 0.0;
    a = 0.0;
    b_s = fabs(y[0]) + fabs(y[1]);
    if (b_s > 0.0) {
      b_a = b_s;
    }
    b_s = d + d1;
    if (b_s > 0.0) {
      a = b_s;
    }
    b_s = fabs(y[2]) + fabs(y[3]);
    if (b_s > b_a) {
      b_a = b_s;
    }
    b_s = d2 + d3;
    if (b_s > a) {
      a = b_s;
    }
    b_a = 2.0 * (b_a / a) / 2.2204460492503131E-16;
    if (b_a == 0.0) {
      b_a = -1.7976931348623157E+308;
    } else {
      b_a = frexp(b_a, &b_eint);
      if (b_a == 0.5) {
        b_a = (double)b_eint - 1.0;
      } else if ((b_eint == 1) && (b_a < 0.75)) {
        b_a = log(2.0 * b_a) / 0.69314718055994529;
      } else {
        b_a = log(b_a) / 0.69314718055994529 + (double)b_eint;
      }
    }
    if (fmax(ceil(b_a / 6.0), 0.0) == 0.0) {
      m = 3;
    } else {
      guard4 = true;
    }
  } else {
    guard4 = true;
  }
  if (guard4) {
    if (eta1 <= 0.253939833006323) {
      d = fabs(A[0]);
      dv[0] = 0.12321872304378752 * d;
      d1 = fabs(A[1]);
      dv[1] = 0.12321872304378752 * d1;
      d2 = fabs(A[2]);
      dv[2] = 0.12321872304378752 * d2;
      d3 = fabs(A[3]);
      dv[3] = 0.12321872304378752 * d3;
      mpower(dv, 11.0, y);
      b_a = 0.0;
      a = 0.0;
      b_s = fabs(y[0]) + fabs(y[1]);
      if (b_s > 0.0) {
        b_a = b_s;
      }
      b_s = d + d1;
      if (b_s > 0.0) {
        a = b_s;
      }
      b_s = fabs(y[2]) + fabs(y[3]);
      if (b_s > b_a) {
        b_a = b_s;
      }
      b_s = d2 + d3;
      if (b_s > a) {
        a = b_s;
      }
      b_a = 2.0 * (b_a / a) / 2.2204460492503131E-16;
      if (b_a == 0.0) {
        b_a = -1.7976931348623157E+308;
      } else {
        b_a = frexp(b_a, &c_eint);
        if (b_a == 0.5) {
          b_a = (double)c_eint - 1.0;
        } else if ((c_eint == 1) && (b_a < 0.75)) {
          b_a = log(2.0 * b_a) / 0.69314718055994529;
        } else {
          b_a = log(b_a) / 0.69314718055994529 + (double)c_eint;
        }
      }
      if (fmax(ceil(b_a / 10.0), 0.0) == 0.0) {
        m = 5;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }
  }
  if (guard3) {
    mpower(A4, 2.0, y);
    a = 0.0;
    b_s = fabs(y[0]) + fabs(y[1]);
    if (b_s > 0.0) {
      a = b_s;
    }
    b_s = fabs(y[2]) + fabs(y[3]);
    if (b_s > a) {
      a = b_s;
    }
    d8 = pow(a, 0.125);
    eta1 = fmax(d6, d8);
    if (eta1 <= 0.95041789961629319) {
      d = fabs(A[0]);
      dv[0] = 0.090475336558796943 * d;
      d1 = fabs(A[1]);
      dv[1] = 0.090475336558796943 * d1;
      d2 = fabs(A[2]);
      dv[2] = 0.090475336558796943 * d2;
      d3 = fabs(A[3]);
      dv[3] = 0.090475336558796943 * d3;
      mpower(dv, 15.0, y);
      b_a = 0.0;
      a = 0.0;
      b_s = fabs(y[0]) + fabs(y[1]);
      if (b_s > 0.0) {
        b_a = b_s;
      }
      b_s = d + d1;
      if (b_s > 0.0) {
        a = b_s;
      }
      b_s = fabs(y[2]) + fabs(y[3]);
      if (b_s > b_a) {
        b_a = b_s;
      }
      b_s = d2 + d3;
      if (b_s > a) {
        a = b_s;
      }
      b_a = 2.0 * (b_a / a) / 2.2204460492503131E-16;
      if (b_a == 0.0) {
        b_a = -1.7976931348623157E+308;
      } else {
        b_a = frexp(b_a, &e_eint);
        if (b_a == 0.5) {
          b_a = (double)e_eint - 1.0;
        } else if ((e_eint == 1) && (b_a < 0.75)) {
          b_a = log(2.0 * b_a) / 0.69314718055994529;
        } else {
          b_a = log(b_a) / 0.69314718055994529 + (double)e_eint;
        }
      }
      if (fmax(ceil(b_a / 14.0), 0.0) == 0.0) {
        m = 7;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }
  }
  if (guard2) {
    if (eta1 <= 2.097847961257068) {
      d = fabs(A[0]);
      dv[0] = 0.071467735648795785 * d;
      d1 = fabs(A[1]);
      dv[1] = 0.071467735648795785 * d1;
      d2 = fabs(A[2]);
      dv[2] = 0.071467735648795785 * d2;
      d3 = fabs(A[3]);
      dv[3] = 0.071467735648795785 * d3;
      mpower(dv, 19.0, y);
      b_a = 0.0;
      a = 0.0;
      b_s = fabs(y[0]) + fabs(y[1]);
      if (b_s > 0.0) {
        b_a = b_s;
      }
      b_s = d + d1;
      if (b_s > 0.0) {
        a = b_s;
      }
      b_s = fabs(y[2]) + fabs(y[3]);
      if (b_s > b_a) {
        b_a = b_s;
      }
      b_s = d2 + d3;
      if (b_s > a) {
        a = b_s;
      }
      b_a = 2.0 * (b_a / a) / 2.2204460492503131E-16;
      if (b_a == 0.0) {
        b_a = -1.7976931348623157E+308;
      } else {
        b_a = frexp(b_a, &d_eint);
        if (b_a == 0.5) {
          b_a = (double)d_eint - 1.0;
        } else if ((d_eint == 1) && (b_a < 0.75)) {
          b_a = log(2.0 * b_a) / 0.69314718055994529;
        } else {
          b_a = log(b_a) / 0.69314718055994529 + (double)d_eint;
        }
      }
      if (fmax(ceil(b_a / 18.0), 0.0) == 0.0) {
        m = 9;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
  }
  if (guard1) {
    d = A6[0];
    d1 = A6[1];
    d2 = A6[2];
    d3 = A6[3];
    for (i = 0; i < 2; i++) {
      b_a = A4[i + 2];
      a = A4[i];
      y[i] = a * d + b_a * d1;
      y[i + 2] = a * d2 + b_a * d3;
    }
    a = 0.0;
    *s = fabs(y[0]) + fabs(y[1]);
    if (*s > 0.0) {
      a = *s;
    }
    *s = fabs(y[2]) + fabs(y[3]);
    if (*s > a) {
      a = *s;
    }
    b_a = fmin(eta1, fmax(d8, pow(a, 0.1))) / 5.3719203511481517;
    if (b_a == 0.0) {
      b_a = -1.7976931348623157E+308;
    } else {
      b_a = frexp(b_a, &eint);
      if (b_a == 0.5) {
        b_a = (double)eint - 1.0;
      } else if ((eint == 1) && (b_a < 0.75)) {
        b_a = log(2.0 * b_a) / 0.69314718055994529;
      } else {
        b_a = log(b_a) / 0.69314718055994529 + (double)eint;
      }
    }
    *s = fmax(ceil(b_a), 0.0);
    b_a = pow(2.0, *s);
    d = fabs(A[0] / b_a);
    dv[0] = 0.05031554467093536 * d;
    d1 = fabs(A[1] / b_a);
    dv[1] = 0.05031554467093536 * d1;
    d2 = fabs(A[2] / b_a);
    dv[2] = 0.05031554467093536 * d2;
    d3 = fabs(A[3] / b_a);
    dv[3] = 0.05031554467093536 * d3;
    mpower(dv, 27.0, y);
    b_a = 0.0;
    a = 0.0;
    b_s = fabs(y[0]) + fabs(y[1]);
    if (b_s > 0.0) {
      b_a = b_s;
    }
    b_s = d + d1;
    if (b_s > 0.0) {
      a = b_s;
    }
    b_s = fabs(y[2]) + fabs(y[3]);
    if (b_s > b_a) {
      b_a = b_s;
    }
    b_s = d2 + d3;
    if (b_s > a) {
      a = b_s;
    }
    b_a = 2.0 * (b_a / a) / 2.2204460492503131E-16;
    if (b_a == 0.0) {
      b_a = -1.7976931348623157E+308;
    } else {
      b_a = frexp(b_a, &f_eint);
      if (b_a == 0.5) {
        b_a = (double)f_eint - 1.0;
      } else if ((f_eint == 1) && (b_a < 0.75)) {
        b_a = log(2.0 * b_a) / 0.69314718055994529;
      } else {
        b_a = log(b_a) / 0.69314718055994529 + (double)f_eint;
      }
    }
    *s += fmax(ceil(b_a / 26.0), 0.0);
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
 * Arguments    : double A[4]
 *                double F[4]
 * Return Type  : void
 */
void expm(double A[4], double F[4])
{
  double s;
  int exitg1;
  int i;
  int r1;
  int r2;
  boolean_T exitg2;
  boolean_T recomputeDiags;
  recomputeDiags = true;
  r1 = 0;
  exitg2 = false;
  while ((!exitg2) && (r1 < 2)) {
    r2 = 0;
    do {
      exitg1 = 0;
      if (r2 < 2) {
        if ((r2 != r1) && (A[r2 + (r1 << 1)] != 0.0)) {
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
          if (A[r2 + (r1 << 1)] != A[r1 + (r2 << 1)]) {
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
      double mul;
      boolean_T guard1;
      A2[0] = A[0];
      A2[1] = A[1];
      A2[2] = A[2];
      A2[3] = A[3];
      anrm = 0.0;
      for (r1 = 0; r1 < 2; r1++) {
        for (r2 = 0; r2 <= r1; r2++) {
          d = fabs(A[r2 + (r1 << 1)]);
          if (d > anrm) {
            anrm = d;
          }
        }
      }
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
        W[0] = 0.0;
        W[1] = 0.0;
        A2[0] = 0.0;
        A2[1] = 0.0;
        A2[2] = 0.0;
        A2[3] = 0.0;
      } else if (recomputeDiags) {
        d = 1.0 / anrm;
        W[0] *= d;
        W[1] *= d;
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
      for (r1 = 0; r1 < 2; r1++) {
        cfromc = F[r1 + 2];
        cfrom1 = F[r1];
        b_A6[r1] = cfrom1 * mul + cfromc * anrm;
        b_A6[r1 + 2] = cfrom1 * d + cfromc * a22;
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
      double mul;
      int blockFormat;
      recomputeDiags = true;
      if (A[1] != 0.0) {
        if (A[0] != A[3]) {
          recomputeDiags = false;
        } else {
          if (A[1] < 0.0) {
            i = -1;
          } else {
            i = (A[1] > 0.0);
          }
          if (A[2] < 0.0) {
            blockFormat = -1;
          } else {
            blockFormat = (A[2] > 0.0);
          }
          if (i * blockFormat != -1) {
            recomputeDiags = false;
          }
        }
      }
      r1 = getExpmParams(A, A2, A4, A6, &s);
      if (s != 0.0) {
        d = pow(2.0, s);
        cfromc = pow(2.0, 2.0 * s);
        a22 = pow(2.0, 4.0 * s);
        cfrom1 = pow(2.0, 6.0 * s);
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
        for (r1 = 0; r1 < 2; r1++) {
          cfromc = A[r1 + 2];
          cfrom1 = A[r1];
          b_A6[r1] = cfrom1 * mul + cfromc * anrm;
          b_A6[r1 + 2] = cfrom1 * d + cfromc * a22;
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
        for (r1 = 0; r1 < 2; r1++) {
          cfromc = A[r1 + 2];
          cfrom1 = A[r1];
          b_A6[r1] = cfrom1 * mul + cfromc * anrm;
          b_A6[r1 + 2] = cfrom1 * d + cfromc * a22;
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
        for (r1 = 0; r1 < 2; r1++) {
          cfromc = A[r1 + 2];
          cfrom1 = A[r1];
          b_A6[r1] = cfrom1 * mul + cfromc * anrm;
          b_A6[r1 + 2] = cfrom1 * d + cfromc * a22;
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
        for (r1 = 0; r1 < 2; r1++) {
          cfromc = A6[r1 + 2];
          cfrom1 = A6[r1];
          V[r1] = cfrom1 * mul + cfromc * anrm;
          V[r1 + 2] = cfrom1 * d + cfromc * a22;
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
        for (r1 = 0; r1 < 2; r1++) {
          cfromc = A[r1 + 2];
          cfrom1 = A[r1];
          b_A6[r1] = cfrom1 * mul + cfromc * anrm;
          b_A6[r1 + 2] = cfrom1 * d + cfromc * a22;
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
        for (r1 = 0; r1 < 2; r1++) {
          cfromc = A6[r1 + 2];
          cfrom1 = A6[r1];
          V[r1] = (cfrom1 * mul + cfromc * anrm) + U[r1];
          V[r1 + 2] = (cfrom1 * d + cfromc * a22) + U[r1 + 2];
        }
        mul = V[0];
        anrm = V[1];
        d = V[2];
        a22 = V[3];
        for (r1 = 0; r1 < 2; r1++) {
          cfromc = A[r1 + 2];
          cfrom1 = A[r1];
          U[r1] = cfrom1 * mul + cfromc * anrm;
          U[r1 + 2] = cfrom1 * d + cfromc * a22;
        }
        mul = (182.0 * A6[0] + 960960.0 * A4[0]) + 1.32324192E+9 * A2[0];
        anrm = (182.0 * A6[1] + 960960.0 * A4[1]) + 1.32324192E+9 * A2[1];
        d = (182.0 * A6[2] + 960960.0 * A4[2]) + 1.32324192E+9 * A2[2];
        a22 = (182.0 * A6[3] + 960960.0 * A4[3]) + 1.32324192E+9 * A2[3];
        for (r1 = 0; r1 < 2; r1++) {
          cfromc = A6[r1 + 2];
          cfrom1 = A6[r1];
          V[r1] = (((cfrom1 * mul + cfromc * anrm) + 6.704425728E+11 * cfrom1) +
                   1.29060195264E+14 * A4[r1]) +
                  7.7717703038976E+15 * A2[r1];
          V[r1 + 2] =
              (((cfrom1 * d + cfromc * a22) + 6.704425728E+11 * cfromc) +
               1.29060195264E+14 * A4[r1 + 2]) +
              7.7717703038976E+15 * A2[r1 + 2];
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
      r1 = (int)s;
      for (r2 = 0; r2 < r1; r2++) {
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

/*
 * File trailer for expm.c
 *
 * [EOF]
 */
