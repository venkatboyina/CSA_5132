#include <stdio.h>
#include <ctype.h>
#include <string.h>

void substitute(char *text, char *key, int encrypt);

int main() {
    char text[100], key[26];

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key (26 unique letters): ");
    fgets(key, sizeof(key), stdin);

   
    key[strcspn(key, "\n")] = '\0';

    
    substitute(text, key, 1);
    printf("Encrypted text: %s\n", text);

   
    substitute(text, key, 0);
    printf("Decrypted text: %s\n", text);

    return 0;
}

void substitute(char *text, char *key, int encrypt) {
    int i;
    char *ptr;

    for (i = 0; text[i] != '\0'; ++i) {
        if (isalpha(text[i])) {
            int offset = isupper(text[i]) ? 'A' : 'a';
            ptr = strchr(key, toupper(text[i]));
            if (ptr != NULL) {
                text[i] = (encrypt ? toupper(key[text[i] - offset]) : 'A' + (ptr - key)) + offset;
            }
        }
    }
}
