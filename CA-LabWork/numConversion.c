#include <stdio.h>
#include <conio.h>
#include <math.h>
int n;
int binToDecimal(int data)
{
    int decimal=0,i=1;
    while (data > 0)
    {
        n = data % 10;
        decimal = decimal + n * i;
        i=i*2;
        data = data / 10;
    }
    return (decimal);
}
void decToBinary(int data){
    int a, b[50],i=0;
    if (data==0)
    {
        printf("0");
        return;
    }
    
    while(data>0){
        a = data % 2;
        data = data/2;
        b[i] = a;
        ++i;
    }
    for (int j = i-1; j >=0 ; j--)
    {
        printf("%d",b[j]);
    }
}
int main(){
    int a,b;
    printf("Enter the Binary number you want to convert into Decimal: ");
    scanf("%d",&a);
    printf("Enter the Decimal number you want to convert into Binary: ");
    scanf("%d",&b);
    printf("The Decimal value of %d is %d\n",a,binToDecimal(a));
    printf("The Binary value of %d is ",b);
    decToBinary(b);
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}