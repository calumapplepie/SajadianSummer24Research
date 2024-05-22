/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_CostFunction_api.h
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 21-May-2024 21:38:08
 */

#ifndef _CODER_COSTFUNCTION_API_H
#define _CODER_COSTFUNCTION_API_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void CostFunction(real_T Vdc, real_T sys[5], real_T Ref[2], real_T If[2],
                  real_T Vc[2], real_T Io[2], real_T mode, real_T *Sa,
                  real_T *Sb, real_T *Sc, real_T *J);

void CostFunction_api(const mxArray *const prhs[7], int32_T nlhs,
                      const mxArray *plhs[4]);

void CostFunction_atexit(void);

void CostFunction_initialize(void);

void CostFunction_terminate(void);

void CostFunction_xil_shutdown(void);

void CostFunction_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_CostFunction_api.h
 *
 * [EOF]
 */
