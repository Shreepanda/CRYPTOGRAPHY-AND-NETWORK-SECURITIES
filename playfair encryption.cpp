#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

char key_matrix[5][5];

int main() {
    char text[MAX_LENGTH], key[MAX_LENGTH];
    int len, count, position1, position2;

    printf("Enter the plain text: ");
    scanf("%s", text);

    printf("Enter the keyword: ");
    scanf("%s", key);

    // Fill the key matrix
    int i = 0, j = 0;
    count = 0;
    len = strlen(key);
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 0 || j == 0)
                key_matrix[i][j] = '/';
            else if (count < len) {
                key_matrix[i][j] = key[count++];
                if (key_matrix[i][j] == 'J')
                    key_matrix[i][j] = 'I';
            } else
                key_matrix[i][j] = '/';
        }
    }

    // Encrypt the text
    printf("\nEncrypted text is: ");
    len = strlen(text);
    for (int i = 0; i < len; i += 2) {
        if (text[i] == text[i + 1]) {
            printf("X ");
            text[i + 1] = 'X';
        }

        char x = text[i];
        char y = text[i + 1];

        if (x != '/' && y != '/') {
            if (x == y) {
                x = key_matrix[0][0];
                y = key_matrix[1][1];
            } else {
                position1 = (int)(x - 'A') * 5 + (int)(x - 'A') + 1;
                position2 = (int)(y - 'A') * 5 + (int)(y - 'A') + 1;

                if (position1 % 5 == position2 % 5) {
                    x = key_matrix[position1 / 25][(position1 + 2) % 5];
                    y = key_matrix[position2 / 25][(position2 + 2) % 5];
                } else if (position1 / 25 == position2 / 25) {
                    x = key_matrix[(position1 + 2) % 5][position1 / 25];
                    y = key_matrix[(position2 + 2) % 5][position2 / 25];
                } else {
                    x = key_matrix[(position1 + 2) % 5][(position1 + 1) % 5];
                    y = key_matrix[(position2 + 2) % 5][(position2 + 1) % 5];
                }
            }
        }

        printf("%c%c ", x, y);
    }

    return 0;
}
