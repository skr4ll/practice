#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct binaryTreeNode BinaryTreeNode;
struct binaryTreeNode{
	char value;
	bool visited;
	BinaryTreeNode* right;
	BinaryTreeNode* left;
};

void dfs(BinaryTreeNode* node);

void dfs(BinaryTreeNode* node){
	if (node == NULL) return;

	if (!node->visited) {
		printf("%c\n", node->value);
		node->visited = true;
	}
	dfs(node->left);
	dfs(node->right);
}

int main(){
	BinaryTreeNode A;
	BinaryTreeNode B;
	BinaryTreeNode C;
	BinaryTreeNode D;
	BinaryTreeNode E;

	A.left = &B;
	A.right = &C;
	B.left = &D;
	B.right = &E;
	A.value = 'A';
	B.value = 'B';
	C.value = 'C';
	D.value = 'D';
	E.value = 'E';
	A.visited = false;
	B.visited = false;
	C.visited = false;
	D.visited = false;
	E.visited = false;
dfs(&A);
return 0;
}


