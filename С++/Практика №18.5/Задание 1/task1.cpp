#include <iostream>
#include <vector>

void swapVec(std::vector<int>& vec, int* arr){
	for(int i = 0; i < 4; i++){
		int temp = vec[i];
		vec[i] = *(arr+i);
		*(arr+i) = temp;
	}
}

int main(){
	std::vector<int> a = {1,2,3,4};
	int b[] = {2,4,6,8};
	swapVec(a,b);
	for(auto num : a)
		std::cout << num;
	std::cout << std::endl;
	for(auto num : b)
		std::cout << num;
	std::cout << std::endl;
	return 0;
}