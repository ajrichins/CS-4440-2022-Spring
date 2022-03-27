


#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif


#define SRC_STRING L"AAAAAAAAAA"


static int staticTrue = 1; 
static int staticFalse = 0; 

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_cpy_05_bad()
{
    wchar_t * data;
    data = NULL;
    if(staticTrue)
    {
        
        data = (wchar_t *)malloc(10*sizeof(wchar_t));
        if (data == NULL) {exit(-1);}
    }
    {
        wchar_t source[10+1] = SRC_STRING;
        
        wcscpy(data, source);
        printWLine(data);
        free(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B1()
{
    wchar_t * data;
    data = NULL;
    if(staticFalse)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = (wchar_t *)malloc((10+1)*sizeof(wchar_t));
        if (data == NULL) {exit(-1);}
    }
    {
        wchar_t source[10+1] = SRC_STRING;
        
        wcscpy(data, source);
        printWLine(data);
        free(data);
    }
}


static void goodG2B2()
{
    wchar_t * data;
    data = NULL;
    if(staticTrue)
    {
        
        data = (wchar_t *)malloc((10+1)*sizeof(wchar_t));
        if (data == NULL) {exit(-1);}
    }
    {
        wchar_t source[10+1] = SRC_STRING;
        
        wcscpy(data, source);
        printWLine(data);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_cpy_05_good()
{
    goodG2B1();
    goodG2B2();
}

#endif 



#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_cpy_05_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_cpy_05_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
