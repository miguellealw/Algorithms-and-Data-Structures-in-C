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
  unsigned int ID_of_node_to_delete = 1;

  Node *head, *current, *node_found, *node_deleted;

  /*printf("\n*****************\n");*/
  /*printf("Add Head to BEGINNING of List");*/
  /*printf("\n*****************\n");*/
  /*head = add_node_begin(NULL, "Head of list", string_arr);*/
  /*print_list(head, "#%d - Node Printed: %s \n");*/

  // add head of list
  PRINT_MESSAGE("Add Head to END of List");
  head = add_node_end(NULL, "Head of list", string_arr);
  print_list(head, "#%d - Node Printed: %s \n");

  /*PRINT_MESSAGE("Delete head with delete_node_in");*/
  /*node_deleted = delete_node_in(&head, 0);*/

  /*PRINT_MESSAGE("Delete head with delete_node_begin");*/
  /*node_deleted = delete_node_begin(&head);*/

  /*PRINT_MESSAGE("Delete head with delete_node_end");*/
  /*node_deleted = delete_node_end(&head);*/
  /*print_list(head, "#%d - Node Printed: %s \n");*/

  // add node
  PRINT_MESSAGE("Add to END of List");
  add_node_end(head, "Second node added to end of list.", string_arr);
  /*head = add_node_end(head, "Second node added to end of list.", string_arr);*/
  add_node_end(head, string_of_node_to_delete, string_arr_2);
  print_list(head, "#%d - Node Printed: %s \n");

  PRINTF_MESSAGE(printf("Add IN BETWEEN index %d and %d of List", 1, 2));
  add_node_in(head, 1, "Node added in between", string_arr);
  print_list(head, "#%d - Node Printed: %s\n");

  PRINT_MESSAGE("Add to BEGINNING of List");
  head = add_node_begin(head, "Node added to beginning of list", string_arr_2);
  print_list(head, "#%d - Node Printed: %s\n");

  // find node
  PRINT_MESSAGE("Find Node");
  printf("Searching for node with ID %d...\n", ID_of_node_to_delete);
  node_found = find_node(head, ID_of_node_to_delete);
  if(node_found != NULL)
    printf("Node with ID %d was found!\n", node_found->ID);
  else
    printf("Node was not found! find_node function not working properly");

  // delete node
  // TODO: figure out when to delete deleted node from memory
  /*PRINTF_MESSAGE("Delete Node with ID of 3");*/
  PRINTF_MESSAGE(printf("Delete Node with ID of %d", ID_of_node_to_delete));
  node_deleted = delete_node_in(&head, ID_of_node_to_delete);
  print_list(head, "#%d - Node Printed: %s\n");
  if(node_deleted != NULL)
  {
    free(node_deleted);
    node_deleted = NULL;
  }

  // Confirm node has been deleted
  node_found = find_node(head, ID_of_node_to_delete);
  if(node_found == NULL)
  {
    printf("\nConfirming Deletion...\n");
    printf("Node with ID: %d was deleted successfully!\n", ID_of_node_to_delete);
  }

  PRINT_MESSAGE("Delete Head Node");
  node_deleted = delete_node_begin(&head);
  print_list(head, "#%d - Node Printed: %s\n");
  if(node_deleted != NULL)
  {
    free(node_deleted);
    node_deleted = NULL;
  }

  PRINT_MESSAGE("Delete Last Node");
  node_deleted = delete_node_end(&head);
  print_list(head, "#%d - Node Printed: %s\n");
  if(node_deleted != NULL)
  {
    free(node_deleted);
    node_deleted = NULL;
  }
  

  PRINT_MESSAGE("Add to END of List to Delete");
  add_node_end(head, "Node Added to End of List 1", string_arr);
  add_node_end(head, "Node Added to End of List 2", string_arr);
  add_node_end(head, "Node Added to End of List 3", string_arr);
  add_node_end(head, "Node Added to End of List 4", string_arr);
  print_list(head, "#%d - Node Printed: %s\n");

  // free linked list from memory
  PRINT_MESSAGE("Delete Entire List from memory");
  delete_list(&head);
  print_list(head, "#%d - Node Printed: %s\n");

  return EXIT_SUCCESS;
}

