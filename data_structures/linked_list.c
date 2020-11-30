#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "./linked_list.h"

int main(void)
{
  char *string_arr[] = {"test1", "test2", "test3"};
  char *string_arr_2[] = {"arr2", "arr3", "arr4"};
  char *some_string = "Hello, World";
  char *some_string_2 = "String 2";

  char *string_of_node_to_delete = "Third node added to end of list."; 

  Node *head, *current, *node_found, *node_deleted;

  // add head of list
  head = add_node_end(NULL, "Head of list", string_arr);

  // add node
  add_node_end(head, "Second node added to end of list.", string_arr);
  add_node_end(head, string_of_node_to_delete, string_arr_2);


  print_list(head, "Node Printed: %s \n");

  // TODO: test if node is added in between
  //add_node_in(head, some_string, string_arr);
  // TODO: test if node is added at beginning of list
  //head = add_node_begin(head, "Node added to beginning of list", string_arr_2);
  //printf("New head added with string of: %s", head->some_string);

  // find node
  printf("\nSearching for node \"%s\"...\n", string_of_node_to_delete);
  node_found = find_node(head, string_of_node_to_delete);
  if(node_found != NULL)
    printf("Node Found!: %s\n", node_found->some_string);
  else
    printf("Node was not found! find_node function not working properly");

  // delete node
  // TODO: figure out when to delete deleted node from memory
  node_deleted = delete_node(head, string_of_node_to_delete);
  printf("\nNode with string \"%s\" has been deleted\n", node_deleted->some_string);

  // Confirm node has been deleted
  node_found = find_node(head, string_of_node_to_delete);
  if(node_found == NULL)
  {
    printf("\nNode Not Found...\n");
    printf("Node with string \"%s\" was deleted successfully!\n", string_of_node_to_delete);
  }

  // TODO: free linked list from memory

  return EXIT_SUCCESS;
}

/*
  Adds node to the end of the linked list and returns newly created node.

  head: head of the node
  some_string: string that belongs to node
  double_pointer: pointer that points to an array that belongs to node

  returns: newly created node
*/
Node *add_node_end(Node *head, char *some_string, char **double_pointer)
{
  Node *last_node = NULL;
  Node *temp_node = (Node *)malloc(sizeof(Node));
  bool isHead = head == NULL;

  if(!isHead)
  {
    last_node = head;
    while(last_node->next != NULL)
    {
      last_node = last_node->next;
    }
  }

  temp_node->some_string = malloc(sizeof(char) * 100);
  temp_node->some_string = some_string;

  temp_node->double_pointer = malloc(sizeof(char *));
  *temp_node->double_pointer = malloc(sizeof(**double_pointer));
  temp_node->double_pointer = double_pointer;

  temp_node->next = NULL;
  
  // check whether the node created was the head
  if(isHead)
    last_node = temp_node;
  else
    last_node->next = temp_node;

  return temp_node;
}

/*
  Adds node to the start of the linked list and returns newly created node.

  head: head of the node
  some_string: string that belongs to node
  double_pointer: pointer that points to an array that belongs to node

  returns: newly created node
*/
Node *add_node_begin(Node *head, char *some_string, char **double_pointer)
{
  // create new node
  Node *temp_node = malloc(sizeof(Node));

  // Assign data to node
  temp_node->some_string = malloc(sizeof(char) * 100);
  temp_node->some_string = some_string;

  temp_node->double_pointer = malloc(sizeof(char *));
  *temp_node->double_pointer = malloc(sizeof(**double_pointer));
  temp_node->double_pointer = double_pointer;

  // next node of new node is the the previous head.
  temp_node->next = head;

  return temp_node;
}

Node *delete_node(Node *head, char *some_string)
{
  // save pointers to current node and previous node
  Node *current = head;
  Node *previous = NULL;

  if(head == NULL)
    return NULL;

  while(strcmp(current->some_string, some_string) != 0)
  {
    // If the end of the list is reached without finding list node
    if(current->next == NULL)
      return NULL;

    // save pointer of current node to previous var for next iteration
    previous = current;
    // move to next node 
    current = current->next;
  }

  // if a match is found
  // assign the next pointer of previous node to next pointer of current node
  previous->next = current->next;

  // TODO: delete current node from memory
  // free(current);

  return current;
}

Node *find_node(Node *head, char *some_string)
{
  Node *current = head;

  while(current != NULL)
  {
    if(strcmp(current->some_string, some_string) == 0) 
      return current;

    current = current->next;
  }

  return NULL;
}

void print_list(Node *head, char* message)
{
  Node *current = head;

  while(current != NULL)
  {
    // printf("Node printed: %s \n", current->some_string);
    printf(message, current->some_string);
    current = current->next;
  }

}
