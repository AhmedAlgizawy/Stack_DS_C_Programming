#ifndef _STACK_DYN_DS_H
#define _STACK_DYN_DS_H

#include <stdlib.h>
#include "Platform_Types.h"

typedef struct Stack_ds{
    void **Stack_Arr  ;  /* Points to the array that allocated in the heap  */
    uint32 Stack_Size ;  /* Has the maximum number of elements in the stack */
    uint32 Stack_Count;  /* Has the actual number of elements in the stack  */
    sint32 Stack_Top  ;  /* Has the index of the top element in the stack   */
}Stack_t;

typedef enum{
    R_NOK,
    R_OK,
    STACK_FULL,
    STACK_NOT_FULL,
    STACK_EMPTY
}ret_status_t;

/**
  * @brief  This algorithm creates an empty stack by allocating the head
            structure and the array from dynamic memory.
  * @param  (StackSize) Stack maximum number of elements
  * @param  (Status) Status returned while performing this operation
  * @retval Pointer to the allocated stack in the heap
  */
Stack_t *CreateStack (uint32 StackSize,ret_status_t * Status);

/**
  * @brief  This function releases all memory to the heap.
  * @param  (MyStack) pointer to stack head structure
  * @param  (Status) Status returned while performing this operation
  * @retval NULL
  */
Stack_t *DestroyStack (Stack_t *MyStack,ret_status_t * Status);
/**
  * @brief This function pushes an item onto the stack.
  * @param (MyStack) pointer to stack head structure
  * @param (itemPtr) pointer to be inserted
  * @retval status of function operation
  */
ret_status_t PushStack(Stack_t *MyStack, void *itemPtr);

/**
  * @brief This function pops the item on the top of the stack.
  * @param  (MyStack) pointer to stack head structure
  * @param  (Status) Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void *PopStack (Stack_t *MyStack, ret_status_t *Status);

/**
  * @brief  This function retrieves the data from the top of the
            stack without changing the stack.
  * @param  (MyStack) pointer to stack head structure
  * @param  (Status) Status returned while performing this operation
  * @retval Pointer to user data if successful, NULL if underflow
  */
void *StackTop (Stack_t *MyStack, ret_status_t *Status);

/**
  * @brief  Returns number of elements in stack.
  * @param  (MyStack) pointer to stack head structure
  * @param  (stack_count) number of elements in stack.
  * @retval status of function operation
  */
ret_status_t StackCount (Stack_t *MyStack, uint32 *stack_count);

#endif // _STACK_DYN_DS_H
