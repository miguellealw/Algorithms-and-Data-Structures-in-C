#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node
{
  char* some_string;
  char** double_pointer;
  struct Node* next;
} Node;

Node* add_node_end(Node* head, char* some_string, char** double_pointer);
Node* add_node_in(Node* head, char* some_string, char** double_pointer);
Node* add_node_begin(Node* head, char* some_string, char** double_pointer);

Node* delete_node(Node* head, char* some_string);
Node* find_node(Node* head, char* some_string);

#endif