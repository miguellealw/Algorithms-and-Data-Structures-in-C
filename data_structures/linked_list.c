#include <stdio.h>
#include <stdlib.h>
#include "./linked_list.h"

int main(void)
{
  char* string_arr[] = {"test1", "test2", "test3"};
  char* string_arr_2[] = {"arr2", "arr3", "arr4"};
  char* some_string = "Hello, World";
  char* some_string_2 = "String 2";

  Node *head, *current, *node_found, *node_deleted;

  // add head of list
  // head = add_node_begin(NULL, some_string, string_arr);

  // add node
  current = add_node_end(head, some_string, string_arr);
  current = add_node_end(head, some_string_2, string_arr_2);

  // TODO: test if node is added in between
  // TODO: test if node is added at beginning of list

  // find node
  node_found = find_node(head, some_string_2);

  // delete node
  node_deleted = delete_node(head, some_string_2);
  printf("Node with string %s has been deleted", node_deleted->some_string);

  // Confirm node has been deleted
  node_found = find_node(head, some_string_2);
  if(node_found == NULL)
    printf("Node with string %s was deleted.", some_string_2);
}

Node* add_node_end(Node* head, char* some_string, char** double_pointer)
{
  // go to last element of list
  Node* current;

  // if head is NULL then the node is being created is the head
  if(head == NULL)
    current = (Node *)malloc(sizeof(Node));
  else
    current = head;
  
  // TODO: figure out logic behind this
  while(current->next != NULL)
  {
    current = current->next;
  }

  // ---- Create Node
  // allocate space for node
  current->next = (Node *)malloc(sizeof(Node));

  // allocate space for some_string
  current->next->some_string = (char*)malloc(sizeof(char) * 100);
  current->next->some_string = some_string;

  current->next->double_pointer = (char **)malloc(2 * sizeof(char*)); 
  *current->next->double_pointer = (char *)malloc(sizeof(char));
  current->next->double_pointer = double_pointer;

  // This assumes array is has 2 indices.
  // *current->next->double_pointer = *double_pointer[0];
  // *current->next->double_pointer = *double_pointer[1];

  // return the created node
  return current->next;
}

Node* delete_node(Node* head, char* some_string)
{

}


/*
  return NULL if node is not found otherwise return found node
*/
Node* find_node(Node* head, char* some_string)
{

}
