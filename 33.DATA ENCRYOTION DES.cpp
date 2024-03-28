#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/des.h>

void des_encrypt(const unsigned char *plaintext, const unsigned char *key, unsigned char *ciphertext) {
    DES_cblock des_key;
    DES_key_schedule des_schedule;

    // Set the key
    memcpy(des_key, key, 8);
    DES_set_key_unchecked(&des_key, &des_schedule);

    // Encrypt the plaintext
    DES_ecb_encrypt((const_DES_cblock *)plaintext, (DES_cblock *)ciphertext, &des_schedule, DES_ENCRYPT);
}

void des_decrypt(const unsigned char *ciphertext, const unsigned char *key, unsigned char *plaintext) {
    DES_cblock des_key;
    DES_key_schedule des_schedule;

    // Set the key
    memcpy(des_key, key, 8);
    DES_set_key_unchecked(&des_key, &des_schedule);

    // Decrypt the ciphertext
    DES_ecb_encrypt((const_DES_cblock *)ciphertext, (DES_cblock *)plaintext, &des_schedule, DES_DECRYPT);
}

int main() {
    const unsigned char plaintext[] = "Hello, world!";
    const unsigned char key[] = "secretK";

    unsigned char ciphertext[64];
    unsigned char decrypted[64];

    // Encrypt
    des_encrypt(plaintext, key, ciphertext);
    printf("Encrypted: ");
    for (int i = 0; i < sizeof(ciphertext); ++i) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decrypt
    des_decrypt(ciphertext, key, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
