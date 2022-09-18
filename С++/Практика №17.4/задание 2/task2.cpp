#include <iostream>

void dec(int* pAr, int size){
	int temp;
	for(int i = 0, j = 9; i < size; i++, j--){
		temp = *(pAr+i);
		*(pAr+i) = *(pAr+j);
		*(pAr+j) = temp;
	}
}

int main(){
	int ar[] = {0,1,2,3,4,5,6,7,8,9};
	dec(ar, sizeof(ar)/sizeof(int)/2);
	for(auto num : ar)
		std::cout << num << " ";
	return 0;
}