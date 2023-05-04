#include <stdio.h>
#include<conio.h>
int binarysearch(int a[],int beg,int end,int element);
void main(){
    int a[10];
    int i,x,element,res;
    printf("\nEnter size of array: ");
    scanf("%d",&x);
    for(i=0;i<x;i++)
    scanf("%d",&a[i]);
      printf("\nEnter size to find ");
      scanf("%d",&element);
      res=binarysearch(a,0,x-1,element);
      if(res>=0)
      printf("\nValues found at index %d",res);
      else
	printf("\nValues not found");
	getch();
}
int binarysearch(int a[],int beg,int end,int element)
{
    if(beg<=end)
    {
	int mid=(beg+end)/2;
	if(a[mid]==element)
	return mid;
	else

	if(a[mid]<element)
	return binarysearch(a,mid+1,end,element);
	else
	return binarysearch(a,mid-1,end,element);
    }
    return -1;
}
