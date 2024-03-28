#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int mod(int a, int b) {
    int result = a % b;
    return result >= 0 ? result : result + b;
}

char encrypt_vigenere_one_time_pad(char p, int key) {
    if (isalpha(p)) {
        char base = isupper(p) ? 'A' : 'a';
        return mod((p - base + key), 26) + base;
    }
    return p;
}

char decrypt_vigenere_one_time_pad(char c, int key) {
    if (isalpha(c)) {
        char base = isupper(c) ? 'A' : 'a';
        return mod((c - base - key), 26) + base;
    }
    return c;
}

int main() {
    int key_stream[1000];
    char plaintext[1000], ciphertext[1000];

    printf("Enter the key stream (space-separated random numbers between 0 and 26): ");
    for (int i = 0; ; i++) {
        if (scanf("%d", &key_stream[i]) == 0) {
            break;
        }
    }

    printf("Enter the plaintext: ");
    scanf(" %[^\n]s", plaintext);

    int key_stream_length = sizeof(key_stream) / sizeof(key_stream[0]);
    int plaintext_length = strlen(plaintext);

    for (int i = 0; i < plaintext_length; i++) {
        int key = key_stream[i % key_stream_length];
        ciphertext[i] = encrypt_vigenere_one_time_pad(plaintext[i], key);
    }
    ciphertext[plaintext_length] = '\0';

    printf("\nEncrypted Ciphertext: %s\n", ciphertext);

    for (int i = 0; i < plaintext_length; i++) {
        int key = key_stream[i % key_stream_length];
        plaintext[i] = decrypt_vigenere_one_time_pad(ciphertext[i], key);
    }
    plaintext[plaintext_length] = '\0';

    printf("Decrypted Plaintext: %s\n", plaintext);

    return 0;
}
