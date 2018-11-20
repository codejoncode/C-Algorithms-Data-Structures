#include <stdio.h>

void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot] && i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}


int main(void) {
  
  int number[26] = {45,89,96,45,12,35,6,78,45,12,47,48,59,6,9,32,56,112,148,986,56,2478,17,11,19};

  int i; 
  int first = 0;  
  int last = 25 - 1; 
  quicksort(number, first, last);

  for(i = 0; i<25; i++){
    printf(" %d", number[i]); 
  }

  return 0;
}

/*
Divide and Conquer  Algorithm   
It will split the problem into sub problems. 


1. need a open spot   to place an item at the end of a list.  
2. Select the first element  as the pivot  


A = { 10,16,8,12,15,6,3,9,5 inf}

search for items   greater than pivot  
search for items   less than pivot  

Swap the items.   

partition takes low and high as paramater  

pivot = A[0]

i = low  
j = high 

while (i < j){
  do {
    i++; 
    while (A[i] <= pivot);
  }

  do {
    j--; 
  }while (a[j] > pivot); 

  if ( i < j){
    swap(A[i], A[j]);
  }
}

swap(A[L], A[j]);
return j;  
^^  partition   

QuickSort(L, H)
if (L, H) {
  j = partition (L, H); 
  QuickSort(L, H); 
  quickSort(j+1, H); 
}

to begin  


pivot = first element 
i = first element 
j = last element   

time complexity will be  n logn if we  start the pivot in the middle   best case. 

element should be the median   but if the list is not sorted we do not know what would be the median.  So achieving best case is not really possible purposely  no way to tell if you are getting the median.  

i starts at the first  and moves if it finds a greater   then it compares with j to perform a swap.       

worst case   starting at the begining or the end of the list.    
O(n^2)  

1. select middle elemnt as pivot   
2.  select Random element as pivot  

no extra space but it uses a stack   max  may be   n       best case logn   

logn to n    stack

*/