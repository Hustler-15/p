/*
Construct binary search tree by inserting the values in the order given
1. Insert a new node
2. Find number of nodes in the longest path 
3. Minimum data value found in the tree
4. Change the tree (swap left and right pointers at every node).
5. Search a value.
*/

#include<iostream>
using namespace std;

class Node
{
	public:
		int key;
		Node *ln;
		Node *rn;
};

class Tree
{
	public:
		Node *root;        //data member               
		
		Node* createTree(int key)
		{
			root = new Node();
			root->key=key;
			root->ln=NULL;
			root->rn=NULL;
			return root;
		}
		
		void insertNode(int key, Node* root)
		{
			Node* node = new Node();
			node->key = key;
			if (key<= root->key)	
			{
				if(root->ln==NULL)
				{
					root->ln = node;
				}
				else
				{
					insertNode(key, root->ln);
				}
			}
			else
			{
				if(root->rn==NULL)
				{
					root->rn = node;
				}
				else
				{
					insertNode(key, root->rn);
				}
			}
		}
		
		void displayInorder(Node* root)
		{
			if(root != NULL)
			{
				displayInorder(root->ln);
				cout<<" -> "<<root->key;
				displayInorder(root->rn);
			}
		}
		
		void displayLeast(Node* root)
		{
			while(root->ln != NULL)
			{
				root=root->ln;
			}
			cout<<"\n The Minimum number in the tree is: "<<root->key;
		}
		
		void search(Node* root, int searchKey)
		{
			if(searchKey<root->key)
			{
				if(root->ln==NULL && root->rn==NULL)
				{
					cout<<"\n Number not found";
				}
				else
				{
					search(root->ln, searchKey);
				}
			}
			else if (searchKey> (root->key))
			{
				if(root->ln==NULL && root->rn==NULL)
				{
					cout<<"\n Number not found";
				}
				else
				{
					search(root->rn, searchKey);
				}
			}
			else if (searchKey==(root->key))
			{
				cout<<"\n Number found!";
			}
			else
			{
				cout<<"\n Number not found";
			}
		}
		int longestPath(Node* root)
		{
			if(root==NULL)
			return 0;
			int Lctr = longestPath(root->ln);
			int Rctr = longestPath(root->rn);
			if(Lctr>Rctr)
			return (Lctr+1);
			else
			return (Rctr+1);
		}
		Node* swapNodes(Node* root)
		{
			Node* temp;
			if (root == NULL)
			return NULL;
			
			temp=root->ln;
			root->ln=root->rn;
			root->rn=temp;
			
			swapNodes(root->ln);
			swapNodes(root->rn);	
		}
};
int main()
{
	int choice, order, flag=0;  
	int key, searchKey;
	Tree t1;
	Node* root;   
	do{
		cout<<"\n <-------MENU------->";
		cout<<"\n 1.Insert a number \n 2. Display \n 3. Swap left and right nodes \n 4. Search \n 5. Exit ";
		cout<<"\n Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\n Enter the Number: ";
				cin>>key;
				if(flag==0)
				{
					root=t1.createTree(key);
					flag=1;
				}
				else
				{
					t1.insertNode(key, root);
				}
				break;
			case 2:
				cout<<"\n <----Display Menu---->";
				cout<<"\n 1. Display List \n 2. Show minimum number \n 3. Show number of nodes in the longest path ";
				cout<<"\n Enter your choice: ";
				cin>>order;
				switch(order)
				{
					case 1:
						cout<<endl;
						t1.displayInorder(root);
						flag=0;
						cout<<endl;
						break;
					case 2:
						t1.displayLeast(root);
						break;
					case 3:
						cout<<"\n The height of the tree or the longest path is: "<<t1.longestPath(root);
						break;
				}
				break;
			case 3: 
				t1.swapNodes(root);
				cout<<"\n The new list is: ";
				t1.displayInorder(root);
				break;
			case 4:
				cout<<"\n Enter the number you want to search: ";
				cin>>searchKey;
				t1.search(root, searchKey);
				break;
			case 5:
				break;
		}
	}
	while (choice != 5);
	return 0;		
}
