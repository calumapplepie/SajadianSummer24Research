/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CostFunction.h
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 21-May-2024 22:00:04
 */

#ifndef COSTFUNCTION_H
#define COSTFUNCTION_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void CostFunction(double Vdc, const double sys[5], const double Ref[2],
                         const double If[2], const double Vc[2],
                         const double Io[2], double mode, double *Sa,
                         double *Sb, double *Sc, double *J);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for CostFunction.h
 *
 * [EOF]
 */
