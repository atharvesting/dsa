#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// BST MENU DRIVEN

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
		return create_node(val);
	}
	if (root->val > val) {
		root->left = insert_node(root->left, val);
	}
	else {
		root->right = insert_node(root->right, val);
	}
	return root;
}

struct Node* build_tree(int* arr, int size) {
	struct Node* root = NULL;
	//int size = (int)sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; i++) {
		root = insert_node(root, arr[i]);
	}
	return root;
}

struct Node* search_node(struct Node* root, int target) {
	if (root == NULL) {
		return NULL;
	}
	if (root->val == target) {
		return root;
	}
	if (root->val > target) {
		return search_node(root->left, target);
	}
	else {
		return search_node(root->right, target);
	}
	return root;
}

/// Find the leftmost node from root. Applied to right subtree for deletion
struct Node* find_inorder_successor(struct Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

struct Node* delete_node(struct Node* root, int target) {
	struct Node* t = NULL;
	if (root == NULL) return NULL;
	if (target < root->val) {
		root->left = delete_node(root->left, target);
	}
	else if (target > root->val) {
		root->right = delete_node(root->right, target);
	}
	else {
		// Case 1: No children
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}

		// Case 3: 2 children
		else if (root->left != NULL && root->right != NULL) {
			t = inorder_successor(root->right);
			root->val = t->val;
			root->right = delete_node(root->right, t->val);
			return root;
		}

		// Case 2: 1 child
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

void traversal_inorder(struct Node* root) {
	if (root == NULL) return;

	traversal_inorder(root->left);
	printf("%d  ", root->val);
	traversal_inorder(root->right);
}

void traversal_preorder(struct Node* root) {
	if (root == NULL) return;

	printf("%d  ", root->val);
	traversal_preorder(root->left);
	traversal_preorder(root->right);
}

void traversal_postorder(struct Node* root) {
	if (root == NULL) return;

	traversal_postorder(root->left);
	traversal_postorder(root->right);
	printf("%d  ", root->val);
}

int main() {
	int arr[SIZE] = { 5,4,6,3,7,2,8,1,9,0 };
	int c, n;
	struct Node* temp = NULL;
	struct Node* root = build_tree(arr, SIZE);
	do {
		traversal_inorder(root); printf("\n");
		printf("1.Insert, 2.Search, 3.Preorder, 4.Postorder, 5.Delete\n");
		printf("Command: ");
		scanf_s("%d", &c);

		switch (c) {
		case 1:
			printf("Val: "); scanf_s("%d", &n);
			temp = insert_node(root, n);
			printf("Node inserted: %d", temp->val);
			break;
		case 2:
			printf("Val: "); scanf_s("%d", &n);
			temp = search_node(root, n);
			if (temp != NULL) printf("Found: %d\n", temp->val);
			else printf("Not Found!\n");
			break;
		case 3: traversal_preorder(root); printf("\n"); break;
		case 4: traversal_postorder(root); printf("\n"); break;
		case 5:
			printf("Val: "); scanf_s("%d", &n);
			temp = delete_node(root, n);
			if (temp == NULL) printf("Not found\n");
			else printf("Deleted!\n");
			break;
		default: break;
		}

	} while (c != 0);

	return 0;
}