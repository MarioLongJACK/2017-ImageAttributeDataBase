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
	
        // the root of the tree
        struct TreeNode root;
        root.value = "";
        root.child = NULL;
        root.sibling = NULL;
	
	struct TreeNode *root_ptr = &root;
	struct TreeNode *temp = root_ptr;
        // Add your code below:
	// number of tokens for each line of argument
	int num_token;
	// reading line by line from std
	while(fgets(buf, BUFFER_SIZE, stdin) != NULL){
		// convert each line into tokens
		num_token = tokenize(buf, args);
		// check if the argument and the number of arguments are correct
		if((strcmp(args[0], "i") == 0) && (num_token == 5)){
			tree_insert(temp, args);
			temp = root_ptr;
			}
		else if((strcmp(args[0], "q") == 0) && (num_token == 4) ){
			tree_search(temp, args);
			temp = root_ptr;
			}
		else if((strcmp(args[0], "p" ) == 0) && (num_token == 1)){
			printf("p works\n");
			}
		else{ fprintf(stderr, "Invalid command\n");}
		
	}

        return 0;
}

	
