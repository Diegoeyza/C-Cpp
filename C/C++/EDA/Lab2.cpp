#include "sort/sort.hpp"
#include "sort/utils.hpp"
#include <chrono>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

long getElapsedTime(std::chrono::time_point<std::chrono::high_resolution_clock> t1,
		std::chrono::time_point<std::chrono::high_resolution_clock> t2){
	auto int_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
	return static_cast<long>(int_ms.count());
}

void testSort(int max_size, int n_sizes){
	int* sizes = sort::linspace(max_size, n_sizes);
	float* A = nullptr;
	int n = 0;
	for (int i = 0; i < n_sizes; i++){
		n = sizes[i];
		A = sort::createRandomIntArray(n, 0, 100);
		auto start = std::chrono::high_resolution_clock::now();
		//change the sort method here
		sort::quickSort(A, n);
		//
		auto end = std::chrono::high_resolution_clock::now();
		long elapsed =  getElapsedTime(start, end);
		sort::deleteArray(A);
		std::cout << " [" << n << "," << elapsed << "]" << std::endl;
	}
	delete[] sizes;
}


//int main(int nargs, char** nvargs){
//	int n_sizes = 10;
//	int max_size = 100000;
//	testSort(max_size, n_sizes);
//	return 0;
//}


int main(int nargs, char** args){

	string myText;

	// Read from the text file
	ifstream MyReadFile("ruts_100.txt");
	int ruts[100];

	// Use a while loop together with the getline() function to read the file line by line
	int i = 0;
	while (getline (MyReadFile, myText)) {
	// Output the text from the file
		ruts[i] = stoi(myText);
		i++;
	}

	cout << "-------------------------------" << endl;

	auto start = std::chrono::high_resolution_clock::now();
	sort::quickSort(ruts, 100);
	auto end = std::chrono::high_resolution_clock::now();
	std::cout<<" Elapsed : " << getElapsedTime(start, end) << std::endl;
	// for(int i=0; i< 100; i++){
	// 	cout << ruts[i] << endl;
	// }

	// Close the file
	MyReadFile.close();

//	auto start = std::chrono::high_resolution_clock::now();
//	sort::quickSort(A, n);
//	sort::printArray(A, n);
//	sort::deleteArray(A);
//	auto end = std::chrono::high_resolution_clock::now();
//	std::cout<<" Elapsed : " << getElapsedTime(start, end) << std::endl;
	return 0;
}
