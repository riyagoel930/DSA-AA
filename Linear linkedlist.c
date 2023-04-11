//SINGLE LINEAR LINKEDLIST
#include<stdio.h>
#include<alloc.h>
#include<conio.h>
#include<process.h>

//DECLARATION OF STRUCTURE
typedef struct simplelink 
{
    int data;
    struct simplelink *next;
}node;

//FUN OF CREATE FIRST NODE
node *create(node *p)
{
    p=(node *)malloc(sizeof(node));
    {
        int a;
        printf("\n\n");
        node *brr[25];
        int arr[25];
        a=0;
        while(p!=NULL)
        {
            //printf("\n\n[%d,%u]-->",p->data,p->next);
            arr[a]=p->data;
            brr[a]=p->next;
            p=p->next;
            a++;
        }
        //printf("NULL");
        for(int i=(a-1);i>=0;i--)
        printf("[%d,%u]<--",arr[i],brr[i]);
        printf("HEAD");
        printf("\n\n\npress any key to continue......");
        getch();
    }
    //FUN OF INSERT AT BEGINING
    node *insert_begin(node *p)
    {
        node *temp;
        temp=(node *)malloc (sizeof(node));
        printf("\nEnter the inserted data: ");
        scanf("%d",&temp->data);
        p=temp;
        return (p);
    }
    //FUN OF INSERT AT END
    node *insert_end(node *p)
    {
        node *temp,*q;
        a=p;
        temp=(node *)malloc(sizeof(node));
        printf("\nEnter the inserted data: ");
        scanf("%d",,&temp->data);
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next-temp;
        temp->next=(node *)NULL;
        return(q);
        }
        //FUN OF INSERT AFTER ELEMENT
        node *insert_after(node *p)
        {
            node *temp,*q;
            int x;
            q=p;
            printf("\nEnter the data(after which you enter data: ");
            scanf("%d",&x);
            while(p->data!=x)
            {
                p=p->next;
            }
            temp=(node *)malloc(sizeof(node));
            printf("\nEnter the inserted data: ");
            scanf("%d",&temp->data);
            p->next=temp;
            return(q);
            }
            //FUN OF COUNT THE NO. OF NODES
            int xount(node *p)
            {
                int i=0;
                while(p!=NULL)
                {
                    p=p->next;
                    i++;
                    return(i);
            }
            //FUN  OF INSERT AT SPECIFIC POSITION
            node *insert_at_spe_pos(node *p)
            {
                node *temp_at_spe_pos(node *p)
                {
                    node *temp,*q,*r;
                    int x,a,i=1;
                    a=count(p);
                    q=p;
                    printf("\nEnter the position(at which you want to enter data: ");
                    sacnf("%d",&x);
                    if(x>(a+1))
                    {
                        printf("Not able toinsert node at such position: ");
                        getch();
                    }
                    else
                    {
                        if(x==1)
                        {
                            temp=(node *)malloc(sizeof(node));
                            printf("\nEnter the insert data: ");
                            scanf("%d",&temp->data);
                            temp->next=p;
                            q=temp;
                        }
                        else
                        {
                            while(i!=x)
                            {
                                r=p;
                                p=p->next;
                                i++;
                            }
                            temp=(node *)malloc(sizeof(node));
                            printf("\nEnter the inserted data: ");
                            scanf("%d",&temp->data);
                            r->next=temp;
                        }
                    }
                    return(q);
                }
                //FUN OF DELETE LAST NODE
                node *delend(node *p)
                {
                    node *q,*r;
                    r=p;
                    q=p;
                    if(p->next=NULL)
                    {
                        r=(node *)NULL;
                    }
                    else
                    {
                        while(p->next!=NULL)
                        {
                            q=p;
                            p=p->next;
                        }
                        q->next=(node *)NULL;
                    }
                    free(p);
                    return(r);
                }
                //FUN OF DELETE SPECIFIC ELEMENT
                node *del_speci_ele(node *p)
                {
                    node *q,*r;
                    int x;
                    q=p;
                    r=q;
                    printf("Enter the data toremove: ");
                    scanf("%d",&x);
                    while(q->data!=x)
                    {
                        r=q;
                        q=q->next;
                    }
                    if(q==r)
                    p=p->next;
                    else
                    r->next=q->next;
                    free(q);
                    return(p);
                }
                //FUN OFDELETE FIRST node
                node *delbegin(node *p)
                {
                    node *q;
                    q=p;
                    p=p->next;
                    free(q);
                    return(p);
                }
                //FUN OF DELETE NODE AT SPECIFIC POSITION
                node *delete_at_spe_pos(node *p)
                {
                    node *temp,*q,*r;
                    int x,a,i-1;
                    a=count(p);
                    q=p;
                    printf("\nEnter the position(at which youwanttoremove data: ");
                    scanf("%d",&x);
                    if(x>(a))
                    {
                        printf("Not able to remove node at such position: ");
                        getch();
                    }
                    else
                    {
                        if(x==1)
                        {
                            q=q->next;
                            free(p);
                        }
                        else{
                            while(1!=x)
                            {
                                r=p;
                                p=p->next;
                                i++;
                            }
                            r->next=p->next;
                            free(p);
                        }
                    }
                    return(q);
                }
                //FUN OF REVERSE THE LIST
                node *reverse(node *p)
                {
                    node *q,*r;
                    q=(node *)NULL;
                    while(p!=NULL)
                    {
                        r=q;
                        q=p;
                        p=p->next;
                        q->next=r;
                    }
                    return(q);
                }
                //FUN OF MAIN SCREEN
                void screen(node *dead)
                {
                    clscr();
                    int ch,a;
                    printf("\t\t\t      SINGLE LINEAR LINKED LIST");
                    PRINTF("\n\t\t\t************************************");
                    printf("\n\n  OPTIONS ARE--");
                    printf("\n~~~~~~~~~~~~~~~~~~~~");
                    printf("\n\n 0-Exit");
                    printf("\n\n 1-Create first node");
                     printf("\n\n 2-Insert at beginning");
                      printf("\n\n 3-Insert at end");
                       printf("\n\n 4-Insert after element");
                        printf("\n\n 5-Insert at specific position");
                        printf("\n\n 6-Delete at end");
                     printf("\n\n 7-Delete at begining");
                      printf("\n\n 8-Delete afterelement");
                       printf("\n\n 9-Delete specific element");
                        printf("\n\n 10-Delete element after specific position ");
                         printf("\n\n 11-Traverse in order(Display)");
                          printf("\n\n 12-Traverse in reverse order");
                           printf("\n\n  13-Count no. of node");
                            printf("\n\n  14-Reversed Linked List");
                             printf("\n\n  -----------------------------------------------------------------------");
                              printf("\n\n Enter the choice:");
                              //printf("\n");
                              scanf("%d",&ch);
                              printf("\n-------------------------------------------------------");
                              switch(ch)
                              {
                                  case 0:
                                  exit(0);
                                  case 1:
                                  head=create(head);
                                  //display(head)
                                  
                                  break;
                                  case 2:
                                  head=insert_begin(head);
                                  break;
                                   case 3:
                                  head=insert_end(head);
                                  break; 
                                  case 4:
                                  head=insert_after(head);
                                  break;
                                   case 5:
                                  head=insert_at_spe_pos(head);
                                  break;
                                   case 6:
                                  head=delend(head);
                                  break;
                                   case 7:
                                  head=delbegin(head);
                                  break;
                                   case 8:
                                  head=delete_after(head);
                                  break;
                                   case 9:
                                  head=del_speci_ele(head);
                                  break;
                                   case 10:
                                  head=delete_at_spe_pos(head);
                                  break;
                                   case 11:
                                  display(head);
                                  break;
                                   case 12:
                                  revdisplay(head);
                                  break;
                                   case 13:
                                  a=count(head);
                                  printf("The no. of node in list-:%d",a);
                                  printf("\n\n\npress any key to continue..........");
                                  getch();
                                  break;
                                  case 14:
                                  head=reverse(head);
                                  break;
                                  default:
                                  printf("\n\n\nPlease enter the right choice.....");
                                  getch();
                                  break;
                              }
                              screen(head);
                }
                //DECLARATION OF MAIN
                void main()
                {
                    clscr();
                    node *head;
                    //int a,ch;
                    head=(node *)NULL;
                    screen(head);
                    getche();
                }
                printf("Enter the data: ");
                scanf("%d",&p->data);
                p->next=(node *)NULL;
                return(p);
            }
            //FUN OF TRASVERSE IN ORDER
            void display(node *p)
            {
                printf("\n\n");
                while(p!=NULL)
                {
                    printf("[%d,%u]-->",p->data,p->next);
                    p=p->next;
                }
                printf("NULL");
                printf("\n\n\npress any key to continue......");
                getch();
            }
            
                }
            }
            
                }
                               
