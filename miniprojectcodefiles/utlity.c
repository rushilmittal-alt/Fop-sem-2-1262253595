#include <stdio.h>

void sys_info() {
    printf("--- MiniOS System Info ---\n");
    printf("Compiled on: %s at %s\n", __DATE__, __TIME__);
    printf("Dev Team: CSE Group 4\n");
}

void simple_calc() {
    double a, b;
    char op;

    printf("Enter calculation (e.g., 5 + 3): ");
    scanf("%lf %c %lf", &a, &op, &b);
    getchar(); // Clean buffer

    if (op == '+') printf("Result: %.2f\n", a + b);
    else if (op == '-') printf("Result: %.2f\n", a - b);
    else if (op == '*') printf("Result: %.2f\n", a * b);
    else if (op == '/') printf("Result: %.2f\n", a / b);
    else printf("Invalid operator.\n");
}
