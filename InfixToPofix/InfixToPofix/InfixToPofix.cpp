#include<iostream>
using namespace std;
#define SIZE 50
char stack[SIZE];
int top = -1;

void push(char elem)
{
	top++;
	stack[top] = elem;
	return;

}
char pop()
{
	char x;
	x = stack[top];
	top--;
	return x;
}

char peek()
{
	char x;
	x = stack[top];
	return x;
}

int pr(char ch)
{
	switch (ch)
	{
	case '#':return 0;
	case '(':return 1;
	case '+':
	case '-':return 2;
	case '*':
	case '/':return 3;
	}
}

int main()
{
	char infx[50], pofx[50];
		char ch, elem;
	int i = 0, p = 0;
	cout << "Read the Infix Expression:- ";
	cin >> infx;
	push('#');
	while ((ch = infx[i++]) != '\0')
	{
		if (ch == '(')
			push(ch);
		else if (isalnum(ch))
			pofx[p++] = ch;
		else if (ch == ')')
		{
			while (peek() != '(')
				pofx[p++] = pop();
			elem = pop();
		}
		else
		{
			while (pr(peek()) >= pr(ch))
				pofx[p++] = pop();
			push(ch);
		}
	}
	while (peek() != '#')
		pofx[p++] = pop();
	pofx[p] = '\0';
	cout << "\nGiven Expression:- " << infx <<endl << "Postfix Expression:- " << pofx<<endl;
}