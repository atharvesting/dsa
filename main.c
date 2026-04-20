#include <stdio.h>
#include <stdlib.h>

// BST

struct Node {
	int val;
	struct Node* left;
	struct Node* right;
};

struct Node* create_node(int val) {
	struct Node* t = (struct Node*)malloc(sizeof(struct Node));
	t->val = val; t->left = NULL; t->right = NULL;
	return t;
}

struct Node* insert_node(struct Node* root, int val) {
	if (root == NULL) {
		root = create_node(val);
		return root;
	}
	if (val > root->val) {
		root->right = insert_node(root->right, val);
	}
	else if (val < root->val) {
		root->left = insert_node(root->left, val);
	}
	return root;
}

struct Node* build_bst(int* arr, int size) {
	struct Node* root = NULL;
	for (int i = 0; i < size; i++) {
		root = insert_node(root, arr[i]);
	}
	return root;
}

void free_bst(struct Node* root) {
	if (root == NULL) return;
	free_bst(root->left);
	free_bst(root->right);
	free(root);
}

struct Node* search_bst(struct Node* root, int target) {
	if (root == NULL) {
		return NULL;
	}
	if (root->val == target) {
		return root;
	}
	else if (root->val < target) {
		return search_bst(root->right, target);
	}
	else {
		return search_bst(root->left, target);
	}
	return root;
}

void trav_inorder(struct Node* root) {
	if (root == NULL) {
		return;
	}
	trav_inorder(root->left);
	printf("%d  ", root->val);
	trav_inorder(root->right);
}

struct Node* find_inorder_successor(struct Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

struct Node* delete_bst(struct Node* root, int val) {
	if (root == NULL) return NULL;

	if (root->val > val) {
		root->left = delete_bst(root->left, val);
	}
	else if (root->val < val) {
		root->right = delete_bst(root->right, val);
	}
	else {
		struct Node* t = NULL;
		if (root->left == NULL && root->right == NULL) {
			free(root); return NULL;
		}
		else if (root->left != NULL && root->right != NULL) {
			t = find_inorder_successor(root->right);
			root->val = t->val;
			root->right = delete_bst(root->right, t->val);
			return root;
		}
		else if (root->left != NULL) {
			t = root->left;
			free(root);
			return t;
		}

		else if (root->right != NULL) {
			t = root->right;
			free(root);
			return t;
		}
	}
	return root;
}

int main() {
	int arr[] = { 5, 4, 7, 1, 9, 0, 3, 2, 6, 8 };
	struct Node* root = build_bst(arr, 10);
	trav_inorder(root); printf("\n");
	root = delete_bst(root, 5);
	trav_inorder(root); 
	free_bst(root);

	return 0;
}