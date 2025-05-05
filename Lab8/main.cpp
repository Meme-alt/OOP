#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <cctype>
using namespace std;

string get(const string& s) {
	string a;
	for (char c : s) {
		a += tolower(c);
	}
	return a;
}
bool separator(char c) {
	if (c == ' ' || c == ',' || c == '.' || c == '?' || c == '!')
		return 1;
	return 0;
}
void split(const string& s, map<string, int>& count) {
	size_t i = 0;
	while (i < s.size()) {
		if (separator(s[i]) && i < s.size()) {
			i++;
		}
		size_t start = i;
		while (separator(s[i]) == 0 && i < s.size()) {
			i++;
		}
		if (start < i) {
			string word = get(s.substr(start, i - start));
			count[word]++;
		}
	}
}

int main() {
	ifstream fin("file.txt");
	string s;
	string line;
	while (getline(fin, line)) {
		s += line + ' ';
	}
	fin.close();
	map<string, int> count;
	split(s, count);
	auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second == b.second)
		return a.first > b.first;
	return a.second < b.second;
	};
	priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
	for (const auto& a : count) {
		pq.push(a);
	}
	while (!pq.empty()) {
		cout << pq.top().first << " : " << pq.top().second << endl;
		pq.pop();
	}
	return 0;
}
