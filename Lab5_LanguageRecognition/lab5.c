//Author: Matt Hixon
//Lab4: Stop Words

#include<stdio.h>
#include<dirent.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include "utf8.h"

//started with tree template from http://www.cprogramming.com/tutorial/c/lesson18.html

struct node
{
	char* word;
	char languages[32][64];
	int languageIndex;
	struct node *left;
	struct node *right;
};

struct language
{
	char* name;
	int counter;
};

void destroy_tree(struct node **leaf)
{
  if( *leaf != NULL )
  {
      destroy_tree(&(*leaf)->left);
      destroy_tree(&(*leaf)->right);
      free((*leaf)->word);
      free((*leaf));
  }
}

void insert(char* key, struct node **leaf, char* lang)
{

    if( *leaf == NULL )
    {
        *leaf = (struct node*) malloc( sizeof(struct node));

        (*leaf)->word = strdup(key);
        lang = strtok(lang, ".");
        memset((*leaf)->languages, 0, sizeof((*leaf)->languages));
        strcpy ((*leaf)->languages[0],lang);
        (*leaf)->languageIndex = 1;
        (*leaf)->left = NULL;    
        (*leaf)->right = NULL; 
    }
    else if(strcmp(key, (*leaf)->word) < 0) { insert( key, &(*leaf)->left, lang); }
    else if(strcmp(key, (*leaf)->word) > 0) { insert( key, &(*leaf)->right, lang); } 
    else 
    {
    	strcpy ((*leaf)->languages[(*leaf)->languageIndex], lang);
    	(*leaf)->languageIndex += 1;
    }
}

