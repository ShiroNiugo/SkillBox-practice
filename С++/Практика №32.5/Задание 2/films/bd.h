void createBD() {
	std::ofstream output("../file.json");
	nlohmann::json filmsOutput
		= {
			{"Dune: Part One", {{"country", {"United States"}},
								{"date", "2021"},
								{"studio", {"Warner Bros. Pictures"}},
								{"script author", {{"Jon Spaihts"},{"Denis Villeneuve"},{"Eric Roth"}}},
								{"director", "Denis Villeneuve"},
								{"producer", {{"Denis Villeneuve"},{"Mary Parent"},{"Cale Boyter"},{"Joe Caracciolo Jr."}}},
								{"roles", {{"Paul Atreides", "Timothee Chalamet"},
											{"Chani", "Zendaya"},
											{"Lady Jessica Atreides", "Rebecca Ferguson"},
											{"Duke Leto Atreides","Oscar Isaac"},
											{"Duncan Idaho","Jason Momoa"}}
								}}
			},
			{"Interstellar", {{"country", {{"United States"}, {"United Kingdom"}}},
								{"date", "2014"},
								{"studio", {{"Warner Bros. Pictures"},{"Paramount Pictures"}}},
								{"script author", {{"Jonathan Nolan"},{"Christopher Nolan"}}},
								{"director", "Christopher Nolan"},
								{"producer", {{"Emma Thomas"},{"Christopher Nolan"},{"Lynda Obst"}}},
								{"roles", {{"Cooper", "Matthew McConaughey"},
											{"Brand", "Anne Hathaway"},
											{"Murph", "Jessica Chastain"},
											{"Romilly","David Gyasi"},
											{"Professor Brand","Michael Caine"}}
								}}
			},
			{"Gisaengchung", {{"country", {"South Korea"}},
								{"date", "2019"},
								{"studio", {"CJ Entertainment"}},
								{"script author", {{"Bong Joon Ho"},{"Han Jin-won"}}},
								{"director", "Bong Joon Ho"},
								{"producer", {{"Kwak Sin-ae"},{"Moon Yang-kwon"},{"Bong Joon-ho"},{"Jang Young-hwan"}}},
								{"roles", {{"Ki Taek", "Song Kang-ho"},
											{"Dong Ik", "Lee Sun-kyun"},
											{"Yeon Kyo", "Cho Yeo-jeong"},
											{"Ki Woo","Choi Woo-sik"},
											{"Ki Jung","Park So-dam"}}
								}}
			},
			{"Inception", {{"country", {"United States"}},
								{"date", "2010"},
								{"studio", {"Warner Bros. Pictures"}},
								{"script author", {{"Christopher Nolan"}}},
								{"director", "Christopher Nolan"},
								{"producer", {{"Emma Thomas"},{"Christopher Nolan"}}},
								{"roles", {{"Cobb", "Leonardo DiCaprio"},
											{"Arthur", "Joseph Gordon-Levitt"},
											{"Ariadne", "Elliot Page"},
											{"Eames","Tom Hardy"},
											{"Saito","Ken Watanabe"}}
								}}
			},
			{"The Imitation Game", {{"country", {"United States"}},
								{"date", "2014"},
								{"studio", "The Weinstein Company"},
								{"script author", {{"Graham Moore"},{"Andrew Hodges"}}},
								{"director", "Morten Tyldum"},
								{"producer", {{"Nora Grossman"},{"Ido Ostrowsky"},{"Teddy Schwarzman"}}},
								{"roles", {{"Alan Turing", "Benedict Cumberbatch"},
											{"Joan Clarke", "Keira Knightley"},
											{"Hugh Alexander", "Matthew Goode"},
											{"Detective Robert Nock","Rory Kinnear"},
											{"John Cairncross","Allen Leech"}}
								}}
			}
	};
	output << filmsOutput;
	output.close();
}