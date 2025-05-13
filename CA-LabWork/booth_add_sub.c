#include <stdio.h>

int twos_complement(int num, int n) {
    // To get 2's complement, invert the bits and add 1
    return ((1 << n) - num);
}

void booth_addition(int num1, int num2) {
    int n = 8;  // 8-bit
    int sum = num1 + num2;

    // Ensure the sum is within the 8-bit signed range (-128 to 127)
    if (sum > 127) {
        sum -= 256;  // Overflow, wrap around
    }
    else if (sum < -128) {
        sum += 256;  // Underflow, wrap around
    }

    printf("Booth's Addition result: %d\n", sum);
}

void booth_subtraction(int num1, int num2) {
    int n = 8;  // 8-bit
    // To subtract, add the 2's complement of num2
    int num2_twos_complement = twos_complement(num2, n);
    int difference = num1 + num2_twos_complement;

    // Ensure the difference is within the 8-bit signed range (-128 to 127)
    if (difference > 127) {
        difference -= 256;  // Overflow, wrap around
    }
    else if (difference < -128) {
        difference += 256;  // Underflow, wrap around
    }

    printf("Booth's Subtraction result: %d\n", difference);
}

int main() {
    int num1, num2;

    // Input for both addition and subtraction
    printf("Enter first number (signed 8-bit): ");
    scanf("%d", &num1);
    printf("Enter second number (signed 8-bit): ");
    scanf("%d", &num2);

    // Perform both Booth's addition and subtraction
    booth_addition(num1, num2);
    booth_subtraction(num1, num2);
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}
