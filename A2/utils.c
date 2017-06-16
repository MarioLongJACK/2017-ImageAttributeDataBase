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
	//get the first token
	token = strtok(cmd, " ");
	//insert the first token ino the array
	//walk through other tokens
	while (token != NULL) {

		cmd_argv[argc] = token;
		// remove the "\n" from the last token 
		if(cmd_argv[argc][strlen(cmd_argv[argc]) -1] == '\n'){
			cmd_argv[argc][strlen(cmd_argv[argc]) -1] = '\0';
		}
				
		token = strtok(NULL , " ");
		argc++;
		
	}
        // returning 0 for now, so the compiler does not complain
	return 0;
}
