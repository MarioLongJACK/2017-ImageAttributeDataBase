/*
 * Created by Sotirios-Efstathios Maneas on 2017-01-02.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "utils.h"

int main(void) {

        // char array to hold a line of input
	char buf[BUFFER_SIZE] = {'\0'};

        // char* array to hold the pointers to tokens
	char *args[INPUT_ARG_MAX_NUM];
	/*
        // the root of the tree
        struct TreeNode root;
        root.value = "";
        root.child = NULL;
        root.sibling = NULL;
	
	struct TreeNode *root_ptr = &root;
	*/
        // Add your code below:
	// number of tokens for each line of argument
	int num_token;
	// reading line by line from std
	while(fgets(buf, BUFFER_SIZE, stdin) != NULL){
		// convert each line into tokens
		printf("the buf is %s\n", buf);
		num_token = arg_counter(buf);
		tokenize(buf, args);
		// check if the argument and the number of arguments are correct
		if((strcmp(args[0], "i") == 0) && (num_token == 5)){
			printf("i works\n");
			}
		else if((strcmp(args[0], "q") == 0) && (num_token == 4) ){
			printf("q works\n");
			}
		else if((strcmp(args[0], "p" ) == 0) && (num_token == 1)){
			printf("p works\n");
			}
		else{ fprintf(stderr, "Invalid command\n");}
		
	}

        return 0;
}



// a function that counts the number of tokens in a string arry	

int arg_counter(char * args){
	int k = 0;
	for(int i =0; i < strlen(args); i ++){
		if(args[i] == ' '){
			k++;
		}
	}
 	return k+1; 	
}

	