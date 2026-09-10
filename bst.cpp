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




void printprePost(node *obj) {
	if(obj == NULL) {
		return;
	}
	
	printPrePost(obj->left);
	cout << " " << obj->getData();
	
	
	printPrePost(obj->right);
	cout << " " << obj->getData();
	
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
				curr = new node;
				curr->setData(data);
				
				if (root == NULL) {
					root = new node(data);
				} else {
					temp = root;
					while(temp!=NULL) {
						if(data < temp->getData()) {
							if(temp->left == NULL) {
								temp->left = curr;
							} else {
								temp = temp->left;
							}
							
						} else if(data > temp->getData()) {
							if(temp->left == NULL) {
								temp->left = curr;
							} else {
								temp = temp->right; 
							}
						} else {
							temp = NULL;
						}
					}
					delete curr;
				}
				
				cout << "\nDo you want to insert another node : ";
				cin >> ch;
			} while (ch == 'y');
			
		} else if (task == 2) {
			
		} else {
			cout << "\nError : Invalid task.\n";
		}
		
		cout << "\nDo you want to continue : ";
		cin >> choice;
	} while (choice == 'y');
	
	
	return 0;
}
