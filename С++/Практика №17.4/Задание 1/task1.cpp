#include <iostream>

void swap(int* pa, int* pb){
	int c = *pb;
	*pb = *pa;
	*pa = c;
}

int main(){
	int a = 10, b = 20;
	swap(&a, &b);
	std::cout << a << " " << b << std::endl;
	return 0;
}