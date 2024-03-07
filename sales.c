# include <stdio.h>

void monthlyReport(float sales[12], char months[12][10]) {
    printf("\nMonthy sales report for 2022: \n");
    printf("Month       Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%*s", -12, months[i]);
        printf("$%.2f\n", sales[i]);
    }
}

void salesSummary(float sales[12], char months[12][10]) {
    float minVal[2] = {sales[0], 0}, maxVal[2] = {sales[0], 0}, avgVal = 0;
    for (int i = 0; i < 12; i++) {
        if (sales[i] < minVal[0]) {
            minVal[0] = sales[i];
            minVal[1] = i;
        } 
        if (sales[i] > maxVal[0]) {
            maxVal[0] = sales[i];
            maxVal[1] = i;
        }
        avgVal += sales[i];
    }
    avgVal = avgVal/12;

    printf("\nSales Summary: \n");
    printf("Minimum Sales:  $%.2f   (%s)\n", minVal[0], months[(int) minVal[1]]);
    printf("Maximum Sales:  $%.2f   (%s)\n", maxVal[0], months[(int) maxVal[1]]);
    printf("Average Sales:  $%.2f\n", avgVal);
}

void sixMonthAvg(float sales[12], char months[12][10]) {
    printf("\nSix-Months Moving Average Report: \n");
    float movingAvg = 0;
    float results[7];
    for (int i = 0; i < 6; i++) {
        movingAvg += sales[i];
    }
    results[0] = movingAvg/6;
    for (int i = 6; i < 12; i++) {
        movingAvg -= sales[i-6];
        movingAvg += sales[i];
        results[i-5] = movingAvg/6;
    }
    for (int i = 0; i < 7; i++) {
        printf("%*s - %*s", -10, months[i], -10, months[i+5]);
        printf("  $%.2f\n", results[i]);
    }
}

void salesReport(float sales[12], char months[12][10]) {
    printf("\nSales Report (Highest to Lowest): \n");
    printf(" Month        Sales\n");
    for (int i = 0; i < 12; i++) {
        float maxVal[2] = {sales[0], 0};
        for (int j = 0; j < 12; j++) {
            if (sales[j] > maxVal[0]) {
                maxVal[0] = sales[j];
                maxVal[1] = j;
            }
        }
        printf("%-12s $%.2f\n", months[(int) maxVal[1]], maxVal[0]);
        sales[(int) maxVal[1]] = 0;
    }
}
int main() {
    float sales[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    monthlyReport(sales, months);
    salesSummary(sales, months);
    sixMonthAvg(sales, months);
    salesReport(sales, months);
}
