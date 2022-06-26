
#include <stdio.h>

// define global variables and a function
extern int sum;
extern int count;
void r_avg();
double resu;

void r_avg (void)
{
    resu = ((double) sum) / ((double) count);
    printf("running average is %d / %d = %.3f\n\n", sum, count, resu);
}

