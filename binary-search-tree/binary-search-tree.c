#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node *left, *right;
} node;

node *root = NULL;

node *createNode(int data) {
	node *newNode = malloc(sizeof(node));
	
	newNode -> data = data;
	newNode -> left = newNode -> right = NULL;
	
	return newNode;
}

node *findNode(node *tree, int data) {
	if (tree == NULL) {
		return NULL;
	}

	if (data == tree -> data) {
		return tree;
	}
	
	if (data < tree -> data) {
		return findNode(tree -> left, data);
	}
	return findNode(tree -> right, data);
}

node *insertNode(node *tree, int data) {
	if (root == NULL) {
		root = createNode(data);
		return NULL;
	}
	
	if (tree == NULL) {
		return createNode(data);
	}
	
	if (data < tree -> data) {
		tree -> left = insertNode(tree -> left, data);
	}
	else {
		tree -> right = insertNode(tree -> right, data);	
	}
}

node *findMin(node *tree) {
	if (tree -> left == NULL) {
		return tree;
	}
	
	return findMin(tree -> left);
}

node *deleteNode(node *tree, int data) {
	if (tree == NULL) {
		return NULL;
	}
	
	if (data == tree -> data) {
		if (tree -> left == NULL && tree -> right == NULL) {
			free(tree);
			return NULL;
		}	
	
		if (tree -> left != NULL && tree -> right == NULL) {
			node *temp = tree -> left;
			free(tree);
			return temp;
		}
	
		if (tree -> left == NULL && tree -> right != NULL) {
			node *temp = tree -> right;
			free(tree);
			return temp;
		}
		
		// node has both branches		
		node *temp = findMin(tree -> right); // left-most node of the right node
		int tempData = temp -> data;
		
		deleteNode(root, tempData);
		tree -> data = tempData;				
	}
	else if (data < tree -> data) {
		tree -> left = deleteNode(tree -> left, data);
	}	
	else {
		tree -> right = deleteNode(tree -> right, data);
	}
}

void inOrderTraverse(node *tree) {
    if (tree != NULL) {
        inOrderTraverse(tree -> left);
        printf("%d ", tree -> data);
        inOrderTraverse(tree -> right);
    }
}

void preOrderTraverse(node *root) {
    if (root != NULL) {
    	printf("%d ", root -> data);
        preOrderTraverse(root -> left);
        preOrderTraverse(root -> right);
    }
} 

void postOrderTraverse(node *root) {
    if (root != NULL) {
        postOrderTraverse(root -> left);
        postOrderTraverse(root -> right);
        printf("%d ", root -> data);
    }
}

int maxDepth(node *tree) { // when tree = root, maxDepth == height
	if (tree == NULL) {
		return 0;
	}
	
	int leftDepth = maxDepth(tree -> left);
	int rightDepth = maxDepth(tree -> right);
	
	if (leftDepth > rightDepth) {
		return (leftDepth + 1);
	}
	return (rightDepth + 1);
}


void levelOrderTraversePrintLevel(node *tree, int level) {
	if (tree == NULL) return;
		
	if (level == 1) {
		printf(" %d ", tree -> data);
	}
	else if (level > 1) {
		levelOrderTraversePrintLevel(tree -> left, level - 1);
		levelOrderTraversePrintLevel(tree -> right, level - 1);			
	}
}

void levelOrderTraverse(node *tree) {
	int i;
	for (i = 0; i <= maxDepth(root); i++) {
		levelOrderTraversePrintLevel(root, i);
		printf("\n");
	}
}

int main(void) {
	insertNode(root, 39);
	insertNode(root, 56);
	insertNode(root, 12);
	insertNode(root, 34);
	insertNode(root, 78);
	insertNode(root, 32);
	insertNode(root, 10);
	insertNode(root, 89);
	insertNode(root, 54);
	insertNode(root, 67);
	insertNode(root, 81);
	
	printf("Inorder Traverse: ");
	inOrderTraverse(root);
	
	printf("\nDelete 81 ");
	deleteNode(root, 81);

	printf("\nInorder Traverse: ");
	inOrderTraverse(root);
	
	printf("\nMax depth/height: %d", maxDepth(root));
	
	printf("\nLevel order traverse:\n");
	levelOrderTraverse(root);
	
	printf("\nDelete 12 ");
	deleteNode(root, 12);
	
	printf("\nLevel order traverse:\n");
	levelOrderTraverse(root);
	
	printf("\nInorder Traverse: ");
	inOrderTraverse(root);

	return 0;
}
