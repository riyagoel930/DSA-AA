#include <stdio.h>
void cal1D();
void cal2D();
int main()
{

    int ch;
    printf("\n1. Calculate for 1 D array ");
    printf("\n2. Calculate for 2 D array ");
    printf("\nEnter your choice ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: cal1D();
                break;
        case 2: cal2D();
                break;
        default: printf("\nWrong choice ");
    }
    return 0;
}
void cal1D()
{
    int r,base,k,calcu;
    printf("\nEnter no of elements ");
    scanf("%d",&r);
    printf("\nEnter the element address you want to check ");
    scanf("%d",&k);
    printf("\nEnter the base address ");
    scanf("%d",&base);
    calcu=base+(sizeof(int)*k);
    printf("\nThe address of element %d  is %d ",k,calcu);
}
void cal2D()
{
    int r,c,base,i,j,calcur,calcuc,li,lj,ui,uj;
    
     printf("\nEnter lower and upper bound of row ");
    scanf("%d %d",&li,&ui );
     printf("\nEnter lower and upper bound of column");
    scanf("%d %d",&lj,&uj );
    r=(ui-li)+1;
    c=(uj-lj)+1;
  
    printf("\nEnter the element (row and column) whose address you want to check ");
    scanf("%d %d",&i,&j);
    printf("\nEnter the base address ");
    scanf("%d",&base);
    calcuc=base+(sizeof(int)*((r*(j-lj))+(i-li)));
     calcur=base+(sizeof(int)*((c*(i-li))+(j-lj)));
    printf("\nThe address of element(%d,%d) is %d for row major",i,j,calcur);
     printf("\nThe address of element(%d,%d) is %d for column major",i,j,calcuc);
}
