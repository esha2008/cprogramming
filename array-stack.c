#include<stdio.h>
#define MAXSIZE 6

struct stack{
	int stk[MAXSIZE];
	int top;
	}s;

void pop();
void push();
void display();

int main()
{
	s.top=-1;
	int element,choice;
	while(1)
	{
		printf("\n 1. Push \n 2. Pull \n 3. Display \n Please enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{		
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			default:return;
		}
	}
}
void push()
{
	int totalnumbers;	
	int arr[6];
	int j;
	totalnumbers=s.top;
	if(totalnumbers==6) 
	{
		printf("\n Stack is already full");
		return;
	}
	else
	{
		
		printf("\n Enter the numbers to be entered");
		for(j=0;j<(6-totalnumbers-1);j++)
		{
			scanf("%d",&arr[j]);
			s.top++;
			s.stk[s.top]=arr[j];
		}	
	}
display();
}
void pop()
{
	int num;
	if(s.top==-1)
	{	
		printf("\n Stack is empty");
		return;
	}
	else
	{
		num=s.stk[s.top];
		s.top--;
		printf("\n The number popped out is: %d",num);
	}
display();
}
void display()
{
	int i;
	if(s.top==-1)
		printf("\n Stack is empty");
	else
	{
		printf("\n Your stack:\n");
		for(i=s.top;i>=0;i--)
			printf("\n%d\n",s.stk[i]);
		 }
}

			
