#include<stdio.h>
#include<stdlib.h>
#define Max 3
void push(int stack[],int *top,int item);
int pop(int stack[],int *top);
int peak(int stack[],int *top);
void main()
{
    int stack[Max],top=-1,ch,item;
    while(1)
    {
        printf("\n1. Push ");
        printf("\n2. Pop ");
        printf("\n3. Peak");
        printf("\n4. Exit");
        printf("\nEnter your choice ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(top==Max-1)
                    printf("\nOverflow");
                    else
                    {
                        printf("\nEnter element ");
                        scanf("%d",&item);
                        push(stack,&top,item);
                    }
                    break;
            case 2: if(top==-1)
                    printf("\nUnderflow");
                    else
                    {
                        item=pop(stack,&top);
                        printf("%d",item);
                    }
                    break;
          case 3:   if(top==-1)
                    printf("\nList is empty");
                    else
                    {
                    item = peak(stack,&top);
                    printf("\nPeak element is %d",item);
                    }
            case 4: exit(0);
        }
    }
}
void push(int stack[],int *top,int item)
{
    (*top)++;
    stack[*top]=item;
}
int pop(int stack[],int *top)
{
    int item;
    item=stack[*top];
    (*top)--;
    return item;
    
}
int peak(int stack[],int *top)
{
    int item;
    item=stack[*top];
    return item;
}
