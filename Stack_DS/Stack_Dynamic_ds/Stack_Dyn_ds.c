#include "Stack_Dyn_ds.h"

static ret_status_t StackFull (Stack_t *MyStack)
{
    if (MyStack->Stack_Count == MyStack->Stack_Size)
        return STACK_FULL ;
    else
        return STACK_NOT_FULL;

}

/***********************************************************************/
static ret_status_t Stack_Empty (Stack_t *MyStack)
{
    if (MyStack->Stack_Count == ZERO)
        return STACK_EMPTY ;
    else
        return STACK_NOT_FULL;
}

/***********************************************************************/
Stack_t *CreateStack (uint32 StackSize,ret_status_t * Status)
{
    Stack_t *MyStack = NULL ;
    if (NULL == Status)
    {
        *Status = R_NOK;
    }
    else
    {
        MyStack = (Stack_t *)malloc(sizeof(Stack_t));
        if (!MyStack)
        {
            *Status = R_NOK;
            MyStack=NULL;
        }
        else
        {
            MyStack->Stack_Count = 0 ;
            MyStack->Stack_Size = StackSize;
            MyStack->Stack_Top = -1;
            MyStack->Stack_Arr = (void *)calloc(MyStack->Stack_Size,sizeof(void *));
            if (!MyStack->Stack_Arr)
            {
                free(MyStack);
                MyStack=NULL;
                *Status = R_NOK;
            }
            else
            {
                *Status = R_OK;
            }
        }
    }
    return MyStack ;
}

/***********************************************************************/
Stack_t *DestroyStack (Stack_t *MyStack,ret_status_t * Status)
{
    if ((NULL == MyStack) || (NULL == Status))
    {
        *Status = R_NOK;
    }
    else
    {
        free(MyStack->Stack_Arr);
        free(MyStack);
        MyStack = NULL ;
        *Status = R_OK ;
    }
    return NULL ;
}

/***********************************************************************/
ret_status_t PushStack (Stack_t *MyStack, void *itemPtr)
{
    ret_status_t ret = R_NOK ;
    if ((NULL == itemPtr))
    {
        ret = R_NOK;
    }
    else
    {
        if (StackFull(MyStack) == STACK_FULL)
        {
            printf("Stack is full !! \n");
            ret = STACK_FULL;
        }
        else
        {
            (MyStack->Stack_Top)++ ;
            MyStack->Stack_Arr[MyStack->Stack_Top] = itemPtr ;
            (MyStack->Stack_Count) ++ ;
            ret = R_OK ;
        }
    }
    return ret;
}

/***********************************************************************/
void *PopStack (Stack_t *MyStack, ret_status_t *Status)
{
    void *itemPtr_Popped =NULL ;
    if ((NULL == MyStack) || (NULL == MyStack))
    {
        *Status = R_NOK ;
    }
    else
    {
        if (STACK_EMPTY == Stack_Empty(MyStack))
        {
            printf("Stack is empty !! \n");
            itemPtr_Popped=NULL;
            *Status = STACK_EMPTY;
        }
        else
        {
            itemPtr_Popped = MyStack->Stack_Arr[MyStack->Stack_Top];
            MyStack->Stack_Top--;
            MyStack->Stack_Count--;
            Status = R_OK ;
        }
    }
    return itemPtr_Popped ;
}

/***********************************************************************/
void *StackTop (Stack_t *MyStack, ret_status_t *Status)
{
    void *itemPtr_Top =NULL ;
    if ((NULL == MyStack) || (NULL == MyStack))
    {
        *Status = R_NOK ;
    }
    else
    {
        if (STACK_EMPTY == Stack_Empty(MyStack))
        {
            printf("Stack is empty !! \n");
            itemPtr_Top=NULL;
            *Status = STACK_EMPTY;
        }
        else
        {
            itemPtr_Top = MyStack->Stack_Arr[MyStack->Stack_Top];
            Status = R_OK ;
        }
    }
    return itemPtr_Top ;
}

/***********************************************************************/
ret_status_t StackCount (Stack_t *MyStack, uint32 *stack_count)
{
    ret_status_t ret = R_NOK ;
    if ((NULL == MyStack) || (NULL == stack_count))
    {
        ret = R_NOK;
    }
    else
    {
        *stack_count = MyStack->Stack_Count;
        ret = R_OK ;
    }
    return ret;
}
