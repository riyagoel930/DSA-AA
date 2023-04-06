#include <stdio.h>

int main()
{
    int a[30],n,i,temp;
    printf("\nENter no of elements of array");
    scanf("%d",&n);
    printf("\nEnter elements of array ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("\nElements of array before reversal ");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    for(i=0;i<n/2;i++)
    {
        temp=a[i];
        a[i]=a[n-(i+1)];
        a[n-(i+1)]=temp;
    }
    printf("\nElements of array after reversal ");
     for(i=0;i<n;i++)
    printf("%d ",a[i]);
}
