/*
https://www.hackerrank.com/challenges/sorting-array-of-strings/problem
This problem is from hackerank challenge.  

Author Jonathan Jamel Holloway  

Challenge:  

To sort a given array of strings into lexicographically increasing order or into an order in which the string with the lowest length appears first, a sorting function with a flag indicating the type of comparison strategy can be written.  The disadvantage with doing so is having to rewrite the function for every new comparison strategy.  

A better implementation would be to write a sorting function that accepts a pointer to the function that compares each pair of strings. Doing this will mean only passing a pointer to the sorting function with every new comparison strategy.  

Given an array of strings, you need to implement a string_sort function which sorts according to a comparision function, i.e, you need to implement the function: 

void string_sort(const char **arr, const int cnt, int (*cmp_func) (const char* b)){

}

the arguments passed to this function are:  
an array of strings: arr 
length of string array: count 
pointer to the string comparison function: cmp_func  

You also need to implement  the following four string comparision functions: 

int lexicographic_sort(char*, char*) to sort the strings in lexicographically non-decreasing order. 

int lexicographic_sort_reverse(char*, char*) to sort the strings in lexicographically non-increasing order. 

int sort_by_number_of_distinct_characters(char*, char*) to sort the strings in non-decreasing order of the number of distinct characters present in them. If two strings have the same number of distinct characters present in them, then the lexicographically smaller string should appear first. 

int sort_by_length(char*, char*) to sort the strings in non-decreasing order of their lengths. If two strings have the same length, then the lexicographically smaller string should appear first. 


You have to write your own sorting function and you cannot use the inbuilt qsort function 

the strings consists of lower-case English Alphabets only. 




*/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>



/* Function prototypes*/
int lexicographic_sort(const char* a, const char* b);
int lexicographic_sort_reverse(const char* a, const char* b);
int sort_by_number_of_distinct_characters(const char* a, const char* b);
int sort_by_length(const char* a, const char* b);
void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b));
void quicksort(char **arr, int first, int last, int (*cmp_func)(const char* a, const char* b));
/*Function prototypes*/

/*The purpose of prototypes so to allow for error checking once you declare the functions. One can use the prototypes as a way to architecture their code.  This is is useful because  later once you declare the function and create the body if the declaration return type or paramaters types  differ  it will throw an error / warning. At this time you can go back to your "blueprint" to decide if the difference  should be updated on the prototype or if you are going off of the design in a way that will not get the the solution you desire. Note the paramater names can differ from the prototypes. return type and type of paramaters must match. */

/*The purpose of const is to allow for comparison but avoid accidental changes. No need to change the paramaters only need to be seen/ compared. */

int main(void) {
  
  char **arr;
  //malloc enough room to hold variable. 
  arr = (char**) malloc(4 * sizeof(char*));

  // arr = {"wkue", "qoi", "sbv", "fekls"}; 
  //malloc enough space to hold strings in variable 
  char one [] = "wkue"; 
  char two [] = "qoi";
  char three [] = "sbv";
  char four[] = "fekls";  
  for(int i = 0; i<4; i++){
    arr[i] = malloc(1024 * sizeof(char));
    //this only provides enough space to get the max length string.
    // printf("Enter the string to add: \n"); 
    // scanf("%s", arr[i]);
    switch(i){//just to test without entering data in. 
      case 0: 
        arr[i] = one; 
        break; 
      case 1:
        arr[i] = two; 
        break; 
      case 2:
        arr[i] = three; 
        break; 
      case 3:
        arr[i] = four;
        break; 
    }
    // arr[i] = realloc(arr[i], strlen(arr[i])+1);
    //once we recieve the value we can modify the size to fit exactly what we need. 
  }

  string_sort(arr, 4, lexicographic_sort); 
  

  for(int i = 0; i<4; i++){
    printf("%s\n", arr[i]); 
  }
  printf("\n");
  string_sort(arr, 4, lexicographic_sort_reverse); 
  for(int i = 0; i<4; i++){
    printf("%s\n", arr[i]); 
  }

  string_sort(arr, 4,sort_by_number_of_distinct_characters);
  printf("\n");
  for(int i = 0; i<4; i++){
    printf("%s\n", arr[i]); 
  }

  string_sort(arr, 4, sort_by_length);
  printf("\n");
  for(int i = 0; i<4; i++){
    printf("%s\n", arr[i]); 
  }

  for(int i = 0; i<4; i++){
    free(arr[i]); 
  }
  
  free(arr); 
  return 0;
}

