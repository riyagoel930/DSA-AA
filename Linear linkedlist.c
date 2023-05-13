//LINKED LIST 
#include<stdio.h>
#include<stdlib.h>

//DEFINTION OF STRUCTURE
typedef struct nodeType
{
    int info;
    struct nodeType *next;
}node;

//Function prototypes

void createEmptyList(node **head);
void traverseInOrder1(node *head);
void traverseInReverseOrder2(node *head);
node *searchInUnsortedList(node *head,int item);
node *searchInSortedList(node *head,int item);
void auxilliarySearch(node *head, node **ploc,node **loc, int item);
void insertAtBeginning(node **head, int item);
void insertAfterElement(node *head,int item,int after);
void insertAtEnd(node **head,int item);
void deleteFromBeginning(node **head);
void deleteFromEnd(node **head);
void deleteAfterElement(node *head, int after);
void reverseList(node **head);
void deleteList(node **head);

//Main Screen
void main()
{
    node *head;
    int ch,element,after;
    createEmptyList(&head);
    while(1)
    {
	printf("\nOptions Available are :- \n");
	printf("\n+++++++++++++++++++++++++\n");
	printf("\n 1. Insert at Beginning ");
	printf("\n 2. Insert at End ");
	printf("\n 3. Insert after a given element ");
	printf("\n 4. Traverse in order  ");
	printf("\n 5. Traverse in Reverse order  ");
	printf("\n 6. Delete from beginning  ");
	printf("\n 7. Delete from end ");
	printf("\n 8. Delete after a given element ");
	printf("\n 9. Reverse linked list ");
	printf("\n 10. Exit \n\n ");
	printf("\n Enter your choice(1-10) : ");
	scanf("%d",&ch);
	switch(ch)
	{
	    case 1: printf("\nEnter element :");
		    scanf("%d",&element);
		    insertAtBeginning(&head,element);
		    break;
	    case 2: printf("\nEnter element :");
		    scanf("%d",&element);
		    insertAtEnd(&head,element);
		    break;
	    case 3: printf("\nEnter element : ");
		    scanf("%d",&element);
		    printf("\nEnter element after which to insert : ");
		    scanf("%d",&after);
		    insertAfterElement(head,element,after);
		    break;
	    case 4: if(head == NULL)
		    printf("\nList is empty.....");
		    else
		    traverseInOrder1(head);
		    printf("\n\nPress any key to continue.....");
		    getch();
		    break;
	    case 5: if(head == NULL)
		    printf("\nList is empty.........");
		    else
		    traverseInReverseOrder2(head);
		    printf("\n\nPress any key to continue.....");
		    getch();
		    break;
	    case 6: deleteFromBeginning(&head);
		    break;
	    case 7: deleteFromEnd(&head);
		    break;
	    case 8: printf("\nEnter element after which to delete :");
		    scanf("%d",&after);
		    deleteAfterElement(head,after);
		    break;
	    case 9: reverseList(&head);
		    break;
	    case 10: deleteList(&head);
		    exit(0);
	}

    }
}

//Creation of list
void createEmptyList(node **head)
{
    *head=NULL;
}

//Traversing in order
void traverseInOrder1(node *head)
{
    while(head != NULL)
    {
	printf("%d\n",head->info);
	head=head->next;
    }
}

//Traversing in Reverse Order
void traverseInReverseOrder2(node *head)
{
   node *temp,*ptr;
   int i,j,count=0;
   temp=head;
   while(temp!=0)
   {
   count++;
   temp=temp->next;
   }
   for(i=0;i<count;i++)
   {
   temp=head;
   for(j=0;j<count-i-1;j++)
   temp=temp->next;
   printf("%d\n",temp->info);
   }
   // if(head->next !=NULL)
  //  {
    //	traverseInReverseOrder2(head->next);
    //    printf("%d\n",head->info);
   // }
}
//Search in unsorted
node *searchInUnsortedList(node *head, int item)
{
    while((head!=NULL) && (head->info != item))
    {
	head=head->next;
    }
    return NULL;
}

//search in unsorted
node *searchInSortedList(node *head, int item)
{
    while(head !=NULL)
    {
	if(head->info == item)
	return head;
	else if(item<head->info)
	return NULL;
	else
	head=head->next;
    }
    return NULL;
}
 //Auxillary search

void auxilliarySearch(node *head, node **ploc, node **loc, int item)
{
    int flag=0;
    if(head==NULL)
    *ploc=*loc=NULL;
    else if(head->info==item)
    {
	*ploc=NULL;
	*loc=head;
    }
    else
    {
	*ploc=head;
	*loc=head->next;
	while((*loc != NULL) && (!flag))
	{
	    if((*loc)->info==item)
	    flag=1;
	    else
	    {
		*ploc=*loc;
		*loc=(*loc)->next;
	    }
	}
    }

}
//Insert In Beginning
void insertAtBeginning(node **head, int item)
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

//Insert At End
void insertAtEnd(node **head,int item)
{
    node *ptr,*loc;
    ptr=(node *)malloc(sizeof(node));
    ptr->info=item;
    ptr->next=NULL;
    if(*head==NULL )
    *head=ptr;
    else
    {
	loc=*head;
	while(loc->next != NULL)
	loc=loc->next;
	loc->next=ptr;
    }
}

//Insert after element

void insertAfterElement(node *head, int item, int after)
{
    node *ptr,*loc;
    loc= searchInUnsortedList(head,after);
    if(loc==(node *)NULL)
    return;
    ptr=(node *)malloc(sizeof(node));
    ptr->info=item;
    ptr->next=loc->next;
    loc->next=ptr;
}

void deleteFromBeginning(node **head)
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
void deleteFromEnd(node **head)
{
    node *ptr,*loc;
    if(*head==NULL)
    return;
    else
    if((*head)->next==(node *)NULL)
    {
        ptr=*head;
        *head=NULL;
        free(ptr);
    }
    else
    {
        loc=*head;
        ptr=(*head)->next;
        while(ptr->next !=NULL)
        {
            loc=ptr;
            ptr=ptr->next;
        }
        loc->next=NULL;
        free(ptr);
    }
}
void deleteAfterElement(node *head,int after)
{
    node *ptr,*loc;
    loc=searchInUnsortedList(head,after);
    if(loc==(node *)NULL)
    return;
    ptr=loc->next;
    loc->next=ptr->next;
    free(ptr);
}

void reverseList(node **head)
{
    node *previousNode, *currentNode, *nextNode;
    currentNode=*head;
    nextNode=currentNode->next;
    previousNode=NULL;
    currentNode->next=NULL;
    while(nextNode !=NULL)
    {
        previousNode=currentNode;
        currentNode=nextNode;
        nextNode=currentNode->next;
        currentNode->next=previousNode;
    }
    *head=currentNode;
}

void deleteList(node **head)
{
    node *ptr;
    while(*head !=NULL)
    {
        ptr=*head;
        *head=(*head)->next;
        free(ptr);
    }
}
