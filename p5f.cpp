//this is practical 5

#include<iostream>
using namespace std;

void display(int ht[10], int n, int count)
{
    cout<<endl;
    cout<<"\n The List of all the numbers is: ";
    for(int i=0; i<n; i++)
    {
        cout<<ht[i]<<"  ";
    }
    cout<<endl;
    cout<<"\n The count of probing is: "<<count;

}

void linearProbing(int ht[10], int n, int countl)
{
    int index, tel;
    cout<<"\n Enter all the telephone numbers: ";

    for(int i=0; i<n; i++)
    {
        cout<<endl;
        cout<<"\n Enter number: ";
        cin>>tel;

        index = tel % 10;
        if(ht[index]==0)
        {
            ht[index] = tel;
        }
        else
        {
            int j = index + 1;   //imp
            countl++;
            while(j <= 10)
            {
                if(ht[j] == 0)
                {
                    ht[j] = tel;
                    break;
                }
                else if(j>9)
                {
                    j=0;
                    countl++;
                }
                else
                {
                    j++;
                    countl++;
                }
            }
        }
    }
    display(ht, n, countl);
}

void quadraticProbing(int ht[10], int n, int countq)
{
    int tel, index;
    cout<<"\n Enter all the telephone numbers: ";

    for(int i=0; i<n; i++)
    {
        cout<<endl;
        cout<<"\n Enter number: ";
        cin>>tel;

        index = tel % 10;
        if(ht[index]==0)
        {
            ht[index] = tel;
        }
        else
        {
            int j = 1;
            while(j<10)
            {
                index = (tel + (j*j)) % 10;
                if(ht[index]==0)
                {
                    ht[index] = tel;
                    countq++;
                    break;
                }
                else
                {
                    j++;
                    countq++;
                }
            }
        }
    }
    display(ht, n, countq);
}

int main()
{
int ht[10] = {0};
int n, ch;
int countl = 0, countq = 0;
cout<<endl;
cout<<"\n Enter count of telephone numbers";
cin>>n;
cout<<endl;
cout<<"\n<==== MENU ====>";
cout<<"\n 1. Linear Probing";
cout<<"\n 2. Quadratic Probing";
cout<<"\n Enter your choice: ";
cin>>ch;
switch(ch)
{
    case 1:
    linearProbing(ht, n, countl);
    break;

    case 2:
    quadraticProbing(ht, n, countq);
    break;

    default:
    cout<<"\n Wrong Choice! ";
    break;
}
return 0;
}