
#include<stdio.h> 
#include <string.h>
#include<ctype.h>
#include <stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include"time_calc.h"


int flag=0,flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;

time_spec_t *time_spec1,*time_spec2;//global pointer for holding timespec value
num_seconds_t num_sec1,num_sec2,*seconds_p,temp ;

                              
void conv(char* str1);


void add(char *str1,char *str2);
void subt (char *str1,char *str2);
void usage( void );

void comp(char *str1,char *str2);



void error(char*str1);//for posting error
int main (int argc, char *argv[])
{  char *str1,*str2;
  if(argv[1]!=NULL)
 {   /*check if argumnets are present in command line if present do \
     initialization*/
     if(argv[2]!=NULL)  
        {str1=argv[2];}
     if(argv[3]!=NULL)
       {str2=argv[3];}
     
  
   
   
 //check  argv[1] request which command
 if((strcmp(argv[1],"conv")==0))
 {   if(argc==3) //check if arguments are sufficent 
     conv(str1);
     else if (argc>3) 
    {
         fprintf(stderr, "%s", "error: too many arguments\n");
          usage();        
         }
     else
        {
         fprintf(stderr, "%s", "error: too few arguments\n");
          usage();        
         }
 }
 else if((strcmp(argv[1],"add")==0))//check  argv[1] request which command
 { if(argc==4)//check if arguments are sufficent 
       add(str1,str2);
   else if (argc>4)
    {
         fprintf(stderr, "%s", "error: too many arguments\n");
          usage();        
         }
     else
        {
         fprintf(stderr, "%s", "error: too few arguments\n");
          usage();        
         }
     
 }
 else if((strcmp(argv[1],"subt")==0))//check  argv[1] request which command
 {
    
   if(argc==4)//check if arguments are sufficent
       subt(str1,str2) ;
   else if (argc>4)
    {
         fprintf(stderr, "%s", "error: too many arguments\n");
          usage();        
         }
     else
        {
         fprintf(stderr, "%s", "error: too few arguments\n");
          usage();        
         }
}
 else if((strcmp(argv[1],"comp")==0))//check  argv[1] request which command
 {
    
   if(argc==4)//check if arguments are sufficent
       comp(str1,str2) ;
   else if (argc>4)
    {
         fprintf(stderr, "%s", "error: too many arguments\n");
          usage();        
         }
     else
        {
         fprintf(stderr, "%s", "error: too few arguments\n");
          usage();        
         }
 }
 else if((strcmp(argv[1],"help")==0))//check  argv[1] request which command
 {  usage();
     
 }
 else 
{ fprintf(stderr, "%s%s%s", "error:  command " ,argv[1], " not recognized\n");
   usage();
  }
 
error(str1);
}
else usage();
return 0;
}

void conv(char* str1)
{  if(get_time_arg(str1,seconds_p)!=0)/*check if string is able to produce\
    secods*/
      {  
         
       
        }
    else 
       { 
         if(flag1!=0&&flag1!=3)//check the sting is a time spec of wrong format
          { 
         if((is_legal_seconds(str1)!=0))
         { 
         num_sec1=string_to_seconds( str1 );
             time_spec1=seconds_to_time_spec(num_sec1);
             
        if(valid_spec_gen(time_spec1)!=0)//print only if spec is valid
        print_time_spec(time_spec1);
             }
    
       
          }
       }
  
  
}
void error(char*str1)
{ if(flag5==1&&flag4==0&&flag3!=9)
  fprintf(stderr, "%s%s%s", "error: ",str1," is not a valid time spec\n");
 else if(flag4!=0&&flag5!=0)
   fprintf(stderr, "%s", "error: number of seconds outside of valid range\n");
 else if(flag5==3&&flag4==0&&flag3!=9)
   fprintf(stderr, "%s%s%s", "error: ",str1," is not a valid time spec\n");
 
  }

void add(char *str1,char *str2)    
{  
    if(is_legal_time_spec(str1)!=0)
    {    
         time_spec1 = string_to_time_spec( str1 );
         num_sec1=time_spec_to_seconds(time_spec1);
          if(is_legal_time_spec(str2)!=0)
          {
	   time_spec2 = string_to_time_spec( str2 );
          num_sec2=time_spec_to_seconds(time_spec2);
                  
           temp=num_sec1+num_sec2;
                 
                  
          time_spec1=seconds_to_time_spec(temp);
                  if(valid_spec_gen(time_spec1)!=0&&(temp>=num_sec1)&&(temp>=num_sec2))
         { print_time_spec(time_spec1);}
                  else {flag2=5;}
             
           }
          else if(is_legal_seconds(str2)!=0)
           {num_sec2=string_to_seconds( str2 );
            temp=num_sec2+num_sec1;
             time_spec1=seconds_to_time_spec(temp);
                    if(valid_spec_gen(time_spec1)!=0&&(temp>=num_sec1)&&(temp>=num_sec2))
                print_time_spec(time_spec1);
                    else flag2=5;
                  }
          
    }
    else if(is_legal_seconds(str1)!=0)
    {      num_sec1=string_to_seconds( str1 );
           
           if(is_legal_time_spec(str2)!=0)
           {  time_spec1 = string_to_time_spec( str2 );
              num_sec2=time_spec_to_seconds(time_spec1);
              temp=num_sec1+num_sec2;
              time_spec1=seconds_to_time_spec(temp);
               if(valid_spec_gen(time_spec1)!=0&&(temp>=num_sec1)&&(temp>=num_sec2))
                  print_time_spec(time_spec1);
                       else flag2=5;
            }
            else if(is_legal_seconds(str2)!=0)
            { num_sec2=string_to_seconds( str2 );
              temp=num_sec1+num_sec2;
              time_spec1=seconds_to_time_spec(temp);
               if(valid_spec_gen(time_spec1)!=0&&(temp>=num_sec1)&&(temp>=num_sec2))
                  print_time_spec(time_spec1);
                        else flag2=5;
            }

                
    }

       if(flag2==5)
       fprintf(stderr, "%s", " error: time range exceeded\n");
       
              
}
void usage( void ){
puts( "Usage: time_calc help" );
puts( " time_calc conv " );
puts( " time_calc {add,subt,comp} " );
}

