
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

///////////////////////////////////////////////////////////////////////////////


int count(char *str)
{
  int count = 1; // offset 1 for comma count
  int i = 0;
  int is_string = 0;

  for(i = 0; i < strlen(str); i++)
  {
  // escape after backslashes? ////
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

void parse(char *str, void *ptrs)
{
  int i = 0; // string index
  int n = 0; // list index

  void item;
  
  for(n = 0; n < count(str); n++)
  {
    while(str[i] != ',')
    {
      if(str[i] == '\'')
        HANDLE STRING /////////////
      else if(IS A NUMBER)
        ptrs[n] = malloc(sizeof((int)str[i]));
    }
  }

  return
}

void * list(char *args) 
{

/* 
creates (struct) list, 
accept list of args as a string:
  my_list = list("5, 'legs', 'arms and dogs', 2 + 3"); 

// TODO: add support for variables and pointers

requres list struct definition ////
*/

  void *list; // array of pointers to list objects
  int length  // length of the list

  length = count(args);

  list = malloc(length * sizeof(void *));

  parse(args, list); // parse args, allocate memory for each item, put pointers to item into list //// write parse

  return list;
}



////////////////////////////////////////////////////////////////////////////////
