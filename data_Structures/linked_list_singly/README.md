The purpose of this readme is to go over a singly linked list for better understanding before implementing a singly linked list.  Of course, there are many ways to achieve a singly linked list. 

A linked list data structure is very popular because it is very flexible. Many data structures use a linked list to implement its structure. 
A linked list is a set of nodes featuring a value and a next pointer to the next node. Sometimes you will see a previous pointer. 

[value, next]  -->  [value, next] --> [NULL, NULL]   

To achieve any value we have to traverse the list.   We can add, remove or just search for a value. 

To implement this data structure in C,  we will use a struct  list_node  

struct list_node {  int value;  struct list_node  *next; } ; 
To create a structure, we need another structure that stores the size and head of the list.  

struct list {  int size;     list_node * head;}; 

We will need a function that will create the list as well as a function that will generate the list_node when we begin to add to the list.  
Inside each function, we will use dynamic memory using the malloc function. We will also set the head of the list to NULL to start. 

Another useful function will be one that serves the purpose of checking whether or not the list is empty. 

To add an element to the list, we need to decide the position we wish to add the item.  Back, front maybe even in the middle depending on your linked list needs.  

Imagine we want to add the element from the front of the list. 

[NULL, 0] = list  

To add an element we need first to create a list node.   
Imagine adding the number 9. 
[9, NULL]   = newly_created_null   
We will then take the head and point it to the newly created node. 

If the list has some other node already in place, then our newly created node would be different.   

[some_other_node, 1] = list  
[9, some_other_node] = newly_created_null 
We would then update the head  and the size. 
[newly_created_node, 2] = list

Recap 
1. Create a list node  (allocate memory)
2  Fill in the value   
3. fill in the next  (list-head)
4. make list head = the newly created node 
5. increment size of the list. 

To test this out, we will need to remove elements from the list.  Again this is a matter of choice and you can implement many ways to remove from the list just as you can have more than one way to add to a list.  We will withdraw from the head which is pretty much like our stack data structure.  

First, we have to copy the value we want to return. We then copy the address (so that we can free it later).  Then we want to point the head to the next of the current head. Free the memory and return the value. 

1. Copy the value from l->head. 
2. create a node that takes the address of the head.
3. make head change to the next node of current head. 
4. free the node we want to delete (former top). 
5. decrement the size. 
6. return the value. 

Of course, we do not want to pop from an empty list, so we need to add a conditional before we begin our steps to make sure there is something in the list. 

Now let's explore adding an element to the back of a list. 

The last node in the list should be pointed to NULL.   

list = [head, size] 

head = [value = 22, next-->]  [value=28, next-->]   NULL.   
Illustrated above is a list with two items the first item is the head with a value of 22 which points to a node with the value of 28.   This node points to nothing. 

So that we get to the NULL spot or at least the node that points to NULL, we will have to interate through the list or a more common term traverse the list. There are issues concerned with this method of adding to the back.  Adding to the front gave us a 0(1)  constant time speed complexity.   Linear vs. constant occurs because adding to the front takes the same amount of steps each time, however, adding to the end now depends on how big the list is, which provides us with linear speed or O(n), as the list gets bigger so will the time it takes to add elements to the list.  I will implement the O(n) version, but we could provide out list structure with a tail to our structure so that we can keep the O(1) time of adding to our list.  

To traverse the list, we will start with a temporary pointer so that we can move through without affecting the list. We will call next until we cannot do so anymore, which will occur once the next is NULL. 
We will also as we did for adding to the front we will create and malloc space for our new node.   

1. create a new node (set value, set next to NULL)
2. create temp pointer 
3. traverse until we get to a node with next == to null
4.  make the last node that has no next connect to the new node. 
5. increment size. 

Now if the list is empty, we will just set the newly created node to be the list head.  

Now let's pop from the back.    Similar to the add to the back we will have to iterate until we find the last element.   We will then copy the value and free that element.  