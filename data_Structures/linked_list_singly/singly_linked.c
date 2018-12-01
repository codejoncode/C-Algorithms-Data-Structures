#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct list_node 
{
    int value; 
    struct list_node * next; 
}; 
typedef struct list_node  list_node; 

struct list {
    struct list_node * head; 
    int size; 
}; 
typedef struct list  list; 

list * create_list() 
{
    list * l = (list *) malloc(sizeof(list)); 
    //^allocate the memory 
    l->head = NULL; 
    //^because the list starts off empty
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
    //allocate the memory 
    ln->value = value; 
    //fill value
    ln->next = l->head; 
    //fill the next with the list head 
    l->head = ln; 
    //make the list head = newly created node. 
    l->size++; 
}

int remove_from_front_list(list * l)
{
    if (list_is_empty(l)){
        printf("Error cannot remove from a empty list\n");
        return 0; 
    }
    int value = l->head->value; 
    list_node *removing = l->head; 
    l->head = l->head->next; 
    free(removing);
    l->size--;
    return value; 
}

void add_to_back_list(list * l, int value)
{
    list_node * ln = (list_node *) malloc(sizeof(list_node));
    //allocate the memory 
    ln->value = value; 
    //fill value 
    ln->next = NULL; 
    //set NULL
    
    list_node * temp = l->head; 
    //create temp

    while( temp != NULL && temp->next != NULL){
        temp = temp->next; 
    }
    //traverse the list 
    //TEMP == NULL  is pretty much a check for if the list is empty so the while loop will never trigger. 

    //set next to new node 
    if(temp == NULL){
        l->head = ln; 
    }
    else {
        temp->next = ln; 
        l->size++; 
    }
}

int remove_from_back_list(list * l)
{
    if(list_is_empty(l)){
        printf("ERROR: Cannot remove from a empty list\n");
        return 0; 
    }
    int value;
    if(l->size == 1){
        value = l->head->value; 
        free(l->head);
        l->head = NULL; 
        l->size--;
        return value; 
    }

    list_node * temp = l->head; 

    while(temp->next->next != NULL){
        temp = temp->next; 
    }
    //notice the difference in the while loop we have already checked if the list is empty 
    //also notice we want to check if the next next is null.  This is becasue we don't have a previous part of our struct. 
    ///So we can't go to the last node without doing what we need to do for everything. 
    value = temp->next->value; 
    free(temp->next);
    temp->next = NULL; 
    l->size--; //I forgot this and ended up not getting the last element and a segmentation fault. Very important. 
    return value; 
    //Now if you take a look at this  had we moved to the end with our while loop we could get the value and we could free
    //however we wouldn't be able to perform line 113  where we set the next to NULL. Without doing this after our free 
    //the results of temp->next would vary thus make it hard for us to perform these similar actions later since we are using 
    // next->next-> != NULL   if the end of our list is a value other than NULL  we may run into a infinte loop. 

}

int main() 
{
    list * l = create_list(); 
    add_to_front_list(l, 56);
    add_to_front_list(l, 78);
    add_to_front_list(l, 43); 
    add_to_back_list(l, 112);
    add_to_back_list(l, 215); 

    while (!list_is_empty(l)){
        printf("%d\n", remove_from_back_list(l)); 
    }
    //should return 215 112 56 78 43    because we add to the front  56   then   78 56  then 43 78 56 then we add to the back 
    // 43 78 56 112   215  
    //we will then pop from the back   215  112  56 78 43. 
    free(l);  // free the list    free of the nodes is taken care of when we remove.
    return 0; 
}