//queue implementation using an array

#include<iostream>
#include<conio.h>// new line and screen holding
#include<stdlib.h>// 
#define MAXSIZE 5

using namespace std;

class queue
{
	int rear, front;
	int myqueue[MAXSIZE];
	public:
		queue()//constructor one object is one stack and value of top is -1
		{
			rear =-1;
			front =-1;		
		}
		void ENQUEUE(int data)
		{
			if(isEmpty())
				front++;	
			rear++;
			if(!isFull())
				myqueue[rear]=data;	
			else
				{
					cout<<"queue overflow\n";
					rear--;
				}
		}
		void DEQUE()
		{
			if(!isEmpty())
				{
					front++;
				}
				//condition for when front and rear equal and resetting them to -1
			if(front==rear)
				queue();
			else 
				cout<<"queue underflow\n";
			
		}
		int isFull()
		{
			return (rear==(MAXSIZE))?1:0;
		}
		int isEmpty()
		{
			// when 2 data entered and done 3 deque
			return (rear==-1 || front>rear)?1:0;
			
			
		}
		
		void Peekr()
		{
			if(isEmpty())
				cout<<"queue is empty\n";
			else 
			cout<<myqueue[rear];
			
		}
		void Peekf()
		{
			if(isEmpty())
				cout<<"queue is empty\n";
			else 
			cout<<myqueue[front];
			
		}
};
int main()
{
	queue s;
	/*
	s.ENQUEUE(2);//0
	s.ENQUEUE(324);//1
	s.ENQUEUE(324);//2
	s.DEQUE();//1
	s.ENQUEUE(324);//2
	s.ENQUEUE(324);//3
	s.ENQUEUE(3233);//4
	cout<<s.Peek();
	*/
	int i=1,data,j;
	do
	{
		cout<<"1 to enqueue the data\n";
		cout<<"2 to deque the data\n";
		cout<<"3 to see the Front data\n";
		cout<<"4 to exit\n";
		cin>>j;
		switch(j)
		{
			case 1:
				cout<<"enter the data\n";
				cin>>data;
				s.ENQUEUE(data);
				break;
			case 2:
				s.DEQUE();
				break;
			case 3:
				s.Peekf();
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
