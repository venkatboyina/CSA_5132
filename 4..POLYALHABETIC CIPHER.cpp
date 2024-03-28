#include <stdio.h>
#include <string.h>
#include <ctype.h>

void polyalphabeticSubstitution(char *plaintext, char *key) {
    int keyLength = strlen(key);
    int i;

    for (i = 0; plaintext[i] != '\0'; i++) {
        char currentChar = plaintext[i];
        char currentKeyChar = key[i % keyLength];

        if (isalpha(currentChar)) {
            int shift = toupper(currentKeyChar) - 'A';

            if (islower(currentChar)) {
                plaintext[i] = 'a' + (currentChar - 'a' + shift) % 26;
            } else {
                plaintext[i] = 'A' + (currentChar - 'A' + shift) % 26;
            }
        }
    }

    printf("Ciphertext: %s\n", plaintext);
}

int main() {
    char plaintext[1000];
    char key[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 
    printf("Enter the key: ");
    scanf("%s", key);

    polyalphabeticSubstitution(plaintext, key);

    return 0;
}
