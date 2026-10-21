#include <iostream>
using namespace std;

class Node {
private:
	int data;
	
public:
	Node *left = NULL;
	Node *right = NULL;
	
	Node(int d) {
		data = d;
	}
	
	void setData(int d) {
		data = d;
	}
	
	int getData() {
		return data;
	}
	
	void printData() {
		cout << data;
	}
};

class stackNode {
public:
	Node* sRoot;
	stackNode *next = NULL;
	
};

class stack {
private:
	stackNode *tRoot = NULL;
	
public:
	void push(Node *root) {
		if (tRoot == NULL) {
			tRoot = root;
		}
		
		Node *temp = tRoot
		while (temp != NUll) {
			curr = temp;
			temp = temp->next;
		}
		temp = root;
	}
	
	Node* pop() {
		Node *head = tRoot;
		Node *temp, *;
		while(head->next != NULL) {
			temp = head;	
			head = head->next;
		}
		curr = head;
		temp->next = NULL;
		
		return curr;
	}
};

Node* insert(Node *root, int data) {
	if (root == NULL) {
		return new Node(data);
	}
	
	if (data > root->getData()) {
		root->right = insert(root->right, data);
	} else if (data < root->getData()) {
		root->left = insert(root->left, data);
	}
	
	return root;
}

void preOrderTraversalRecursive(Node *root) {
	if (root == NULL) {
		return;
	} 
	
	cout << root->getData() <<" ";
	preOrderTraversalRecursive(root->left);
	preOrderTraversalRecursive(root->right);
}

int main() {
	
	int task, data;
	char choice = 'y';
	Node *root = NULL, *curr = NULL, *temp = NULL;
	
	do {
		cout << "\nBinary Tree operations :\n";
		cout << "1. Insert data\n";
		cout << "2. Print data\n";
		cout << "3. Exit\n";
		
		cout << "\nEnter task : ";
		cin >> task;
		
		if (task == 1) {
			cout << "\nEnter Data : ";
			cin >> data;
			root = insert(root, data);
			
		} else if(task == 2) {
			preOrderTraversalRecursive(root);
			
		} else if(task == 3) {
			choice = 'n';
		} else {
			cout << "\nError : Invalid task.\n";
		}
		
	} while (choice == 'y');
	
	return 0;
}
