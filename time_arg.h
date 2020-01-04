#ifndef TIME_ARG
#define TIME_ARG
#include"seconds.h"
#include"time_calc.h"
#include<stdio.h> 
#include <string.h>
#include <stdlib.h>
#include<inttypes.h>

#include"time_spec.h"

#define SIZE 80 
char format[SIZE];

#define year 31557600 //number of seconds in a year
#define month    2629800 //number of seconds in a month
#define day    86400 //number of seconds in a day
#define hour    3600 //number of seconds in a hour
#define min    60 //number of seconds in a min

/*typedef struct  time_spec_t { //define struct and typedef it
   uint8_t y,n,d,h,m,s;
 }time_spec_t ;*/

time_spec_t *seconds_to_time_spec( long num );
num_seconds_t   time_spec_to_seconds( time_spec_t *temp);
bool get_time_arg( char *in_str, num_seconds_t *seconds_p );
int valid_seconds_gen(long int num);
#endif 
