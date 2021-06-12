//stack implementation using an array

#include<iostream>
#include<conio.h>// new line and screen holding
#include<stdlib.h>// 
#define STACKSIZE 4

using namespace std;

class stack
{
	int top;
	int mystack[STACKSIZE];
	public:
		stack()//constructor one object is one stack and value of top is -1
		{
			top=-1;	
		}
		void PUSH(int data)
		{
			top++;
			if(!isFull())
				mystack[top]=data;	
			else
				{
					cout<<"stack overflow\n";
					top--;
				}
		}
		void POP()
		{
			if(!isEmpty())
				top--;
			else 
				cout<<"stack underflow\n";
			
		}
		int isFull()
		{
			return top==(STACKSIZE)?1:0;
		}
		int isEmpty()
		{
			return top==-1?1:0;
		}
		
		void Peek()
		{
			if(isEmpty())
				cout<<"stack is empty\n";
			else 
			cout<<mystack[top];
			
		}
};
int main()
{
	stack s;
	/*
	s.PUSH(2);//0
	s.PUSH(324);//1
	s.PUSH(324);//2
	s.POP();//1
	s.PUSH(324);//2
	s.PUSH(324);//3
	s.PUSH(3233);//4
	cout<<s.Peek();
	*/
	int i=1,data,j;
	do
	{
		cout<<"1 to insert the data\n";
		cout<<"2 to delete the data\n";
		cout<<"3 to see the top data\n";
		cout<<"4 to exit\n";
		cin>>j;
		switch(j)
		{
			case 1:
				cout<<"enter the data\n";
				cin>>data;
				s.PUSH(data);
				break;
			case 2:
				s.POP();
				break;
			case 3:
				s.Peek();
				cout<<endl;
				break;
			case 4:
				i=0;
				break;
			default:
				cout<<"enter a valid option\n";
				break;
		}
	}while(i==1);
	return 0;
}
