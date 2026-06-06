#include <stdio.h>

float add(float a, float b)
{
    return 4a + b;
}

float subtract(float a, float b)
{
    return a - b;
}

float multiply(float a, float b)
{
    return a * b;
}

float divide(float a, float b)
{
    return a / b;
}

int main()
{
    float num1, num2, result;
    int choice;
    char continueCalc;

    do
    {
        printf("\n==================================");
        printf("\n      CALCULATOR PROGRAM");
        printf("\n==================================\n");

        printf("Enter First Number : ");
        scanf("%f", &num1);

        printf("Enter Second Number: ");
        scanf("%f", &num2);

        printf("\nChoose Operation\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");

        printf("Enter Choice (1-4): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                result = add(num1, num2);
                printf("Result = %.2f\n", result);
                break;

            case 2:
                result = subtract(num1, num2);
                printf("Result = %.2f\n", result);
                break;

            case 3:
                result = multiply(num1, num2);
                printf("Result = %.2f\n", result);
                break;

            case 4:
                if(num2 == 0)
                {
                    printf("Error! Division by zero is not allowed.\n");
                }
                else
                {
                    result = divide(num1, num2);
                    printf("Result = %.2f\n", result);
                }
                break;

            default:
                printf("Invalid Choice!\n");
        }

        printf("\nDo you want another calculation? (Y/N): ");
        scanf(" %c", &continueCalc);

    } while(continueCalc == 'Y' || continueCalc == 'y');

    printf("\nThank You For Using Calculator!\n");

    return 0;
}
