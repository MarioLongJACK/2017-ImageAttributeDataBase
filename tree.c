/*
 * Created by Sotirios-Efstathios Maneas on 2017-01-02.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"


/**
 *  A helper function that allocates a new tree node.
 *
 *  @param value The entry's value. It represents either an attribute or a filename.
 *  @return A pointer to the newly allocated node.
 *  (for now it returns NULL, so the compiler does not complain)
 */
struct TreeNode *allocate_node(const char *value) {
	struct TreeNode* new_node = malloc(sizeof(struct TreeNode));
	new_node->value = malloc(sizeof(char)*strlen(value));
	strcpy(new_node->value, value);
	new_node->sibling = NULL;
	new_node->child = NULL; 
	return new_node;
}

/**
 *  Insert a new image to a tree
 *
 *  @param tree A pointer to the root of the tree.
 *  @param values An array, whose first three members are the attribute values for 
 *                the image and the last one is the filename
 */
void tree_insert(struct TreeNode *root, char **values) {
		// start with root 
		struct TreeNode *temp = root;
		// loop 3 times to create corresponding attributes
		for(int i =1; i <4; i++){
		temp = insert_help(temp, values[i]);
		}
		// insert the child
		insert_child(temp, values[4]);
}
/**
 *  Searches a tree to print all files with matching attribute values.
 *
 *  @param tree A pointer to the root of the tree.
 *  @param values An array of attribute values
 */
void tree_search(const struct TreeNode *root, char **values) {
		// use the first attributes to be the root
		struct TreeNode *temp = root->child;
		int i = 1;
		// whenever an attribute is not found, the output will be null
		while(i < 4 && temp!= NULL){
			temp = search_help(temp, values[i]);
			i++;
		}
		// if all attributes match, print siblings one by one
		if(temp != NULL){
			while(temp != NULL) {
				printf("%s ", temp->value);
				temp = temp->sibling;
			}
			printf("\n");
		}
		else{
			printf("(NULL)\n");
		}
}
/**
 *  Prints a complete tree to the standard output.
 *
 *  @param tree A pointer to the root of the tree.
 */
void tree_print(const struct TreeNode *tree) {
}



/* a helper function that returns the correct node
   given the root node and the value that need to be found
*/

struct TreeNode *insert_help(struct TreeNode *curr, char *cur_val){
	struct TreeNode *final;
	// if the tree has no image implemented, created the corresponding node
	if(curr->child == NULL){
		struct TreeNode *result_node = allocate_node(cur_val);
		curr->child = result_node;
		final = result_node;
	}
	// if the tree has image implemented already
	else{	
		// create a temp node to store the first child node
		struct TreeNode *temp;
		temp = curr->child;
		// loop through sibling to find node, stop at the end of list or the node is found

		while((temp->sibling != NULL) && (strcmp(temp->value, cur_val) != 0)){
				temp = temp->sibling;
		}

		// if no node is found, created one and attach it to the end of list
		if((strcmp(temp->value, cur_val) != 0) && (temp->sibling == NULL )){
			struct TreeNode *result_node1 = allocate_node(cur_val);
			temp->sibling = result_node1;
			final = result_node1;

		}
		//if the node is found, return the node
		else{	

			final = temp;
		}
	}
	return final;
}
		
/* once the node is currently the leaf node, add child to it
*/
void insert_child(struct TreeNode* leaf, char *name){
		// if the leaf has no child add a child to it
		if(leaf->child == NULL) {
			struct TreeNode *result = allocate_node(name);
			leaf->child = result;
		}
		// if the leaf has child, go to the last child's sibling and add new node to the list end
		else{	
			struct TreeNode *temp = leaf->child;
			while(temp->sibling != NULL){
				temp= temp->sibling;
			}
			struct TreeNode *result1 = allocate_node(name); 
			temp->sibling = result1;
			}
}





/* a helper function that returns the correct node
   given the root node and the value that need to be found
*/

struct TreeNode *search_help(struct TreeNode *curr, char *cur_val){
	struct TreeNode *final;
	struct TreeNode *temp;
	temp = curr;
	// loop through sibling to find node, stop at the end of list or the node is found
	while((temp->sibling != NULL) && (strcmp(temp->value, cur_val) != 0)){
			temp = temp->sibling;
	}
	// if no node is found, return null
	if(strcmp(temp->value, cur_val) != 0){
		final = NULL;
	}
	//if the node is found, return the node
	else{	
		final = temp->child;
	}
	return final;
}




