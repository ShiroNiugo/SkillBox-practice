#include <iostream>

using namespace std;

int main(){
	float number[15];
	cout << "Input: ";
	for(int i = 0; i < 15; i++)
		cin >> number[i];
	for(int i = 0; i < 15; i++)
		for(int j = i; j < 15; j++)
			if(number[i] < number[j])
				swap(number[j], number[i]);
	for(auto num : number)
		cout << num << " ";
}