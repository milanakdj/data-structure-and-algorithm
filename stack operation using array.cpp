//stack implementation using an array

#include<iostream>
#include<conio.h>// new line and screen holding
#include<stdlib.h>//
#include<string.h>
#include<math.h>
#define STACKSIZE 20

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
		
		int PEEK()
		{
			if(!isEmpty())
				return mystack[top];
			
		}
		
		
};

int preEval(char pre[])
		{
			stack s;
			int i, op1, op2, operand,ans;
			
			for(i=strlen(pre)-1;i>=0;i--)
			{
				if(pre[i] >='0' && pre[i] <='9')
				{
					//1 = asci == 49, 0 == 48, then operand =1
					operand =pre[i] - '0';
					s.PUSH(operand);
				}
				else
				{
					op1=s.PEEK();
					s.POP();
					op2=s.PEEK();
					s.POP();
					switch(pre[i])
					{
						case '+':
							ans=op1+op2;
							break;
						case '-':
							ans=op1-op2;
							break;
						case '*':
							ans=op1*op2;
							break;
						case '/':
							ans=op1/op2;
							break;
						case '$':
							ans=pow(op1,op2);
							break;
						default:
							cout<<"invalid operator\n";
							break;
					}
					s.PUSH(ans);
				}
			}
			return s.PEEK();
		}

int postEval(char pre[])
	{
		stack s;
		int i, op1, op2, operand,ans;
		
		for(i=0;i<=strlen(pre)-1;i++)
		{
			if(pre[i] >='0' && pre[i] <='9')
			{
				//1 = asci == 49, 0 == 48, then operand =1
				operand =pre[i] - '0';
				s.PUSH(operand);
			}
			else
			{
				op2=s.PEEK();
				s.POP();
				op1=s.PEEK();
				s.POP();
				switch(pre[i])
				{
					case '+':
						ans=op1+op2;
						break;
					case '-':
						ans=op1-op2;
						break;
					case '*':
						ans=op1*op2;
						break;
					case '/':
						ans=op1/op2;
						break;
					case '$':
						ans=pow(op1,op2);
						break;
					default:
						cout<<"invalid operator\n";
						break;
				}
				s.PUSH(ans);
			}
	}
			return s.PEEK();
	}
int main()
{
	// need a string variable for the numbers and the operators
	char exp[20];
	char ch;
	int i=0,j;
	
	
	do
	{
		cout<<"1 to insert prefix data\n";
		cout<<"2 to delete postfix data\n";
		cout<<"3 to exit\n";
		cin>>j;
		switch(j)
		{
			case 1:
				cout<<"enter the expression below\n";
				cin.ignore();
				cin.getline(exp,20);
				i=preEval(exp);
				i!=0? cout<<"the answer is : "<<i<<endl:cout<<"Error\n";
				break;
				case 2:
				cout<<"enter the expression below\n";
				cin.ignore();
				cin.getline(exp,20);
				i=postEval(exp);
				i!=0? cout<<"the answer is : "<<i<<endl:cout<<"Error\n";
				break;
			case 3:
				i=0;
				break;
			default:
				cout<<"enter a valid option\n";
				break;
		}
	}while(i==1);
	return 0;

	return 0;
}
