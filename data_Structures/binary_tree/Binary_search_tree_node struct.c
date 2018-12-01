#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  struct node *left; 
  struct node *right; 
  int value; 
  
} node;

node* newNode(int item)
{
  node *root = (node *) malloc(sizeof(node));
  root->left = NULL; 
  root->right = NULL; 
  root->value = item; 
  
  return root; 
}

void printInOrder(node *root)
{
  
  if(root == NULL){
    return ; 
  }
  printInOrder(root->left);
  printf("%d\t", root->value);
  printInOrder(root->right);
  
}

node* insert(node* node, int item)
{
  if (node == NULL){
    return newNode(item);
  }
  
  if (item < node->value){
    node->left = insert(node->left, item);
  }
  else {
    node->right = insert(node->right, item); 
  }
}

int main(int argc, char* argv[])
{
  node *root = NULL;
  // printf("%s", *root);
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);
  
  printInOrder(root);
  
  return 0;
}