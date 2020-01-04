#include "time_spec.h"

int valid(int temp[]);
int valid_spec_gen(time_spec_t *time_spec_p);

 
bool is_legal_time_spec(char* str1)
{ int status,temp[6];
  char t;//to check if time spec does not contain any other char after "s"
  status=sscanf(str1,"%dy%dn%dd%dh%dm%d%s",&(temp[0]),&(temp[1]),\
  &(temp[2]),&(temp[3]),&(temp[4]),&(temp[5]),&t);    
  if((status==7)&&(valid(temp)!=0)&&(t=='s'))//valid to check if spec values are in range 
    {
      return true;
    }
      
  else 
    { if(temp[0]<0&&(status==1))
       { printf("error: number of seconds outside of valid range\n");
         return false; 
       }
      else if(status!=7)
          {
                flag5=3;
                flag1=2;
                return false; 
            }
      else return false; 
        
       
    }

}

int valid(int temp[])//check the spec is range
{
  

        if (((temp[0]>=100)||temp[0]<0)&&(((temp[1])<12)&&temp[1]>=0)&&\
         ((temp[2])<31)&&((temp[3])<24)&&((temp[4])<60)&&((temp[5])<60))
       {
            fprintf(stderr, "%s", " error: years outside of valid range\n");
            flag1=3;return 0;
                }
        else if (((temp[0])<100)&&((temp[1]>=12)||temp[1]<0)&&((temp[2])<31)\
                &&((temp[3])<24)&&((temp[4])<60)&&((temp[5])<60))
      {fprintf(stderr, "%s", " error: months outside of valid range\n");
                 flag1=3;return 0;}

    else if (((temp[0])<100)&&((temp[1])<12)&&(temp[2]>=31||temp[2]<0)&&\
                ((temp[3])<24)&&((temp[4])<60)&&((temp[5])<60))
           {fprintf(stderr, "%s", " error: days outside of valid range\n")
                 ;flag1=3;return 0;}

    else if (((temp[0])<100)&&((temp[1])<12)&&((temp[2])<31)&&\
              (temp[3]>=24||temp[3]<0)&&((temp[4])<60)&&((temp[5])<60))
       {fprintf(stderr, "%s", " error: hours outside of valid range\n");
           flag1=3;return 0;}

    else if (((temp[0])<100)&&((temp[1])<12)&&((temp[2])<31)&&\
           ((temp[3])<24)&&(temp[4]>=60||temp[4]<0)&&((temp[5])<60))
      {fprintf(stderr, "%s", " error: minutes outside of valid range\n");
           flag1=3;return 0;}

    else if (((temp[0])<100)&&((temp[1])<12)&&((temp[2])<31)&&\
          ((temp[3])<24)&&((temp[4])<60)&&(temp[5]>=60||temp[5]<0))
      {fprintf(stderr, "%s", " error: seconds outside of valid range\n");
           flag1=3;return 0;}
               
        else if(((temp[0])<100)&&((temp[1])<12)&&((temp[2])<31)&&\
                ((temp[3])<24)&&((temp[4])<60)&&((temp[5])<60))
                return 1;

         else  { fprintf(stderr, "%s", "error: time range exceeded\n");
                return 0;}
     
   

}

time_spec_t *string_to_time_spec(char* str1 )
{
time_spec_t *time_spec_p= malloc(sizeof(time_spec_t));
 //format1 use for making a suitable format specifier
 strcpy( format1, "%" );
 strcat( format1, SCNu8 );
 strcat( format1, "y" );
 strcat( format1, "%");
strcat( format1, SCNu8 );
strcat( format1, "n");
strcat( format1, "%" );
strcat( format1, SCNu8 );
strcat( format1, "d");
strcat( format1, "%" );
strcat( format1, SCNu8 );
strcat( format1,"h");
strcat( format1, "%" );
strcat( format1, SCNu8 );
strcat( format1, "m");
strcat( format1, "%" );
strcat( format1, SCNu8 );
strcat( format1, "s");
sscanf(str1,format1,&(time_spec_p->y),&(time_spec_p->n),&(time_spec_p->d)\
,&(time_spec_p->h),&(time_spec_p->m),&(time_spec_p->s));
return time_spec_p ;
}

