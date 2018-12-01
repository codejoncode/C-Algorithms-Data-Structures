#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Author Jonathan Jamel Holloway 
Purpose: To implement a stack structure based off the ideas in the readme.
Using a node structure instead of an array. Also implementing Push pop and check for empty functions.

*/

struct stack_node {
    int value;
    struct stack_node * next; 
};

typedef struct stack_node stack_node; 

struct stack {
    int capacity; 
    stack_node * head; 
};

typedef struct stack stack; 

stack * create_stack() {
    stack * s = (stack *) malloc(sizeof(stack));
    //allocated the required memory for a stack
    s->capacity = 0; 
    s->head = NULL; 
    return s; 
}

bool stack_is_empty(stack * s){
    return s->capacity == 0; 
}

void push_to_stack(stack * s, int value){
    //create the new node.
    stack_node *n = (stack_node *) malloc(sizeof(stack_node)); 
    //allocated the required memory for a stack_node.  
    n->value = value; 
    n->next = s->head;
    //Since the new node will be come the head it's next is the current head. 
     
    s->head = n;  
    //set the head to be the new node. 
    s->capacity++; 
    //increase capacity
}

int pop_from_stack (stack *s){
    //grab the value
    int value = s->head->value; 
    //get the address of the head so we can free / delete later. 
    stack_node *popped_node = s->head; 
    //set the next value to be the head 
    s->head = s->head->next; 
    //delete the node 
    free(popped_node);
    //decrement the capacity
    s->capacity--; 

    return value; 
    
    
}

int main(void) {

    stack * s = create_stack(); 

    push_to_stack(s, 5); 
    push_to_stack(s, 9);
    push_to_stack(s, 4);

    while(!stack_is_empty(s)){
        printf("%d\n", pop_from_stack(s));
    }

    free(s);
    return 0; 
}