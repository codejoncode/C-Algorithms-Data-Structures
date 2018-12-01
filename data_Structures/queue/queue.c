#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct queue_node {
    int value; 
    struct queue_node *next; 
};

typedef struct queue_node queue_node; 

struct queue {
    queue_node * front; 
    queue_node * back; 
    int capacity; 
};

typedef struct queue queue; 

queue * create_queue() {
    //allocate memory for the queue 
    queue * q = (queue *) malloc (sizeof(queue)); 
    q->back = NULL; 
    q->front = NULL; 
    q->capacity = 0; 
    return q; 
}

bool queue_is_empty (queue * q){
    return q->capacity == 0; 
}

void add_to_queue(queue *q, int value){
    //allocate memory for the new_node
    queue_node * new_node = (queue_node *) malloc(sizeof(queue_node));
    //set next to null
    new_node->next = NULL; 
    //set new_node's value 
    new_node->value = value; 

    //check if the queue is empty 
    if(queue_is_empty(q)){
        //set front and back to the new node. 
        q->front = new_node; 
        q->back = new_node;


    } else {
        //set the current back next to the new node 
        q->back->next = new_node;
        //set the back to the new node
        q->back = new_node; 
    }

    q->capacity++;
}

int pop_from_queue(queue *q){

    if(queue_is_empty(q)){
        printf("Error, Queue is empty!!");
        return 0; 
    }
    //grab value 
    int value = q->front->value; 
    //grab address of the node to pop
    queue_node * popped_node = q->front; 
    //set the current front next to the front
    q->front = q->front->next; 
    //delete the popped node
    free(popped_node);
    //decrement the capacity 
    q->capacity--;
    //return the value  
    return value;
}

int main(){

    queue * q = create_queue(); 
    add_to_queue(q, 26);
    add_to_queue(q, 34);
    add_to_queue(q, 123);

    while (!queue_is_empty(q)){
      printf("%d\n", pop_from_queue(q));
    }

    free(q); 
    return 0; 
}