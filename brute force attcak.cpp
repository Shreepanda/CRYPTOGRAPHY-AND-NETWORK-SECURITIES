#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
int main() {
    char message[] = "RD SFRJ NX WFLMZ";
    int length = strlen(message);
    int key;
    for ( key = 0; key < 26; key++) {
        printf(" %d: ",key);
        for (int i = 0; i < length; i++) {
            if (islower(message[i])) {
                putchar(((message[i] - 'a') + key) % 26 + 'a');
            } else if (isupper(message[i])) {
                putchar(((message[i] - 'A') + key) % 26 + 'A');
            } else {
                putchar(message[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
