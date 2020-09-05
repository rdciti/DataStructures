#include<iostream>

using namespace std;

#define SIZE 10

struct Node {
	int data;
	struct Node* link;
};
struct Node* top;

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
		top = top + 1;
		a[top] = x;
		cout << x << " is pushed onto Stack." << endl;
		return true;
	}
}

int Stack::pop()
{
	int x;
	int elementToBePopped;

	if (top < 0)
	{
		cout << "Stack is underflow" << endl;
		return 0;
	}
	else
	{
		elementToBePopped = a[top];
		top = top - 1;
		x = a[top];
		return elementToBePopped;
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

void stackByArray()
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
}



// Utility function to add an element data in the stack 
 // insert at the beginning 
void push(int data)
{
	// create new node temp and allocate memory 
	struct Node* temp;
	temp = new Node();

	// check if stack (heap) is full. Then inserting an element would 
	// lead to stack overflow 
	if (!temp) {
		cout << "\nHeap Overflow";
		exit(1);
	}

	// initialize data into temp data field 
	temp->data = data;

	// put top pointer reference into temp link 
	temp->link = top;

	// make temp as top of Stack 
	top = temp;
}

// Utility function to check if the stack is empty or not 
int isEmpty()
{
	return top == NULL;
}

// Utility function to return top element in a stack 
int peek()
{
	// check for empty stack 
	if (!isEmpty())
		return top->data;
	else
		exit(1);
}

// Utility function to pop top  
// element from the stack 

void pop()
{
	struct Node* temp;

	// check for stack underflow 
	if (top == NULL) {
		cout << "\nStack Underflow" << endl;
		exit(1);
	}
	else {
		// top assign into temp 
		temp = top;

		// assign second node to top 
		top = top->link;

		// destroy connection between first and second 
		temp->link = NULL;

		// release memory of top node 
		free(temp);
	}
}

// Function to print all the  
// elements of the stack  
void display()
{
	struct Node* temp;

	// check for stack underflow 
	if (top == NULL) {
		cout << "\nStack Underflow";
		exit(1);
	}
	else {
		temp = top;
		while (temp != NULL) {

			// print node data 
			cout << temp->data << " ";

			// assign temp link to temp 
			temp = temp->link;
		}
	}
}
void stackByLinkedList()
{
	push(11);
	push(22);
	push(33);
	push(44);

	// display stack elements 
	display();

	// print top element of stack 
	cout << "\nTop element is :" << peek() << endl;

	// delete top elements of stack 
	pop();
	pop();

	// display stack elements 
	display();
	
	// print top element of stack 
	cout << "\nTop element is :" << peek();
}

int main()
{
	stackByArray();

	printf("\n\n Now, implementation by LinkedList: \n");
	stackByLinkedList();

	return 0;
}