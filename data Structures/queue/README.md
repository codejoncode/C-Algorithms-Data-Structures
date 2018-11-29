The purpose of this file is to go over the queue data structure, creating an overview and pseudo code to help obtain a picture of how to implement the queue. 

A queue data structure is first in first out. Queues usually described as a line for entering an establishment.  Movies, restaurant, amusement park etc. the first person to join the line is the first person to leave to exit.  

Add  3 9 0 9 17    When we remove in the same order as we added to the list.
Queues are virtually the complete opposite of a stack data structure.   

To implement this data structure, we will be doing so dynamically meaning we are going to use pointers. So we will create nodes, and that will feature value and a next node.   

struct queue_node  
{
int value;  
struct queue_node * next; 
}

The queue structure will have a  front back and capacity(or size). 

The functions that will allow us to add and remove from the queue are as follows: 

First, we have to declare a queue. 

We will have to allocate the queue. We will set front to NULL back to NULL, and the capacity will be 0; 

There will be a need to check if the queue is empty.  
We can check if the capacity or size is equal to zero to determine if the queue is empty. 

Different from the stack we are dealing with two pointers.   We are going to have to declare a new queue_node and copy the queue_node value and next will be NULL to begin.  

Next, we will connect the new queue node to the queue data structure. 
To begin the front and back will be set to the same node because the queue starts empty.  For this reason we  and because we will also remove items from the queue we will have to check if the queue is empty before we add to the queue structure. 

take 5, 6  
we add five by first creating a queue_node  where the q front and q back is set to the new q node which will have a  value of 5 and a next of NULL. 
To add the 6  we will check if the queue is empty if it is empty we can do what we did for the 5 however it won't be.   So we create a new node.  where the value is 6 and its next is set to NULL.    The front of the queue remains the same however the back of the node is the new node. It will be every new node that is added.  we will make the back next point to the newly created node which 5  has a  next of NULL. Now it will have a next of a node with the value of 6 creating a linked line. 

Recap for adding an item to the queue. 
1. create the node  
2. set the value  
3. current back next is set to the new node 
4. queue back set to the new node. 
This should really make sense as if you are getting in line and people are in front of you, the person directly in front of you who was at the end of the line is now one spot up. Once that person is attended to, you are next, the new back of the line. 

Removing an element from the queue would work like this.  

We are removing the front, so we will need to set the front-next to equal the front. Before doing this, we would want to grab the initial value. Because we have a dynamic queue, we will have to free the node we are popping. We will also catch the address of the node we are popping.  We will have to decrement the capacity as well. 

Recap removing from the queue 
1. grab the value and set it to a variable. 
2. grab the address of the front node. 
3. set the front next to the front. 
4. free the popped node.
5. decrement capacity. 
6. return the value. 











