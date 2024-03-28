#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


void encrypt(char plaintext[], int key[], char ciphertext[]) {
    int len = strlen(plaintext);
    int key_len = sizeof(key) / sizeof(key[0]); 
    int i;

    for (i = 0; i < len; i++) {
        if (isalpha(plaintext[i])) {
            
            int shift = key[i % key_len];

            
            if (isupper(plaintext[i]))
                ciphertext[i] = 'A' + (plaintext[i] - 'A' + shift) % 26;
            else
                ciphertext[i] = 'a' + (plaintext[i] - 'a' + shift) % 26;
        } else {
       
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[i] = '\0'; 
}


void decrypt(char ciphertext[], int key[], char decrypted[]) {
    int len = strlen(ciphertext);
    int key_len = sizeof(key) / sizeof(key[0]); 
    int i;

    for (i = 0; i < len; i++) {
        if (isalpha(ciphertext[i])) {
            
            int shift = key[i % key_len];

        
            if (isupper(ciphertext[i]))
                decrypted[i] = 'A' + (ciphertext[i] - 'A' - shift + 26) % 26;
            else
                decrypted[i] = 'a' + (ciphertext[i] - 'a' - shift + 26) % 26;
        } else {
          
            decrypted[i] = ciphertext[i];
        }
    }

    decrypted[i] = '\0'; 
}

int main() {
    char plaintext[] = "sendmoremoney";
    int key[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    char ciphertext[strlen(plaintext) + 1];
    char decrypted[strlen(plaintext) + 1];

   
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted Text: %s\n", ciphertext);

   
    char target[] = "cashnotneeded";
    int target_key[strlen(target)];

    decrypt(ciphertext, key, decrypted);

    printf("Decrypted Text: %s\n", decrypted);

    
    for (int i = 0; i < strlen(plaintext); i++) {
        int shift = (decrypted[i] - plaintext[i] + 26) % 26;
        target_key[i] = shift;
    }

    printf("Key to Decrypt to 'cashnotneeded': ");
    for (int i = 0; i < strlen(target); i++) {
        printf("%d ", target_key[i]);
    }

    printf("\n");

    return 0;
}
