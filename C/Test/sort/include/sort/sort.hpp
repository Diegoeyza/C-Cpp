#ifndef SORT_SORT_HPP
#define SORT_SORT_HPP
#include <string>
using namespace std;

namespace sort {
	void selectionSort(float* A, int n);
	int split_qs(float* A, int i, int j);
	int split_qs(string A[], int i, int j);
	void quickSort(float* A, int i, int j);
	void quickSort(string* A, int i, int j);
	void quickSort(float* A, int n);
	void quickSort(int* A, int i, int j);
	void quickSort(int* A, int n);
	int  k_smallest(float* A, int i, int j, int k);
	int  k_smallest(float* A, int n, int k);
	int sequence(string key, string* A, int i, int max);
	int bsearch(string key, string* A, int i, int j);
}

#endif
