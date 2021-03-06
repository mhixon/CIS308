//Author: Matt Hixon
//Lab1: Vigenere Cipher

#include<stdio.h>
#include<string.h>

int main(){
	printf("----- Vigenere Cipher -----\n---- Matt Hixon CIS308 ----\n");
	
	//get a keyword from user
	printf("\nEnter a keyword (UPPERCASE ONLY): ");
	char keyword[64];
	fgets(keyword, 64, stdin);

	printf("\nYour keyword is: %s", keyword);
	
	//get a message from user
	char message[128];
	printf("\nEnter a message (UPPERCASE ONLY): ");
	fgets(message, 128, stdin);

	printf("\nYour message is: %s", message);
	
	//encode message
	int i;
	char encodedMessage[strlen(message)];

	for(i=0;i<strlen(message);i++)
	{
		if(message[i] > 64 && message[i] < 91)
		{
			//i%strlen(keyword)-1 keeps looping from 0...n to access keyword[n]
			//keyword[n]-'A' normalizes the value between 0 and 25
			//message[i]-'A' accesses message[i] and normalizes it between 0 and 25
			//keyword[n]+message[i]%26+'A' adds the two together and normalizes it between 0 and 25 and then converts it back to its corresponding ascii char value

			encodedMessage[i] = (((keyword[i%(strlen(keyword)-1)])-'A' + (message[i]-'A'))%26)+'A';

		} else {
			encodedMessage[i] = message[i];
		}
	}
	
	printf("\nYour encoded message is: ");

	for(i=0;i<strlen(encodedMessage);i++)
	{
		printf("%c", encodedMessage[i]);
	}

	//decode message

}
