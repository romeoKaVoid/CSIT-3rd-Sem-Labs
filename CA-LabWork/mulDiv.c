#include <stdio.h>
#include <conio.h>
#include <math.h>
int n, count = 0;
int binToDecimal(int data)
{
    int decimal = 0, i = 1;
    while (data > 0)
    {
        n = data % 10;
        decimal = decimal + n * i;
        i = i * 2;
        data = data / 10;
    }
    return (decimal);
}
void decToBinary(int data)
{
    int a, b[50], i = 0;
    if (data == 0)
    {
        printf("0");
        return;
    }
    while (data > 0)
    {
        a = data % 2;
        data = data / 2;
        b[i] = a;
        ++i;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", b[j]);
    }
}
void binMul(int num1,int num2){
    int product = 0;
    int dec1 = binToDecimal(num1);
    int dec2 = binToDecimal(num2);
    product = dec1*dec2;
    printf("\nMultiplication result:\n");
    printf("%d x %d = ",num1,num2);
    decToBinary(product);
    printf("\n");
}
void binDiv(int num1, int num2){
    int quo=0,rem = 0;
    int dec1 = binToDecimal(num1);
    int dec2 = binToDecimal(num2);
    if (dec2 == 0)
    {
        printf("Division by zero is not Possible!!\n");
        return;
    }
    quo = dec1/dec2;
    rem = dec1%dec2;
    printf("\nDivision Result:\n");
    printf("Quotient = ");
    decToBinary(quo);
    printf("\n");
    printf("Remainder = ");
    decToBinary(rem);
}
int main()
{
    int a, b;
    printf("Enter the 1st binary number: ");
    scanf("%d", &a);
    printf("Enter the 2nd binary number: ");
    scanf("%d", &b);
    binMul(a,b);
    binDiv(a,b);
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}