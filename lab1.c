#include<stdio.h>
#include<string.h>

int main(){
	printf("----- Vigenere Cipher -----\n---- Matt Hixon CIS308 ----\n");
	
	printf("\nEnter a keyword (UPPERCASE ONLY): ");
	char keyword[64];
	fgets(keyword, 64, stdin);

	printf("\nYour keyword is: %s", keyword);
	
	char message[128];
	printf("\nEnter a message (UPPERCASE ONLY): ");
	fgets(message, 128, stdin);

	printf("\nYour message is: %s", message);
	
	int i; 
	int referenceOne;
int referenceTwo;
	for(i=0;i<strlen(message);i++)
	{
		referenceOne = keyword[i] - 'A'; 
		
		referenceTwo = (referenceOne + message[i])%26;
		printf("\n%d, %d, %d", i, referenceOne, referenceTwo);
	}

	//once you have keyword, take first letter of keyword and add first letter of word to encode %26 




}