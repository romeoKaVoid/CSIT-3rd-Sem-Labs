#include<stdio.h>
#include<conio.h>
#include<string.h>
int precedency(char);
int alpha(char);
int main()
{
    int ptos=-1, otos=-1,length;
    char infix[100],prestack[100],opstack[100];
    printf("Enter the Valid Infix Expression:\n");
    gets(infix);
    length = strlen(infix);
    for (int i = length-1; i >=0; i--)
    {
        if (infix[i]==')')
        {
            opstack[++otos] = infix[i];
        }
        else if(alpha(infix[i])){
            prestack[++ptos] = infix[i];
    }
    else if(infix[i] =='('){
        while (opstack[otos]!=')')
        {
            prestack[++ptos] = opstack[otos];
            otos--;
        }
        otos--;
    }
    else{
        if(precedency(opstack[otos])>=precedency(infix[i])){
            prestack[++ptos] = opstack[otos];
            otos--;
            // opstack[++otos] = infix[i];
        }
        opstack[++otos] = infix[i];
        }
    }
    while (otos!=-1)
    {
        prestack[++ptos] = opstack[otos];
        otos--;
    }
    printf("The Prefix Expression is:\n");
    for (int i = ptos; i >=0; i--)
    {
        printf("%c",prestack[i]);
    }
    printf("\n\n\tBy Krishna Aryal");
    return 0;
    }
int precedency(char ch)
{
    switch (ch)
    {
    case '$':
    case '^':
        return(4);
        break;
    case '*':
    case '/':
        return(3);
        break;
    case '+':
    case '-':
        return(2);
        break;
    default:
    return(1);
        break;
    }
}
int alpha(char ch){
    int a=ch;
    if ((a>=65&&a<=90)||(a>=97&&a<=122))
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
