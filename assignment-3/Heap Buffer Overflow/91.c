


#include "std_testcase.h"

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_15_bad()
{
    int64_t * data;
    data = NULL;
    switch(6)
    {
    case 6:
        
        data = (int64_t *)malloc(50*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    {
        int64_t source[100] = {0}; 
        {
            size_t i;
            
            for (i = 0; i < 100; i++)
            {
                data[i] = source[i];
            }
            printLongLongLine(data[0]);
            free(data);
        }
    }
}

#endif 

#ifndef OMITGOOD


static void goodG2B1()
{
    int64_t * data;
    data = NULL;
    switch(5)
    {
    case 6:
        
        printLine("Benign, fixed string");
        break;
    default:
        
        data = (int64_t *)malloc(100*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
        break;
    }
    {
        int64_t source[100] = {0}; 
        {
            size_t i;
            
            for (i = 0; i < 100; i++)
            {
                data[i] = source[i];
            }
            printLongLongLine(data[0]);
            free(data);
        }
    }
}


static void goodG2B2()
{
    int64_t * data;
    data = NULL;
    switch(6)
    {
    case 6:
        
        data = (int64_t *)malloc(100*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
        break;
    default:
        
        printLine("Benign, fixed string");
        break;
    }
    {
        int64_t source[100] = {0}; 
        {
            size_t i;
            
            for (i = 0; i < 100; i++)
            {
                data[i] = source[i];
            }
            printLongLongLine(data[0]);
            free(data);
        }
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_15_good()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_15_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_loop_15_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
