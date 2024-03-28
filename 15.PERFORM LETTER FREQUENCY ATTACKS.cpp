#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26


void calculateFrequency(const char *text, int frequency[]) {
    int i;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char c = tolower(text[i]);
            frequency[c - 'a']++;
        }
    }
}


void decrypt(const char *ciphertext, char *plaintext, int key) {
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            char c = tolower(ciphertext[i]);
            char decrypted_char = ((c - 'a' - key) % ALPHABET_SIZE + ALPHABET_SIZE) % ALPHABET_SIZE + 'a';
            plaintext[i] = isupper(ciphertext[i]) ? toupper(decrypted_char) : decrypted_char;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[i] = '\0';
}


void rankPlaintexts(char *ciphertext, int topN) {
    int observedFrequency[ALPHABET_SIZE] = {0};
    int i;
    calculateFrequency(ciphertext, observedFrequency);

    printf("Top %d Possible Plaintexts:\n", topN);

    for (i = 0; i < ALPHABET_SIZE; i++) {
        char plaintext[strlen(ciphertext) + 1];
        decrypt(ciphertext, plaintext, i);
        int decryptedFrequency[ALPHABET_SIZE] = {0};
        calculateFrequency(plaintext, decryptedFrequency);

       
        int score = 0;
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            score += abs(observedFrequency[j] - decryptedFrequency[j]);
        }

      
        printf("%s (Score: %d)\n", plaintext, score);
    }
}

int main() {
    char ciphertext[] = "Falszztysyjzyjkywjrztyjztyynaryjkyswarztyegyyj";
    int topN = 10;

    rankPlaintexts(ciphertext, topN);

    return 0;
}
