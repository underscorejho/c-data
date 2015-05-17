
// Jared Henry Oviatt

// cdata Library source
// 
// Lists
// Hash Maps
// Stacks
// Trees
// Linked Lists

///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

///////////////////////////////////////////////////////////////////////////////
/////                               LISTS                                 /////
///////////////////////////////////////////////////////////////////////////////

typedef struct {
  int length = 0;
  void *list;
} List;

///////////////////////////////////////////////////////////////////////////////


int list_count(char *str)
{
  int count = 1; // offset 1 for comma count
  int i = 0;
  int is_string = 0;

  for(i = 0; i < strlen(str); i++)
  {
//// escape after backslashes? ////
//    if(str[i] == '\\')
//      continue;
    if(str[i] == '\'')
      if(!is_string)
        is_string++;
      else
        is_string--;
    if(!is_string)
      if(str[i] == ',')
        count++;
  }

  return count;
}

void list_parse(char *str, void *ptrs)
{
  int i = 0; // string index
  int n = 0; // list index

  int j = 0; // counter variable

  int str_length = 0;

  char *int_string;

  for(n = 0; n < list_count(str); n++)
  {
    if(str[i] == ',')
      continue;
    if(str[i] == '\'') // handle string
    {
      for(j = 1; str[i+j] != '\''; j++)          // get length of string
        str_length = j;

      ptrs[n] = malloc(sizeof(char) * (j+1));    // allocate memory for string with room for \0

      for(j = 1; j < str_length; j++)            // put string in ptrs
        ptrs[n][j] = str[i+j];
      ptrs[n][j+1] = '\0';

      i += j;                                    // move i to end of item
    }
    else // handle int
    {
      for(j = 0; str[i+j] != ','; j++)           // get length of number
        string_len = j;

      int_string = malloc(sizeof(char) * (j+1)); // allocate memory for number string

      for(j = 0; str[i+j] != ','; j++)
        int_string[j] = str[i+j];                // put number in int_string
      
      ptrs[n] = malloc(sizeof(strtol(*int_string)));
      *ptrs[n] = strtol(*int_string);
      
      free(int_string);                          // free memory

      i += j;                                    // move i to end of item
    }
  }
  
  ptrs[n+1] = NULL;
/* 
creates (struct) list, 
accept list as a string:
  my_list = list("5, 'legs', 'arms and dogs', 2 + 3"); 
access list as:
  **my_list.list[n];
free list with:
  list_free(my_list.list);

// TODO: add support for variables and pointers
// NOTE: this function needs a function header in `.h` file
*/

  List list;   // list to return
  void *arr;   // array of pointers to list objects
  int length;  // length of the list

  length = list_count(args);

  arr = malloc(length * sizeof(void *));

  list_parse(args, arr);
  
  list.length = length;
  list.list = arr;

  return list;
}

void list_free(arr)
{
// NOTE: this function needs a function header in `.h` file
  int i = 0;

  if(!arr)
    return;
  while(arr[i])
    free(arr[i++]);
  return;
}

///////////////////////////////////////////////////////////////////////////////
/////                               TESTS                                 /////
///////////////////////////////////////////////////////////////////////////////

// List Tests
int list_test1()
{
  int i = 0;
  List my_list;
 
  my_list = list("5, 6, 'dog', 'leg', 2, 'nine'");

  printf("List Test 1:\n");
  for(i = 0; i <= my_list.length; i++)
    printf("%s\n", **my_list.list[i]);
  printf("End List Test 1\n");

  list_free(mylist.list);

  return 0;
}

int list_test2()
{
  int i = 0;
  List my_list;
 
  my_list = list("7");

  printf("List Test 2:\n");
  for(i = 0; i <= my_list.length; i++)
    printf("%s\n", **my_list.list[i]);
  printf("End List Test 2\n");

  list_free(mylist.list);

  return 0;
}

int list_test3()
{
  int i = 0;
  List my_list;
 
  my_list = list("'orangutans are, neat'");

  printf("List Test 3:\n");
  for(i = 0; i <= my_list.length; i++)
    printf("%s\n", **my_list.list[i]);
  printf("End List Test 3\n");

  list_free(mylist.list);

  return 0;
}

int list_test4()
{
  int i = 0;
  List my_list;
 
  my_list = list("");

  printf("List Test 4:\n");
  for(i = 0; i <= my_list.length; i++)
    printf("%s\n", **my_list.list[i]);
  printf("End List Test 4\n");

  list_free(mylist.list);

  return 0;
}

int main()
{
  list_test1();
  list_test2();
  list_test3();
  list_test4();
  return 0;
}
