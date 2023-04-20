#include<stdio.h>
#include<stdlib.h>

   typedef struct node1{
        int info;
        struct node1 *prev;
        struct node1 *next;
    }node;
    void createEmptyList(node **head,node **tail)
    {
     *head=*tail=NULL;
    }
    void insertAtBeginning( node **head, node **tail,int item)
    {
        node *ptr;
        ptr=ptr = (node *)malloc(sizeof(node));
        ptr->info=item;
        if(*head==NULL)
        {
            ptr->next=ptr->prev=NULL;
            *head=*tail=ptr;
        }
        else
        {
            ptr->prev=NULL;
            ptr->next=*head;
            (*head)->prev=ptr;
            *head=ptr;
        }
    }
    void peakElement(node *head){
        node *loc,*nloc,*ploc;
        int num;
        
        loc=head->next;
        while(loc!=NULL)
        {
            ploc=loc->prev;
            nloc=loc->next;
            if((ploc->info<loc->info)&&(nloc->info<loc->info))
            {
                num=loc->info;
                break;
            }
            else
            loc=loc->next;
        }
        printf("\nPeak element %d",num);
    }

int main()
{
    node *head,*tail;
    createEmptyList(&head,&tail);
    insertAtBeginning(&head,&tail,5);
     insertAtBeginning(&head,&tail,10);
      insertAtBeginning(&head,&tail,3);
       insertAtBeginning(&head,&tail,2);
       peakElement(head);
}
