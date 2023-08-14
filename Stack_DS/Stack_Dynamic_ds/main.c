#include <stdio.h>
#include <stdlib.h>

#include "Stack_Dyn_ds.h"

Stack_t *Stack1 = NULL ;
uint32 Stack_Size ;
void *Ptr = NULL;

uint32 Var1 = 11 ;
uint32 Var2 = 22 ;
uint32 Var3 = 33 ;

uint32 Count=ZERO;
int main()
{
    ret_status_t Ret_Status = R_NOK ;
    printf ("Stack 1 = 0x%X \n",Stack1);
    printf("Enter number of stack 1 elements : ");
    scanf("%i",&Stack_Size);

    Stack1 = CreateStack(Stack_Size,&Ret_Status);
    if (R_OK == Ret_Status)
    {
        printf ("Stack 1 is created. \n");
    }

    printf ("Stack 1 = 0x%X \n",Stack1);


    Ret_Status = PushStack(Stack1,&Var1);printf ("Return status = %i\n",Ret_Status);
    printf("Data = %i \n",*((uint32 *)Stack1->Stack_Arr[Stack1->Stack_Top]));
    Ret_Status = PushStack(Stack1,&Var2);printf ("Return status = %i\n",Ret_Status);
    printf("Data = %i \n",*((uint32 *)Stack1->Stack_Arr[Stack1->Stack_Top]));
    Ret_Status = PushStack(Stack1,&Var3);printf ("Return status = %i\n",Ret_Status);
    printf("Data = %i \n",*((uint32 *)Stack1->Stack_Arr[Stack1->Stack_Top]));
    Ret_Status = PushStack(Stack1,&Var3);printf ("Return status = %i\n",Ret_Status);
    printf("Data = %i \n",*((uint32 *)Stack1->Stack_Arr[Stack1->Stack_Top]));

    Ret_Status=StackCount(Stack1,&Count);
    printf ("Count = %i\n",Count);
    printf ("***********************************\n");

    Ptr = StackTop(Stack1,&Ret_Status);printf ("Return status = %i\n",Ret_Status);
    printf("Top Data = %i \n",*((uint32 *)Ptr));

    Ptr = PopStack(Stack1,&Ret_Status);printf ("Return status = %i\n",Ret_Status);
    printf("Popped Data = %i \n",*((uint32 *)Ptr));

    printf ("***********************************\n");

    Ret_Status=StackCount(Stack1,&Count);
    printf ("Count = %i\n=======================\n",Count);

    Ptr = StackTop(Stack1,&Ret_Status);printf ("Return status = %i\n",Ret_Status);
    printf("Top Data = %i \n",*((uint32 *)Ptr));

    Ptr = PopStack(Stack1,&Ret_Status);printf ("Return status = %i\n",Ret_Status);
    printf("Popped Data = %i \n",*((uint32 *)Ptr));

    printf ("***********************************\n");

    Ptr = StackTop(Stack1,&Ret_Status);printf ("Return status = %i\n",Ret_Status);
    printf("Top Data = %i \n",*((uint32 *)Ptr));

    Ptr = PopStack(Stack1,&Ret_Status);printf ("Return status = %i\n",Ret_Status);
    printf("Popped Data = %i \n",*((uint32 *)Ptr));

    printf ("***********************************\n");

    Ptr = StackTop(Stack1,&Ret_Status);printf ("Return status = %i\n",Ret_Status);
    //printf("Top Data = %i \n",*((uint32 *)Ptr));

    Ptr = PopStack(Stack1,&Ret_Status);printf ("Return status = %i\n",Ret_Status);
    //printf("Popped Data = %i \n",*((uint32 *)Ptr));

    printf ("***********************************\n");

    Ret_Status=StackCount(Stack1,&Count);
    printf ("Count = %i\n=======================\n",Count);

    Stack1 = DestroyStack (Stack1,&Ret_Status);
    if (R_OK == Ret_Status)
    {
        printf ("Stack 1 is destroyed. \n");
    }

    printf ("Stack 1 = 0x%X \n",Stack1);

    return 0;
}
