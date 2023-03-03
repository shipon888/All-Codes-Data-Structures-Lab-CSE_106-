// Linked list operations in C

#include <stdio.h>
#include <stdlib.h>

// Create a node
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
// Insert at the beginning
void insertAtBeginning(int x)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = head;
    head = new_node;
}

// Insert a node after a node
void insertAfter(struct Node *prev_node, int x)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Insert the the end
void insertAtEnd(int x)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = head; 

    new_node->data = x;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node; // previous last node pointing to the new node.
    return;
}

// Delete a node
void deleteNode(int key)
{
    struct Node *temp = head, *prev;

//first element
    if (temp != NULL && temp->data == key)
    {
        head = temp->next;
        free(temp);
        return;
    }
    // Find the key to be deleted
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not present
    if (temp == NULL)
        return;

    // Remove the node
    prev->next = temp->next;

    free(temp);
}


// Print the linked list
void printList()
{
    struct Node *node = head;
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

// Driver program
int main()
{
    insertAtEnd(1);
    insertAtBeginning(2);
    insertAtBeginning(3);
    insertAtEnd(4);
    insertAfter(head->next, 5);

    printf("Linked list: ");
    printList();

    printf("\nAfter deleting an element: ");
    deleteNode(3);
    printList();

}