/*
 * File: System_20200613_1514_38_controller.h
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

#ifndef RTW_HEADER_System_20200613_1514_38_controller_h_
#define RTW_HEADER_System_20200613_1514_38_controller_h_
#include <string.h>
#include <stddef.h>
#ifndef System_20200613_1514_38_controller_COMMON_INCLUDES_
# define System_20200613_1514_38_controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* System_20200613_1514_38_controller_COMMON_INCLUDES_ */

#include "System_20200613_1514_38_controller_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T BpzApz_states[2];             /* '<Root>/Bp(z)//Ap(z)' */
  real_T Rz_states[2];                 /* '<Root>/R(z)' */
  real_T BmzAmz_states[2];             /* '<Root>/Bm(z)//Am(z)' */
  real_T Tz_states[2];                 /* '<Root>/T(z)' */
  real_T uSz_states[2];                /* '<Root>/1//S(z)' */
} DW_System_20200613_1514_38_co_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T into;                         /* '<Root>/into' */
  real_T into2;                        /* '<Root>/into2' */
} ExtU_System_20200613_1514_38__T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Outform;                      /* '<Root>/Outform' */
  real_T Outform2;                     /* '<Root>/Outform2' */
} ExtY_System_20200613_1514_38__T;

/* Real-time Model Data Structure */
struct tag_RTM_System_20200613_1514__T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_System_20200613_1514_38_co_T System_20200613_1514_38_cont_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_System_20200613_1514_38__T System_20200613_1514_38_contr_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_System_20200613_1514_38__T System_20200613_1514_38_contr_Y;

/* Model entry point functions */
extern void System_20200613_1514_38_controller_initialize(void);
extern void System_20200613_1514_38_controller_step(void);
extern void System_20200613_1514_38_controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_System_20200613_1514_T *const System_20200613_1514_38_cont_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'System_20200613_1514_38_controller'
 */
#endif                                 /* RTW_HEADER_System_20200613_1514_38_controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
