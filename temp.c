#include "r_cg_macrodriver.h"
#include "r_cg_adc.h"
#include <math.h>

int GetTemp (void) {
double t0 = 298.15;
int r0 = 10000;
int ra = 10000;
int Beta = 3977;
double vcc = 3.3;
double vm= ((double)(ADCR >> 6U))*3.3/1023;
double rntc = ra/((vcc/vm)-1);
double logaritmo = log(rntc/r0);
double temp2 = (logaritmo/((double)Beta));
double temp3 = 1/t0;
double temp4 = temp2+temp3;
double temp5 = (1/temp4)-273.15;
int temp = ((int) temp5);
return temp;
}
