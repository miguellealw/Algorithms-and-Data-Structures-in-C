# Linked List Notes

---
**Table of Contents:**
- Node \*add_node_end(Node *head, char *some_string, char **double_pointer);
- Node *add_node_in(Node *head, char *some_string, char **double_pointer);
- Node *add_node_begin(Node *head, char *some_string, char **double_pointer;
- Node *delete_node(Node *head, char *some_string);
- Node *find_node(Node *head, char *some_string);
---

* Some Notes: *
  - You can either pass the head poniter as reference or return the new head and assign to head variable
  - When iterating over list `while(current->next != NULL)` will go up to last node whereas `while(current != NULL)` will go past last node.


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
  - First allocate space for the string on the node. Since `temp_node->some_string` will contain the reference to the first character of the string then the size type has to be `char *`. Allocate `sizeof(char) * 100);` bytes (1 byte * 100);
  - Assign the string (reference to the first character of the string) to the newly allocated space.
  - Allocate space for the char double pointer (pointer to string array)
    - size allocated will be `sizeof(char *)` (size of one pointer).
  - Then dereference double pointer to go the address of the array and allocate space for that array.
    - Allocated space size will be `sizeof(**double_ponter)` since it will be the size of the array. `**double_pointer` is just the size of the array.
      - `**double_pointer` - the array itself since it is dereferenced twice.
      - `*double_pointer` - the pointer to the first element of the array.

**4. Set next node of the newly created now to NULL since the node will be appended to the end of the list.**
   
**5. Check if the node being created is the head**
  - if it is, then assign the newly created node directly to the last_node(the head) of the list
  - if it is not the head, assign the newly created node to the next pointer of the last_node
  - return the temp_node (newly created node)
```c
Node *add_node_end(Node *head, char *some_string, char **double_pointer)
{
  // 1.
  Node *last_node = NULL;
  Node *temp_node = (Node *)malloc(sizeof(Node));
  bool isHead = head == NULL;

  // 2.
  if(!isHead) 
  {
    last_node = head;
    while(last_node->next != NULL)
    {
      last_node = last_node->next;
    }
  }

  // 3.
  temp_node->some_string = malloc(sizeof(char) * 100);
  temp_node->some_string = some_string;

  temp_node->double_pointer = malloc(sizeof(char *));
  *temp_node->double_pointer = malloc(sizeof(**double_pointer));
  temp_node->double_pointer = double_pointer;

  // 4.
  temp_node->next = NULL;

  // 5.
  if(isHead)
    last_node = temp_node;
  else
    last_node->next = temp_node;

  return temp_node;
}
```