void print_time_spec(time_spec_t *time_spec1 )
{ if(time_spec1!=NULL)//if time spec leagl print it 
 { 
     if(valid_spec_gen(time_spec1)!=0)
        { strcpy( format1, "%" );
         strcat( format1, PRIu8 );
         strcat( format1, "y" );
         strcat( format1, "%");
        strcat( format1, PRIu8  );
        strcat( format1, "n");
        strcat( format1, "%" );
        strcat( format1, PRIu8  );
        strcat( format1, "d");
        strcat( format1, "%" );
        strcat( format1, PRIu8 );
        strcat( format1,"h");
        strcat( format1, "%" );
        strcat( format1, PRIu8 );
        strcat( format1, "m");
        strcat( format1, "%" );
        strcat( format1, PRIu8  );
        strcat( format1, "s");
        printf(format1,time_spec1->y,time_spec1->n,time_spec1->d\
            ,time_spec1->h,time_spec1->m,time_spec1->s);
            printf("\n");
        }
          
  }
 else fprintf(stderr, "%s", "error: negative time not allowed\n");
}


int valid_spec_gen(time_spec_t *time_spec_p)
{ 
  if(((time_spec_p->y)<100)&&((time_spec_p->n)<12)&&((time_spec_p->d)<31)&&\
      ((time_spec_p->h)<24)&&((time_spec_p->m)<60)&&((time_spec_p->s)<60))
      {return 1;}
  else { 
       if (((time_spec_p->y)>=100)&&((time_spec_p->n)<12)&&\
             ((time_spec_p->d)<31)&&((time_spec_p->h)<24)&&((time_spec_p->m)\
              <60)&&((time_spec_p->s)<60))          
              { if((time_spec_p->n)>0)
          fprintf(stderr, "%s", " error: years outside of valid range\n");
              }
          else if (((time_spec_p->y)<100)&&((time_spec_p->n)>=12)&&\
         ((time_spec_p->d)<31)&&((time_spec_p->h)<24)&&((time_spec_p->m)<60)\
          &&((time_spec_p->s)<60))
      fprintf(stderr, "%s", " error: months outside of valid range\n");
      else if (((time_spec_p->y)<100)&&((time_spec_p->n)<12)&&\
          ((time_spec_p->d)>=31)&&((time_spec_p->h)<24)&&((time_spec_p->m)<60)\
           &&((time_spec_p->s)<60))
      fprintf(stderr, "%s", " error: days outside of valid range\n");
      else if (((time_spec_p->y)<100)&&((time_spec_p->n)<12)&&\
          ((time_spec_p->d)<31)&&((time_spec_p->h)>=24)&&((time_spec_p->m)<60)\
          &&((time_spec_p->s)<60))
      fprintf(stderr, "%s", " error: hours outside of valid range\n");
       else if (((time_spec_p->y)<100)&&((time_spec_p->n)<12)&&\
           ((time_spec_p->d)<31)&&((time_spec_p->h)<24)&&((time_spec_p->m)>=60)\
           &&((time_spec_p->s)<60))
      fprintf(stderr, "%s", " error: minutes outside of valid range\n");
       else if (((time_spec_p->y)<100)&&((time_spec_p->n)<12)&&\
          ((time_spec_p->d)<31)&&((time_spec_p->h)<24)&&((time_spec_p->m)<60)\
           &&((time_spec_p->s)>=60))
       fprintf(stderr, "%s", " error:  outside of valid range\n");
        
        else fprintf(stderr, "%s", "error: time range exceeded\n");
       
       return 0;
      }
}   

