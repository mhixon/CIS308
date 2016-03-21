//Author: Matt Hixon
//Lab3: Alphabet Recognition

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utf8.h"

//Create a structure to hold information about each block
struct blockElement{

	unsigned int start;
	unsigned int end;
	char *name;

};

//Create array of blockElements
struct blockElement blocks[300];

//Use binary search to match codepoint to codeblock
int findMatch(int codepoint, int last){

	int first = 0;
	int middle = (first+last)/2;

	while(first <= last){
		if(blocks[middle].end < codepoint){
			first = middle+1;
		} else if(blocks[middle].start > codepoint) {
			last = middle-1;
		} else if(blocks[middle].start <= codepoint && blocks[middle].end >= codepoint){
			return middle;
		}
	middle = (first+last)/2;
	}
	return -1;
}

//Parse input from file to codeblock
void parseInput(char* line, int blockIndex) {

	//get 1st hex
	int i = 0;	
	while(line[i] != '.'){
		i++;
	}
	*(line+i) = '\0';
	blocks[blockIndex].start = (int) strtol(line, NULL, 16);
	
	i++;
	i++;
	
	//get 2nd hex
	int j = 0;
	while(line[i+j] != ';'){
		j++;
	}
	*(line+i+j) = '\0';
	blocks[blockIndex].end = (int) strtol((line+i), NULL, 16);
	
	j++;
	j++;

	//get language
	int k = 0;
	while(line[i+j+k] != '\n'){
		k++;
	}
	*(line+i+j+k) = '\0';
	blocks[blockIndex].name = strdup(line+i+j);
	
	/*
	//Display content of struct
	printf("Start 	|| %d\n", blocks[blockIndex].start);
	printf("End 	|| %d\n", blocks[blockIndex].end);
	printf("Name 	|| %s\n", blocks[blockIndex].name);
	puts(" ---------------------------- ");
	*/
}

//Read a file
int readBlocksFile() {
	
	FILE* fp;
	char line[256];
	int blockIndex = 0;
	
	//if fp is null, display error
	fp = fopen("Blocks.txt", "r");
	if(fp == NULL){
		perror("[ERROR]");
		return 0;
	} else {
		//loop through each line (ignoring text at beginning) and store relevant information
		while(fgets(line, 300, fp) != NULL) {
			if(line[0] == '#' || line[0] == ' ' || line[0] == '\n'){ continue; } 
			else {
				parseInput(line, blockIndex);
				blockIndex++;
			}
		}

		fclose(fp);
		return blockIndex;
	}
}

int main() {

	puts("\n\n ----- 	Lab 3: Alphabet Recognition 	----- ");
	puts(" -----	    Author: Matt Hixon 		-----\n\n");

	//get blocks
	int size = readBlocksFile();
	
	//recognize alphabet
	unsigned char* c;
	int* intptr;
 	int codepoint;
	char line[2048];
	while(fgets(line, 2048, stdin)){
		c = line;
		while(c != '\0'){
			codepoint = utf8_to_codepoint(c, intptr);
			printf("Codepoint: %d\n", codepoint);
			c = c + *intptr;
		}
		
		
	}

/*
	if(size != 0){
		int codepoint;
		puts("Enter a Codepoint Value (integer)\n");
		scanf("%d", &codepoint);

		do{
			puts("--------------- ");
			int blockIndex = findMatch(codepoint, size);

			if(blockIndex == -1){
				puts("No matching block found.");
			} else {
				printf("%s", blocks[blockIndex].name);
			}

			puts("\n\n\nTry another number (-1 to exit):\n");
			scanf("%d", &codepoint);
		} while (codepoint != -1);

	}
*/
	//free memory in struc here before program ends
	
}








