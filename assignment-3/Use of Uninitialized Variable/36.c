


#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__struct_18_bad()
{
    twoIntsStruct data;
    goto source;
source:
    
    ; 
    goto sink;
sink:
    
    printIntLine(data.intOne);
    printIntLine(data.intTwo);
}

#endif 

#ifndef OMITGOOD


static void goodB2G()
{
    twoIntsStruct data;
    goto source;
source:
    
    ; 
    goto sink;
sink:
    
    data.intOne = 1;
    data.intTwo = 2;
    printIntLine(data.intOne);
    printIntLine(data.intTwo);
}


static void goodG2B()
{
    twoIntsStruct data;
    goto source;
source:
    
    data.intOne = 1;
    data.intTwo = 2;
    goto sink;
sink:
    
    printIntLine(data.intOne);
    printIntLine(data.intTwo);
}

void CWE457_Use_of_Uninitialized_Variable__struct_18_good()
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
    CWE457_Use_of_Uninitialized_Variable__struct_18_good();
    printLine("Finished good()");
#endif 
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__struct_18_bad();
    printLine("Finished bad()");
#endif 
    return 0;
}

#endif
