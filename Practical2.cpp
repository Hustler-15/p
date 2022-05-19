#include<iostream>
#include<fstream>
using namespace std;

class student{
	int admno;
	char name[50];
	char addr[50];
	char div;
	public:
		void set_data()
		{
			cout<<"\n Enter Name of the student: ";
			cin>>name;
			cout<<"\n Enter Roll No of the student: ";
			cin>>admno;
			cout<<"\n Enter division of the student: ";
			cin>>div;
			cout<<"\n Enter the address of the student: ";
			cin>>addr;	
		}
		void show_data()
		{
			cout<<"\n Name of the Student is: "<< name;
			cout<<"\n Roll No of the student is: "<<admno;
			cout<<"\n Division of the student is: "<<div;
			cout<<"\n Address of the studment is: "<<addr;
			cout<<"\n ----------------------------";
		}
		int retAdmno()
		{
			return admno;
		}
};
void write_record()
{
	ofstream outFile;
	outFile.open("student.txt", ios::binary | ios::app);
	student obj;
	obj.set_data();
	outFile.write((char*)&obj, sizeof(obj));
	outFile.close();
}
void display()
{
	ifstream inFile;
	inFile.open("student.txt", ios::binary);
	int flag=0;
	student obj;
	
	while(inFile.read((char*)&obj, sizeof(obj)))
	{
		obj.show_data();
	}
	inFile.close();
}
void search(int n)
{
	ifstream inFile;
	inFile.open("student.txt", ios::binary);
	int flag=0;
	student obj;
	
	while(inFile.read((char*)&obj, sizeof(obj)))
	{
		if(obj.retAdmno()==n)
		{
			obj.show_data();
			flag=1;
			break;
		}
	}
	if(flag==0)
	cout<<"\n No record found";
	inFile.close();
}
void delete_record(int n)
{
	student obj;
	ifstream inFile;
	inFile.open("student.txt", ios::binary);
	ofstream outFile;
	outFile.open("temp.txt",ios::out | ios::binary);
	
	while(inFile.read((char*)&obj, sizeof(obj)))
	{
		if(obj.retAdmno() != n)
		{
			outFile.write((char*)&obj, sizeof(obj));
		}
	}
	inFile.close();
	outFile.close();
	remove("student.txt");
	rename("temp.txt", "student.txt");
}
int main(){
	int ch;
	while(1){
		cout<<endl<<endl;
		cout<<"\n <===== File Operations =====>";
		cout<<"\n 1.Write \n 2.Display \n 3.Search \n 4.Delete";
		cout<<"\n Enter your Choice: ";
		cin>>ch;
		switch(ch){
			case 1: cout<<"\n Enter the number of records: ";
			int n;
			cin>>n;
			for(int i=0;i<n;i++)
			{
				write_record();
			}
			break;
			
			case 2: 
			cout<<"\n List of records: ";
			display();
			break;
			
			case 3: 
			cout<<"\n Enter roll no. of student to be searched: ";
			int s;
			cin>>s;
			search(s);
			break;
			
			case 4: 
			int d;
    		cout<<"\n Enter roll no. of student to b deleted: "<<endl;
    		cin>>d;
    		delete_record(d);
    		cout<<"\n Record Deleted.";
    		break;
			
			default:
    		cout<<"\n Thank you! "<<endl;
        	break;
		}
	}
	return 0;
}
