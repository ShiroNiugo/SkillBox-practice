#include <iostream>
#include <fstream>
#include <string>

// D:\\test\\questions.txt

int main()
{
	int person = 0, viewer = 0, offset, indexStr = 0;
	std::string path, question, answer, answerTrue;
	bool retired[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	std::cout << "Input path (\\->\\\\): ";
	std::cin >> path;
	std::ifstream data(path), answers;
	if (data.is_open())
	{
		while (person < 6 && viewer < 6)
		{
			printf("Input offset (current %i): ", (indexStr+1));
			std::cin >> offset;
			indexStr += offset;
			while (!retired[indexStr])
				(indexStr < 13) ? indexStr++ : indexStr = 0;
			data.seekg(0);
			for (int j = 0; j <= indexStr; j++)
				getline(data, question);
			std::cout << question << std::endl << "Input answer: ";
			std::cin >> answer;
			answers.open("D:\\test\\" + std::to_string(indexStr + 1) + ".txt");
			answers >> answerTrue;
			answers.close();
			(answer == answerTrue) ? person++ : viewer++;
			retired[indexStr] = false;
			std::cout << "Person: " << person << "\nViewer: " << viewer << std::endl;
		}
		std::cout << (person>viewer?"Win player":"Win viewer") << std::endl;
		data.close();
	}
	return 0;
}