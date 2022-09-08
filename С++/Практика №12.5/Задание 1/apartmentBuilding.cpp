#include <iostream>
#include <string>

using namespace std;

int main(){
	string apartments[10];
	for(size_t i = 0; i < 10; i++){
		cout << "Apartment " << (i+1) << ": ";
		getline(std::cin, apartments[i]);
	}
	for(size_t i = 0; i < 3; i++){
		int num;
		do{
			cout << "Apartment number: ";
			cin >> num;
			if(num > 0 && num <= 10) break;
			else cout << "The apartment number is false" << endl;
		}while(1);
		cout << "Lives in an apartment: " << apartments[num-1] << endl;
	}
	return 0;
}