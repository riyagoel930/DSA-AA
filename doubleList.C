#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct doublelklist{
	int info;
	struct doublelklist *next;
	struct doublelklist *prev;
}node;
int main(){
	void insert_at_beg(node **,node **,int);
	void insert_at_end(node **,node **,int);
	void insert_after(node **,node **,int,int);
	void insert_before(node **,node **,int,int);
	void delete_from_beg(node **,node **);
	void delete_from_end(node **,node **);
	void delete_after(node **,node **,int);
	void delete_before(node **,node **,int);
	void rev_traverse(node *);
	void traverse(node *);
	int choice,item,n;
	node *head;
	node *tail;
	head=tail=NULL;
	while(1){
		printf("\NDOUBLLY LINKED LIST------------\n");
		printf("1-Insert at begening\n2-Insert at end\n3-Insert after node\n4-Insert before node\n5-Traverse\n6-Exit\n7-reverse Traversing\n8-Delete from start\n9- Delete from end\n10- Delete after a value\n11- Delete before a value\n");
		printf("Enter the index of operation you want to perform\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("Enter the value of the node\n");
				   scanf("%d",&item);
				   insert_at_beg(&head,&tail,item);
				   break;
			case 2:printf("Enter the value of the node\n");
				   scanf("%d",&item);
				   insert_at_end(&head,&tail,item);
				   break;
			case 3:printf("Enter the value of the node\n");
				   scanf("%d",&item);
				   printf("Enter the value after which you want to insert node\n");
				   scanf("%d",&n);
				   insert_after(&head,&tail,item,n);
				   break;
			case 4:printf("Enter the value of the node\n");
				   scanf("%d",&item);
				   printf("Enter the value before which you want to insert node\n");
				   scanf("%d",&n);
				   insert_before(&head,&tail,item,n);
				   break;
			case 5:traverse(head);
				   break;
			case 6:getch();
				   exit(0);
				   break;
			case 7:rev_traverse(tail);
				   break;
			case 8:delete_from_beg(&head,&tail);
			       break;
			case 9:delete_from_end(&head,&tail);
			       break;
			case 10:printf("Enter the number before which you want to delete the node\n");
				scanf("%d",&n);
				delete_after(&head,&tail,n);
			       break;
			case 11:printf("Enter the number before which you want to delete the node\n");
				scanf("%d",&n);
				delete_before(&head,&tail,n);
			       break;

			default:printf("Wrong Input\n");
		}
	}
}
void insert_at_beg(node **start,node **end,int item){
	node *temp=(node*)malloc(sizeof(node));
	temp->info=item;
	temp->next=NULL;
	temp->prev=NULL;
	if(*start==NULL){
		*start=*end=temp;
	}
	else{
		(*start)->prev=temp;
		temp->next= *start;
	}
	*start=temp;
}
void insert_at_end(node **start,node **end,int item){
	node *temp=(node*)malloc(sizeof(node));
	temp->info=item;
	temp->next=NULL;
	temp->prev=NULL;
	if(*start==NULL){
		*start=*end=temp;
	}
	else{
	   (*end)->next=temp;
		temp->prev=*end;
	}
	*end=temp;
}


void traverse(node *start){
	while(start!=NULL){
		printf("%d ",start->info);
		start=start->next;
	}
	printf("\n");
}
void rev_traverse(node *end){
	while(end!=NULL){
		printf("%d ",end->info);
		end=end->prev;
	}
	printf("\n");
}
node * search(node *start,int n){
    while(start!=NULL){
	if(start->info==n){
	    return start;
	}
	start=start->next;
    }
return NULL;
}
void insert_after(node **start,node **end,int item,int n){
	node *temp=(node*)malloc(sizeof(node));
	node *loc;
	temp->info=item;
	temp->next=NULL;
	temp->prev=NULL;
	loc=search(*start,n);
	if(loc==NULL){
	    return;
	}
	else{

	    if(loc->next==NULL){
		loc->next=temp;
		temp->prev=loc;
		*end=temp;
	    }
	    else{
		temp->prev=loc;
		temp->next=loc->next;
		(loc->next)->prev=temp;
		loc->next=temp;
	    }
	}

}
void insert_before(node **start,node **end,int item,int n){
	node *temp=(node*)malloc(sizeof(node));
	node *loc;
	temp->info=item;
	temp->next=NULL;
	temp->prev=NULL;
	loc=search(*start,n);
	if(loc==NULL){
	    return;
	}
	else{

	    if(loc->prev==NULL){
		loc->prev=temp;
		temp->next=loc;
		*start=temp;
	    }
	    else{
		temp->next=loc;
		temp->prev=loc->prev;
		(loc->prev)->next=temp;
		loc->prev=temp;
	    }
	}

}
void delete_from_beg(node **start,node **end){
    node *temp;
    if(*start==*end){
       temp=*start;
       *start=*end=NULL;
    }
    else{
	temp=*start;
	(temp->next)->prev=NULL;
	*start=temp->next;
    }
    free(temp);
}

void delete_from_end(node **start,node **end){
    node *temp;
    if(*start==*end){
       temp=*start;
       *start=*end=NULL;
    }
    else{
	temp=*end;
	(temp->prev)->next=NULL;
	*end=temp->prev;
    }
    free(temp);
}
void delete_after(node **start,node **end,int n){
    node *loc=search(*start,n);
    node *temp;
    if(loc->next==NULL){
	printf("There is no node after %d\n",n);
	return;
    }
    else{
	temp=loc->next;
	if(loc->next->next==NULL){
	    loc->next=NULL;
	    *end=loc;
	}
	else{
	    loc->next=temp->next;
	    (temp->next)->prev=loc;
	}
	free(temp);
    }
}
void delete_before(node **start,node **end,int n){
    node *loc=search(*start,n);
    if(loc->prev==NULL){
	printf("There is no node before %d\n",n);
	return;
    }
    else{
	if((loc->prev)->prev==NULL){
	    delete_from_beg(&(*start),&(*end));
	}
	else{
	    node *temp=loc->prev;
	    (temp->prev)->next=loc;
	    loc->prev=temp->prev;
	    free(temp);
	}
    }
}
