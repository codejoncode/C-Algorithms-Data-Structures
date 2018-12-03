#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct edge_node 
{
    int value; //number of node we are connected to. 
    int weight; 
    struct edge_node * next; //next node we are connected to. 
};
typedef struct edge_node edge_node; 

struct graph 
{
    edge_node * * edges;  //Dynamic sizing  array of pointers. 
    //could have done this edge_node * edges[100]; however this says we will always have 100 could be a problem if we don't or need more. 
    int number_of_nodes; 
    int number_of_edges; 
    bool directed; 
};
typedef struct graph graph; 

graph * create_graph(int number_of_nodes,  bool directed)
{
    graph * g = (graph *) malloc(sizeof(graph));
    g->number_of_nodes = number_of_nodes;
    g->number_of_edges = 0; 
    g->directed = directed; 
    g->edges = (edge_node **) malloc(sizeof(graph *) * number_of_nodes); 
    //allocated pointer array multipled by the number of nodes.  

    for(int i = 0; i < g->number_of_nodes; i++){
        g->edges[i] = NULL; 
    }
    return g; 

}

void print_graph (graph * g) 
{ 
    //every noded in list. 
    for(int i = 0; i < g->number_of_nodes; i++){
        printf("%d ---> ", i);
        //print all nodes connected to i 
        edge_node * e = g->edges[i];

        while(e != NULL){
            printf("%d ", e->value); 
            e = e->next; 
        }
        printf("\n");
        //the reason why we didn't use the new line instruction when printing the value is if the nodes are connected 
        //we want them on the same line for visibility. 
    }
}

//conect  connect to nodes and   add in weight  

void graph_add_edge (graph * g, int index, int value, int weight)
{
    edge_node * e = (edge_node *) malloc(sizeof(edge_node)); 
    e->value = value; 
    e->weight = weight;
    e->next = g->edges[index]; 
    g->edges[index] = e; 
    if(!g->directed){
        //if the graph is not directed. 
        edge_node * ee = (edge_node *) malloc(sizeof(edge_node)); 
        ee->value = index; 
        ee->weight = weight; 
        ee->next = g->edges[value]; 
        g->edges[value] = ee; 
    }
    g->number_of_edges++; 
}



int main () 
{
    graph * g = create_graph(6, true); // 6 nodes  0-5 and directed true 
    graph_add_edge(g, 2,4, 1); //create a node  of 2 connect to the 4th index  with weight of 1. 
    graph_add_edge(g, 2,5,1);
    print_graph(g); 

    //we should see that there are several nodes not connected to anything.
    // 0 --->
    // 1 --->
    // 2 ---> 5 4
    // 3 --->
    // 4 --->
    // 5 ---> 
    //above is our graph with the only 2 having a 4 and 5 the other indexs are empty.  If the graph is directed. 
    printf("\n");
    graph * gg = create_graph(6, false); // 6 nodes  0-5 and directed true 
    graph_add_edge(gg, 2,4, 1); //create a node  of 2 connect to the 4th index  with weight of 1. 
    graph_add_edge(gg, 2,5,1);
    print_graph(gg); 

    // 0 --->
    // 1 --->
    // 2 ---> 5 4
    // 3 --->
    // 4 ---> 2
    // 5 ---> 2

    //above is if the graph is not directed thus if you are at  one edge you can get to the eges that are connected.  

    return 0; 
}