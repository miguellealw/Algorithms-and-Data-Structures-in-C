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
  unsigned int ID_of_node_to_delete = 2;

  Node *head, *current, *node_found, *node_deleted;

  printf("\n*****************\n");
  printf("Add to END of List");
  printf("\n*****************\n");

  // add head of list
  head = add_node_end(NULL, "Head of list", string_arr);

  // add node
  add_node_end(head, "Second node added to end of list.", string_arr);
  add_node_end(head, string_of_node_to_delete, string_arr_2);

  print_list(head, "#%d - Node Printed: %s \n");

  // TODO: test if node is added in between
  //add_node_in(head, some_string, string_arr);
  
  printf("\n*****************\n");
  printf("Add to BEGINNING of List");
  printf("\n*****************\n");
  head = add_node_begin(head, "Node added to beginning of list", string_arr_2);
  printf("New head added with string of: %s and ID of: #%d\n", head->some_string, head->ID);

  // find node
  printf("\n*****************\n");
  printf("Find Node");
  printf("\n*****************\n");

  printf("Searching for node - \"%s\"...\n", string_of_node_to_delete);
  node_found = find_node(head, ID_of_node_to_delete);
  if(node_found != NULL)
    printf("Node Found!: %s\n", node_found->some_string);
  else
    printf("Node was not found! find_node function not working properly");

  // delete node
  // TODO: figure out when to delete deleted node from memory
  printf("\n*****************\n");
  printf("Delete Node");
  printf("\n*****************\n");
  node_deleted = delete_node(head, ID_of_node_to_delete);
  printf("Node with string \"%s\" and ID: %d has been deleted\n", node_deleted->some_string, node_deleted->ID);

  // Confirm node has been deleted
  node_found = find_node(head, ID_of_node_to_delete);
  if(node_found == NULL)
  {
    printf("\nConfirming Deletion...\n");
    printf("Node with string \"%s\" and ID: %d was deleted successfully!\n", string_of_node_to_delete, ID_of_node_to_delete);
  }

  // TODO: free linked list from memory

  return EXIT_SUCCESS;
}

Node *create_node(Node* head, char *some_string, char **double_pointer)
{
  Node *temp_node = malloc(sizeof(Node));

  // Assign ID to node
  // TODO: figure out how to handle ID's when nodes are added in between and at start of list 
  unsigned int list_length = length(head);
  temp_node->ID = list_length;

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
  bool isHead = head == NULL;

  Node *new_node = create_node(head, some_string, double_pointer);
  
  // If the node being added is not the head then go to the end of the list 
  if(!isHead)
  {
    last_node = head;
    while(last_node->next != NULL)
    {
      last_node = last_node->next;
    }
  }

  // check whether the node created was the head
  if(isHead)
    last_node = new_node;
  else
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
  Node *new_node = create_node(head, some_string, double_pointer);
  // create new node
  /*Node *temp_node = malloc(sizeof(Node));*/

  /*// Assign data to node*/
  /*temp_node->some_string = malloc(sizeof(char) * 100);*/
  /*temp_node->some_string = some_string;*/

  /*temp_node->double_pointer = malloc(sizeof(char *));*/
  /**temp_node->double_pointer = malloc(sizeof(**double_pointer));*/
  /*temp_node->double_pointer = double_pointer;*/

  /*// next node of new node is the the previous head.*/
  new_node->next = head;
  /*temp_node->next = head;*/

  /*return temp_node;*/
  return new_node;
}

Node *add_node_in(Node *head, int index, char *some_string, char **double_pointer)
{
  // create node
  // assign data to node

  // get previous node
  // get next node

  // assign next of previous node to new node
  // assign next of new node to next node
}

Node *delete_node(Node *head, unsigned int ID)
{
  // save pointers to current node and previous node
  Node *current = head;
  Node *previous = NULL;

  if(head == NULL)
    return NULL;

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
  // assign the next pointer of previous node to next pointer of current node
  previous->next = current->next;

  // TODO: delete current node from memory
  // free(current);

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
  Node *current = head;

  while(current != NULL)
  {
    printf(message, current->ID, current->some_string);
    current = current->next;
  }

}

unsigned int length(Node *head)
{
  if(head == NULL)
    return 0;

  Node *current = head;  
  int counter = 0; 

  while(current != NULL)
  {
    counter++;    
    current = current->next;
  }

  return counter;
}


