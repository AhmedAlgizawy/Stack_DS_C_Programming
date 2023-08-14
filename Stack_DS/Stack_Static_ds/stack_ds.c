#include "stack_ds.h"

/**
  * @brief  Check stack is full
  * @param  My_Stack pointer to the stack
  * @retval Status of the stack
  */
static stack_status_t Stack_full(stack_ds_t *My_Stack)
{
    if (My_Stack->Stack_Pointer == (STACK_MAX_SIZE-1) )
        return Stack_Full ;
    else
        return Stack_Not_Full ;
}

/**
  * @brief  Check stack is empty
  * @param  My_Stack pointer to the stack
  * @retval Status of the stack
  */
static stack_status_t Stack_empty (stack_ds_t *My_Stack)
{
    if (My_Stack->Stack_Pointer == -1 )
        return Stack_Empty ;
    else
        return Stack_Not_Full ;
}

/**
  * @brief  initialize the stack pointer
  * @param  My_Stack pointer to the stack
  * @retval Status of initialization process
  */
ret_status_t Stack_inti(stack_ds_t *My_Stack)
{
    ret_status_t ret = R_NOK ;
    if (NULL==My_Stack)
    {
        ret=R_NOK;
    }
    else
    {
        My_Stack->Stack_Pointer = -1;
        ret=R_OK;
    }

    return ret;
}

/**
  * @brief  Push Value to the stack
  * @param  My_Stack pointer to the stack
  * @param  Val will be push to the stak
  * @retval Status of push to stack process
  */
ret_status_t Stack_Push (stack_ds_t *My_Stack, uint32_t  Val)
{
    ret_status_t ret = R_NOK ;
    if ( (NULL == My_Stack)||(Stack_Full == Stack_full(My_Stack)) )
    {
        printf("Error !! => Can't push (%i) \n",Val);
        ret=R_NOK ;
    }
    else
    {
        My_Stack->Stack_Pointer++;
        My_Stack->Stack_Arr[My_Stack->Stack_Pointer] = Val ;
        printf("Value (%i) pushed to the stack. \n",Val);
        ret=R_OK;
    }

    return ret ;
}

/**
  * @brief  Pop Value from the stack
  * @param  My_Stack pointer to the stack
  * @param  Val pointer to the value will be pop
  * @retval Status of pop to stack process
  */
ret_status_t Stack_Pop  (stack_ds_t *My_Stack, uint32_t *Val)
{
     ret_status_t ret = R_NOK ;
    if ( (NULL == My_Stack)||(NULL == Val)||(Stack_Empty == Stack_empty(My_Stack)) )
    {
        printf("Error !! => Can't pop \n");
        ret=R_NOK ;
    }
    else
    {
        *Val = My_Stack->Stack_Arr[My_Stack->Stack_Pointer];
        My_Stack->Stack_Pointer--;
        printf("Value (%i) popped from the stack. \n",*Val);
        ret=R_OK ;
    }
    return ret ;
}

/**
  * @brief  Display the top data of the stack
  * @param  My_Stack pointer to the stack
  * @param  Val pointer to the value will Display
  * @retval Status of Stack_Top process
  */
ret_status_t Stack_Top  (stack_ds_t *My_Stack, uint32_t *Val)
{
    ret_status_t ret = R_NOK ;
    if ( (NULL == My_Stack)||(NULL == Val)||(Stack_Empty == Stack_empty(My_Stack)) )
    {
        printf("Error !! => Can't display the top. \n");
        ret=R_NOK ;
    }
    else
    {
        *Val = My_Stack->Stack_Arr[My_Stack->Stack_Pointer];
        printf("Value (%i) is the top stack. \n",*Val);
        ret=R_OK ;
    }
    return ret ;
}

/**
  * @brief  Display the size of the stack
  * @param  My_Stack pointer to the stack
  * @param  Val pointer to the value of size will Display
  * @retval Status of Stack_Size process
  */
ret_status_t Stack_Size (stack_ds_t *My_Stack, uint32_t *Stack_Size)
{
    ret_status_t ret = R_NOK ;
    if ( (NULL == My_Stack)||(NULL == Stack_Size) )
    {
        printf("Error !! => Can't display the Size. \n");
        ret=R_NOK ;
    }
    else
    {
        *Stack_Size = My_Stack->Stack_Pointer + 1;
        printf("Size of stack = (%i). \n",*Stack_Size);
        ret=R_OK ;
    }
    return ret ;
}

/**
  * @brief  Display the element of the stack
  * @param  My_Stack pointer to the stack
  * @retval Status of display process
  */
ret_status_t Stack_Display (stack_ds_t *My_Stack)
{
    ret_status_t ret = R_NOK ;
    sint32_t Temp  = My_Stack->Stack_Pointer + 1;

    if ((NULL==My_Stack) ||(Stack_Empty == Stack_empty(My_Stack)))
    {
        printf("Error !! => Can't display the element of stack. \n");
        ret=R_NOK;
    }
    else
    {
        printf("Stack Elements : \n");
        while (Temp--)
        {
            printf("(%i) \t",(My_Stack->Stack_Arr[Temp]));
        }
        printf ("\n******************\n");
        ret=R_OK;
    }
    return ret ;
}
