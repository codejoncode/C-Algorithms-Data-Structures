Doubly Linked Lists  : 

A doubly linked list is a list that features list nodes.  Each list_node has a next pointer and a previous pointer and a value.    Similar to the linked list only doubly linked lists features a previous pointer which can help with certain aspects of traversing the list. 

NULL<---[previous, value next] ---> <---[previous, value next] ---> <---[previous, value next] ---> 

The list structure will feature a head and tail and size.   The idea behind the doubly linked list is to help make functions faster.  This was discussed in the singly linked list readme.   

list   = [head, tail, size] 

[ previous = null,   value = 5,  next --->,     <--previous, value 8, next --->   NULL] 

Here the node with the value 5   is the head and the node with the value 8 is the tail.  This allows us to add to the front in constant time and add to the back in constant time.  

Adding to the front is similar to adding to the front in the singly linked list same with the back. We just have to change now the tail similar to how we have to adjust the head.  

The steps involve adding the previous node and tail node to the structs from the singly linked list.   We will also have to set tail to NULL just as we do when we create the list and initialize the head. 

pushing to the front we have to check whether the list is empty this would let us know if we have to set the tail. The first element added will be the head and the tail. 
Newly created nodes for an empty list will have a next and previous = NULL. 

if there is something in the list adding to the front  would involve: 
setting the newly created node next to the head then setting the newly created node previous to NULL   and then setting the list head to the newly created node.  

(Note this process is similar to adding to the back only it involves the tail.    You would also flip-flop the next and previous instructions. To help remember this the head of the list will have a previous of NULL. The tail of a list will have a next of NULL.  Now there are some cases where you may need to connect the doubly linked list circularly. This would involve setting the tail next to the head and the head previous to the tail. I will not implement this but this is a possibility and there may come a time where you need to have everything linked together. ) 

Basically, we care about two directions which is what makes it a doubly linked list.  We care about the top of the list and the bottom and we care about what's left and what's right for the node. 

Removing elements from the back and front: Checking if the list is empty remains the same.  We cannot remove what doesn't exist.  

Due to the previous, we would need to make the head next  previous to = null
head,  next node  
remove the head    
next node previous is now null (IT WAS the head).     head <<< next node = previous,  value next >> another node or NULL 

We will need to check if there is only one element in the list due to the head and the tail. We will need to set head and tail to NULL.  ELSE we are just going to set the tail to be the tails previous and the tails next to equal NULL   we will also need to first create a temp node so that after setting the tail to equal the current tails previous and the new tail next to NULL we can free the old tail from memory.  
