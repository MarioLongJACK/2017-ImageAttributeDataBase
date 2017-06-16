/*
 * Created by Sotirios-Efstathios Maneas on 2017-06-02.
 */

#ifndef _UTILS_H
#define _UTILS_H

#define INPUT_ARG_MAX_NUM	5
#define BUFFER_SIZE	256
#define DELIMITERS	" \n"


/*
 * Tokenize the string stored in cmd based on DELIMITERS as separators.
 * Return the number of tokens, and store pointers to them in cmd_argv.
 */
int tokenize(char *, char **);

#endif /* _UTILS_H */
