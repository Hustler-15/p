/*
A book consists of chapters, chapters consist of sections and sections consist of subsections.
Construct a tree and print the nodes.Find the time and space requirements of your method.
*/

#include<iostream>
#include<string>
using namespace std;

struct node
{
	char label[10];          
	int ch_count;            
	struct node *child[10];
}*root;

class Tree{                     
	public:
		void create_tree();
		void display(node *r1);
		Tree()
		{
			root=NULL;
		}
};

void Tree :: create_tree()
{
	int tbooks, tchapters, i, j, k;
	
	root = new node();
	cout<<"\n Enter name of the book: ";
	cin>>root->label;
	cout<<"\n Enter number of chapters in the book "<<root->label<<" : ";
	cin>>root->ch_count;
	root->ch_count==tchapters;
	
	for(i=0; i<root->ch_count ;i++)
	{
		root->child[i]=new node;                                                                   //creating new chapters
		cout<<"\n Enter name of the chapter "<<i+1<<" :";
		cin>>root->child[i]->label;
		cout<<"\n Enter number of sections in the chapter=> "<<root->child[i]->label<<" :";
		cin>>root->child[i]->ch_count;
		
		for(j=0; j<root->child[i]->ch_count; j++)
		{
			root->child[i]->child[j]=new node;                                                      // creating new sections
			cout<<"\n Enter name of the section: ";
			cin>>root->child[i]->child[j]->label;
			
			cout<<"\n Enter number of sub-sections in "<<root->child[i]->child[j]->label<<" :";
			cin>>root->child[i]->child[j]->ch_count;

			for(k=0; k<root->child[i]->child[j]->ch_count;k++)
			{
				root->child[i]->child[j]->child[k]= new node;                                       // creating new sub-sections
				cout<<"\n Enter name of the sub-section: ";
				cin>>root->child[i]->child[j]->child[k]->label;
			} 
		}	
	}
}

void Tree::display(node *r1)
{
	int i, j, k, tchapters;
	if(r1!=NULL)
	{
		cout<<"\n <-- Book Hierarchy -->";
		cout<<"\n Title of the book is: "<<r1->label;
		tchapters=r1->ch_count;
		for(i=0;i<tchapters;i++)
		{
			cout<<"\n";
			cout<<"\n Chapter "<<i+1<<" :";
			cout<<r1->child[i]->label;
			cout<<"\n Sections: ";
			for(j=0;j<r1->child[i]->ch_count;j++)
			{
				cout<<"\n";
				cout<<r1->child[i]->child[j]->label;
				
				cout<<"\n Sub-sections: ";
				for(k=0;k<root->child[i]->child[j]->ch_count;k++)
				{
					cout<<root->child[i]->child[j]->child[k]->label<<" , ";
				}
			}	
		}
	}
}
 int main(){
	int choice;
	Tree t;
	
	while(1)
	{
		cout<<endl;
		cout<<"\n <=== MENU ===>";
		cout<<"\n 1. Create tree";
		cout<<"\n 2. Display tree";
		cout<<"\n 3. Quit";
		cout<<"\n Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: t.create_tree(); 
					break;
			case 2: t.display(root); 
					break;          
			case 3: cout<<"Thank you! ";
					exit(0); 
					break;
			default:
					cout << "Wrong choice!!!" << endl;
		}	
	}
	return 0;		
}
