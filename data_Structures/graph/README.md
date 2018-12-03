Graph data structure.    
Graph Theory.  
Model the problem as a network.         

Take a look at the Graph Diagram I drew in this folder.   You will see circles representing nodes.  You will also notice that some nodes have lines and that have one arrow and others with two arrows (one on each end). The arrows represent the direction that the node travels. For example, a node can connect to another node either in a one-way connection or a two way.  I left a node where it cannot get to another node after you get to it.  Think about a bunch of buildings and how some buildings can be connected while others you would have to go around to get inside. Or streets some streets allow you to travel in any direction but others you can only move down one route. Some roads lead to dead ends. With graph theory connecting nodes work very similar to this. There can even be cases where you have nodes that connect to nothing at all but the node itself exists.  You consider this as a bus route in the United States that allows you to go from state to state.   Well, Hawaii cannot be reached by bus, but it does exist as a location in the United States. Graph theory presents a very well known problem  "shortest-path problem."    When you have a network type problem, you would want to implement a graph.    The circles would be the nodes the lines connecting the nodes is known as edges or arches.    A node is also called a vertice. Each edge would have a number associated with known as its weight. It could be a benefit you gain or disadvantage.   I have tried to go over this before we reach graphs since all of these data structures are similar to a linked list just a different way to set it up.  The weight can be a time to reach the node or distance traveled. It could be the cost to travel like "gas money."  Of course, you could have a weight and several other parameters depending on what you needed to keep track of as I have stated in a different readme. Any network that needs to be connected together will use graph theory. 

We will have an edge_node struct, and each edge node will have a value, a weight, a pointer to the next edge_node.   Every list will point to a bunch of edge nodes.   The array will pretty much be an array of pointers.  This is called an adjacency list so the array will have a list of all the edges.  You can also use the adjacency matrix(search for this for more information, however, a matrix is vertically arrays within arrays). 
Adjacency lists are considered to be more efficient than an adjacency matrix. 

There are two types of graphs.  Graphs that are not directed meaning if we say node A  is connected to node B then if you are at node A you can go to node B  and if you are at node B you can go to node A.    This is referred to as an undirected graph.   

Directed graphs if you can go from A to B it doesn't necessarily mean you can go from B to A. This is where we would get it into one directional and bi-directional edges.   

There is also a case where there will be unweighted graphs meaning there are no weights.  In this case, each weight would be considered 1 or equal.  When equality is not the case, then you would want to provide some weight or difference between the vertices(node). 

So we will have  an array    adjacency_list  which would represent our graph.  

It will feature pointers that point to a linked list edge. 

[
[poiner0] ->    [v,w,n]--> [v,w,n]-->[v,w,n]-> null
[poiner1] ->    [v,w,n]-->  null
[poiner2] ->    [v,w,n]--> [v,w,n]--> null
[poiner3] ->    [v,w,n]--> [v,w,n]-->[v,w,n]-> null
[poiner4] ->     null
[poiner5] ->    [v,w,n]--> [v,w,n]-->[v,w,n]-> null
[poiner6] ->    null
]
Again v = value    w = weight   n = next pointer.  
We could have pointer0 connected to 2 3 and 4  
Then one connected to some nodes and so on and so.  We can also have a node that points to nothing. 

struct of edge_node  
{
int v; 
int weight; 
struct edge_node * next; 
}

The graph will feature the number of nodes, number of edges and a variable to indicate if the graph is directed or not.   

We will need to create a function that creates a graph and returns a graph. 
We will malloc the graph and the edges array.   We will also set the number of edges to 0  to begin.   Finally, we need to set the cells to NULL which will cause for iterating using a for or while loop. 


To test that the graph has been implemented correctly we will print the graph using a function.  

Take in the argument  graph    
Then iterate through the graph so that we can print out the nodes. Similar to how we initialize with NULL. For each cell in the array, we will iterate through the next node until we reach NULL which would be the end of the list. 

Of course, we will need a function that will connect the nodes as we desire. 

We will need the graph a index int and a value int and a weight for the edge. 

We need to create an edge node. This involves malloc space for an edge node.  
We then need to fill in the properties.   e->value = value; e->weight = weight;   
We then need to add this node to the last node on the graph.   So we need to go to the index of the array on the graph check if its null? If it adds it if it isn't going to the next.   Now we will add from the front so that it will give us constant time. If we add to the end, it will give us o(n) time.   We want to be, so while you could go to the end of the connections, this would cause us to go through O(n) where n is the number of edge_nodes.   We can achieve what we desire but just setting new_edge -> next = g->edges[index]  where g->edges[index]  (index is the parameter we receive to connect to) is a pointer which satisfies our needs. 
We will then updated  g->edges[index] to be the newly created edge and also increment the  number_of_edges.  Again we are adding to the front. 
if we are adding the first edge then the newly created node will have a next of NULL.    Let us add in another to the same index will our newly created node two will have a next of our previously created node and it will become the top pointer and so on and so on. 

if the graph is not directed, we will have to connect both directions.  

The index becomes the value and the value becomes the index, and everything else is the same only done inside of the conditional for if the graph->directed = false. 

Again there are many ways to do this but I will attempt the bare minimum. 