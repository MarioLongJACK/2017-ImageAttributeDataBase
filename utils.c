/*
 * Created by Sotirios-Efstathios Maneas on 2017-01-02.
 */

#include <stdio.h>
#include <string.h>

#include "utils.h"


/*
 * Tokenize the string stored in cmd based on DELIMITERS as separators.
 * Return the number of tokens, and store pointers to them in cmd_argv.
 */
int tokenize(char *cmd, char **cmd_argv) {
	char *token;
	int argc = 0;
	//Remove the \n by the end of command
	cmd[strlen(cmd)-1]= '\0';
	if(cmd[strlen(cmd) - 1] == ' '){
		int k = 1;
		while(cmd[strlen(cmd)-k] == ' '){
			k++;
		}
	cmd[strlen(cmd)-k+1] = '\0';
	}
	 
	//get the first token
	token = strtok(cmd, " ");
	//insert the first token ino the array
	//walk through other tokens
	while (token != NULL) {

		cmd_argv[argc] = token;
		token = strtok(NULL , " ");
		argc++;
		
	}
        // returning argc, so that it tells how many tokens are there
	return argc;
}
