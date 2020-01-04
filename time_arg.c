

#include "time_arg.h"


time_spec_t *seconds_to_time_spec( long num )
{ long tmp; // temprory variable for holdig calculations 
  time_spec_t *temp = malloc(sizeof(time_spec_t));
  if(num>=0)//dont execute if seconds are negative
  {   /* in this the number fo seconds is divide by firstly by
         year/month/day/hour/min and the
        resultant is then multiplied againg with
         year/month/day/hour/min and subtract the num to obtain the 
         resultant seconds and store the Numerator in time spec*/

         if (num>=year) 
      {
          tmp=(num/year);
                  temp->y=tmp;
               
          num = num-year*(tmp); 
                
      }
      if (num>=month)
      {
          tmp=(num/month);
                   temp->n=tmp;
                 
           num =num - month*(tmp) ;
                  
      }
      if(num>=day)
      {
          tmp=(num/day);
                  temp->d=tmp;
               
          num =num - day*(tmp);  
                 
      }
      if(num>=hour)
      {
          tmp=(num/hour);
                  temp->h=tmp;
          num =num - hour*(tmp);  
                   
      }
      if(num>=min)
        {     
            tmp=(num/min);
                  temp->m=tmp;
             num = num -min*(tmp);  
                  
          
        }
       if(num<min)
       {temp->s=num;
              
        }
      return temp; 
  }
  else return NULL;
}

num_seconds_t   time_spec_to_seconds( time_spec_t *temp)
{ num_seconds_t num ,y,n,d,h,m,s;
       
        y=temp->y;
        n=temp->n;
        d=temp->d;
        h=temp->h;
        m=temp->m;
        s=temp->s;
     
    num = (((y)*year)+((n)*month)+((d)*day)+
            ((h)*hour)+((m)*min)+((s)*1)); 
      
    return num    ; 
}
bool get_time_arg( char *in_str, num_seconds_t *seconds_p )
{   
   
   if(is_legal_time_spec(in_str)!=0)
    { 
    
    time_spec1 = string_to_time_spec( in_str);
        num_sec1= time_spec_to_seconds(time_spec1);
        seconds_p=&num_sec1;
        if(valid_seconds_gen(num_sec1)!=0)
               { strcpy( format, "%" );
                strcat( format, PRId64 );
        printf(format,*seconds_p);//print the num of seconds 
                 printf("\n");}
        else
        fprintf(stderr, "%s", "error: time range exceeded\n");
        
        
        return  1;    
    }
   else return 0;
 }
int valid_seconds_gen(long int num)
{ if(num<Max&&num>=0)
  return 1;
  else return 0;

}