void subt (char *str1,char *str2)    
{
    if(is_legal_time_spec(str1)!=0)
        {
                       
             time_spec1 = string_to_time_spec( str1 );
             num_sec1=time_spec_to_seconds(time_spec1);
                        
              if(is_legal_time_spec(str2)!=0)
              { time_spec2 = string_to_time_spec( str2 );
              num_sec2=time_spec_to_seconds(time_spec2);
                          if(num_sec1>=num_sec2){
                  num_sec1=num_sec1-num_sec2;
                  time_spec1=seconds_to_time_spec(num_sec1);
                  print_time_spec(time_spec1);
                }
                               else printf("error:negative time not allowed\n");
               }
                          
              else if(is_legal_seconds(str2)!=0)
               { num_sec2=string_to_seconds( str2 );
                              if(num_sec1>=num_sec2){ 
                 num_sec1=num_sec1-num_sec2;
                 time_spec1=seconds_to_time_spec(num_sec1);
                 print_time_spec(time_spec1);
                             }
                            else printf("error:negative time not allowed\n");
                             
             }
              
        }
    else if(is_legal_seconds(str1)!=0)
        {      num_sec1=string_to_seconds( str1 );
               
               if(is_legal_time_spec(str2)!=0)
               {  time_spec2 = string_to_time_spec( str2 );
                  num_sec2=time_spec_to_seconds(time_spec2);

                 if(num_sec1>=num_sec2){ 
                  num_sec1=num_sec1-num_sec2;
                  time_spec1=seconds_to_time_spec(num_sec1);
                  print_time_spec(time_spec1);
                              }
                              else printf("error:negative time not allowed\n");
                }
               else if(is_legal_seconds(str2)!=0)
               { num_sec2=string_to_seconds( str2 );
                                  if(num_sec1>=num_sec2){
                  num_sec1=num_sec1-num_sec2;
                  time_spec1=seconds_to_time_spec(num_sec1);
                  print_time_spec(time_spec1);    
                                 }
                              else printf("error:negative time not allowed\n");
                }
                    
                
        }
    
}
void comp(char *str1,char *str2)    
{
    if(is_legal_time_spec(str1)!=0)
            {
                           
                 time_spec1 = string_to_time_spec( str1 );
                 num_sec1=time_spec_to_seconds(time_spec1);
                  if(is_legal_time_spec(str2)!=0)
                  { time_spec2 = string_to_time_spec( str2 );
                  num_sec2=time_spec_to_seconds(time_spec2);
                      if(num_sec1<num_sec2)
                      {
                         printf("less\n");
                       }
                      else if (num_sec1>num_sec2)
                      {
                          printf("greater\n");
                      }
                      else printf("equal\n");
                  }
                  else if(is_legal_seconds(str2)!=0)
                   { num_sec2=string_to_seconds( str2 );
                     if(num_sec1<num_sec2)
                        {
                             printf("less\n");
                           }
                        else if (num_sec1>num_sec2)
                           {
                             printf("greater\n");
                           }
                        else printf("equal\n");
                          }
                 
            }
    else if(is_legal_seconds(str1)!=0)
            {      num_sec1=string_to_seconds( str1 );
                   
                   if(is_legal_time_spec(str2)!=0)
                   {  time_spec2 = string_to_time_spec( str2 );
                      num_sec2=time_spec_to_seconds(time_spec2);
                      if(num_sec1<num_sec2)
                          {
                            printf("less\n");
                          }
                      else if (num_sec1>num_sec2)
                          {
                            printf("greater\n");
                          }
                      else printf("equal\n");
                    }
                                    
                       
                   else if(is_legal_seconds(str2)!=0)
                    { num_sec2=string_to_seconds( str2 );
                       if(num_sec1<num_sec2)
                        {
                          printf("less\n");
                        }
                       else if (num_sec1>num_sec2)
                        {
                          printf("greater\n");
                         }
                       else printf("equal\n");
                    }
                        
                        
                    
            }
       if(flag3==9)
       { fprintf(stderr, "%s%s%s", " error: problem with input"\
                          ,tmp_str ," as number of seconds\n");
	fprintf(stderr, "%s", " error: problem with input time value\n");	   
	}
         
}

