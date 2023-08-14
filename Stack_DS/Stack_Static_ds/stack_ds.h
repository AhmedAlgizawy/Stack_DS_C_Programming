#ifndef _STACK_DS_H
#define _STACK_DS_H

#include "Types.h"

#define STACK_MAX_SIZE  5

typedef struct stack_ds{
    sint32_t Stack_Pointer ;
    uint32_t Stack_Arr[STACK_MAX_SIZE];
}stack_ds_t;

typedef enum stack_status {
    Stack_Full,
    Stack_Empty,
    Stack_Not_Full
}stack_status_t;

/**
  * @brief  initialize the stack pointer
  * @param  My_Stack pointer to the stack
  * @retval Status of initialization process
  */
ret_status_t Stack_inti(stack_ds_t *My_Stack);

/**
  * @brief  Push Value to the stack
  * @param  My_Stack pointer to the stack
  * @param  Val will be push to the stak
  * @retval Status of push to stack process
  */
ret_status_t Stack_Push (stack_ds_t *My_Stack, uint32_t  Val);

/**
  * @brief  Pop Value from the stack
  * @param  My_Stack pointer to the stack
  * @param  Val pointer to the value will be pop
  * @retval Status of pop to stack process
  */
ret_status_t Stack_Pop  (stack_ds_t *My_Stack, uint32_t *Val);

/**
  * @brief  Display the top data of the stack
  * @param  My_Stack pointer to the stack
  * @param  Val pointer to the value will Display
  * @retval Status of Stack_Top process
  */
ret_status_t Stack_Top  (stack_ds_t *My_Stack, uint32_t *Val);

/**
  * @brief  Display the size of the stack
  * @param  My_Stack pointer to the stack
  * @param  Val pointer to the value of size will Display
  * @retval Status of Stack_Size process
  */
ret_status_t Stack_Size (stack_ds_t *My_Stack, uint32_t *Stack_Size);

/**
  * @brief  Display the element of the stack
  * @param  My_Stack pointer to the stack
  * @retval Status of display process
  */
ret_status_t Stack_Display (stack_ds_t *My_Stack);

#endif // _STACK_DS_H
