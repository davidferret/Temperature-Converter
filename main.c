#include <stdio.h>

// Function prototypes
float Celsius(float F);
float Fahrenheit(float C);
void generateTemperatureTable();
void batchTemperatureConversion();
void kelvinConversion();

int main(void) {
    generateTemperatureTable();
    batchTemperatureConversion();
    kelvinConversion();
    printf("Temperature data saved to 'temperature.txt'.\n");
    return 0;
}

void generateTemperatureTable() {
    FILE *fp = fopen("temperature.txt", "w");
    if (!fp) {
        printf("Error creating file!\n");
        return;
    }
    
    float c, f;
    
    printf("Fahrenheit equivalents of Celsius temperatures:\n");
    fprintf(fp, "Fahrenheit equivalents of Celsius temperatures:\n");
    printf("%10s%13s\n", "Celsius", "Fahrenheit");
    fprintf(fp, "%10s%13s\n", "Celsius", "Fahrenheit");
    
    for (c = 0; c <= 100; c += 10) {
        printf("%10.0f%13.2f\n", c, Fahrenheit(c));
        fprintf(fp, "%10.0f%13.2f\n", c, Fahrenheit(c));
    }
    
    printf("Celsius equivalents of Fahrenheit temperatures:\n");
    fprintf(fp, "Celsius equivalents of Fahrenheit temperatures:\n");
    printf("%13s%10s\n", "Fahrenheit", "Celsius");
    fprintf(fp, "%13s%10s\n", "Fahrenheit", "Celsius");
    
    for (f = 32; f <= 212; f += 20) {
        printf("%13.0f%10.2f\n", f, Celsius(f));
        fprintf(fp, "%13.0f%10.2f\n", f, Celsius(f));
    }
    
    fclose(fp);
}

float Celsius(float F) {
    return (5.0 / 9.0) * (F - 32);
}

float Fahrenheit(float C) {
    return (9.0 / 5.0) * C + 32;
}

void batchTemperatureConversion() {
    int count, precision;
    float temp;
    char unit;
    
    printf("\nEnter the number of conversions: ");
    scanf("%d", &count);
    
    printf("Enter decimal precision (0-5): ");
    scanf("%d", &precision);
    
    if (precision < 0) precision = 0;
    if (precision > 5) precision = 5;
    
    for (int i = 0; i < count; i++) {
        printf("\nEnter temperature value followed by unit (C/F): ");
        scanf("%f %c", &temp, &unit);
        
        if (unit == 'C' || unit == 'c') {
            printf("%.*f Celsius is %.*f Fahrenheit\n", precision, temp, precision, Fahrenheit(temp));
        } else if (unit == 'F' || unit == 'f') {
            printf("%.*f Fahrenheit is %.*f Celsius\n", precision, temp, precision, Celsius(temp));
        } else {
            printf("Invalid unit entered. Please use 'C' for Celsius or 'F' for Fahrenheit.\n");
        }
    }
}

void kelvinConversion() {
    float temp;
    char unit;
    
    printf("\nEnter temperature value followed by unit (C/F/K): ");
    scanf("%f %c", &temp, &unit);
    
    if (unit == 'C' || unit == 'c') {
        printf("%.2f Celsius is %.2f Fahrenheit and %.2f Kelvin\n", temp, Fahrenheit(temp), temp + 273.15);
    } else if (unit == 'F' || unit == 'f') {
        printf("%.2f Fahrenheit is %.2f Celsius and %.2f Kelvin\n", temp, Celsius(temp), Celsius(temp) + 273.15);
    } else if (unit == 'K' || unit == 'k') {
        printf("%.2f Kelvin is %.2f Celsius and %.2f Fahrenheit\n", temp, temp - 273.15, Fahrenheit(temp - 273.15));
    } else {
        printf("Invalid unit entered. Please use 'C' for Celsius, 'F' for Fahrenheit, or 'K' for Kelvin.\n");
    }
}
