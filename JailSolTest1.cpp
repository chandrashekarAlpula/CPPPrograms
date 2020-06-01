#include<map>
#include<vector>
#include<string>
#include <fstream>

#include<iostream>
#include<dirent.h>
#include<stdio.h>
#include<cstring>
using namespace std;


void f2(){
	DIR *d;
	char *tocken;
	int ret;
	struct dirent *dir;

	d = opendir(".");
	if(!d){
		cout << "Failed to open the director" << endl;
		return ;
	}

	while((dir = readdir(d)) != NULL){
		std::string str = dir->d_name;
		if( str.find(".dict") != std::string::npos ){
			cout << "Found file " << str ;
		}
	}
}


void f1(){

	DIR *d;
	char *tocken;
	int ret;
	struct dirent *dir;

	d = opendir(".");
	if(!d){
		cout << "Failed to open the director" << endl;
		return ;
	}

	while((dir = readdir(d)) != NULL){
		tocken = strtok(dir->d_name, ".");
		if(tocken){
			tocken = strtok(NULL, ".");
		}

		if(tocken &&  !strcmp(tocken, "dict")){
			cout << "Found file  " << dir->d_name << endl;
		}else{
		//	cout << "Not found file " << dir->d_name << endl ;
		}
	}
}

int main(){

	f2();
	return 0;
}
