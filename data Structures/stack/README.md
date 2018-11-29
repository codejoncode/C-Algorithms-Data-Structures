The purpose of this readme is to go over the stack data structure. Also, provide pseudo code on how to implement the stack. 

A stack is First in Last out. 

Imagine an Array 

[]

The process of adding to the array is called pushing. 

let's go ahead and push 6  7 and 8 

[6]
[6,7]
[6,7,8]

The process of removing is called pop 

Popping will take the most recently added item from the array. 

pop()  on our current array would return  8  

This would leave our array looking like this. 

[6,7]

With C programming if we have a static stack, we would have a head. 

So as we add to the stack, we would increment the head. 

Whenever we remove we decrement the head. 

[6]
the head points to 6. 

[6,7]
the head points to 7. 

[6,7,8]
the head points to 8. 

Most of us have been in a lunchroom before and have used strays. However, we may not have participated in cleaning the strays. 
I like this example because I have worked in the dish room in my college days.  The stray I cleaned first ended up on the bottom. The most recently cleaned tray was the first tray on the top thus shows the way a stack works. First In Last Out. 

Let's take the head and set it to 0 

head = -1  

to add to the stack, we would want to increment the head 

head++ 

then we place the item on the stack array  

stack[head] = whatever value we choose

stack[head] points to the recent item in the stack 
to add another  we would take 

The reason why we start at  -1 is because we can check what head is to see whether the stack is empty before we pop. 

if stack == -1   then we have not yet added anything to the stack. 

We may want to perform this check before popping. 

function  are_you_empty_stack () {
    return  head == -1 
}

if we get a truthy return, we will go ahead and pop. 

Another good use of the variable head is to check if the stack is full.   Usually, you want to make good use of memory so the head would let us know if we have reached capacity. 

Let's say we have a capacity of 12 (< indicating the total amount of space available to our stack>). 

We can now perform a function check to see if head == capacity -1  
We subtract one from the capacity because the head is also used as an index thus starts our stack at 0. 

function are_you_full_stack () {
    return head == capacity - 1
}

Now let's consider how we will group all of these variables in one place. 

There will always be a thousand different ways to do something in any programming language. However, let's examine the usage of a struct 

struct stack {
    int capacity; 
    int *arr[capacity + 1]; 
    int head; 
}

Here are the head is the current index and our capacity is the limit we place on the number of items our struct could point to. Arr would be our array.  Now I am using it for this however you would have to adjust the type based on the data you are prepared to receive. 

We will need to create the stack as our project starts  

We would also have to create our push and pop functions 

void push (stack *s; int value);
1. Check if the stack is full
2. Increment head (head++)
3.  access the  array using the head 
s->arr[s->head]
You could also do the following   s->arr[++head]  this increments the head then sets the value  Search prefix increment for more info on this. 

int pop (stack *s); 

First, notice int we are returning something. Push does not need to return. 
1. access the current head  and return  
2. decrement the head 

Now if we do something like return  s->[s->head] we won't be able to decrement because the return statement would take us out of the function.   Let's postfix decrement s->[s->head--] this uses the current head and returns but also decreases the head by 1 for later usage. Again search prefix and postfix increment and decrement for more information on this.  

Now the other function we need will set up our stack for usage. 

void  initialize_stack (stack *s, int capacity)
s->head = -1 
s->capacity = capacity 



You could also perform this where you plan to malloc the data.  


The array disadvantage is you are limited to the size of the array. You make the changes it is not very dynamic. 
Imagine making it a billion, but you only need four places.  Or vice versa.  Making use of dynamic allocation and pointers would solve this problem.  


Stack.node 
[value| @] points to another [value|@] .. until it points to NULL  this would be the last.  

stack data structure  

head points to the very first stack node the other property would be size. 

Whenever you want to add an element to the stack, the first thing we do is declare another stack node.  

stack node  
[5| points to head]

The second operation would be to change the head of the stack to point to the new stack node   

To remove an element of a stack, We have to copy the number we want to pop 
Secondly, we would have to make a copy of the address of the stack node so we can free it later.  

We would create a new pointer that obtains the address of that stack node. 

The head would point to what the previous node pointed to. 

Calling free on the node we want to delete deletes the node.  

The struct stack_node will look similar to this. 

typedef struct stack_node{
    int value; 
    struct stack_node * next; 
}stack_node; 

typedef will allow us to declare a stack_node struct without using the keyword struct  

typedef struct stack {
    stack_node *head  
    int capacity; 
}; 

You may see size used instead of capacity or top instead of the head. This is only a choice in name what they will do is the same. 






