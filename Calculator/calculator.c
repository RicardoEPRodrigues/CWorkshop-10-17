#include <stdio.h>

/* This is a declaration of a function.
 * The implementation is below main.
 * This allows main to use function that haven't been defined yet.
 */

float add(float value);

float subtract(float value);

float multiply(float value);

float divide(float value);

float clear();

/* This is were the program starts */
int main() {
    /* This variable store the value of the calculator at any time. */
    float value = 0.0f;
    int input = 0;

    printf("Hello! Welcome to the CWorkshop Calculator!\n");
    do {
        /* prints available options */
        printf("\nVALUE: %.2f\n\n", value);
        printf("0 - Exit; 9 - Clear;\n");
        printf("1 - Add; 2 - Subtract; 3 - Multiply; 4 - Divide;\n");

        /* Asks for what option to use */
        printf("INPUT: ");
        scanf("%d", &input);
        printf("\n\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n\n");

        /* See what to do with the input given */
        switch (input) {
            case 1:
                value = add(value);
                break;
            case 2:
                value = subtract(value);
                break;
            case 3:
                value = multiply(value);
                break;
            case 4:
                value = divide(value);
                break;
            case 9:
                value = clear();
                break;
            case 0:
            default:
                break;
        }
    } while (input != 0);

    return 0;
}

/* Adds a given amount to value. */
float add(float value) {
    float scanValue = 0;
    printf("%.2f + ", value);
    /* Asks for the value to add */
    scanf("%f", &scanValue);
    /* Adds the value and returns it. */
    return value + scanValue;
}

/* The following function use the same mechanic as add(); */

float subtract(float value) {
    float scanValue = 0;
    printf("%.2f - ", value);
    scanf("%f", &scanValue);
    return value - scanValue;
}

float multiply(float value) {
    float scanValue = 0;
    printf("%.2f * ", value);
    scanf("%f", &scanValue);
    return value * scanValue;
}

float divide(float value) {
    float scanValue = 0;
    printf("%.2f / ", value);
    scanf("%f", &scanValue);

    if (scanValue == 0) {
        printf("Can't divide by Zero!");
        return value;
    }
    return value / scanValue;
}

float clear() {
    printf("Clearing Value\n");
    return 0;
}
