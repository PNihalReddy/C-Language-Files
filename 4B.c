#include <stdio.h>

int main() {
    int age;
    char gender;
    float premium, discount;

    printf("\nEnter the age of the customer:");
    scanf("%d", &age);

    printf("\nEnter the first letter of the gender of the customer:");
    scanf(" %c", &gender); 

    printf("\nEnter the premium amount of the customer in float:");
    scanf("%f", &premium);

    if (gender == 'm' && age < 35) {
        discount = 0.20 * premium;
    }
	else if (gender == 'm' && age > 35) {
        discount = 0.25 * premium;
    }
	else if (gender == 'f' && age < 35) {
        discount = 0.30 * premium;
    }
	else if (gender == 'f' && age > 35) {
    	discount = 0.35 * premium;
    }
    
    premium=premium-discount;

    printf("The premium amount is: %.2f\n", premium);
    printf("The discount amount is: %.2f\n", discount);

    return 0;
}
