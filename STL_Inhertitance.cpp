/*
 * STL_Inhertitance.cpp
 *
 *  Created on: Jul 29, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<vector>
#include<fstream>
#include<iterator>
#include<algorithm>

class FileEditor : public std::vector<std::string>{
public:
	FileEditor(char *fileName){
		std::istream in(fileName);
		std::string line ;
		while(getline(in, line)){
			push_back(line);
		}
	}
	void Print(){
		for(iterator itr = begin(); itr != end(); itr++)
			std::cout << *itr << " " ;
		std::cout << std::endl;

	}
	void Write(std::ostream &out = std::cout){
		std::copy(begin(), end(), std::ostream_iterator(out, "\n"))
	}
};
int main(int argv, char *argc[]){

	return 0;
}