Node *create_node(Node* head, char *some_string, char **double_pointer)
{
  Node *temp_node = malloc(sizeof(Node));

  // Assign ID to node
  // TODO: figure out how to handle ID's when nodes are added in between and at start of list 
  static long ID = 0;
  temp_node->ID = ID++;

  temp_node->some_string = malloc(sizeof(char) * 100);
  temp_node->some_string = some_string;

  temp_node->double_pointer = malloc(sizeof(char *));
  *temp_node->double_pointer = malloc(sizeof(**double_pointer));
  temp_node->double_pointer = double_pointer;

  temp_node->next = NULL;

  return temp_node;
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
  Node *new_node = create_node(head, some_string, double_pointer);
  
  // if node created is head there is no need to go to end of list
  if(IS_EMPTY(head))
    return new_node;
  
  // If the node created is not the head then go to the end of the list 
  last_node = head;
  while(last_node->next != NULL)
    last_node = last_node->next;

  last_node->next = new_node;

  return new_node;
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
  Node *new_node = create_node(head, some_string, double_pointer);

  if(IS_EMPTY(head))
    head = new_node;
  else
    // next node of new node is the the previous head.
    new_node->next = head;

  return new_node;
}

// The node will be added AFTER the index passed in
Node *add_node_in(Node *head, unsigned int index, char *some_string, char **double_pointer)
{
  // TODO: handle when head is NULL (When list is empty)

  // create node
  Node *new_node = create_node(head, some_string, double_pointer);

  // get current node
  Node *current = head;
  // get previous node
  Node *previous = NULL;

  index++; 
  while(current->ID != index)
  {
   if(current->next == NULL)
    return NULL;
    
   previous = current;
   current = current->next;
  }

  // assign next of previous node to new node
  previous->next = new_node; 
  // assign next of new node to next node
  new_node->next = current;


  return new_node;
}

Node *delete_node_begin(Node **head)
{
  if(IS_EMPTY(*head))
    return NULL;

  // Get reference to current head before being removed
  Node *deleted_head = *head;

  // assign new head to node after the current head
  // FIXME: head is not being changed. Figure out if passed by reference.
  *head = (*head)->next;
  
  // return node deleted
  return deleted_head;
}

Node *delete_node_in(Node **head, unsigned int ID)
{
  if(IS_EMPTY(head))
    return NULL;

  // save pointers to current node and previous node
  Node *current = *head;
  Node *previous = NULL;

  // TODO: check what happens when head is the only node in the list
  while(current->ID != ID)
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
  // Check if head is node being removed
  if(previous != NULL)
    // assign the next pointer of previous node to next pointer of current node
    previous->next = current->next;
  else
    // if head is the node being removed
    *head = current->next; 

  return current;
}

Node *delete_node_end(Node **head)
{
  // get reference of node to delete
  Node *current = *head;
  // get reference to previous node
  Node *previous = NULL;

  // go to end of list 
  while(current->next != NULL)
  {
    previous = current;
    current = current->next;
  }

  // assign next pointer of previous node to NULL 
  if(previous != NULL)
    previous->next = NULL;
  else
    *head = current->next;

  // return deleted node
  return current;
}

Node *find_node(Node *head, unsigned int ID)
{
  Node *current = head;

  while(current != NULL)
  {
    if(current->ID == ID) 
      return current;

    current = current->next;
  }

  return NULL;
}


void print_list(Node *head, char* message)
{
  if(IS_EMPTY(head))
    printf("List is Empty.\n");

  Node *current = head;

  while(current != NULL)
  {
    printf(message, current->ID, current->some_string);
    current = current->next;
  }

}

// FIXME: fix counter issue. Replicated ID's are possible if you delete then add nodes.
unsigned int length(Node *head)
{
  if(IS_EMPTY(head))
    return 0;

  Node *current = head;  
  int counter = 0; 

  for(; current != NULL; current = current->next)
    counter++;

  return counter;
}

void delete_list(Node **head)
{
  // Base case: once the end of the list is reached stop recursion
  if(IS_EMPTY(*head))
    return;

  delete_list(&((*head)->next));
  free(*head);

  // set head reference to NULL to confirm it has been deleted
  *head = NULL;
}
