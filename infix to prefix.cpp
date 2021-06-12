#include<iostream>
#include<string.h>
#include<ctype.h>
#include<algorithm>
using namespace std;

#define STACKSIZE 10
class stack
{
	int top;
	char mystack[STACKSIZE];
	public:
		stack()//constructor one object is one stack and value of top is -1
		{
			top=-1;	
		}
		void PUSH(char data)
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
		
		char Peek()
		{
			if(isEmpty())
				return '^';
			else 
			return mystack[top];
			
		}
		int hashigherorsameprecedence(char op)
		{
			if((op==mystack[top]) || ((op=='+' || op=='-') && (mystack[top] == '*' || mystack[top]=='/')) || (op=='*' && mystack[top]=='/')|| ((op=='*' ||op=='/' ||op=='+' ||op=='-' ) && mystack[top]=='$') ||  (op=='/' && mystack[top]=='*')|| (op=='+' && mystack[top]=='-')|| (op=='-' && mystack[top]=='+')  )
				return 1;
			else 
				return 0;
		}
};
void reverse(char str[])
{
		for(int i=0;i<strlen(str)/2;i++)
	{
	    char temp=str[i];
	    str[i]=str[strlen(str)-i-1];
	    str[strlen(str)-i-1]=temp;
	}
}


int main()
{
	stack s;
	char result[10]="";
	char infix[10], postfix[10];
	int j=0,z=0;
	//a-b*c
	cout<<"enter an expression\n";
	cin.getline(infix,10);
	reverse(infix);
	for(int i=0; i< strlen(infix);i++)
	{
		if(isdigit(infix[i]) || isalpha(infix[i]))
			{
				result[z]=infix[i];
				z++;
			}
		else if(infix[i]=='(')
			s.PUSH(infix[i]);
		else if(infix[i]=='$')
		{
			if(s.Peek()=='$')
				s.PUSH(infix[i]);
			else
				goto label;
		}
		else if(infix[i]=='*'||infix[i]=='/'||infix[i]=='-'||infix[i]=='+')
		{
			label:
			if(!s.isEmpty() && s.hashigherorsameprecedence(infix[i]))
			{
				result[z]=s.Peek();
				z++;
				s.POP();
				s.PUSH(infix[i]);
			}
			else
				s.PUSH(infix[i]);
			
		}
		else if(infix[i]==')')
		{
			do 
			{
				result[z]=s.Peek();
				z++;
				s.POP();
			}while(s.Peek()!='(');
			s.POP();
		}
		else 
			s.PUSH(infix[i]);
	}
	do
	{
	result[z]=s.Peek();
				z++;
				s.POP();
			
	}while(!s.isEmpty());
	reverse(result);

	cout<<result;
	
	for(int i=0;i<strlen(result);i++)
	{
		cout<<endl;
		cout<<result[i]<<endl;
	}
	return 0;
}
