#include <stdio.h>
#include <stdlib.h>

struct Node
{
  struct Node *next;
  int value;
};

/// @brief Adds a new node to the end of the linked list.
/// If head node is NULL then initializes head node with data and sets next node as NULL
/// @param head pointer to the pointer of the head of linked list
/// @param data the int value that will be set as value property on a newly added node
void add(struct Node **head, int data)
{
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->value = data;
  newNode->next = NULL;
  if (*head == NULL)
  {
    *head = newNode;
    return;
  }

  struct Node *current = *head;
  while (current->next != NULL)
  {
    current = current->next;
  }

  current->next = newNode;
}

/// @brief Deletes a first node which value property matches to data parameter value
/// @param head pointer to the pointer of the head of linked list
/// @param data integer
void delete(struct Node **head, int data)
{
  if (*head == NULL)
  {
    printf("Linked list is empty");
    return;
  }

  struct Node *current = *head;

  if (current->value == data)
  {
    *head = current->next;
    free(current);
    return;
  }
  struct Node *previous = NULL;
  while (current != NULL)
  {
    if (current->value == data)
    {
      previous->next = current->next;
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }

  printf("Node with data %d not found.\n", data);
}

/// @brief finds a node by its value attribute.
/// If no such node exists return NULL.
/// @param head a head of a linked list
/// @param data value with which node fill be found
/// @return pointer to a found node
struct Node *getByValue(struct Node *head, int data)
{
  if (head == NULL)
  {
    printf("Linked list is empty!");
    return NULL;
  }

  struct Node *current = head;

  while (current != NULL)
  {
    if (current->value == data)
    {
      return current;
    }
    current = current->next;
  }
  printf("Node with value \"%i\" doesn't exist!", data);
  return NULL;
}

/// @brief Prints linked list in format:
/// Index: <index of a node>
/// Value: <value of a value filed on a node>
/// @param head Head of linked list
void printList(struct Node *head)
{
  if (head == NULL)
  {
    printf("Linked List is empty!");
    return;
  }

  int index = 0;
  struct Node *current = head;
  while (current != NULL)
  {
    printf("Index: %i\n", index);
    printf("Value: %i\n", current->value);
    index++;
    current = current->next;
  }
}

int main()
{
  struct Node *head = NULL; // define head of the linked list

  add(&head, 23);
  add(&head, 123);
  add(&head, 7);
  add(&head, -12);
  add(&head, 31);

  struct Node *node = getByValue(head, 7);

  printf("Node: %i\n", node->value);

  // delete (&head, 7);
  // delete (&head, 23);

  // printList(head);

  return 0;
}
