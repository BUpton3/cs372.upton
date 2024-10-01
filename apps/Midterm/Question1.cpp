// Breah Upton
// Used for Help: https://www.geeksforgeeks.org/stack-in-cpp-stl/
// Used for Help: https://www.geeksforgeeks.org/print-stack-elements-from-bottom-to-top/
// 

#include <iostream>
#include <string>
#include <stack>

using namespace std;

void matchingParents(string, int);
void printStack(stack<char>);
void goThrough(int, stack<char>);

int main()
{
	string userInput;
	cout << "Please insert string: ";
	getline(cin, userInput);
	int length = userInput.length();
	matchingParents(userInput, length);

	return 0;
}

void matchingParents(string input, int length)
{
	stack<char> Stack;
	stack<char> temp;
	Stack.push(input[0]);
	for (int count = 1; count < length; count++)
	{
		Stack.push(input[count]);
	}
	temp = Stack;
	cout << "\nYour entered string in its Stack: ";
	printStack(Stack);
	cout << endl << endl;
	int counter = 0;
	goThrough(counter, temp);
}
void printStack(stack<char> Stack)
{
	if (Stack.empty())
		return;
	char x = Stack.top();
	Stack.pop();
	printStack(Stack);
	cout << x;
	Stack.push(x);
}
void goThrough(int counter, stack<char> Stack)
{
	if (Stack.empty())
	{
		if (counter == 0)
		{
			cout << "No parenthesis in entered string." << endl;
			return;
		}
		else if (counter % 2 == 0)
		{
			cout << "All sets of parenthesis have a match." << endl;
			return;
		}
		else
		{
			cout << "There is a parenthesis that does not have an open/close." << endl;
			return;
		};
	}
	char x = Stack.top();
	if (x == '(' || x == ')')
		counter++;
	Stack.pop();
	goThrough(counter, Stack);
	Stack.push(x);
}
