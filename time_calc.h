#ifndef TIME_CALC
#define TIME_CALC
#include <stdbool.h> 
#include "time_arg.h"
#include "seconds.h"
#include "time_spec.h"

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>


/*typedef char bool;
enum bool {false,true}flag;

#define true 1
#define false 0*/
#ifndef FLAG
#define FLAG

#endif
extern time_spec_t *time_spec1,*time_spec2;//global pointer for holding timespec value
extern num_seconds_t num_sec1,num_sec2,*seconds_p,temp ;
char *tmp_str;



#endif
