#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

int main()
{
	std::ofstream file("../file.json");
	nlohmann::json film 
	= {
		{"film","Dune: Part One"},
		{"country", {"United States"}},
		{"date", "2021"},
		{"studio", {"Warner Bros. Pictures"}},
		{"script author", {{"Jon Spaihts"},{"Denis Villeneuve"},{"Eric Roth"}}},
		{"director", "Denis Villeneuve"},
		{"producer", {{"Denis Villeneuve"},{"Mary Parent"},{"Cale Boyter"},{"Joe Caracciolo Jr."}}},
		{"roles:", {
					{"Paul Atreides", "Timothée Chalamet"},
					{"Chani", "Zendaya"},
					{"Lady Jessica Atreides", "Rebecca Ferguson"},
					{"Duke Leto Atreides","Oscar Isaac"},
					{"Duncan Idaho","Jason Momoa"}
				   }}
	};
	file << film;
	return 0;
}
