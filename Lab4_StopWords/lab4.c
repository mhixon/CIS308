//Author: Matt Hixon
//Lab4: Stop Words


#include<stdio.h>
#include<dirent.h>
#include<errno.h>
#include<stdlib.h>
#

//used tree template from http://www.cprogramming.com/tutorial/c/lesson18.html
struct node{
	char* word;
	char** languages;
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


void insert(char[] key, struct node **leaf)
{
    if( *leaf == 0 )
    {
        *leaf = (struct node*) malloc( sizeof( struct node ) );
        (*leaf)->word = key;
        /* initialize the children to null */
        (*leaf)->left = 0;    
        (*leaf)->right = 0;  
    }
    else if(strcmp(key, (*leaf)->word) < 0)
    {
        insert( key, &(*leaf)->left );
    }
    else if(strcmp(key, (*leaf)->word) > 0)
    {
        insert( key, &(*leaf)->right );
    }
}

struct node *search(int key, struct node *leaf)
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
			char line[300];
			FILE* fp = fopen(dp->d_name, "r");
			if(fp == NULL){
				perror("[ERROR]");
				return;			
			} else {
				while(fgets(line, 300, fp) != NULL){
					struct *node newNode = (struct node)malloc(sizeof(struct node));
					newNode->word = line;
					newNode->languages = dp->d_name;
					insert(dp->d_name, newNode);
				}
			}
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
