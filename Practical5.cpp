#include<iostream>
using namespace std;

void display(int ht[10],int count)
{
     cout<<"Phone number list is : "<<endl;         //display
   for(int i=0;i<10;i++)
   {
       cout<<ht[i]<<" ";
          }cout<<endl;
    cout<<"Count of probing "<<count<<endl;
}

void Linear_Probing(int ht[10],int n,int countl)
{
    int tel,index;                                           
      cout<<"Enter the telephone numbers"<<endl;
   for(int i=0;i<10;i++)                                   // accepting array
   {
       cin>>tel;
       index=tel % 10;
       if(ht[index]==0)             
        {
           ht[index]=tel;
        }
       else 
       {                                                
           int j= index + 1;                           // linear probing
           while(j<=10)
           {
               if(ht[j]==0)
               {
                   ht[j]=tel;
                   countl++;
                    break;
               }
               else if(j>9)
               {
                   j=0;
               }
               else
               {
                   j++;
                   countl++; 
                }
            }
        }
    }
   display(ht,countl);
}

void Quadratic_Probing(int ht[10],int n, int countq)
{
    int tel,index;
    cout<<"Enter the telephone numbers "<<endl;                    
    for(int i=0;i<10 ;i++)
    {                                                       //accepting array
        cin>>tel;
       index=tel % 10;
         if(ht[index]==0)            
       {
           ht[index]=tel;
       }
       else if(ht[index]!=0)
       {
            int j=1;
                while( j< 10)
                {
                    // j=1;
                  index=(tel+(j*j))%10;                // qudratic probing
                  if(ht[index]==0)
                    {
                      ht[index]=tel;
                      countq++;
                      break;
                    }
                   j++;
                   countq++;
                }    
        }
    }
     display(ht,countq);
}

int main()
{
   int n, ht[10]={0};
    int countq=0, countl=0;
   cout<<"Enter number of telephone  "<<endl;
   cin>>n;

   int ch;
   cout<<"1. Linear Probing"<<endl;
   cout<<"2. Quadratic probing"<<endl;
   cin>>ch;
   switch (ch)
   {
       case 1:
          Linear_Probing(ht,n,0);
          break;

       case 2:
          Quadratic_Probing(ht,n,0);
          break;
       
       default:
       cout<<"Wrong Input"<<endl;
       break;
   }
    return 0;
}
