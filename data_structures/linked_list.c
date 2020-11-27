#include <stdio.h>
#include <stdlib.h>
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
    printf("Some string: %s \n", current->some_string);
    current = current->next;
  }

  // TODO: test if node is added in between
  // TODO: test if node is added at beginning of list

  // find node
  // node_found = find_node(head, some_string_2);

  // delete node
  // node_deleted = delete_node(head, some_string_2);
  // printf("Node with string %s has been deleted", node_deleted->some_string);

  // Confirm node has been deleted
  // node_found = find_node(head, some_string_2);
  // if(node_found == NULL)
  //   printf("Node with string %s was deleted.", some_string_2);
}

Node *add_node_end(Node *head, char *some_string, char **double_pointer)
{
  /*
    * allocate memory for new node
      * make a temp node that is used as the new node being created
    
    * get reference to last element in list
      * assign data to temp node
      * assign temp->next to NULL since the node will be added to the end of list
      * 
      * if head is NULL.
        * If it is then assign temp to node to head
        * return head
      * if head is NOT NULL
        * Assign current->next = temp
        * return temp 
  */
  Node *last_node = NULL;
  Node *temp_node = (Node *)malloc(sizeof(Node));

  // Get reference to last node in list
  if(head == NULL)
  {
    // if head is NULL then node being created is the head
    last_node = (Node *)malloc(sizeof(Node));
  }
  else
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
  *temp_node->double_pointer = (char *)malloc(sizeof(char));
  temp_node->double_pointer = double_pointer;

  temp_node->next = NULL;

  last_node->next = temp_node;

  // free(temp_node);

  return last_node->next;
}

Node *delete_node(Node *head, char *some_string)
{
}

/*
  return NULL if node is not found otherwise return found node
*/
Node *find_node(Node *head, char *some_string)
{
}
