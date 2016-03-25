//Author: Matt Hixon
//Lab4: Stop Words


#include<stdio.h>
#include<dirent.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>



#define MAX 32

//used tree template from http://www.cprogramming.com/tutorial/c/lesson18.html
struct node{
	char* word;
	char languages[MAX][64];
	int languageIndex;
	struct node *left;
	struct node *right;
};

struct node *root = 0;


void destroy_tree(struct node *leaf)
{
  if( leaf != 0 )
  {
      destroy_tree(leaf->left);
      destroy_tree(leaf->right);
      free( leaf );
  }
}


void insert(char* key, struct node **leaf, char* lang)
{
	//puts("Insert Method");
    if( *leaf == NULL )
    {
    	//puts("NULL LEAF");
        *leaf = (struct node*) malloc( sizeof(struct node));
        (*leaf)->word = malloc(strlen (key) + 1);
        strcpy ((*leaf)->word, key);
        //puts("LEAF CPY");
        memset((*leaf)->languages, 0, sizeof((*leaf)->languages));
        strcpy ((*leaf)->languages[0],lang);
        (*leaf)->languageIndex = 1;
        /* initialize the children to null */
        (*leaf)->left = NULL;    
        (*leaf)->right = NULL;
        printf("Key: %s,  Value: %s,  Lang1: %s\n" , key, (*leaf)->word, (*leaf)->languages[0]);  
    }
    else if(strcmp(key, (*leaf)->word) < 0)
    {
        insert( key, &(*leaf)->left, lang);
    }
    else if(strcmp(key, (*leaf)->word) > 0)
    {
        insert( key, &(*leaf)->right, lang);
    } else {
    	strcpy ((*leaf)->languages[(*leaf)->languageIndex], lang);
    	(*leaf)->languageIndex += 1;
    }
}

struct node *search(char* key, struct node *leaf)
{
  if( leaf != 0 )
  {
	
      if(strcmp(key, leaf->word) == 0)
      {
          return leaf;
      }
      else if(strcmp(key, leaf->word) < 0)
      {
          return search(key, leaf->left);
      }
      else
      {
          return search(key, leaf->right);
      }
  }
  else return 0;
}




void readDirectory(char* dir, struct node* root) {
	//check if dir exists
	DIR *dirp = opendir(dir);
	if(dirp == NULL){
		perror("couldn't open");
		return;
	} else{


	
	//store everything in dir
	struct dirent *dp = readdir(dirp);
	char* fileName = strcat(dir, "/");
	char lng[64];
	//printf("FILENAME: %s\n", fileName);
	
	//iterate through dir

	while((dp = readdir(dirp)) != NULL){
		char line[300];
		//printf("%s\n", dp->d_name);
		strcpy(lng, fileName);
		strcat(lng, dp->d_name);
		printf("%s\n", lng);
		FILE* fp = fopen(lng, "r");
		if(fp == NULL){
			perror("[ERROR]");
			return;			
		} else {
			while(fgets(line, 300, fp) != NULL){
				insert(line, &root, dp->d_name);
			}
		}
	}
	closedir(dirp);
}


int main() {
	puts("\n\n ----- 	Lab 4: Stop Words 	----- ");
	puts(" -----	Author: Matt Hixon 	-----\n\n");

	puts("Enter the name of a directory containing stop words: \n");
	
	char* stopWordDir = (char*)malloc(sizeof(256));
	scanf("%s", stopWordDir);
	struct node *root = NULL;
	readDirectory(stopWordDir, root);
	struct node *result = search("ale", root);
	printf("RESULT: %s", result->word);
	


	//printf("%s", stopWordDir);
	return 0;

}
