This is a time calculator prgram , which perform fuction like conversion 
addition , subtraction and comparsions among time seconds and time spec(YNDHMS)
where Y->year N->Months D->days H->Hours M->minutes S->seconds.

 ./time_calc <function> <argument-1> <argument-2>

1. function can be conv/add/subt/comp/help
   if invalid command is given 
   error representing that input is invalid command 
   is generated. 
2. argument can be in format of number of seconds or time spec. 

3.  required arrguments as per command 
    i. conv 1 
    ii. add 2 
    iii.subt 2
    iv. comp 2
    v. help 0
4. limitaions 
   i. seconds less 3155760000 can only be operated. 
   ii. for time spec smaller than 99y11n30d10h30m00s can be used. 

5. commands 
   i.conv 
     convert the given time format to the time other by checking it format  and validity.  
     i.e. seconds => time-spec & time-spec=>seconds. 
   ii. add preform addition between the given times irrespective of the format just they should be valid.
   iii. sub  preform  subtraction between the given times irrespective of the format just they should be valid.
   iv. comp  preform comparision between the given times irrespective of the format just they should be valid.
       produce output =>
       less    arg1 < arg2
       greater arg1 > arg2
       equal   arg1 == arg2
   v. help 
     produce help message. 
     Usage: time_calc conv <time>
	    time_calc {add,subt,comp} <time1> <time2>
6. general error

	error: number of seconds outside of valid range
	=>if input is greater then the limit. 
	error: time range exceeded
	=> if time spec is grater the limit. 
	error: too few arguments
	=>less arguments than required. 
	error: too many arguments
	=>more arguments than required. 
	error: command '<string>' not recognized
	=>if input command is invalid. 
	Usage: time_calc conv <time>
	       time_calc {add,subt,comp} <time1> <time2>
	=>if the operation given is not valid.
	error: '<argument>' is not a valid time spec
	=>if the argument is not a valid time spec. 
	error: years outside of valid range
	=>if the year are out of range 
	error: months outside of valid range
	=>if the months are out of range 
	error: days outside of valid range
	=>if the days are out of range 
	error: hours outside of valid range
	=>if the hours are out of range 
	error: min outside of valid range
	=>if the min are out of range 
	error: seconds outside of valid range
	=>if the seconds are out of range 
	error: negative time not allowed
	=>if opertion give or generate negative time. 

