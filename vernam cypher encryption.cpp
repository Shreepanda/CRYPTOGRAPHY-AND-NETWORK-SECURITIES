#include<stdio.h>
#include<string.h>

int main() 
{
    char text[] = "HELLO";
    char key[] = "ABCD";
    int text_len,key_len;
    text_len = strlen(text);
    key_len = strlen(key);
    
    
   for (int i = 0; i < text_len; i++)
    {
        text[i] = text[i] ^ key[i % key_len];
	}

    printf("Encrypted text: %c\n", text_len);

  
}
