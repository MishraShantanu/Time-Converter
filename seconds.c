#include "seconds.h"
bool is_legal_seconds(char* str)
{   long  num=0;
  //for loop for removing spaces and converting string to number for checking 
    for (int i = 0; str[i] != '\0'; i++) 
        {  if(str[i]!=' ')
          {num = num*10 + str[i] - '0'; }
          else if(str[i]=='-')
             {flag4=1;flag5=0;}
       }
    
  if(numbers_only(str)!=0)/*number only fun check if string is only numbers\
  (white space and "-" ) accepted*/ 
   { 
    if ((num<Max))
       { flag=0;
             flag5=0;
        return true;
        }
    else if ((num>Max)||((int)num<0))
         { flag=2;
               flag5=0;
           return false;
          }
        flag5=0;    
    return false;
        
     }
  else 
     {//flag=2;
      flag3=9;
      tmp_str=str;
    return false;}
}
int numbers_only(const char *str)
{  char *a =" ",*b="-";
    while (*str) { //traverdsing sting for checking if there is no invlaid char
        if ((isdigit(*str++) == 0)&&((*str++)!=*a)&&(*str++)!=*b) return 0;
        
    }
   
    return 1;
}
num_seconds_t string_to_seconds(char* str )
{ int i;long  num=0; 
 //for loop for removing spaces converting string into number
   for ( i = 0; str[i] != '\0'; ++i)
       { if(str[i]!=' ')
        num = num*10 + str[i] - '0';
     
        
       }
 
 return     num ;
}

