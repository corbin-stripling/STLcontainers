/************************************************************************
 * File Name : main.cpp
 * Author: Corbin Stripling
 * Date: 11/26/2017
 * Description: main file for Lab 9.
************************************************************************/
#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<ctime>
#include<cstdlib>
#include"menu.hpp"
 
int main(){

	std::srand(std::time(NULL));//Seeds random for use with buffer sim.

	int userSelect;//variable for menu choice.

	int numRounds,percentToPush,percentToPop,N;//variables for user input and N.
	
	std::queue<int> buffer;// buffer queue
	std::queue<int> tempBuffer;//temporary queue to assist with printing buffer values
	
	userSelect = runMenu();//calls menu function
	
	while(userSelect != 3){//runs program as long as user does not choose to exit
		if(userSelect == 1){
			//Start of the buffer sim if selected by user.
			double avgLength = 0.0;
			double sumOfLengths = 0.0;
			std::cout<<"How many rounds will be simulated?"<<std::endl;
			std::cin>>numRounds;

			while(!std::cin){//input validation for number of rounds
				std::cin.clear();
				std::cin.ignore();
				std::cout<<"Invalid number of rounds:"<<std::endl;
				std::cin>>numRounds;
			}
	
			std::cout<<"What is the percentage chance to add to the end of the buffer?"<<std::endl;
			std::cin>>percentToPush;

			while(!std::cin){//input validation for percentage to add.
				std::cin.clear();
				std::cin.ignore();
				std::cout<<"Invalid percentage(must be in int format):"<<std::endl;
				std::cin>>percentToPush;
			}

			std::cout<<"What is the percentage chance to remove from the front on the buffer?"<<std::endl;
			std::cin>>percentToPop;

			while(!std::cin){//input validation for percentage to remove
				std::cin.clear();
				std::cin.ignore();
				std::cout<<"Invalid percentage(must be in int format):"<<std::endl;
				std::cin>>percentToPop;
			}

			for(int i = 0; i < numRounds; i++){//for loop performs rounds requirements set forth in guidelines.
				int chanceToPush;
				int chanceToPop;
				double roundCount = i + 1;
	
				N = rand() % 1000 + 1;//generates random int between 1 - 1000
				chanceToPush = rand() % 100 + 1;//generates percent chance to push value to queue
				chanceToPop = rand() % 100 + 1;//generates percent chance to pop from queue

				if(chanceToPush <= percentToPush){//checks for push against user input 
					buffer.push(N);
				}
		
				if(chanceToPop <= percentToPop && !buffer.empty()){
				//Only pops if buffer not empty to avoid segmentation fault.
					buffer.pop();
				}
		
				if(!buffer.empty()){//prints copy of queue if not empty	
					while(!buffer.empty()){
						tempBuffer.push(buffer.front());
						buffer.pop();
					}
					int x;
					x = tempBuffer.size();
					sumOfLengths += x; //adds current length to sum of lengths to get round by round average
					for(int j = 0; j < x; j++){
						std::cout<<tempBuffer.front()<<" ";
						buffer.push(tempBuffer.front());
						tempBuffer.pop();
					}
			
					std::cout<<std::endl;
	
					std::cout<<"Buffer length is: "<<x<<std::endl;
				}
				else if(buffer.empty()){//prints generic message if queue is empty
					std::cout<<"Buffer is currently empty"<<std::endl;
				}
		
				avgLength = (sumOfLengths / roundCount);
		
		
				std::cout<<"Average length for round "<<roundCount<<": "<<avgLength<<std::endl;	
			}
			if(!buffer.empty()){ //Empties buffer in case you run sim again.
				while(!buffer.empty()){
					buffer.pop();
				}
			}		
		}
		else if(userSelect == 2){
			std::string word;
			std::stack<char> wordStack;
			std::cout<<"Enter a string to create the palindrome: "<<std::endl;
			std::cin>>word;

			for(int i = 0; i < word.length(); i ++){//pushes individual char on to stack
				wordStack.push(word.at(i));
			}	

			while(!wordStack.empty()){//Pushes characters to the back of the inputted word in reverse order.
				word.push_back(wordStack.top());
				wordStack.pop();
			}

			std::cout<<word<<std::endl;//prints palindrome
		}
		userSelect = runMenu();
	}
	return 0;
} 
  
