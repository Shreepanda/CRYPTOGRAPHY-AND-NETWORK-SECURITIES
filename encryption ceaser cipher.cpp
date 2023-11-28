#include<stdio.h>
#include<conio.h>
int main()
{
	char message[50],ch;
	int i,key;
	
	printf("Enter the encrypted message: ");
	gets(message);
	printf("Enter the key: ");
	scanf("%d",&key);
	for(i=0;message[i]!='\0';++i)
	{
	  	ch=message[i];
	  	if(ch>='a'&&ch<='z')
		ch = ch+key;
		
		if(ch>='z')
		ch=ch-'z'+'a'-1;
		
		ch=message[i];
	}
	printf("Encrypted message is %s",message);
}
