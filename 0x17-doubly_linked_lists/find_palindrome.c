#include <stdio.h>

// Function to check if a number is palindrome
int isPalindrome(int num) {
    int original = num;
    int reverse = 0;

    while (num > 0) {
        reverse = reverse * 10 + num % 10;
        num /= 10;
    }

    return (original == reverse);
}

int main() {
    int maxPalindrome = 0;
    int num1, num2;

    // Loop through all 3-digit numbers
    for (int i = 100; i <= 999; i++) {
        for (int j = i; j <= 999; j++) { // To avoid duplicates
            int product = i * j;

            if (isPalindrome(product) && product > maxPalindrome) {
                maxPalindrome = product;
                num1 = i;
                num2 = j;
            }
        }
    }

    // Save the result in the file "102-result"
    FILE *file = fopen("102-result", "w");
    fprintf(file, "%d", maxPalindrome);
    fclose(file);

    return 0;
}

