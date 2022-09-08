#include <iostream>
#include <vector>

int main(){
	float sum = 0;
	std::vector<float> prices {2.5, 4.25, 3.0, 10.0};
	std::vector<int> items {1, 1, 0, 3};
	for(size_t i = 0; i < items.size(); i++){
		sum+=prices[items[i]];
	}
	std::cout << "Total cost: " << sum << std::endl;
}