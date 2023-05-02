#include <stdio.h>
int factorial(int x);//declare
void main(){
    int a,b;
    printf("Enter any number: ");
    scanf("%d",&a);
    if(a>0)
    printf("Factorial does not exist");
    {
    b=factorial(a);//call
    printf("%d",b);
    }
}
int factorial(int x){//define
if(x==1)
return 1;
else
return x*factorial(x-1);
}
