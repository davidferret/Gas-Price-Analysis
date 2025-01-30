#include <stdio.h>
#include <string.h>
#define MAXSIZE 100

void readGasData(char month[][30], int year[], double regular[], double premium[], int *size);
void displayGasData(char month[][30], int year[], double regular[], double premium[], int size);
void calculateAverages(double regular[], double premium[], int size);
void sortDataByPrice(double regular[], double premium[], char month[][30], int year[], int size, int ascending);
void sortDataByMonth(char month[][30], int year[], double regular[], double premium[], int size);
void userGasPriceAnalysis(double regular[], double premium[], int size);
void findCheapestMonths(char month[][30], int year[], double regular[], int size);
void compareHistoricalPrices(double regular[], double premium[], int year[], int size);

int main(void) {
    char month[MAXSIZE][30];
    int year[MAXSIZE], size = 0, choice, order;
    double regular[MAXSIZE], premium[MAXSIZE];
    
    readGasData(month, year, regular, premium, &size);
    
    printf("Choose sorting method:\n1 - Sort by Regular Gas Price\n2 - Sort by Month\n3 - No Sorting\nEnter choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Choose sorting order:\n1 - Ascending\n2 - Descending\nEnter choice: ");
        scanf("%d", &order);
        sortDataByPrice(regular, premium, month, year, size, order == 1);
    } else if (choice == 2) {
        sortDataByMonth(month, year, regular, premium, size);
    }
    
    displayGasData(month, year, regular, premium, size);
    calculateAverages(regular, premium, size);
    findCheapestMonths(month, year, regular, size);
    compareHistoricalPrices(regular, premium, year, size);
    userGasPriceAnalysis(regular, premium, size);
    
    return 0;
}

void readGasData(char month[][30], int year[], double regular[], double premium[], int *size) {
    FILE *fp = fopen("gas.txt", "r");
    if (fp == NULL) {
        puts("Cannot open file.");
        return;
    }
    
    while (fscanf(fp, "%s %d %lf %lf\n", month[*size], &year[*size], &regular[*size], &premium[*size]) != EOF) {
        (*size)++;
    }
    fclose(fp);
}

void displayGasData(char month[][30], int year[], double regular[], double premium[], int size) {
    printf("%-10s%-10s%-10s%-12s\n", "Month", "Year", "Regular", "Premium");
    for (int i = 0; i < size; i++) {
        printf("%-10s%-10d%-10.2lf%-10.2lf\n", month[i], year[i], regular[i], premium[i]);
    }
}

void calculateAverages(double regular[], double premium[], int size) {
    double avgreg = 0, avgprem = 0;
    for (int i = 0; i < size; i++) {
        avgreg += regular[i];
        avgprem += premium[i];
    }
    avgreg /= size;
    avgprem /= size;
    printf("The average regular gasoline price: %.2lf\n", avgreg);
    printf("The average premium gasoline price: %.2lf\n", avgprem);
}

void sortDataByPrice(double regular[], double premium[], char month[][30], int year[], int size, int ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((ascending && regular[j] > regular[j + 1]) || (!ascending && regular[j] < regular[j + 1])) {
                double tempReg = regular[j];
                regular[j] = regular[j + 1];
                regular[j + 1] = tempReg;
                
                double tempPrem = premium[j];
                premium[j] = premium[j + 1];
                premium[j + 1] = tempPrem;
                
                int tempYear = year[j];
                year[j] = year[j + 1];
                year[j + 1] = tempYear;
                
                char tempMonth[30];
                strcpy(tempMonth, month[j]);
                strcpy(month[j], month[j + 1]);
                strcpy(month[j + 1], tempMonth);
            }
        }
    }
}

void findCheapestMonths(char month[][30], int year[], double regular[], int size) {
    double minPrice = regular[0];
    for (int i = 1; i < size; i++) {
        if (regular[i] < minPrice) {
            minPrice = regular[i];
        }
    }
    printf("Cheapest months with regular gas price of %.2lf:\n", minPrice);
    for (int i = 0; i < size; i++) {
        if (regular[i] == minPrice) {
            printf("%s %d\n", month[i], year[i]);
        }
    }
}

void compareHistoricalPrices(double regular[], double premium[], int year[], int size) {
    printf("Historical Gas Price Comparison:\n");
    for (int i = 1; i < size; i++) {
        printf("%d vs %d - Regular: %.2lf -> %.2lf, Premium: %.2lf -> %.2lf\n", year[i - 1], year[i], regular[i - 1], regular[i], premium[i - 1], premium[i]);
    }
}

void userGasPriceAnalysis(double regular[], double premium[], int size) {
    double threshold;
    printf("Enter a price threshold to find months with regular gas price below this value: ");
    scanf("%lf", &threshold);
    
    printf("Months with regular gas price below %.2lf:\n", threshold);
    for (int i = 0; i < size; i++) {
        if (regular[i] < threshold) {
            printf("Regular: %.2lf | Premium: %.2lf\n", regular[i], premium[i]);
        }
    }
}
