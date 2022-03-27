


#include "std_testcase.h"


static int staticTrue = 1; 
static int staticFalse = 0; 

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_05_bad()
{
    int64_t * data;
    data = NULL;
    if(staticTrue)
    {
        
        data = (int64_t *)malloc(50*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
    }
    {
        int64_t source[100] = {0}; 
        
        memmove(data, source, 100*sizeof(int64_t));
        printLongLongLine(data[0]);
        free(data);
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B1()
{
    int64_t * data;
    data = NULL;
    if(staticFalse)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        data = (int64_t *)malloc(100*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
    }
    {
        int64_t source[100] = {0}; 
        
        memmove(data, source, 100*sizeof(int64_t));
        printLongLongLine(data[0]);
        free(data);
    }
}


static void goodG2B2()
{
    int64_t * data;
    data = NULL;
    if(staticTrue)
    {
        
        data = (int64_t *)malloc(100*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
    }
    {
        int64_t source[100] = {0}; 
        
        memmove(data, source, 100*sizeof(int64_t));
        printLongLongLine(data[0]);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_05_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_05_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_05_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
