#include <stdio.h>
#include <string.h>

void decrypt(char *c) {
    char m[128], d[1000], t[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int f[128] = {0};

    for (int i = 0; c[i] != '\0'; i++) f[c[i]]++;

    for (int i = 0; i < 26; i++) {
        int max_index = 0;
        for (int j = 1; j < 128; j++) {
            if (f[j] > f[max_index]) max_index = j;
        }
        m[max_index] = t[i], f[max_index] = 0;
    }

    for (int i = 0; c[i] != '\0'; i++) d[i] = m[c[i]];
    d[strlen(c)] = '\0';

    printf("Decrypted plaintext: %s\n", d);
}

int main() {
    char c[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 "
               "(88)5*†;46(;88*96*?;8)‡(;485);5†2:‡(;4956*2(5—4)8¶8*"
               ";4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81"
               "(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";
    decrypt(c);

    return 0;
}
