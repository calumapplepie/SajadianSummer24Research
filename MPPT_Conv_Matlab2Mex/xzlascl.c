/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xzlascl.c
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 21-May-2024 22:00:04
 */

/* Include Files */
#include "xzlascl.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double cfrom
 *                double cto
 *                int m
 *                double *A
 * Return Type  : void
 */
void b_xzlascl(double cfrom, double cto, int m, double *A)
{
  double cfromc;
  double ctoc;
  int i;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    double cfrom1;
    double cto1;
    double mul;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    for (i = 0; i < m; i++) {
      *A *= mul;
    }
  }
}

/*
 * Arguments    : double cfrom
 *                double cto
 *                int m
 *                double A[2]
 *                int iA0
 * Return Type  : void
 */
void xzlascl(double cfrom, double cto, int m, double A[2], int iA0)
{
  double cfromc;
  double ctoc;
  int b_i;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    double cfrom1;
    double cto1;
    double mul;
    int i;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    i = (unsigned char)m;
    for (b_i = 0; b_i < i; b_i++) {
      int i1;
      i1 = (iA0 + b_i) - 1;
      A[i1] *= mul;
    }
  }
}

/*
 * File trailer for xzlascl.c
 *
 * [EOF]
 */
