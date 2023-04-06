#include <stdio.h>

int main()
{
    int a[30],n,i,pos,temp,flag=0;
    printf("\nENter no of elements of array");
    scanf("%d",&n);
    printf("\nEnter elements of array ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("\nEnter value to find in array ");
    scanf("%d",&temp);
    for(i=0;i<n;i++)
    {
        if(a[i]==temp)
        {
            flag=1;
            break;
            pos=i;
        }
        else
        flag=0;
    }
   if(flag==1)
   printf("\nValue found at index %d",i);
   else
   printf("\nValue not found" );
}
