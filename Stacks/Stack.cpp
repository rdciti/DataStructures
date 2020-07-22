#include<iostream>

using namespace std;

#define SIZE 10

class Stack
{
	int top;

	public:
		int a[SIZE]; //Array of Size 10

		Stack()
		{
			top = -1; //Initializing top variable to -1 in a Constructor
		}

		bool push(int x);
		int pop();
		int peek();
		bool isEmpty();

		void display(int size);
};

bool Stack::push(int x)
{
	//If value of top is more than size of the array then stack is overflowed
	if (top >= (SIZE - 1))
	{
		cout << "Stack Overflow!!!" << endl;
		return false;
	}
	else
	{
		top    = top + 1;
		a[top] = x;
		cout << x << " is pushed onto Stack." << endl;
		return true;
	}
}

int Stack :: pop()
{
	int x;

	if (top < 0)
	{
		cout << "Stack is underflow" << endl;
		return 0;
	}
	else
	{
		top = top - 1;
		x = a[top];
		return x;
	}
}

int Stack::peek()
{
	int x;

	if (top < 0)
	{
		cout << "Stack is Empty!!" << endl;
		return 0;
	}
	else
	{
		x = a[top];
		return x;
	}
}

bool Stack::isEmpty()
{
	if (top < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Stack::display(int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
}

int main()
{
	Stack s; //Instantiate class Stack

	s.push(5);
	s.push(10);
	s.push(15);

	cout << "\nAfter pushing 3 elements, Stack is: ";
	s.display(3);

	cout << "\n" << s.pop() << " has been popped out from the stack" << endl;
	cout << "Now elements in the array are: ";
	s.display(2);
	return 0;
}