#ifndef SECONDS
#define SECONDS
//#include <stdlib.h>
#include<inttypes.h>
//#include<stdio.h>
#include <ctype.h>
typedef  uint32_t num_seconds_t ;
#include"time_calc.h"


#define Max 3155760000// maximum input seconds

extern int flag5,flag4,flag3,flag1,flag;


/*#define true 1
#define false 10*/
char *tmp_str;

num_seconds_t string_to_seconds(char* str );

int numbers_only(const char *str);

bool is_legal_seconds(char* str);

#endif
