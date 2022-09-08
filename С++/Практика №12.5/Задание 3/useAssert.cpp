#include <iostream>
#include <cassert>

using namespace std;

float travelTime(float distance, float speed){
	assert(speed > 0);
	return distance/speed;
}

int main(){
	float distance, speed;
	cout << "Input distance(km), speed(km/h): ";
	cin >> distance >> speed;
	cout << "Input time: " << travelTime(distance, speed) << " h";
	return 0;
}