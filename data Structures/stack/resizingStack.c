#include <stdio.h>
#include <stdlib.h>
/*Stack data structure.  This stack will resize once it reaches capacity using realloc and doubling its size. */
// Struct representing a Stack that holds an integer representing the 
// the index of the top of the stack, the total capacity that the stack
// can hold, and a pointer to an array of integers

typedef struct Stack {
  int top;
  unsigned int capacity;
  int* data;
} Stack;
 
// Function to create a stack of given capacity. It initializes size of
// stack as 0
Stack* createStack(unsigned int capacity)
{
  Stack* stack = malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->data = malloc(capacity * sizeof(int));
  
  return stack;
}

int isFull(Stack* stack)
{
  if (stack->top == stack->capacity - 1){
    return 1; 
  }
  
  return 0; 
  
}
 
int isEmpty(Stack* stack)
{
  if (stack->top == -1){
    return 1; 
  } else {
    return 0; 
  }
}

void push(Stack* stack, int item)
{
  if (isFull(stack)) {
    stack->capacity = stack->capacity *2; 
    stack->data = realloc(stack->data, stack->capacity * sizeof(int));
  }
  
  stack->data[++stack->top] = item; 
   
}
 
int pop(Stack* stack)
{
  if (isEmpty(stack)){
    return -1; 
  } else {
    return stack->data[stack->top--];
  }
}

// Program to test above functions
int main()
{
  Stack* stack = createStack(2);
  
  printf("stack is full: %d\n", isFull(stack));
  printf("stack is empty: %d\n", isEmpty(stack));
  
  push(stack, 10);
  printf("stack is empty: %d\n", isEmpty(stack));
  push(stack, 20);
  
  printf("stack is full: %d\n", isFull(stack));
  
  printf("%d popped from stack\n", pop(stack));
  printf("%d popped from stack\n", pop(stack));
  printf("%d popped from stack\n", pop(stack));
  
	const int push_count = 100000;

	printf("pushing %d things\n", push_count);
	for (int i = 0; i < push_count; i++) {
		push(stack, i);
	}

	printf("popping %d things\n", push_count);
	for (int i = push_count - 1; i >= 0; i--) {
		int v = pop(stack);

		if (v != i) {
			printf("Popped %d but expected %d\n", v, i);
		}
	}

  return 0;
}