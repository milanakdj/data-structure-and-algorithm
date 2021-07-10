#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
void toh(int n, char from, char to, char aux)
{
	if(n==1)// NUmber of Disks is 1: Base Case
		{
			cout<<"move disk "<<n<<" from peg- "<<from<<" to peg- "<<to<<endl;
			return;	
		}
	
	toh(n-1,from,aux,to);
	cout<<"move disk "<<n<<" from peg- "<<from<<" to peg- "<<to<<endl;
	toh(n-1,aux,to,from);
	//cout<<"move disk "<<n<<" from peg- "<<aux<<" to peg- "<<to;
}
int mul(int a, int b)// 5*3= 5 + 5*2; 5*2= 5 + 5
{
	if(b==1)
		return a;
	else 
	{
		int c=a+mul(a,b-1);
		return c;
	}
}
int main()
{
	cout<<"\t\t Implementation of Tower of Hanoi using Recursion\n";
	int c,n=0,m;
	do
	{
		cout<<"1. The TOH\n";
		cout<<"2. For multiplication\n";
		cout<<"3. Exit\n";
		cout<<"Enter your choice:\n";
		cin>>c;
		switch(c)
		{
			case 1:
				cout<<endl<<"please enter the data to be inserted: ";
				cin>>n;
				toh(n,'A','B','C');
				break;
			case 2:
				cout<<endl<<"please enter two numbers: ";
				cin>>n>>m;
				cout<<"multiplication is: "<<mul(n,m)<<endl;
				break;
			case 3:
				c=0;
				getch();
				system("CLS");
				break;
			default:
				cout<<"enter a valid option";
				break;
		}		
	}while(c!=0);
	return 0;
}
