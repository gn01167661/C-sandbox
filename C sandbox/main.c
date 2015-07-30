//
//  main.c
//  C sandbox
//
//  Created by may on 2015/4/27.
//  Copyright (c) 2015年 C. All rights reserved.
//

#include <stdio.h>

#include <stdarg.h>


char* foofmt(char* format, ...){
    char buf[100];
    va_list vl;
    va_start(vl, format);
    
    vsnprintf(buf,sizeof(buf),format,vl);
    

    va_end(vl);
    //printf(buf);
    return buf;
    
}




int main(int argc, const char * argv[]) {
    
    FILE *fptr;
    
    char str[] ="<i2c_write addr=""0x74"" count=""2"" radix=""16"">00 00</i2c_write>";
    char str1[]="<i2c_read addr=""0x74"" count=""32"" radix=""16""/>";
    char wait[]= "<sleep ms=""10""/>";
    int int_Num =0 ;
    printf(str);
    printf(str1);
    printf(wait);
    

    

    printf("\n");
    
    fptr=fopen("regdump_PMU.xml","a+");
    
    if(fptr == NULL){
        printf("open failure");
        return 1;
    }else{
    
        
        
        while(int_Num < 0x4027){
            strcpy(str,"");
            strcpy(str,foofmt("<i2c_write addr=""0x74"" count=""2"" radix=""16"">%02x %02x</i2c_write>",    int_Num>>8,int_Num&0xff));
            int_Num+=32;
            printf(str);
            printf("\n");
            if (int_Num>(0x4027-32 )){
                printf("%d", 32-(0x4027 - int_Num));
                break;
            }
        }
    }
    
    
    
    return 0;
}


//int a (){
//    return 11;
//}


//
