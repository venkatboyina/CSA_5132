#include <stdio.h>

#define N 2 
int determinant(int key[N][N]) {
    return key[0][0] * key[1][1] - key[0][1] * key[1][0];
}


int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1; 
}


void inverse(int key[N][N], int inv[N][N]) {
    int det = determinant(key);
    int invDet = modInverse(det, 26);

    
    int temp = key[0][0];
    key[0][0] = key[1][1];
    key[1][1] = temp;
    key[0][1] = -key[0][1];
    key[1][0] = -key[1][0];

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            inv[i][j] = (key[i][j] * invDet) % 26;
            if (inv[i][j] < 0)
                inv[i][j] += 26;
        }
    }
}

int main() {
    
    char plaintexts[3][3] = {"ME", "AT", "DO"};
    char ciphertexts[3][3] = {"ZR", "GY", "PK"};

    
    int plaintextNum[3][2], ciphertextNum[3][2];
    for (int i = 0; i < 3; i++) {
        plaintextNum[i][0] = plaintexts[i][0] - 'A';
        plaintextNum[i][1] = plaintexts[i][1] - 'A';
        ciphertextNum[i][0] = ciphertexts[i][0] - 'A';
        ciphertextNum[i][1] = ciphertexts[i][1] - 'A';
    }

   
    int key[N][N];
    for (int i = 0; i < N; i++) {
        key[0][i] = (plaintextNum[0][0] * plaintextNum[1][1] - plaintextNum[0][1] * plaintextNum[1][0]) *
                        ciphertextNum[0][i] +
                    (plaintextNum[1][0] * plaintextNum[2][1] - plaintextNum[1][1] * plaintextNum[2][0]) *
                        ciphertextNum[1][i] +
                    (plaintextNum[2][0] * plaintextNum[0][1] - plaintextNum[2][1] * plaintextNum[0][0]) *
                        ciphertextNum[2][i];
        key[0][i] %= 26;
        if (key[0][i] < 0)
            key[0][i] += 26;
    }

   
    int inv[N][N];
    inverse(key, inv);

    
    printf("Key Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", inv[i][j]);
        }
        printf("\n");
    }

    return 0;
}
