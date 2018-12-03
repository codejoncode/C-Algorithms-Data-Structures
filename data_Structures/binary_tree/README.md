Binary Tree 
This data structure will solve a lot of problems.  There are a bunch of nodes connected.   Very popular algorithms use binary tree data structures. 
I created a  Binary tree Diagram.png file.   It showcases a binary tree how there is a left side and a right side.  You will also see that I have created levels this is not important in implementing a search tree however when you start to use breadth-first search algorithms and depth-first algorithms the levels become essential. This is why I included it before we implement the binary tree.   
Now, in general, the first element becomes the parent.   Everything less than the parent goes to the left and everything greater than the parent goes to the right.  When we think about searching for something we can perform a conditional check that will cut the list in half.   If we continue this conditional check on the next parent node we can again cut it in half.  

The parent or top (parent)  is level 0.  level 1  has two children of the top parent. Each one of these nodes can become parents.   The rules are the same.  if an element is greater than the parent, it goes to the right.  If the element is less than its parent, it goes left. So each time we go down we can cut the items we have to search in half.    Imagine a binary tree with 1000 items now it won't cut in half precisely because there can be  400 items on the left and 600 on the right.  However, the first check for an item starts with if item <  parent go left else if an item is greater than parent goes right.    Now we will take the parent and go right if the item is greater and perform the same conditional. Until we arrive to a check for our node with the value we desire.  Binary tree's are used for many types of problems to search for the quickest way to get to a particular node and the path it has to travel.   We will implement a simple binary tree but consider the fact there is a 1000 ways to do something you can always create it differently.   In this implementation, we will have a left and a right the only thing that makes this different than a doubly linked list is now we are deciding how to place our node in the "list" instead of just choosing front or back.   We are comparing the parent and putting the item in place based on the rules less than goes left and higher than goes right. 

To implement this our struct will have a left and right value for sure. We could have a parent value, and we could also have other parameters such as weight or color, etc. We will go into this more on different data structures and algorithms.  But keep it in mine as the implementation serves many purposes.   One example before going into how to implement is weight,  I may use weight, and it would serve the purpose of holding time.  Let's say I have a program that helps show the quickest route to get to a place.  The value parameter in the struct may contain the address however the weight would hold the miles from the parent or the time from the parent. So as I traverse the list, I would add up the time to figure out what is the quickest path. Consider the color,  well bust routes train routes normally associate each path with a color.   So I could write a program based on the path color.   In the picture, I presented there is only black lines, and in reality, your path won't have a color, but we can provide one as a parameter in the struct.  You have to consider what your exact needs are as you implement the binary tree because they will vary depending on what you need to do and what purpose your tree serves. When you're trying to figure out how to solve a problem, consider what parameters or available for each node and what use they serve.  I failed a sprint question I had to take at Lambda School-based off the structure of the tree was different than I had seen.   So this is why I stress this in this section before implementing. I cannot blame Lambda instructions specifically because it is impossible to go over every exact way to achieve a binary tree.  Also, consider the value could be an address,  a number a string you might even have the colors or another parameter order in an array and you access indexs the list, and use cases go on and on.   Now on to implementation. 


We will have three properties for the node struct
left 
value 
right 
When setting up a new node left, and right will be NULL.  This will be similar to the doubly linked list when we set everything up. 

8  will be are first element and we will make it the parent and set its left and right to be null. 

now let's add 3  
3  is created with a left and right of null however to add 3  we need to set  8's left to be the new node with value 3 this is because 3 is less than 8.  Let's say we add in 2.    We would continue to go left only this time because a value is set we need to do a comparison on that node which is the node with the value of 3.    We would go left and make the node with value three left  = newly created node of 2.    I did this because we would perform these checks and go left or right based on the rules no matter what.   Now consider adding 73.   We would go right of 8 and set the parent node right to a new node with value 73.     Let's go ahead and add in  28.   We would now go right of 8  which holds the value 73  and do a check which would result in going left. None stop we continue these checks and following the instructions. We only add in once we reach a null spot.   When we have to go left if parent.left == NULL   we set if it's not we do another check.  We are going to have to use temp values so we can traverse and we are going to need to implement loops.   

Elements that already exist will not get added.  
tree_node  will have left child right child and value the tree data struct will have a root and a size.   
The root is the top parent, which does not have a parent but has children.  We will also include size in the tree struct. 

Now my sons are  10 9 7 and 4.  They saw me as I was created this and asked "dad what's that I explained it to them then the next day asked them to tell to me what it was.   My 7-year-old called the root node (top of the tree) the adult.   I thought this was cool as I didn't explain that everything underneath it were children. I called it the parent.  But every node underneath a parent is a child node.   leftchild rightchild are naming conventions you can call it anything you want. 



Pseudo code for printing the Tree: 
we are going to perform this recursively (though there are multiple ways to implement this. usually if you can do it recursively you can also create a way to do the same job using a while loop.)

print_tree(root)  our function will take the root of the tree as a parameter. 
if  root == null   return   nothing to print . 
we then want to call the print_tree function on the left child of the root followed by calling the print_tree function on the right child of the root.  This may not make much sense at this point however we are going to be breaking out using the return statement if root == null.  Remember root is just a tree node. So if there is nothing to the left nothing happens and same with the right. 
Inbetween the calls to the left and right children we will print out the value of the current root.   printf("%d",  root->value); 

The order will go as far left as possible and then if there is a right it prints out.  This method of printing will be similar to a depth-first search. 
