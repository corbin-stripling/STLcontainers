/*****************************************************************************************
 * Program Name: menu.cpp
 * Author: Corbin stripling
 * Date: 10/08/2017
 * Description: menu.cpp is the source file for the menu function used in project one. It
 * is designed to be modular by allowing you to change the string in the array to generate
 * new menu options.
*****************************************************************************************/

#include "menu.hpp"
#include "inputValidate.hpp" 
#include<iostream>
#include<string>
int runMenu(){
	std::string menuDesc[] = {"Run Buffer Sim","Run Palindrome","Exit"};

	int menuSize = 3;
	
 
	std::cout<<"*****************************************************"<<std::endl;
	std::cout<<"|                  LAB 9 MAIN MENU                  |"<<std::endl;
	std::cout<<"*****************************************************\n"<<std::endl;
	      
	for(int i = 0;i < menuSize;++i){
		int x = i + 1;
		std::cout<<"  "<<x<<" - "<<menuDesc[i]<<std::endl;
	}

  	std::cout<<"*****************************************************"<<std::endl;

	int userSelect = validateInt( 1, menuSize); 
	return userSelect;

}


