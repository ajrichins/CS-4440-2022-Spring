


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__src_char_declare_cpy_12_bad()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    if(globalReturnsTrueOrFalse())
    {
        
        memset(data, 'A', 100-1); 
        data[100-1] = '\0'; 
    }
    else
    {
        
        memset(data, 'A', 50-1); 
        data[50-1] = '\0'; 
    }
    {
        char dest[50] = "";
        
        strcpy(dest, data);
        printLine(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    if(globalReturnsTrueOrFalse())
    {
        
        memset(data, 'A', 50-1); 
        data[50-1] = '\0'; 
    }
    else
    {
        
        memset(data, 'A', 50-1); 
        data[50-1] = '\0'; 
    }
    {
        char dest[50] = "";
        
        strcpy(dest, data);
        printLine(data);
    }
}

void CWE121_Stack_Based_Buffer_Overflow__src_char_declare_cpy_12_good()
{
    goodG2B();
}

#endif 



#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE121_Stack_Based_Buffer_Overflow__src_char_declare_cpy_12_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__src_char_declare_cpy_12_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
