#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>

#define IS_EMPTY(x) (x == NULL)

#define PRINT_MESSAGE(message)\
  printf("\n*****************\n");\
  printf("%s", message);\
  printf("\n*****************\n");

#define PRINTF_MESSAGE(func)\
  printf("\n*****************\n");\
  func;\
  printf("\n*****************\n");

typedef struct Node
{
  unsigned int ID;
  char *some_string;
  char **double_pointer;
  struct Node *next;
} Node;

int linked_list(void);

// Create Nodes
Node *add_node_end(Node *head, char *some_string, char **double_pointer);
Node *add_node_in(Node *head, unsigned int index, char *some_string, char **double_pointer);
Node *add_node_begin(Node *head, char *some_string, char **double_pointer);

// Delete Node
Node *delete_node_begin(Node **head);
Node *delete_node_in(Node **head, unsigned int ID);
Node *delete_node_end(Node **head);

// Interface for list
Node *find_node(Node *head, unsigned int ID);
Node *create_node(Node *head, char *some_string, char **double_pointer);
unsigned int length(Node *head);
void print_list(Node *head, char *message);
void delete_list(Node **head);

// TODO: save pointer to head and tail of list
Node *head, *tail;

#endif
