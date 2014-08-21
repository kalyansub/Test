#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
typedef unsigned int UINT;

struct node
{
    int data;
    struct node* next;
};

typedef struct node Node;
typedef struct node* NodePtr;

int Length(NodePtr head);

NodePtr buildList(NodePtr head, NodePtr second, NodePtr third)
{
    
    head->data = 1;
    head->next  = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    return head; 
}

int countIntInList(NodePtr head, int val)
{
    int count = 0;
    NodePtr cur = head;

    while( cur != NULL)
    {
        if (cur->data == val)
        {
            count++;
        }
        cur = cur->next;
    }
    return count;
}

void printList(NodePtr head)
{
    NodePtr curr = head;
    int count = 0;

    assert( head != NULL);

    printf("Length= %d\n", Length(head));
    while(curr != NULL)
    {
        count++;
        printf("[Node %d: data: %d]\n", count, curr->data);
        curr = curr->next; 
    }
}

void Push(NodePtr* headRef, int dataIn)
{
    NodePtr newNode = malloc(sizeof(Node));
    newNode->data = dataIn;
    newNode->next = *headRef;
    *headRef = newNode;
}

int Length(NodePtr head)
{
    int len = 0;
    NodePtr curr = head;
    assert(head != NULL);

    while(curr != NULL)
    {
        len++;
        curr = curr->next;
    }
    return(len);
}

int getNth(NodePtr head, int n)
{
    NodePtr cur = head;

    for(int i = 0; i < n -1; i++)
    {
       cur = cur->next; 
    }
    return(cur->data); 
}

void Append(NodePtr* aRef, NodePtr* bRef)
{
    NodePtr cur;
    assert(*aRef != NULL);
    assert(*bRef != NULL);
 
    //printf("Append(): *aRef = 0x%08x, *bRef = 0x%04x\n", *aRef, *bRef);
    printList(*aRef);
    printList(*bRef);

    if(*aRef == NULL) /* if a is empty, append is just adding b to the new list
    {
        *aRef = *bRef;
    }
    else /* otherwise, find the end of a and tack on b to it and set b to NULL */
    {
        printf("Append(): in else clause\n");
        cur = *aRef; /* start with the current pointer at a */

        while( cur->next != NULL ) /* go to the end of a */
        {
            cur = cur->next;
        }
        cur->next = *bRef; /* tack on b to the end of a */ 
        (*bRef)->next = NULL; 
        (*bRef) = NULL;/* set original b to NULL */
    }
    printf("At the end of Append():\n");
}

void Delete(NodePtr* headRef)
{
   NodePtr cur = *headRef; // deref the real head to get the real head
   NodePtr tmp;
   printf("Inside Delete: with headRef = 0x%08x\n", (uintptr_t)*headRef);
   while(cur != NULL)
   {
       tmp = cur->next; //save the next ptr
       free(cur);      //delete the current node
       cur = tmp;      // advance to the next node
   }
   *headRef = NULL;    //deref headRef to affect the real head back in caller
   printf("Delete() done!\n");
}

int main(int argc, char* argv[])
{
        
    NodePtr head = NULL;
#if 0
    NodePtr second = NULL;
    NodePtr third = NULL;

    head = malloc(sizeof(Node));
    second = malloc(sizeof(Node));
    third = malloc(sizeof(Node));

    assert(head != NULL);
    assert(second != NULL);
    assert(third != NULL);
    head = buildList(head, second, third);

    NodePtr newNode;
   
    newNode = malloc(sizeof(Node));
    newNode->data = 1;
    newNode->next = head;    

    head = newNode; // now head points to list {1,2,3}
    printList(head);

    Push(&head, 13);
    Push(&head, 2);
    Push(&head, 1);
    Push(&head, 23);
    Push(&head, 35);

    printList(head);
    int count = countIntInList(head, 1);
    printf("count of %d in list is : %d\n", 1, count);
    
    printf("Third item in list is : %d\n", getNth(head, 3) );
#endif    

    printf("Test code for append()\n");

    NodePtr a;
    a = malloc(sizeof(a));
    assert( a!= NULL);
    Push(&a, 100);
    Push(&a, 200);
    printf("Built list a :\n");
    printList(a);

    NodePtr b;
    b = malloc(sizeof(a));
    assert( b!= NULL);
    Push(&b, 300);
    Push(&b, 400);
    printf("Built list b :\n");
    printList(b);

    //Delete(&a);

    Append(&a, &b);
    printf("After appending a to b :\n");
    printList(a);

    free(head);
#if 0
    free(second);
    free(third);
    free(newNode);
#endif
    free(a);
    free(b);
  
    return 0; 
}

