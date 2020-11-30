#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node
{
  unsigned int ID;
  char *some_string;
  char **double_pointer;
  struct Node *next;
} Node;

Node *add_node_end(Node *head, char *some_string, char **double_pointer);
Node *add_node_in(Node *head, int index, char *some_string, char **double_pointer);
Node *add_node_begin(Node *head, char *some_string, char **double_pointer);

Node *delete_node(Node *head, unsigned int ID);
//Node *find_node(Node *head, char *some_string);
Node *find_node(Node *head, unsigned int ID);

Node *create_node(Node *head, char *some_string, char **double_pointer);

unsigned int length(Node *head);

void print_list(Node *head, char *message);

#endif
