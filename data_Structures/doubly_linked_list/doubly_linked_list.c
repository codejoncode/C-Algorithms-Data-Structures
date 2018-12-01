#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct list_node 
{
    int value; 
    struct list_node * next; 
    struct list_node * previous; 
}; 
typedef struct list_node  list_node; 

struct list {
    struct list_node * head; 
    struct list_node * tail; 
    int size; 
}; 
typedef struct list  list; 

list * create_list() 
{
    list * l = (list *) malloc(sizeof(list)); 
    l->head = NULL; 
    l->tail = NULL; 
    l->size = 0; 
    return l; 
}

bool list_is_empty (list * l)
{
    return l->size == 0; 
}

void add_to_front_list(list * l, int value)
{
    list_node * ln = (list_node *) malloc(sizeof(list_node)); 
    ln->value = value; 
    ln->previous = NULL; 
    //no matter what the steps above will happen no matter if the list is empty or not. 
    if(list_is_empty(l)){ 
        ln->next = NULL;
        l->head = ln; 
        l->tail = ln;  
    } else {
        ln->next = l->head; 
        l->head->previous = ln; 
        l->head = ln; 
    }
    l->size++; //this step happens no matter what but we can't increment before the check if if the list is empty. 
    
}

int remove_from_front_list(list * l)
{
    if (list_is_empty(l)){
        printf("Error cannot remove from a empty list\n");
        return 0; 
    }
    int value = l->head->value; 

    if(l->size == 1){
        l->size--; 
        l->head = NULL;
        free(l->head);
        l->tail = NULL; 
        return value;
    }
    list_node *removing = l->head; 
    l->head = l->head->next; 
    l->head->previous = NULL; //different from the single linked list. 
    free(removing);
    l->size--;
    return value; 
}

void add_to_back_list(list * l, int value)
{
    list_node * ln = (list_node *) malloc(sizeof(list_node)); 
    ln->value = value; 
    ln->next = NULL; 
    //no matter what the steps above will happen no matter if the list is empty or not. 
    if(list_is_empty(l)){ 
        ln->previous = NULL;
        l->head = ln; 
        l->tail = ln;  
    } else {
        ln->previous = l->tail; 
        l->tail->next = ln; 
        l->tail = ln; 
    }
    l->size++; //this step happens no matter what but we can't increment before the check if if the list is empty.
}

int remove_from_back_list(list * l)
{
    if(list_is_empty(l)){
        printf("ERROR: Cannot remove from a empty list\n");
        return 0; 
    }
    int value = l->tail->value; 
    if(l->size == 1){
        value = l->head->value; 
        free(l->head);
        l->head = NULL;
        l->tail = NULL; 
        l->size--;
        return value; 
    }
    list_node * ln = l->tail; 
    l->tail = l->tail->previous; 
    l->tail->next = NULL; 
    free(ln); 
    l->size--; 
    return value; 
    
}

int main() 
{
    list * l = create_list(); 
    add_to_front_list(l, 56);
    add_to_front_list(l, 78);
    add_to_front_list(l, 43); 
    add_to_back_list(l, 112);
    add_to_back_list(l, 215); 

    printf("Here is the head %d \n", l->head->value);
    printf("Here is the tail %d \n", l->tail->value); 

    while (!list_is_empty(l)){
        printf("%d\n", remove_from_back_list(l)); 
    }
    
    free(l); // good practice to free removing  will free the indiviudal nodes  this frees the malloc for the list. 

    return 0; 
}