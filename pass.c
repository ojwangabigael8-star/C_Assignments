#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length;
    int hasUpper = 0;
    int hasLower = 0;
    int hasDigit = 0;
    int hasSpecial = 0;
    int score = 0;

    printf("===== PASSWORD STRENGTH CHECKER =====\n");
    printf("Enter a password: ");

    if (fgets(password, sizeof(password), stdin) == NULL) {
        printf("Input error.\n");
        return 1;
    }

    // Remove the newline entered by fgets
    password[strcspn(password, "\n")] = '\0';

    length = strlen(password);

    // Check each character
    for (int i = 0; i < length; i++) {
        unsigned char ch = (unsigned char)password[i];

        if (isupper(ch)) {
            hasUpper = 1;
        } else if (islower(ch)) {
            hasLower = 1;
        } else if (isdigit(ch)) {
            hasDigit = 1;
        } else {
            hasSpecial = 1;
        }
    }

    // Calculate the strength score
    if (length >= 8) {
        score++;
    }
    if (length >= 12) {
        score++;
    }
    if (hasUpper) {
        score++;
    }
    if (hasLower) {
        score++;
    }
    if (hasDigit) {
        score++;
    }
    if (hasSpecial) {
        score++;
    }

    // Display the result
    printf("\nPassword Analysis\n");
    printf("-------------------------\n");
    printf("Length: %d characters\n", length);
    printf("Contains uppercase: %s\n", hasUpper ? "Yes" : "No");
    printf("Contains lowercase: %s\n", hasLower ? "Yes" : "No");
    printf("Contains number: %s\n", hasDigit ? "Yes" : "No");
    printf("Contains special character: %s\n",
           hasSpecial ? "Yes" : "No");

    printf("\nPassword Strength: ");

    if (length < 8 || score <= 2) {
        printf("WEAK\n");
    } else if (score <= 4) {
        printf("MODERATE\n");
    } else {
        printf("STRONG\n");
    }

    if (length < 8) {
        printf("Tip: Use at least 8 characters.\n");
    }
    if (!hasUpper) {
        printf("Tip: Add an uppercase letter.\n");
    }
    if (!hasLower) {
        printf("Tip: Add a lowercase letter.\n");
    }
    if (!hasDigit) {
        printf("Tip: Add a number.\n");
    }
    if (!hasSpecial) {
        printf("Tip: Add a special character, e.g. ! or @.\n");
    }

    return 0;
}