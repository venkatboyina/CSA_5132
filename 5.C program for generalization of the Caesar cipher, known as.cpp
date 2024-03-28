#include <stdio.h>
#include <ctype.h>


int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


int isCoprime(int a) {
    return gcd(a, 26) == 1;
}


char encrypt(char p, int a, int b) {
    if (isalpha(p)) {
        char base = islower(p) ? 'a' : 'A';
        return ((a * (p - base) + b) % 26) + base;
    }
    return p; 
}

int main() {
    int a, b;
    char plaintext[1000], ciphertext[1000];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the values of a and b (separated by space): ");
    scanf("%d %d", &a, &b);

  
    if (!isCoprime(a)) {
        printf("Invalid value of 'a'. 'a' must be coprime with 26.\n");
        return 1;
    }

   
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = encrypt(plaintext[i], a, b);
    }
    ciphertext[i] = '\0';

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
