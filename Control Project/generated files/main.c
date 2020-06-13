#include <stdio.h>
#include <stdlib.h>
int main()
{
FILE * fp = fopen("mydata.csv", "w");
if(fp == NULL){
printf("Couldnt open file");
return;
}
float Ts=1;
int n_samples=1000;
float Ref[3];
float Uk[3];
float Ek[3];
float yk[7];
for(int i=1;i<3;i++)Ref[i]=0;
for(int i=1;i<3;i++)Uk[i]=0;
for(int i=1;i<3;i++)Ek[i]=0;
for(int i=1;i<7;i++)yk[i]=0 ;
for(int k=0;k<n_samples;++k)
{
//simulate
Ref[0]=1;
Ek[0]=+3.3333*Ref[0]-4.5803*Ref[1]+1.6223*Ref[2]+3.0005*yk[0]-3.9395*yk[1]+1.3143*yk[2];
Uk[0]=Ek[0]+0.37415*yk[1]+0.62585*yk[2];
yk[0]=0*Ek[0]-0.2381*Ek[1]-0.47619*Ek[2]+0.37415*yk[1]+3.0068*yk[2]-6.367*yk[3]+4.654*yk[4]+1.895*yk[5]-2.563*yk[6];

if(k==1)yk[0]=.02*yk[0];
if(k==100)yk[0]=yk[0]+.28;
printf("y[%d] = %f\n", k, yk[0]);
fprintf(fp, "%d,%f,%f,%f\n", k, k*Ts,-Uk[0],-yk[0]);
for(int i=0;i<2;i++)Ref[i+1]=Ref[i];
for(int i=0;i<2;i++)Uk[i+1]=Uk[i];
for(int i=0;i<2;i++)Ek[i+1]=Ek[i];
for(int i=0;i<6;i++)yk[i+1]=yk[i];
}fclose(fp);
return 0;
}