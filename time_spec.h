#ifndef TIME_SPEC_H
#define TIME_SPEC_H

#include <stdio.h>	// for fprintf()
#include <stdlib.h>	// for NULL, malloc(), abort(), free()
#include<inttypes.h>
#include <string.h>

typedef struct  time_spec_t { //define struct and typedef it
   uint8_t y,n,d,h,m,s;
 }time_spec_t ;
#include"time_calc.h"


extern int flag5,flag1;

#define SIZE 80   //size for fromat array for PRI & SCN
/*typedef char bool; 
enum bool {false,true}flag;


#define true 1
#define false 10*/


	
char format1[SIZE];
//int flag1=0,flag5=0;

bool is_legal_time_spec(char* str1);
int valid_spec_gen(time_spec_t *time_spec_p);

time_spec_t *string_to_time_spec(char* str1 );

void print_time_spec(time_spec_t *time_spec1 );

#endif
