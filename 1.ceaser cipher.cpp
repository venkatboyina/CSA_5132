#include <stdio.h>
#include <ctype.h>

void caesarEncrypt(char message[], int key);
void caesarDecrypt(char message[], int key);

int main() {
    char message[100];
    int key;
 printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key (1-25): ");
    scanf("%d", &key);
    if (key < 1 || key > 25) {
        printf("Invalid key! Key must be between 1 and 25.\n");
        return 1;
    }
	 caesarEncrypt(message, key);
    printf("Encrypted message: %s\n", message);

   
    caesarDecrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void caesarEncrypt(char message[], int key) {
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if(isalpha(ch)) {
            if(islower(ch)) {
                ch = 'a' + (ch - 'a' + key) % 26;
            }
            else if(isupper(ch)) {
                ch = 'A' + (ch - 'A' + key) % 26;
            }
            message[i] = ch;
        }
    }
}

void caesarDecrypt(char message[], int key) {
    
    caesarEncrypt(message, 26 - key);
}
