/*
 * AsyncSample1.cpp
 *
 *  Created on: Nov 27, 2019
 *      Author: chandra.shekhar
 */
#include<iostream>
#include<future>
#include<chrono>

using namespace std;

 bool is_prime(unsigned long x){
	 std::chrono::time_point<std::chrono::system_clock> start, end;
	 start = std::chrono::system_clock::now();
	 std::cout << "Calculating. Please, wait...\n";
	 for (int i=2; i<x; ++i) if (x%i==0) return false;
	 end = std::chrono::system_clock::now();
	 std::chrono::duration<double> elapsed_time = end - start;

	 cout <<"\n time take to compute is " << elapsed_time.count() << endl;
	 return true;
 }
int main(){

	unsigned long x = 313222313;
	//unsigned long x = 313222313;
	//std::future<bool> fut = std::async(std::launch::async, is_prime, x);
	std::future<bool> fut = std::async(std::launch::async, is_prime, x);
	cout << "\nCalled Assync \n";
	cout << "\n Get " << fut.get() << endl;
	return 0;
}



