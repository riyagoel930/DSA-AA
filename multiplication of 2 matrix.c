#include <stdio.h>
int main()
{
    int i,j,k,m,n,a[20][20],b[20][20],c[20][20];
    printf ("enter no. of rows and column in a matrix:");
    scanf("%d %d",&m,&n);
    printf("\nEnter the element of first matrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
         scanf("%d",&a[i][j]);   
        }
    }
    printf("Enter the element of second matrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
         scanf("%d",&b[i][j]);   
        }
    }
    printf("First matrix is:\n");
      for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
        printf(" %d ",a[i][j]);   
        }
        printf("\n");
    }
    printf("second matrix is:\n");
      for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
        printf(" %d ",b[i][j]);   
        }
        printf("\n");
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
              c[i][j] =c[i][j]+(a[i][k]*b[k][j]);  
            }
        }
    }
            printf("resultant matrix is:\n");
      for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
        printf(" %d ",c[i][j]);   
        }
        printf("\n");
    }
    return 0;
}

OUTPUT:-
enter no. of rows and column in a matrix:3
3

Enter the element of first matrix:
1
2
3
4
5
6
7
8
9
Enter the element of second matrix:
9
8
7
6
5
4
3
2
1
First matrix is:
 1  2  3 
 4  5  6 
 7  8  9 
second matrix is:
 9  8  7 
 6  5  4 
 3  2  1 
resultant matrix is:
 30  24  18 
 84  69  54 
 138  114  90 
