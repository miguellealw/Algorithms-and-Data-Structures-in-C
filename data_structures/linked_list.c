#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./linked_list.h"

int main(void)
{
  char *string_arr[] = {"test1", "test2", "test3"};
  char *string_arr_2[] = {"arr2", "arr3", "arr4"};
  char *some_string = "Hello, World";
  char *some_string_2 = "String 2";

  Node *head, *current, *node_found, *node_deleted;

  // add head of list
  head = add_node_end(NULL, some_string, string_arr);

  // add node
  // current = add_node_end(head, some_string, string_arr);
  add_node_end(head, some_string, string_arr);
  // current = add_node_end(head, some_string_2, string_arr_2);
  add_node_end(head, some_string_2, string_arr_2);

  current = head;
  while (current != NULL)
  {
    printf("Current node - some_string: %s \n", current->some_string);
    current = current->next;
  }

  // TODO: test if node is added in between
  // TODO: test if node is added at beginning of list

  // find node
  node_found = find_node(head, some_string_2);
  printf("Node found with some_string_2 being: %s\n", node_found->some_string);

  // delete node
  // TODO: figure out when to delete deleted node from memory
  node_deleted = delete_node(head, some_string_2);
  printf("Node with string %s has been deleted\n", node_deleted->some_string);

  // Confirm node has been deleted
  node_found = find_node(head, some_string_2);
  if(node_found == NULL)
    printf("Node with string %s was deleted successfully!\n", some_string_2);

  // TODO: free linked list from memory

  return EXIT_SUCCESS;
}

Node *add_node_end(Node *head, char *some_string, char **double_pointer)
{
  Node *last_node = NULL;
  Node *temp_node = (Node *)malloc(sizeof(Node));

  // Get reference to last node in list
  if(head != NULL)
  {
    last_node = head;
    // if head is NOT NULL then node being created is NOT the head
    // In this case go to the last node of the list
    /*
      * When the next node is NULL it means it is the last node on the list.
      * Once the next element is NULL, then stay on the current node and assign next node info on current->next   
   */
    while(last_node->next != NULL)
    {
      last_node = last_node->next;
    }
  }

  temp_node->some_string = (char *)malloc(sizeof(char) * 100);
  temp_node->some_string = some_string;

  temp_node->double_pointer = (char **)malloc(2 * sizeof(char *));
  *temp_node->double_pointer = (char *)malloc(sizeof(**double_pointer));
  temp_node->double_pointer = double_pointer;

  temp_node->next = NULL;
  
  // check whether the node created was the head
  if(head == NULL)
    last_node = temp_node;
  else
    last_node->next = temp_node;

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

/*
  return NULL if node is not found otherwise return found node
*/
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
