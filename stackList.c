#include<stdio.h>
#include<stdlib.h>

//DEFINTION OF STRUCTURE
typedef struct nodeType
{
    int info;
    struct nodeType *next;
}node;
void createEmptyList(node **head)
{
    *head=NULL;
}
void push(node **head, int item)
{
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    ptr->info=item;
    if(*head==NULL)
    ptr->next=NULL;
    else
    ptr->next=*head;
    *head=ptr;
}
void pop(node **head)
{
    node *ptr;
    if(*head==NULL)
    return;
    else
    {
	ptr=*head;
	*head=(*head)->next;
	free(ptr);
    }
}
void main()
{
    node *head;
    int ch,element,after;
    createEmptyList(&head);
    while(1)
    {
	printf("\nOptions Available are :- \n");
	printf("\n1. PUSH");
	printf("\n2. POP");
	printf("\n3. PEAK");
	printf("\n4. EXIT");
    printf("\nEnter your choice ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("\nEnter element to push ");
                scanf("%d",&element);
                push(&head,element);
                break;
        case 2: if(head==NULL)
                printf("\nUnderflow");
                else
                pop(&head);
                break;
        case 3: after=head->info;
                printf("\n%d",after);
                break;
        case 4: exit(0);
    }
}
