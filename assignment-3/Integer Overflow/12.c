


#include "std_testcase.h"

#ifndef OMITBAD

void CWE190_Integer_Overflow__int64_t_max_preinc_12_bad()
{
    int64_t data;
    data = 0LL;
    if(globalReturnsTrueOrFalse())
    {
        
        data = LLONG_MAX;
    }
    else
    {
        
        data = 2;
    }
    if(globalReturnsTrueOrFalse())
    {
        {
            
            ++data;
            int64_t result = data;
            printLongLongLine(result);
        }
    }
    else
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

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    int64_t data;
    data = 0LL;
    if(globalReturnsTrueOrFalse())
    {
        
        data = LLONG_MAX;
    }
    else
    {
        
        data = LLONG_MAX;
    }
    if(globalReturnsTrueOrFalse())
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
    else
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
    int64_t data;
    data = 0LL;
    if(globalReturnsTrueOrFalse())
    {
        
        data = 2;
    }
    else
    {
        
        data = 2;
    }
    if(globalReturnsTrueOrFalse())
    {
        {
            
            ++data;
            int64_t result = data;
            printLongLongLine(result);
        }
    }
    else
    {
        {
            
            ++data;
            int64_t result = data;
            printLongLongLine(result);
        }
    }
}

void CWE190_Integer_Overflow__int64_t_max_preinc_12_good()
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
    CWE190_Integer_Overflow__int64_t_max_preinc_12_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int64_t_max_preinc_12_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
