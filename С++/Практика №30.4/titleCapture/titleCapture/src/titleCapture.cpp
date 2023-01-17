#include <iostream>
#include "cpr/cpr.h"

using namespace std;

int main()
{
	cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"), cpr::Header({ {"accept", "text/html"} }));
	for (size_t start = r.text.find("<h1>")+4; start < r.text.find("</h1>"); start++)
		cout << r.text.at(start);
	cout << endl;
	return 0;
}
