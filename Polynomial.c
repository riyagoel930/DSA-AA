#include <stdio.h>
typedef struct nodeType
{
int coeff;
int power;
struct nodeType *next;
}node;
void main()
{//declaration of local variable
node *poly1,*poly2,*poly3;
int choice,element,after,before;
//function prototypes
void readPolynomial(node **);
void addpoly(node *,node *,node **);

void addNode(node **,float,int);
void printPolynomial(node *);
poly1=poly2=poly3=NULL;
clrscr();
printf("\nProgram to add two Polynomials----");
printf("Enter first polynimial: ");
readPolynomial(&poly1);
printf("Enter second polynimial: ");
readPolynomial(&poly2);
addpoly(poly1,poly2,&poly3);
printf("\nSum of polynomial\n");
printPolynomial(poly1);
printf("\nand\n");
printPolynomial(poly2);
printf("\nis\n");
printPolynomial(poly3);
getch();
}
//Function to add term t the beginning of the list
void addNode(node **ptr,float coef,int powe)
{
    node *tempPtr;
    tempPtr=(node *)malloc(sizeof(node));
    tempPtr->coeff=coef;
    tempPtr->power=powe;
    if(*ptr==NULL)
    {
	tempPtr->next=NULL;
	*ptr=tempPtr;
    }
    else
    {
	tempPtr->next=*ptr;
	*ptr=tempPtr;
    }
}
//Function to read a polynomail
void readPolynomial(node **p)
{
    int coficient,power;
    printf("\nEnter the terms in ascnding order of power: ");
    while(1){
	printf("\nEnter the degree of x: ");
	scanf("%d",&power);
	printf("\nEnter its coficient: ");
	scanf("%d",&coficient);
	addNode(p,coficient,power);
	printf("\nAny more term (Y/N): ");
	if(toupper(getch())!='Y');
	break;
    }
}
//function to print the polynomial
void printPolynomial(node *ptr)
{
    if(ptr!=NULL)
    printf("%dx^%d",ptr->coeff,ptr->power);
    {
	if(ptr->coeff > 0)
	printf(" + ");
	 if(ptr->power == 0)
	printf("%d",ptr->coeff);
	else if(ptr->power == 1)
	printf("%dx",ptr->coeff);
	else
	printf("%d%dx",ptr->coeff,ptr->power);
    }
}
void addpoly(node *ptr1,node *ptr2,node **ptr3)
{//Function to add two Polnomial
int powe;
float coef;
    while((ptr1!=NULL)&&(ptr2!=NULL)){
	if(ptr1->power >ptr2->power)
	{
	    coef=ptr1->coeff;
	    powe=ptr1->power;
	    ptr1=ptr1->next;
	}
	else
	if(ptr2->power>ptr1->power)
	{
	coef=ptr2->coeff;
	powe=ptr2->power;
	ptr2=ptr2->next;
	}
	else
	{
	    coef=ptr1->coeff + ptr2->coeff;
	    powe=ptr1->power;
	    ptr1=ptr1->next;
	    ptr2=ptr2->next;
	}
	if(coef!=0)
	addNode(ptr3,coef,powe);
    }
	if(ptr1==NULL)
	{
	    for( ;ptr2!=NULL;ptr2=ptr2->next)
	    addNode(ptr3,ptr2->coeff,ptr2->power);
	}else
	if(ptr2 ==NULL)
	{
	     for( ;ptr1!=NULL;ptr1=ptr1->next)
	    addNode(ptr3,ptr1->coeff,ptr1->power);
	}
    }
