#include <iostream>

int main()
{
	enum note
	{
		DO = 1,
		RE = 2,
		MI = 4,
		FA = 8,
		SOL = 16,
		LA = 32,
		SI = 64
	};

	std::string melody[12];
	int numNotes, size = std::size(melody);

	for(int i = 0; i < size; i++){
		int notes = 1;
		do{
			std::cout << "Input note: "; 
			std::cin >> numNotes;
			numNotes--;
		}while(numNotes < 0 || numNotes >= 7);
		notes <<= numNotes;
		melody[i] = ((notes & DO) ? "DO" : (notes & RE)  ? "RE"
										 : (notes & MI)  ? "MI"
										 : (notes & FA)  ? "FA"
										 : (notes & SOL) ? "SOL"
										 : (notes & LA)  ? "LA"
										 : (notes & SI)  ? "SI"
										 			     : "");
	}
	for (auto note : melody){
		std::cout << note << " ";
	}
	std::cout << "\n";

	return 0;
}