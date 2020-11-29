# Linked List Notes

---
**Table of Contents:**
- Node \*add_node_end(Node *head, char *some_string, char **double_pointer);
- Node *add_node_in(Node *head, char *some_string, char **double_pointer);
- Node *add_node_begin(Node *head, char *some_string, char **double_pointer;
- Node *delete_node(Node *head, char *some_string);
- Node *find_node(Node *head, char *some_string);
---


## add_node_end
*Code Explanation:*
**1. Create node variables:**
  - `last_node` - will contain the reference to the last node in the list.
  - `temp_node` - this is will contain the reference to the node being created.

**2. If the head is NOT null then the node being created is not the head.**
  - Iterate over the list until the last node is reached.
  - While loop explained
    - `while(last_node->next != NULL)` - keep looping until last_node->next is NULL (last node has been reached).
    - `last_node = last_node->next;` - assign the next node to the current instance of the last_node. This will keep a reference to the current last_node. When the while loop breaks (the last node was reached) the last_node will point to the last node of the list.

**3. After the last_node is found start assigning the data to the new node.**
  - First allocate space for the string on the node. Since `temp_node->some_string` will contain the reference to the first character of the string then the size type type has to be `char *`. Allocate `sizeof(char) * 100);` bytes (1 byte * 100);
  - Assign the string (reference to the first character of the string) to the newly allocated space.
  - Allocate space for the char double pointer (pointer to string array)
    - size allocated will be `2 * sizeof(char *)` (size of 2 pointers).
  - Then dereference double pointer to go the address of the array and allocate space for that array.
    - Allocated space size will be `sizeof(char)` since it will 

```c
Node *add_node_end(Node *head, char *some_string, char **double_pointer)
{
  // 1.
  Node *last_node = NULL;
  Node *temp_node = (Node *)malloc(sizeof(Node));

  // 2.
  if(head != NULL) 
  {
    last_node = head;
    while(last_node->next != NULL)
    {
      last_node = last_node->next;
    }
  }

  // 3.
  temp_node->some_string = (char *)malloc(sizeof(char) * 100);
  temp_node->some_string = some_string;

  // 4.
  temp_node->double_pointer = (char **)malloc(2 * sizeof(char *));
  *temp_node->double_pointer = (char *)malloc(sizeof(char));
  temp_node->double_pointer = double_pointer;

  temp_node->next = NULL;

  if(head == NULL)
    last_node = temp_node;
  else
    last_node->next = temp_node;

  return temp_node;
}
```
