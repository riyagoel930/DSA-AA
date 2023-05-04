#include <stdio.h>
void towerofhonoi(char from,char to,char other,int n)
{
    if(n==1)
    {
        printf("Move disk from  %c to %c\n",from,to);
        }
        else
        {
    towerofhonoi(from,other,to,n-1);
    towerofhonoi(from,other,to,1);
    towerofhonoi(other,to,from,n-1);
        }
}
    int main()
    {
        int noofdisk;
        printf("Enter no. of disks: ");
        scanf("%d",&noofdisk);
        towerofhonoi('A','C','B',noofdisk);
        
    }


//output:
Enter no. of disks: 3
Move disk from  A to C
Move disk from  A to C
Move disk from  C to B
Move disk from  A to B
Move disk from  B to A
Move disk from  B to A
Move disk from  A to C

