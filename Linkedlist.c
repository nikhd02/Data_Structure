#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType
{
    int data;
    struct nodeType *next;
} node;

void createEmptyList(node **head)
{
    *head = NULL;
}

void insertAtEnd(node **head, int item)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = item;
    ptr->next = NULL;

    if (*head == NULL)
        *head = ptr;
    else
    {
        node *current = *head;
        while (current->next != NULL)
            current = current->next;

        current->next = ptr;
    }
}

void insertAtStart(node **head, int info)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = info;

    ptr->next = *head;
    *head = ptr;
}

int listLength(node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

node *reverseLinkedList(node *head)
{
    node *temp = head;
    node *prev = NULL;

    while (temp != NULL)
    {
        node *front = temp->next;

        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

void traverseInOrder(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

void traverseInOrder2(node *head)
{
    for (; head != NULL; head = head->next)
    {
        printf("%d ", head->data);
    }
}

void traverseInReverseOrder(node *head)
{
    head = reverseLinkedList(head);
    traverseInOrder(head);
    head = reverseLinkedList(head);
}

void traverseInReverseOrder2(node *head)
{
    
    if (head->next != NULL)
        traverseInReverseOrder(head->next);

    printf("\n%d", head->data);
}

node *searchInUnsortedList(node *head, int item)
{
    while (head != NULL && head->data != item)
    {
        head = head->next;
    }
    return head;
}

node *searchInSortedList(node *head, int item)
{
    while (head != NULL && head->data != item)
    {
        if (head->data < item)
            return NULL;
        head = head->next;
    }

    return head;
}

void insertAfterElement(node *head, int insertAfter, int item)
{
    node *ptr = (node *)malloc(sizeof(node));
    node *insertAfterNode = searchInUnsortedList(head, insertAfter);
    if (insertAfterNode != NULL)
    {
        ptr->data = item;
        ptr->next = insertAfterNode->next;
        insertAfterNode->next = ptr;
        printf("\nInserted");
    }
    else
        printf("\nNode not found");
}

void deleteAtStart(node **head)
{
    if (*head == NULL)
    {
        printf("\nList Empty.");
        return;
    }
    node *ptr = *head;
    *head = ptr->next;
    printf("\nDeleted.");
}

void deleteAtEnd(node **head)
{
    if (*head == NULL)
    {
        printf("\nList Empty.");
        return;
    }
    node *curr = *head;
    if (curr->next == NULL)
        *head = NULL;
    else
    {
        while (curr->next->next != NULL)
            curr = curr->next;

        curr->next = NULL;
    }
    printf("\nDeleted.");
}

void deleteSpecificNode(node **head, int item)
{
    if (*head == NULL)
    {
        printf("\nList Empty.");
        return;
    }
    node *prev = *head;

    if (prev->data == item)
    {
        *head = prev->next;
        printf("\nDeleted.");
        return;
    }

    while (prev != NULL && prev->next != NULL && prev->next->data != item)
        prev = prev->next;

    if (prev == NULL)
    {
        printf("\nNode does not exist.");
        return;
    }
    node *curr = prev->next;
    prev->next = curr->next;
    printf("\nDeleted.");
}

int main()
{
    node *head;
    int choice, d, insAfter;
    createEmptyList(&head);

    do
    {
        printf("\n\n1. Create A New Linked List.");
        printf("\n2. Insert at the Start of the list.");
        printf("\n3. Insert at the end of the list.");
        printf("\n4. Insert after an item.");
        printf("\n5. Delete from the Start of the list.");
        printf("\n6. Delete from the end of the list.");
        printf("\n7. Delete a specific item.");
        printf("\n8. Traverse In Order.");
        printf("\n9. Traverse In Reverse Order.");
        printf("\n10. Reverse LinkedList.");
        printf("\n11. Check List Length.");
        printf("\n12. Exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createEmptyList(&head);
            printf("\nNew List Created");
            break;
        case 2:
            printf("\nEnter data: ");
            scanf("%d", &d);
            insertAtStart(&head, d);
            printf("\nInserted");
            break;
        case 3:
            printf("\nEnter data: ");
            scanf("%d", &d);
            insertAtEnd(&head, d);
            printf("\nInserted");
            break;
        case 4:
            printf("\nEnter data: ");
            scanf("%d", &d);
            printf("\nEnter item info to insert after: ");
            scanf("%d", &insAfter);
            insertAfterElement(head, insAfter, d);
            break;
        case 5:
            deleteAtStart(&head);
            break;
        case 6:
            deleteAtEnd(&head);
            break;
        case 7:
            printf("\nEnter item info to delete: ");
            scanf("%d", &d);
            deleteSpecificNode(&head, d);
            break;
        case 8:
            traverseInOrder(head);
            break;
        case 9:
            traverseInReverseOrder(head);
            break;
        case 10:
            head = reverseLinkedList(head);
            printf("\nList Reversed");
            break;
        case 11:
            printf("\n%d", listLength(head));
            break;
        case 12:
            printf("\nExited");
            break;
        default:
            printf("\nInvalid Choice");
        }
    } while (choice != 12);
}