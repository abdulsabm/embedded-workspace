#include <stdio.h>
#include <math.h> // Required for fabs()

// Function to calculate sine using Taylor Series expansion
double calculateSine(double degrees) {
    // Step 1: Convert degrees to radians (Taylor series requires radians)
    // Formula: radians = degrees * (pi / 180)
    double x = degrees * (3.14159265358979323846 / 180.0);

    double sum = x;      // First term of the series (x^1 / 1!)
    double term = x;     // Tracks the value of the current term
    int i = 1;

    // Step 2: Loop to accumulate terms until the value becomes negligible
    while (1) {
        // Optimization: Calculate the next term using the previous term.
        // term_next = - (term_prev * x^2) / ((2*i) * (2*i + 1))
        // This avoids computing huge factorials and powers from scratch, preventing overflow.
        term = -term * x * x / ((2.0 * i) * (2.0 * i + 1.0));
        
        sum += term;

        // Check for convergence (if the term is extremely close to 0, stop)
        if (fabs(term) < 1e-15) {
            break;
        }

        i++;
        
        // Safety cap to prevent infinite loops for extremely large inputs
        if (i > 100) {
            break;
        }
    }

    return sum;
}

int main() {
    double degrees;

    // Prompt user for input
    printf("Enter angle in degrees (x): ");
    if (scanf("%lf", &degrees) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    // Call the function by passing the value (Call by Value)
    double result = calculateSine(degrees);

    // Print the result
    printf("Sine of %.2f degrees is: %.6f\n", degrees, result);

    return 0;
}