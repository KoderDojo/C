#include <stdio.h>

int main() {
    float mealCost;
    int tipPercent;
    int taxPercent;

    scanf("%f", &mealCost);
    scanf(" %d", &tipPercent);
    scanf(" %d", &taxPercent);

    float tip = mealCost * (float)tipPercent/100;
    float tax = mealCost * (float)taxPercent/100;

    int totalCost = (int)(mealCost + tip + tax + 0.5);

    printf("The total meal cost is %d dollars.", totalCost);

    return 0;
}