void search(char* key, struct node *leaf, struct language languageArray[], int langCount)
{
  if( leaf != NULL )
  {
      if(strcasecmp(key, leaf->word) == 0)
      {
      	int num = leaf->languageIndex;
		int i,j;

		for(j = 0; j < langCount; j++){
			for(i = 0; i < num; i++){
				if(strcmp(languageArray[j].name, leaf->languages[i]) == 0){
					languageArray[j].counter++;
				}
			}
		}
      }
      else if(strcasecmp(key, leaf->word) < 0) { return search(key, leaf->left, languageArray, langCount); }
      else { return search(key, leaf->right, languageArray, langCount); }
  }else{ //printf("Word: %s, not found\n", key); 
	}
}
/*
struct language* readDirectory(char* dir, struct node** rootp) {
	//check if dir exists
	DIR *dirp = opendir(dir);
	if(dirp == NULL){ perror("couldn't open"); } 
	else
	{
		struct dirent *dp = readdir(dirp);
		char* fileName = strcat(dir, "/");
		char lng[64];
		struct language* languageArray;
		int languageIndex = 0;
		while((dp = readdir(dirp)) != NULL){
			char line[300];
			strcpy(lng, fileName);
			strcat(lng, dp->d_name);
			//printf("Language %s\n", dp->d_name);

			languageArray[languageIndex].name = malloc(strlen(dp->d_name)+1);
			strcpy(languageArray[languageIndex].name, dp->d_name);
			languageArray[languageIndex].counter = 0;
			languageIndex++;

			FILE* fp = fopen(lng, "r");
			if(fp == NULL){ perror("[ERROR]"); } 
			else {
				while(fgets(line, 300, fp) != NULL){

					int slen = strlen(line);
					while(isspace(line[slen-1]) && slen){ slen--; }

					if(slen){ line[slen] = '\0'; }
					insert(line, rootp, dp->d_name);
				}
			}
		}
		closedir(dirp);
		//printf("%s\n", languageArray->name);
	}
}

void getInput(struct node* rootp, struct language languageArray[]){
	char *line = (char*)malloc(sizeof(512));
	char word[32];
	int i;
	int lenptr;
	unsigned int codepoint;
	unsigned char *c;
	//loop through each line
	while(fgets(line,512,stdin) != NULL){

		i=0;
		c = line;
		//while not the end of a string
		while(*c != '\0'){
			//get each letter
			codepoint = utf8_to_codepoint(c, &lenptr);

			//check for punctuation but ignore single quote
			if(*c == ' ' || ispunct(*c)){
				if (*c == '\'')
				{
					word[i] = *c;
					i++;
				} else{
					word[i] = '\0';

					search(word,rootp, languageArray);

					i=0;
				}
			} else{
				//add letter to an array that contains the word
				word[i] = *c;
				i++;
			}
			//increment the pointer to point to next letter
			if(codepoint > 0){
				c += lenptr;
			}
			if(codepoint == 0){
				c++;
			}
		}
		
	}
}
*/
int main(int argc, char *argv[]) {


	puts("\n\n ----- 	Lab 4: Stop Words 	----- ");
	puts(" -----	Author: Matt Hixon 	-----\n\n");

	//init some variables
	int MAXSIZE = 32;
	struct language languageArray[MAXSIZE];
	struct node *root = NULL;
	int languageCounter = 0;

	//check if directory was entered properly
	if(argc != 2 || (opendir(argv[1])) == NULL)
	{
		puts("Command line argument error.\n");
		puts("Please re-run program with name of valid directory to read from.");
	} 
	else 
	{
		printf("Collecting words from %s\n", argv[1]);

	//read directory
	DIR *dirp = opendir(argv[1]);
	if(dirp == NULL){ perror("couldn't open"); } 
	else
	{
		struct dirent *dp = readdir(dirp);
		//create base file name
		char* fileName = strcat(argv[1], "/");
		char lng[64];
		//keep track of # of languages
		int languageIndex = 0;
		//loop through all files and directories
		while((dp = readdir(dirp)) != NULL){
			//increment counter
			languageCounter++;
			char line[300];
			//get full file name
			strcpy(lng, fileName);
			strcat(lng, dp->d_name);
			//create name in array of languages to use for finding max # of words in language
			languageArray[languageIndex].name = malloc(strlen(dp->d_name)+1);
			char* langwot = strdup(dp->d_name);
			*(langwot+(strlen(langwot)-4)) = '\0';
			strcpy(languageArray[languageIndex].name, langwot);
			languageArray[languageIndex].counter = 0;
			languageIndex++;

			//add words to tree from file
			FILE* fp = fopen(lng, "r");
			if(fp == NULL){ perror("[ERROR]"); } 
			else {
				while(fgets(line, 300, fp) != NULL){

					int slen = strlen(line);
					while(isspace(line[slen-1]) && slen){ slen--; }

					if(slen){ line[slen] = '\0'; }
					insert(line, &root, dp->d_name);
				}
			}
		}

		/*int z = 0;
		while(z <= languageCounter-1){
			printf("array %i: %s\n", z, languageArray[z].name);
			z++;
			}
*/
		closedir(dirp);
		//free(fileName);
		//printf("%s\n", languageArray->name);
	}

	//free(dirp);
		//printf("%s\n", languageArray->name);

		//getInput(root, languageArray);



	/*get input*/
	//init variables for reading stdin
	char *line = (char*)malloc(sizeof(512));
	char word[32];
	int i;
	int lenptr;
	unsigned int codepoint;
	unsigned char *c;
	//loop through each line
	while(fgets(line,512,stdin) != NULL){

		i=0;
		c = line;
		//while not the end of a string
		while(*c != '\0'){
			//get each letter
			codepoint = utf8_to_codepoint(c, &lenptr);

			//check for punctuation but ignore single quote
			if(*c == ' ' || ispunct(*c)){
				if (*c == '\'')
				{
					word[i] = *c;
					i++;
				} else{
					word[i] = '\0';
					//find word in tree and increment corresponding counter
					search(word,root, languageArray, languageCounter);
					i=0;
				}
			} else{
				//add letter to an array that contains the word
				word[i] = *c;
				i++;
			}
			//increment the pointer to point to next letter
			if(codepoint > 0){
				c += lenptr;
			}
			if(codepoint == 0){
				c++;
			}
		}
		
	}
	//loop for finding language
	int high = 0;
	char *highestLang;
	int zz;
	for(zz = 0; zz < languageCounter; zz++){
		if(languageArray[zz].counter > high){
			high = languageArray[zz].counter;
			highestLang = strdup(languageArray[zz].name);
		}
	}

	printf("The language is: %s\n", highestLang);
	free(highestLang);


		//char* wordToFind = (char*)malloc(sizeof(256));
		//puts("Enter Word to find: \n");
		//scanf("%s", wordToFind);
		//search(wordToFind, root, languageArray);
	}

	//free everything
	destroy_tree(&root);
	root = NULL;
	int a;
	for(a = 0; a < languageCounter; a++)
	{
		free(languageArray[a].name);           // Deletes the Languages one at a time
	}
	return 0;
}
