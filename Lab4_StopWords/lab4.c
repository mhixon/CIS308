//Author: Matt Hixon
//Lab4: Stop Words


#include<stdio.h>
#include<dirent.h>
#include<errno.h>
#include<stdlib.h>

void readDirectory(char* dir) {
	//check if dir exists
	DIR *dirp = opendir(dir);
	if(dirp == NULL){
		perror("couldn't open");
		return;
	}
	
	//store everything in dir
	struct dirent *dp = readdir(dirp);
	
	//iterate through dir
	do {
        if ((dp = readdir(dirp)) != NULL) {
			//do stuff here
			//store in a struct
			//create a giant tree with all the stop words
			//how do you differentiate from smae words in different language
			//create tree with

			//char* word
			//char*[] languages
			//tree leftchild
			//tree rightchild
			printf("%s\n", dp->d_name);
        }
    } while (dp != NULL);
	closedir(dirp);
}


int main() {
	puts("\n\n ----- 	Lab 4: Stop Words 	----- ");
	puts(" -----	Author: Matt Hixon 	-----\n\n");

	puts("Enter the name of a directory containing stop words: \n");
	
	char* stopWordDir = (char*)malloc(sizeof(256));
	scanf("%s", stopWordDir);
	readDirectory(stopWordDir);

	


	//printf("%s", stopWordDir);
	return 0;
}
