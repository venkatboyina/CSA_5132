#include <stdio.h>
#include <openssl/dsa.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <string.h>
void generate_and_sign() {
    DSA *dsa = DSA_generate_parameters(1024, NULL, 0, NULL, NULL, NULL, NULL);
    DSA_generate_key(dsa);
    RSA *rsa = RSA_generate_key(1024, RSA_F4, NULL, NULL);
    const char *message = "Hello, world!";
    unsigned char signature_dsa[1024];
    unsigned int signature_dsa_len;
    unsigned char signature_rsa[1024];
    unsigned int signature_rsa_len;
    DSA_sign(0, (const unsigned char *)message, strlen(message), signature_dsa, &signature_dsa_len, dsa);
    RSA_sign(NID_sha256, (const unsigned char *)message, strlen(message), signature_rsa, &signature_rsa_len, rsa);
    printf("Message: %s\n", message);
    printf("DSA Signature: ");
    for (int i = 0; i < signature_dsa_len; i++) {
        printf("%02x", signature_dsa[i]);
    }
    printf("\nRSA Signature: ");
    for (int i = 0; i < signature_rsa_len; i++) {
        printf("%02x", signature_rsa[i]);
    }
    printf("\n");
    DSA_free(dsa);
    RSA_free(rsa);
}
int main() {
    printf("Signing message for DSA and RSA:\n");
    generate_and_sign();
    printf("\nSigning the same message again:\n");
    generate_and_sign();
    return 0;
}
