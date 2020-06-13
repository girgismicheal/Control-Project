/*
 * File: System_20200613_1514_38_controller.c
 *
 * Code generated for Simulink model 'System_20200613_1514_38_controller'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Sat Jun 13 15:15:07 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "System_20200613_1514_38_controller.h"
#include "System_20200613_1514_38_controller_private.h"

/* Block states (default storage) */
DW_System_20200613_1514_38_co_T System_20200613_1514_38_cont_DW;

/* External inputs (root inport signals with default storage) */
ExtU_System_20200613_1514_38__T System_20200613_1514_38_contr_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_System_20200613_1514_38__T System_20200613_1514_38_contr_Y;

/* Real-time model */
RT_MODEL_System_20200613_1514_T System_20200613_1514_38_cont_M_;
RT_MODEL_System_20200613_1514_T *const System_20200613_1514_38_cont_M =
  &System_20200613_1514_38_cont_M_;

/* Model step function */
void System_20200613_1514_38_controller_step(void)
{
  real_T numAccum;
  real_T denAccum;
  real_T denAccum_0;

  /* Sum: '<Root>/Sum2' incorporates:
   *  DiscreteFilter: '<Root>/Bp(z)//Ap(z)'
   *  Inport: '<Root>/into2'
   */
  System_20200613_1514_38_contr_Y.Outform = (0.1 *
    System_20200613_1514_38_cont_DW.BpzApz_states[0] + 0.2 *
    System_20200613_1514_38_cont_DW.BpzApz_states[1]) +
    System_20200613_1514_38_contr_U.into2;

  /* DiscreteFilter: '<Root>/Bm(z)//Am(z)' incorporates:
   *  Inport: '<Root>/into'
   */
  denAccum = (System_20200613_1514_38_contr_U.into - -1.2451 *
              System_20200613_1514_38_cont_DW.BmzAmz_states[0]) - 0.4066 *
    System_20200613_1514_38_cont_DW.BmzAmz_states[1];
  numAccum = 0.0927 * denAccum + 0.0687 *
    System_20200613_1514_38_cont_DW.BmzAmz_states[0];

  /* DiscreteFilter: '<Root>/1//S(z)' incorporates:
   *  DiscreteFilter: '<Root>/Bm(z)//Am(z)'
   *  DiscreteFilter: '<Root>/R(z)'
   *  DiscreteFilter: '<Root>/T(z)'
   *  Sum: '<Root>/Sum1'
   */
  System_20200613_1514_38_contr_Y.Outform2 = ((((3.3333 * numAccum + -4.5803 *
    System_20200613_1514_38_cont_DW.Tz_states[0]) + 1.6223 *
    System_20200613_1514_38_cont_DW.Tz_states[1]) - ((3.0005 *
    System_20200613_1514_38_contr_Y.Outform + -3.9395 *
    System_20200613_1514_38_cont_DW.Rz_states[0]) + 1.3143 *
    System_20200613_1514_38_cont_DW.Rz_states[1])) - -0.37415 *
    System_20200613_1514_38_cont_DW.uSz_states[0]) - -0.62585 *
    System_20200613_1514_38_cont_DW.uSz_states[1];

  /* Update for DiscreteFilter: '<Root>/Bp(z)//Ap(z)' incorporates:
   *  Outport: '<Root>/Outform2'
   */
  denAccum_0 = (System_20200613_1514_38_contr_Y.Outform2 - -1.3 *
                System_20200613_1514_38_cont_DW.BpzApz_states[0]) - 0.42 *
    System_20200613_1514_38_cont_DW.BpzApz_states[1];
  System_20200613_1514_38_cont_DW.BpzApz_states[1] =
    System_20200613_1514_38_cont_DW.BpzApz_states[0];
  System_20200613_1514_38_cont_DW.BpzApz_states[0] = denAccum_0;

  /* Update for DiscreteFilter: '<Root>/R(z)' */
  System_20200613_1514_38_cont_DW.Rz_states[1] =
    System_20200613_1514_38_cont_DW.Rz_states[0];
  System_20200613_1514_38_cont_DW.Rz_states[0] =
    System_20200613_1514_38_contr_Y.Outform;

  /* Update for DiscreteFilter: '<Root>/Bm(z)//Am(z)' */
  System_20200613_1514_38_cont_DW.BmzAmz_states[1] =
    System_20200613_1514_38_cont_DW.BmzAmz_states[0];
  System_20200613_1514_38_cont_DW.BmzAmz_states[0] = denAccum;

  /* Update for DiscreteFilter: '<Root>/T(z)' incorporates:
   *  DiscreteFilter: '<Root>/Bm(z)//Am(z)'
   */
  System_20200613_1514_38_cont_DW.Tz_states[1] =
    System_20200613_1514_38_cont_DW.Tz_states[0];
  System_20200613_1514_38_cont_DW.Tz_states[0] = numAccum;

  /* Update for DiscreteFilter: '<Root>/1//S(z)' */
  System_20200613_1514_38_cont_DW.uSz_states[1] =
    System_20200613_1514_38_cont_DW.uSz_states[0];
  System_20200613_1514_38_cont_DW.uSz_states[0] =
    System_20200613_1514_38_contr_Y.Outform2;
}

/* Model initialize function */
void System_20200613_1514_38_controller_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(System_20200613_1514_38_cont_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&System_20200613_1514_38_cont_DW, 0,
                sizeof(DW_System_20200613_1514_38_co_T));

  /* external inputs */
  (void)memset((void *)&System_20200613_1514_38_contr_U, 0, sizeof
               (ExtU_System_20200613_1514_38__T));

  /* external outputs */
  (void) memset((void *)&System_20200613_1514_38_contr_Y, 0,
                sizeof(ExtY_System_20200613_1514_38__T));
}

/* Model terminate function */
void System_20200613_1514_38_controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
