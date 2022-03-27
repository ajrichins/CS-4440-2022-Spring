


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE416_Use_After_Free__malloc_free_int64_t_13_bad()
{
    int64_t * data;
    
    data = NULL;
    if(GLOBAL_CONST_FIVE==5)
    {
        data = (int64_t *)malloc(100*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5LL;
            }
        }
        
        free(data);
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        
        printLongLongLine(data[0]);
        
    }
}

#endif 

#ifndef OMITGOOD


static void goodB2G1()
{
    int64_t * data;
    
    data = NULL;
    if(GLOBAL_CONST_FIVE==5)
    {
        data = (int64_t *)malloc(100*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5LL;
            }
        }
        
        free(data);
    }
    if(GLOBAL_CONST_FIVE!=5)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        
        
        
        ; 
    }
}


static void goodB2G2()
{
    int64_t * data;
    
    data = NULL;
    if(GLOBAL_CONST_FIVE==5)
    {
        data = (int64_t *)malloc(100*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5LL;
            }
        }
        
        free(data);
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        
        
        
        ; 
    }
}


static void goodG2B1()
{
    int64_t * data;
    
    data = NULL;
    if(GLOBAL_CONST_FIVE!=5)
    {
        
        printLine("Benign, fixed string");
    }
    else
    {
        data = (int64_t *)malloc(100*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5LL;
            }
        }
        
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        
        printLongLongLine(data[0]);
        
    }
}


static void goodG2B2()
{
    int64_t * data;
    
    data = NULL;
    if(GLOBAL_CONST_FIVE==5)
    {
        data = (int64_t *)malloc(100*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5LL;
            }
        }
        
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        
        printLongLongLine(data[0]);
        
    }
}

void CWE416_Use_After_Free__malloc_free_int64_t_13_good()
{
    goodB2G1();
    goodB2G2();
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
    CWE416_Use_After_Free__malloc_free_int64_t_13_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_int64_t_13_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
