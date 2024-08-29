#include "sort/sort.hpp"
#include "sort/utils.hpp"
#include <chrono>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

#define wordsfile "D10000.txt"   //poner el archivo a utilizar
#define max 10000				  //tamaño del archivo en cantidad de palabras

long getElapsedTime(std::chrono::time_point<std::chrono::high_resolution_clock> t1,
		std::chrono::time_point<std::chrono::high_resolution_clock> t2){
	auto int_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
	return static_cast<long>(int_ms.count());
}

int main(int nargs, char** args){

	static string words[max];   //se utiliza static para evitar el kernel overflow
	string myText;

	ifstream words_file(wordsfile);
	int i=0;


	while (getline (words_file, myText)) {
		words[i]=myText;
		i++;
	}
	cout<<"finished filling"<<endl;
	words_file.close();
	int coincidence=0;


	ifstream requests("Nc.txt");

	//auto start = std::chrono::high_resolution_clock::now();
	sort::quickSort(words,0,max-1);
	auto start = std::chrono::high_resolution_clock::now();

	while (getline (requests, myText)){		//comentar o descomentar el sequence para usarlo, si se descomenta, comentar el quick sort y el bsearch, también se puede hacer un contador+=sort::sequence (aprovechando el contaodr ya declarado) para guardar la cantidad de palabras encontradas
		//sort::sequence(myText,words,0,max);
		sort::bsearch(myText,words,0,max-1);
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::cout<<" Elapsed : " << getElapsedTime(start, end) << std::endl;
	//std::cout<<" coincidences : " << coincidence << std::endl;

	requests.close();
	cout << "-------------------------------" << endl;
	return 0;
}