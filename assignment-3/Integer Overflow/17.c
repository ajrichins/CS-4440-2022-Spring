


#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__int64_t_max_preinc_17_bad()
{
    int i,j;
    int64_t data;
    data = 0LL;
    for(i = 0; i < 1; i++)
    {
        
        data = LLONG_MAX;
    }
    for(j = 0; j < 1; j++)
    {
        {
            
            ++data;
            int64_t result = data;
            printLongLongLine(result);
        }
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    int i,k;
    int64_t data;
    data = 0LL;
    for(i = 0; i < 1; i++)
    {
        
        data = LLONG_MAX;
    }
    for(k = 0; k < 1; k++)
    {
        
        if (data < LLONG_MAX)
        {
            ++data;
            int64_t result = data;
            printLongLongLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}


static void goodG2B()
{
    int h,j;
    int64_t data;
    data = 0LL;
    for(h = 0; h < 1; h++)
    {
        
        data = 2;
    }
    for(j = 0; j < 1; j++)
    {
        {
            
            ++data;
            int64_t result = data;
            printLongLongLine(result);
        }
    }
}

void CWE190_Integer_Overflow__int64_t_max_preinc_17_good()
{
    goodB2G();
    goodG2B();
}

#endif 



#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE190_Integer_Overflow__int64_t_max_preinc_17_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int64_t_max_preinc_17_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
