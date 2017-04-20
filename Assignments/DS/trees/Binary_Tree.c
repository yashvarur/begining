# include <stdio.h>

typedef struct binary_tree
{
	int data;
	struct binary_tree *left;
	struct binary_tree *right;
}NODE;

int main()
{
	int choice;
	NODE *root = NULL;
	while(1) {
		printf("1-insert\n");
		printf("2-display\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
				root = insert(root);
				break;
			default:
				break;
		}
	}
}

NODE *insert(NODE *root)
{
	NODE *new_node;
	NODE *temp;
	new_node = create_node();

	if(root == NULL)
		root = new_node;
	else {
		temp = root;
		if(root -> data < new_node -> data) {
			while(temp -> data < new_node -> data) {
					temp = temp -> right;
					if(temp -> right == NULL && temp -> data < new_node -> data) {
							temp -> right = new_node;
							break;	
					}
					if(temp -> left == NULL) {
						temp -> left = new_node;
						break;
					}
			}
			
					
			
