/*
 * File: ert_main.c
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

#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "System_20200613_1514_38_controller.h" /* Model's header file */
#include "rtwtypes.h"

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(int Ts,FILE *fp,int k);
void rt_OneStep(int Ts,FILE *fp,int k)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(System_20200613_1514_38_cont_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */
 System_20200613_1514_38_contr_U.into=1;
 if(k<100){     System_20200613_1514_38_contr_U.into2=0;     }
 else{         System_20200613_1514_38_contr_U.into2=-.25;     }
  /* Step the model */
  System_20200613_1514_38_controller_step();

  /* Get model outputs here */
 if(k%1==0){
printf("%d ,%f ,%f\n",k,System_20200613_1514_38_contr_Y.Outform2 ,System_20200613_1514_38_contr_Y.Outform);
fprintf(fp, "%d,%d,%f,%f\n", k, k*Ts,System_20200613_1514_38_contr_Y.Outform2,System_20200613_1514_38_contr_Y.Outform);
    }
  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific.  This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Initialize model */
  System_20200613_1514_38_controller_initialize();

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 1.0 seconds (the model's base sample time) here.  The
   * call syntax for rt_OneStep is
   *
   *  rt_OneStep();
   */

  fflush((NULL));
   FILE * fp = fopen("mydata.csv", "w");     if(fp == NULL){
       printf("Couldnt open file");         return;     }     int Ts=1;     for (int i =0;i<300;i=i+1 )
       {         rt_OneStep(Ts, fp ,i);     }


  /* Disable rt_OneStep() here */
fclose(fp);
  /* Terminate model */
  System_20200613_1514_38_controller_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
