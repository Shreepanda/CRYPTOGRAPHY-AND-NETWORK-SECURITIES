#include <stdio.h>
#include <string.h>
#include<ctype.h>



int main() {
    char text[] = {"HELLO WORLD"};
    char key[] = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" };
    int n;
    n=strlen(text);
    for (int i = 0; i < n; i++)
	 {
        if (isupper(text[i]))
            text[i] = key[text[i] - 'A'];
        else if (islower(text[i]))
            text[i] = key[text[i] - 'a'];
    }
    printf("Encrypted text: %s\n", text);

    return 0;
}
