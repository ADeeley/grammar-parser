#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
inline void keep_window_open() { char ch; cin >> ch; }

int error(string s) {
	throw runtime_error(s);
}

string type(string word) {
	// takes in a string and returns the word type as a string

	string nouns[]{ "bird", "cat", "dog", "fish", "dogs" };
	string articles[]{ "the", "a", "The" };
	string verbs[]{ "runs", "flys", "swims", "barks", "run", "fly", "swim", "bark", "jumps"};
	string adjectives[]{ "big", "small", "happy", "sad" };
	string conjunctions[]{ "but", "and", "however" };

		for (string n : nouns)
			if (n == word)
				return "noun";

		for (string n : articles)
			if (n == word)
				return "article";

		for (string n : verbs)
			if (n == word)
				return "verb";

		for (string n : adjectives)
			if (n == word)
				return "adjective";

		for (string n : conjunctions)
			if (n == word)
				return "conjunction";

		error("Word not in dictionary.");
}

void grammar_checker() {
	// Takes in user input and runs throgh the grammar checks.
	// throws an error if any of the checks fail.

	vector<string>sentence;
	string word;
	while (cin >> word) {
		if (word == ".")
			break;
		else
			sentence.push_back(type(word));
	}

	string prev = "none";
	for (string word : sentence) {
		if (word == "noun" && (prev != "article" && prev != "adjective"))
			error("Nouns must be preceeded by either an article or adjective.");

		else if (word == "adjective" && (prev != "adjective" && prev != "none" && prev != "article"))
			error("Adjectives can only follow articles or another adjective.");

		else if (word == "verb" && (prev != "noun" && prev != "conjunction" && prev != "none"))
			error("Verbs must follow a noun or a conjunction.");

		else prev = word;
	}
}

int main() {
	try {
		grammar_checker();
	}
	catch (runtime_error&e) {
		cout << e.what() << endl;
		keep_window_open();
		return 1;
	}
	catch (...) {
		cout << "Unknown Error" << endl;
		keep_window_open();
		return 1;
	}
	cout << "Correct sentence." << endl;
	return 0;
}