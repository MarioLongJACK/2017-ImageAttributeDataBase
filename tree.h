/*
 * Created by Sotirios-Efstathios Maneas on 2017-06-02.
 */

#ifndef _TREE_H
#define _TREE_H

#include "utils.h"


struct TreeNode {
	char *value;

        struct TreeNode *sibling;
        struct TreeNode *child;
};

void tree_insert(struct TreeNode *, char **);
void tree_search(const struct TreeNode *, char **);
void tree_print(const struct TreeNode *);

#endif /* _TREE_H */
