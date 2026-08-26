// 1.8.20

#include <math.h>
#include <stdio.h>

int main() {
    float a, b, esp;
    int count = 0;
    printf("Please, enter the beginning of the segment:\n");
    scanf("%f", &a);
    while (a <= 0) {
        printf("Input error. Enter value a > 0:\n");
        scanf("%f", &a);
    }

    printf("Please, enter the end of the segment:\n");
    scanf("%f", &b);
    while (b <= a) {
        printf("Input error. Enter value b > a:\n");
        scanf("%f", &b);
    }

    printf("Please, enter value esp:\n");
    scanf("%f", &esp);
    while (esp <= 0 || esp >= 1) {
        printf("Input error. Enter value esp > 0 and esp < 1:\n");
        scanf("%f", &esp);
    }

    float x, y, Fa, Fb;
    Fa = ((1.0 / 3.0) * (exp(-a) - exp(a * 0.5) + 3.7) - a);
    Fb = ((1.0 / 3.0) * (exp(-b) - exp(b * 0.5) + 3.7) - b);

    if (Fa * Fb < 0) {
        while ((b - a) / 2.0 > esp) {
            x = (a + b) / 2.0;
            y = ((1.0 / 3.0) * (exp(-x) - exp(x * 0.5) + 3.7) - x);
            Fa = ((1.0 / 3.0) * (exp(-a) - exp(a * 0.5) + 3.7) - a);
            if (Fa * y < 0) {b = x;} 
            else {a = x;}
            count ++;
        }
        printf("The point at which the equation is as close to 0, x = %.6f\n", x);
        printf("Number of iterations = %i\n", count);
    }
    else {printf("This equation has no roots\n");}

    return 0;
}