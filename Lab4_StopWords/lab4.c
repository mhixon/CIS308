//Author: Matt Hixon
//Lab4: Stop Words

#include<stdio.h>
#include<dirent.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

//started with tree template from http://www.cprogramming.com/tutorial/c/lesson18.html

struct node
{
	char* word;
	char languages[32][64];
	int languageIndex;
	struct node *left;
	struct node *right;
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

void search(char* key, struct node *leaf)
{
  if( leaf != NULL )
  {
      if(strcmp(key, leaf->word) == 0)
      {
      	int num = leaf->languageIndex;
		int i;

		printf("WORD : %s\n", leaf->word);
		for(i = 0; i < num; i++){
			printf("LANGUAGE %d: %s\n", i+1 ,leaf->languages[(i)]);
		}
      }
      else if(strcmp(key, leaf->word) < 0) { return search(key, leaf->left); }
      else { return search(key, leaf->right); }
  }else{ puts("Word not found"); }
}

void readDirectory(char* dir, struct node** rootp) {
	//check if dir exists
	DIR *dirp = opendir(dir);
	if(dirp == NULL){ perror("couldn't open"); } 
	else
	{
		struct dirent *dp = readdir(dirp);
		char* fileName = strcat(dir, "/");
		char lng[64];
		while((dp = readdir(dirp)) != NULL){
			char line[300];
			strcpy(lng, fileName);
			strcat(lng, dp->d_name);
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
	}
}

int main(int argc, char *argv[]) {
	puts("\n\n ----- 	Lab 4: Stop Words 	----- ");
	puts(" -----	Author: Matt Hixon 	-----\n\n");

	struct node *root = NULL;
	//check if directory was entered
	if(argc != 2 || (opendir(argv[1])) == NULL)
	{
		puts("Command line argument error.\n");
		puts("Please re-run program with name of valid directory to read from.");
	} 
	else 
	{
		printf("Collecting words from %s\n", argv[1]);
		readDirectory(argv[1], &root);
		char* wordToFind = (char*)malloc(sizeof(256));
		puts("Enter Word to find: \n");
		scanf("%s", wordToFind);
		search(wordToFind, root);
	}
	destroy_tree(&root);
	root = NULL;
	return 0;
}
