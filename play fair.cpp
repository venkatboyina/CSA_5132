#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5 

void prepareKey(char *key);
void buildPlayfairMatrix(char *key, char matrix[SIZE][SIZE]);
void encrypt(char *plaintext, char matrix[SIZE][SIZE]);
void decrypt(char *ciphertext, char matrix[SIZE][SIZE]);

int main() {
    char key[100], plaintext[100], ciphertext[100];
    char playfairMatrix[SIZE][SIZE];

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    prepareKey(key);

    buildPlayfairMatrix(key, playfairMatrix);

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

   
    encrypt(plaintext, playfairMatrix);
    printf("Encrypted text: %s\n", plaintext);

    
    decrypt(plaintext, playfairMatrix);
    printf("Decrypted text: %s\n", plaintext);

    return 0;
}


void prepareKey(char *key) {
    int i, j = 0;
    char temp[100];

    for (i = 0; key[i] != '\0'; ++i) {
        if (isalpha(key[i])) {
            temp[j++] = toupper(key[i]);
        }
    }
    temp[j] = '\0';
    strcpy(key, temp);
}


void buildPlayfairMatrix(char *key, char matrix[SIZE][SIZE]) {
    int i, j, k = 0;
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; 

    
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (k < strlen(key)) {
                matrix[i][j] = key[k++];
            } else {
                break;
            }
        }
    }

   
    for (; i < SIZE; ++i) {
        for (; j < SIZE; ++j) {
            for (k = 0; k < 26; ++k) {
                if (!strchr(key, alphabet[k])) {
                    matrix[i][j] = alphabet[k++];
                    break;
                }
            }
        }
        j = 0;
    }
}


void findPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    int i, j;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}


void encrypt(char *plaintext, char matrix[SIZE][SIZE]) {
    int i, len, row1, row2, col1, col2;
    len = strlen(plaintext);

   
    for (i = 0; i < len; ++i) {
        if (plaintext[i] == 'J')
            plaintext[i] = 'I';
    }

    
    if (len % 2 != 0) {
        plaintext[len - 1] = 'X';
        plaintext[len] = '\0';
        ++len;
    }

   
    for (i = 0; i < len; i += 2) {
        findPosition(matrix, plaintext[i], &row1, &col1);
        findPosition(matrix, plaintext[i + 1], &row2, &col2);

     
        if (row1 == row2) {
            plaintext[i] = matrix[row1][(col1 + 1) % SIZE];
            plaintext[i + 1] = matrix[row2][(col2 + 1) % SIZE];
        }
        
        else if (col1 == col2) {
            plaintext[i] = matrix[(row1 + 1) % SIZE][col1];
            plaintext[i + 1] = matrix[(row2 + 1) % SIZE][col2];
        }
        
        else {
            plaintext[i] = matrix[row1][col2];
            plaintext[i + 1] = matrix[row2][col1];
        }
    }
}


void decrypt(char *ciphertext, char matrix[SIZE][SIZE]) {
    int i, len, row1, row2, col1, col2;
    len = strlen(ciphertext);

    
    for (i = 0; i < len; i += 2) {
        findPosition(matrix, ciphertext[i], &row1, &col1);
        findPosition(matrix, ciphertext[i + 1], &row2, &col2);

        
        if (row1 == row2) {
            ciphertext[i] = matrix[row1][(col1 - 1 + SIZE) % SIZE];
            ciphertext[i + 1] = matrix[row2][(col2 - 1 + SIZE) % SIZE];
        }
        
        else if (col1 == col2) {
            ciphertext[i] = matrix[(row1 - 1 + SIZE) % SIZE][col1];
            ciphertext[i + 1] = matrix[(row2 - 1 + SIZE) % SIZE][col2];
        }
        
        else {
            ciphertext[i] = matrix[row1][col2];
            ciphertext[i + 1] = matrix[row2][col1];
        }
    }

    
    len = strlen(ciphertext);
    if (ciphertext[len - 1] == 'X')
        ciphertext[len - 1] = '\0';

  
    for (i = 0; i < len; ++i) {
        if (ciphertext[i] == 'I')
            ciphertext[i] = 'J';
    }
}
