#include<stdio.h>
#include<conio.h>
void TOH(int,char,char,char);
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    TOH(n,'S','D','T');
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}
void TOH(int a,char s,char d,char t){
    if (a==0)
    {
        printf("Disk not Found!!\n");    
    }
    else if (a==1)
    {
        printf("Move disk %d from %c to %c.\n",a,s,d);
    }
    else{
        TOH(a-1,s,t,d);
        printf("Move disk %d from %c to %c.\n",a,s,d);
        TOH(a-1,t,d,s);
    }
}