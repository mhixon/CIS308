//Author: Matt Hixon
//Lab2: Unicode Blocks

#include<stdio.h>

//Create a structure to hold information about each block
struct blockElement{

	int start;
	int end;
	char *name;

};

//Create array of blockElements
//pretty sure this could be a pointer
struct blockElement blocks[300];

int main() {

	puts("\n\n ----- 	Lab 2: Unicode Blocks 	----- ");
	puts(" -----	Author: Matt Hixon 	-----\n\n");

	readFile();
	
	//not working because I need to allocate space
	printf("Name -> ||| %s |||\n", blocks[1].name);

	int codepoint;
	puts("Enter a Codepoint Value (integer)");
	scanf("%d", &codepoint);

	int blockIndex = findMatch(codepoint);
	if(blockIndex == -1){
		puts("No matching block found.");
	} else {
		printf("Block -> ||| %d |||\n", blockIndex);
		printf("Block : %s", blocks[blockIndex].name);
		puts(" ---------\n\n");
	}
	//printf("%d", codepoint);
	
}

int readFile() {
	
	FILE* fp;
	char line[256];
	int blockIndex = 0;
	
	fp = fopen("Blocks.txt", "r");
	
	//loop through each line (ignoring text at beginning) and store relevant information
	while(fgets(line, 300, fp) != NULL) {
		if(line[0] == '#' || line[0] == ' ' || line[0] == '\n'){ continue; } 
		else {
			parseInput(line, blockIndex);
			blockIndex++;
		}
	}

	fclose(fp);
}

int parseInput(char* line, int blockIndex) {

	//convert starting hex to an int and store it as the start of a block
	int i = 0;	
	while(line[i] != '.'){
		i++;
	}
	*(line+i) = '\0';
	blocks[blockIndex].start = (int) strtol(line, NULL, 16);
	
	i++;
	i++;
	
	//convert ending hex to int and store it as the end of a block
	int j = 0;
	while(line[i+j] != ';'){
		j++;
	}
	*(line+i+j) = '\0';
	blocks[blockIndex].end = (int) strtol((line+i), NULL, 16);
	
	j++;
	j++;

	//store last part of line as the name of a block
	int k = 0;
	while(line[i+j+k] != '\n'){
		k++;
	}
	*(line+i+j+k) = '\0';
	blocks[blockIndex].name = line+i+j;
	
	/*
	//Display content of struct
	printf("Start 	|| %d\n", blocks[blockIndex].start);
	printf("End 	|| %d\n", blocks[blockIndex].end);
	printf("Name 	|| %s\n", blocks[blockIndex].name);
	puts(" ---------------------------- ");
	*/
}

int findMatch(int codepoint){

	//implement binary search
/*
	int first = 0;
	int last = 299;
	int middle = (first+last)/2;

	while(first <= last){
		if(blocks[middle].end < codepoint){
			first = middle+1;
		} else if(blocks[middle].start > codepoint) {
			last = middle-1;
		} else if(blocks[middle].start <= codepoint && blocks[middle].end >= codepoint){
			return middle;
		} else {
			return -1;
		}
	middle = (first+last)/2;
	}
*/
	
}



