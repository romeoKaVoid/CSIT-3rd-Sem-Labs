#include <stdio.h>

void booth_multiply(int multiplier, int multiplicand)
{
    int m = multiplier, q = multiplicand;
    int m_neg = -m;
    int n = 8;     // 8-bit
    int a = 0;     // Accumulator (A)
    int q_1 = 0;   // Q-1 (previous bit of Q)
    int count = n; // Number of bits

    printf("Booth's Multiplication:\n");

    while (count > 0)
    {
        if ((q & 1) == 0 && q_1 == 1)
        {
            // Case 1: 10 - A = A + M (Add M to A)
            a = a + m;
        }
        else if ((q & 1) == 1 && q_1 == 0)
        {
            // Case 2: 01 - A = A - M (Subtract M from A)
            a = a + m_neg;
        }

        // Arithmetic right shift (A, Q, and Q-1)
        q_1 = q & 1;
        q = (q >> 1) | ((a & 1) << (n - 1));
        a = (a >> 1);

        count--;
    }
    printf("%d x %d = %d\n",multiplier,multiplicand, (a << n) + q); // Concatenate A and Q
}

void booth_divide(int dividend, int divisor)
{
    int quotient = 0, remainder = 0;
    int n = 8; // 8-bit
    int neg_divisor = -divisor;

    if (divisor == 0)
    {
        printf("Error: Division by zero!\n");
        return;
    }

    printf("Booth's Division:\n");

    for (int i = n - 1; i >= 0; i--)
    {
        // Shift the remainder and quotient
        remainder = (remainder << 1) | ((dividend >> i) & 1);
        quotient = quotient << 1;

        // If remainder >= divisor, subtract divisor from remainder
        if (remainder >= divisor)
        {
            remainder -= divisor;
            quotient |= 1; // Set least significant bit to 1
        }
        // If remainder < 0, add divisor back to remainder
        else if (remainder < neg_divisor)
        {
            remainder += divisor;
            quotient &= ~1; // Set least significant bit to 0
        }
    }
    printf("Quotient: %d, Remainder: %d\n", quotient, remainder);
}

int main()
{
    int n1, n2, n3, n4;

    // Input for both multiplication and division
    printf("Enter multiplier and multiplicand for Multiplication: ");
    scanf("%d%d", &n1, &n2);
    booth_multiply(n1, n2);
    printf("\nEnter divisor and dividend for Division: ");
    scanf("%d%d", &n3, &n4);
    booth_divide(n3, n4);
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}
