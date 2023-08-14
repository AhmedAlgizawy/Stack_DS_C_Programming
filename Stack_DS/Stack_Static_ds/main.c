#include <stdio.h>
#include <stdlib.h>

#include "stack_ds.h"

stack_ds_t Stack1 ;
stack_ds_t Stack2 ;

int main()
{
    ret_status_t Ret = R_NOK ;
    uint32_t Value = ZERO ; // *Ptr = &Value ;

    Ret = Stack_inti(&Stack1);
    if (R_NOK==Ret)
    {
        printf("Stack1 failed to be initialized !! \n");
    }
    else
    {
        Ret = Stack_Push(&Stack1,11);
        Ret = Stack_Push(&Stack1,22);
        Ret = Stack_Push(&Stack1,33);
        Ret = Stack_Push(&Stack1,44);
        Ret = Stack_Push(&Stack1,55);
        Ret = Stack_Push(&Stack1,66);
        Ret = Stack_Push(&Stack1,77);

        printf("===============\n");

        Ret = Stack_Display(&Stack1);
        Ret = Stack_Size(&Stack1,&Value);
        Ret = Stack_Top (&Stack1,&Value);
        Ret = Stack_Pop (&Stack1,&Value);

        Ret = Stack_Display(&Stack1);
        Ret = Stack_Size(&Stack1,&Value);
        Ret = Stack_Top (&Stack1,&Value);
        Ret = Stack_Pop (&Stack1,&Value);

        Ret = Stack_Display(&Stack1);
        Ret = Stack_Size(&Stack1,&Value);
        Ret = Stack_Top (&Stack1,&Value);
        Ret = Stack_Pop (&Stack1,&Value);

        Ret = Stack_Display(&Stack1);
        Ret = Stack_Size(&Stack1,&Value);
        Ret = Stack_Top (&Stack1,&Value);
        Ret = Stack_Pop (&Stack1,&Value);

        Ret = Stack_Display(&Stack1);
        Ret = Stack_Size(&Stack1,&Value);
        Ret = Stack_Top (&Stack1,&Value);
        Ret = Stack_Pop (&Stack1,&Value);

        Ret = Stack_Display(&Stack1);
        Ret = Stack_Size(&Stack1,&Value);
        Ret = Stack_Top (&Stack1,&Value);
        Ret = Stack_Pop (&Stack1,&Value);

        Ret = Stack_Display(&Stack1);
        Ret = Stack_Size(&Stack1,&Value);
        Ret = Stack_Top (&Stack1,&Value);
        Ret = Stack_Pop (&Stack1,&Value);
    }

    Ret = Stack_inti(&Stack2);
    if (R_NOK==Ret)
    {
        printf("Stack2 failed to be initialized !! \n");
    }
    else{}


    return 0;
}
