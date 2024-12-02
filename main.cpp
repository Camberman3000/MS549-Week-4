/* Mark Montenieri
   Fall 2024
   MS549

  Assignment 4.1: Project - Linked List implemented as a Stack and a Queue
  References: I used ChatGPT to help me with the stack and queue code.
   */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <chrono>
#include<vector>
#include <wtypes.h>
#include <winuser.h>
#include "Queue.cpp"
#include "Stack.cpp"

using namespace std;

int menu()
{
	cout << "Please choose from the options below." << '\n' << '\n';
	int choice;
	cout << "1 = Insert random numbers into a queue" << '\n';	 
	cout << "2 = Delete all random numbers from a queue" << '\n';	 
	cout << "3 = Insert random numbers into a stack" << '\n';	 
	cout << "4 = Delete all random numbers from a stack" << '\n';	 
	cout << "5 = Exit program" << '\n';
	cin >> choice;// User input
	return choice;
}; // End of menu

int main()
{
	cout << "Insert and Delete random integers from queues and stacks" << '\n' << '\n';
		 
	Queue q;
	Stack s;

	int choice = menu();// Show menu
	while (choice != 5)
	{
		if (choice == 1)// QUEUE: Insert 100 random numbers into a queue
		{			
			int n;
			cout << "Choose how many random numbers to insert into the queue" << '\n' << '\n';
			cin >> n;
			q.enqueue(n);
		} 
		else if (choice == 2)// QUEUE: Delete all random numbers from the queue
		{
			q.dequeue();
			cout << "Deleted all random numbers from the queue" << '\n' << '\n';

		}
		else if (choice == 3)// QUEUE: Insert random numbers into a stack
		{
			int n;
			cout << "Choose how many random numbers to insert into the stack" << '\n' << '\n';
			cin >> n;
			s.push(n);
		}
		else if (choice == 4)// QUEUE: Delete 100 random numbers into the stack
		{
			s.pop();
			cout << "Deleted all random numbers from the stack" << '\n' << '\n';

		}		 
		else if (cin.fail())
		{
			cout << "Invalid input. Please try again." << '\n';
			cin.clear();
			cin.ignore();
		}
		else
		{
			cout << "Invalid choice. Please try again." << '\n';
		}

		cout << '\n';
		choice = menu();// Reopen menu
		cin.ignore();// clear input buffer
	};

	system("pause");// Pause to keep program open
	return 0;
}// end main