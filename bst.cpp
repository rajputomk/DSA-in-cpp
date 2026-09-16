#include <iostream>
using namespace std;

class node {
private:
	int data;

public:
	node *left = NULL;
	node *right = NULL;
	void setData(int d)  {
		data = d;	
	}
	
	node() {}
	
	node(int d) {
		data = d;
	}
	
	node(node *obj) {
		data = obj->data;
	}
	int getData() {
		return data;
	}
	
};




void printPreOrderTraversal(node *root) {
	if(root == NULL) {
		return;
	}
	
	cout << " " << root->getData();
	printPreOrderTraversal(root->left);
	printPreOrderTraversal(root->right);
	
	return;
}

void printInOrderTraversal(node *root) {
	if(root == NULL) {
		return;
	}
	
	printInOrderTraversal(root->left);
	cout << " " << root->getData();
	printInOrderTraversal(root->right);
	
	return;
}

void printPostOrderTraversal(node *root) {
	if(root == NULL) {
		return;
	}
	
	printPostOrderTraversal(root->left);
	printPostOrderTraversal(root->right);
	cout << " " << root->getData();
	
	return;
}

int main() {
	
	node *root = NULL, *curr = NULL, *temp = NULL;
	int task;
	char choice = 'y';
	
	do {
		
		cout << "\n\nBST operation : \n";
		cout << "1. Insertion.\n";
		cout << "2. Traversal.\n";
		
		cout << "\nEnter task : ";
		cin >> task;
		
		if(task == 1) {
			int data;
			char ch;
			do {
				cout << "\nEnter data : ";
				cin >> data;
				
				if (root == NULL) {
					root = new node(data);
				} else {
					temp = root;
					while(temp!=NULL) {
						if(data < temp->getData()) {
							if(temp->left == NULL) {
								temp->left = new node(data);
							} else {
								temp = temp->left;
							}
							
						} else if(data > temp->getData()) {
							if(temp->right == NULL) {
								temp->right = new node(data);
							} else {
								temp = temp->right; 
							}
						} else {
							temp = NULL;
						}
					}
				}
				
				cout << "\nDo you want to insert another node : ";
				cin >> ch;
			} while (ch == 'y');
				
		} else if (task == 2) {
			cout << "\nPre-order Traversal :";
			printPreOrderTraversal(root);
			
			cout << "\nIn-order Traversal :";
			printInOrderTraversal(root);
			
			cout << "\nPost-order Traversal :";
			printPostOrderTraversal(root);
		} else {
			cout << "\nError : Invalid task.\n";
		}
		
//		cout << "\nDo you want to continue : ";
//		cin >> choice;
	} while (choice == 'y');
	
	
	return 0;
}
