#include <stdio.h>
#include <string.h>
void encryptblock(char *plaintext, char *ciphertext)
{
strcpy(ciphertext, plaintext);
}
void decryptblock(char *ciphertext, char *plaintext)
{
strcpy(plaintext, ciphertext);
}
void simulatetransmittedciphertexterror(char *ciphertext, int
blockindex)
{
ciphertext[blockindex] ^= 0x01;
}
int main()
{
char p1[] = "hello, this is p1.";
char p2[] = "and this is p2.";
char c1[20], c2[20];
char c1_error[20], c2_error[20];
encryptblock(p1, c1);
encryptblock(p2, c2);
printf("ecb mode:\n");
printf("original c1: %s\n", c1);
printf("original c2: %s\n", c2);
strcpy(c1_error, c1);
simulatetransmittedciphertexterror(c1_error, 5);
printf("transmitted c1 with error: %s\n", c1_error);
char p1_error[20];
decryptblock(c1_error, p1_error);
printf("decrypted p1 (with error): %s\n", p1_error);
char p2_decrypted[20];
decryptblock(c2, p2_decrypted);
printf("decrypted p2: %s\n", p2_decrypted);
return 0;
}
