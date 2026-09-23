#include <stdio.h>

// Optimized nPr calculation avoiding intermediate overflow
long long nPr(int n, int r) {
    if (r < 0 || r > n) return 0;

    long long result = 1;
    for (int i = 0; i < r; i++) {
        result *= (n - i);
    }
    return result;
}

// Optimized nCr calculation dividing continuously to avoid overflow
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    
    // Symmetry property: nCr(n, r) == nCr(n, n-r)
    if (r > n / 2) r = n - r;

    long long result = 1;
    for (int i = 1; i <= r; i++) {
        result *= (n - i + 1);
        result /= i; // Always divides evenly at step i
    }
    return result;
}

int main() {
    int n, r;

    printf("Enter two numbers (n and r): ");
    if (scanf("%d %d", &n, &r) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    if (r > n || n < 0 || r < 0) {
        printf("Invalid input: Ensure n >= 0, r >= 0, and n >= r.\n");
        return 1;
    }

    printf("nCr (%dC%d) = %lld\n", n, r, nCr(n, r));
    printf("nPr (%dP%d) = %lld\n", n, r, nPr(n, r));

    return 0;
}