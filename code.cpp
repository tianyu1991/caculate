#include<iostream>  
#include <chrono> 
#include <random>
#include <algorithm>
#include <fstream>
#include<stdlib.h>

using   namespace   std;

int count_num(int* data, int num, int x){
	int counts=0;
	for (int i = 0; i < num; i++){
		if (data[i] == x) counts++;
	}
	return counts;
}

int maxm(int n){
	int *mysen = new int[n];
	for (int i = 1; i < n + 1; ++i) mysen[i-1] = i;
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(mysen, mysen+n, default_random_engine(seed));
	int num = 1;
	int max = 1;
	int M = 1;
	for (int i = 0; i < n ; ++i) cout<<mysen[i];
	cout << endl;
	int*myset = new int[2 * n - 2];
	for (num = 1; num < n; num++){
		myset[2*num-2]= mysen[num - 1] - 1;
		myset[2 * num - 1] = mysen[num - 1] + 1;
		int counts = count_num(myset, 2 * num, mysen[num]);
		if (!counts) M = M + 1;
		if (counts==2) M = M - 1;
		if (max < M) max = M;
		}
	delete[]mysen;
	delete[]myset;
	return max;
}
void main(){
	int n = 100;
	int sum = 0;

	for (int i = 0; i < n; i++){

		cout<< maxm(8)<<" ";
	}
	system("pause");
}