int lexicographic_sort(const char* a, const char* b) {
  return strcmp(a, b);
  
  //Since  0 is falsy I am returning 0  if the item is not less than or equal  -1 if it is and 1 if it is greater. 
  
}

int lexicographic_sort_reverse(const char* a, const char* b) {
  /*Think of this as  reverse alphabetical sort Z to A  or 9 - 0*/
  return strcmp(b, a);
  
  //Since  0 is falsy I am returning 0  if the item is not less than or equal 
  //  this is discovered with  check_return < 1   which qualifies 0 and -1.
  //This function is the complete opposite of lexicographic_sort
}

int distinct_chars(const char *a){
  int dist = 0; 
  while (*a != '\0'){
    if (!strchr(a + 1, *a)){
      dist++; 
    }
    a++; 
  }
  return dist; 
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
   int res = distinct_chars(a) - distinct_chars(b); 
   return (res) ? res : lexicographic_sort(a, b); 
   //get the difference  if its 0  use lexicographic_sort
  
}

int sort_by_length(const char* a, const char* b) {
  /*Number of characters in each string*/
  int res = strlen(a) - strlen(b);
  return (res) ? res : lexicographic_sort(a, b); 
  //get the difference  if its 0  use lexicographic_sort
}


void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
  /*Bubble sort*/
  int half = len / 2; 
  int sorted = 0; 
  while (!sorted){
    sorted = 1; 
    for (int i = 0; i < len - 1; i++){
      if (cmp_func(arr[i], arr[i+ 1]) > 0){
        char *tmp = arr[i]; 
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp; 
        sorted = 0;  
      }
    }
  }

}



/*
To sort a given array of strings into lexicographically increasing order or into an order in which the string with the lowest length appears first, a sorting function with a flag indicating the type of comparison strategy can be written.  The disadvantage with doing so is having to rewrite the function for every new comparison strategy.  

A better implementation would be to write a sorting function that accepts a pointer to the function that compares each pair of strings. Doing this will mean only passing a pointer to the sorting function with every new comparison strategy.  

Given an array of strings, you need to implement a string_sort function which sorts according to a comparision function, i.e, you need to implement the function: 

void string_sort(const char **arr, const int cnt, int (*cmp_func) (const char* b)){

}


the arguments passed to this function are:  
an array of strings: arr 
length of string array: count 
pointer to the string comparison function: cmp_func  

You also need to implement  the following four string comparision functions: 

int lexicographic_sort(char*, char*) to sort the strings in lexicographically non-decreasing order. 

int lexicographic_sort_reverse(char*, char*) to sort the strings in lexicographically non-increasing order. 

int sort_by_number_of_distinct_characters(char*, char*) to sort the strings in non-decreasing order of the number of distinct characters present in them. If two strings have the same number of distinct characters present in them, then the lexicographically smaller string should appear first. 

int sort_by_length(char*, char*) to sort the strings in non-decreasing order of their lengths. If two strings have the same length, then the lexicographically smaller string should appear first. 


You have to write your own sorting function and you cannot use the inbuilt qsort function 

the strings consists of lower-case English Alphabets only.  

Constraints of tests   

 1 <= No. of Strings <= 50 

 1 <= Total Length of all the strings <= 2500 

 Use of qsort can not be done. However    this program should be able to be swapped out with qsort()  

This is because  void qsort (void* base, size_t num, size_t size,  
            int (*comparator)(const void*,const void*));

qsort has a comparator paramater.  

*/