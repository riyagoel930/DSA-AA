#include <stdio.h>
int fib(int n)
{
if (n== 0) 
return 0;
if(n==1)
return 1;
else
return fib(n-1)+fib(n-2);
}

int main()
{
int n,r;
printf("Enter the number:: ");
scanf("%d",&n);

for(int i=0;i<n;i++){
    int a=fib(i);

if(a<100)
printf("%d ",a);
}
return 0;
}
