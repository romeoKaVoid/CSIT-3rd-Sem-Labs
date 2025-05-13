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
void BinAdd(int num1,int num2){
    int sum = 0;
    int dec1 = binToDecimal(num1);
    int dec2 = binToDecimal(num2);
    sum = dec1 + dec2;
    printf("Addition Result: ");
    printf("%d + %d = ",num1,num2);
    decToBinary(sum);
    printf("\n");
}
void binSub(int num1, int num2){
    int diff=0;
    int dec1 = binToDecimal(num1);
    int dec2 = binToDecimal(num2);
    if (dec1<dec2)
    {
        printf("Negative numbers are not supported for unsigned binary!!\n");
        return;
    }
    printf("Subtraction Result: ");
    diff = dec1-dec2;
    printf("%d - %d = ",num1,num2);
    decToBinary(diff);
}
int main()
{
    int a, b;
    printf("Enter the 1st binary number: ");
    scanf("%d", &a);
    printf("Enter the 2nd binary number: ");
    scanf("%d", &b);
    BinAdd(a,b);
    binSub(a,b);
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}