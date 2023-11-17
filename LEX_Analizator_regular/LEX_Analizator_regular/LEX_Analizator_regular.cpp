#include <iostream>
#include <string>
#include <vector>

using namespace std;

//void Normalize(vector<vector<pair<int, char>>>& list);
vector<vector<pair<int, char>>> makeNKA(string str);
void print_NKA(const vector<vector<pair<int, char>>>& list);


int main() {

	string reg_exp;
	cin >> reg_exp;

	vector<vector<pair<int, char>>> NKA = makeNKA(reg_exp);

	print_NKA(NKA);

	return 0;
}


vector<vector<pair<int, char>>> makeNKA(string str) {
	if (str.size() == 0) {
		return { {{}} };
	}
	else if (str.size() == 1) {
		return { {{}}, {{0, str[0]}} };
	}
	vector<vector<pair<int, char>>> NKA = { {{}} };

	for (int i = 0; i < (int)str.size(); i++) {
		if (str[i] == '*' and  i + 1 == (int)str.size()) {
			break;
		}
		if (str[i] != '*' and str[i + 1] != '-') {
			NKA.push_back({ {(int)NKA.size() - 1, str[i]}});
		}
		else if (str[i] != '-') {
			int len = (int)NKA.size() - 1;
			NKA.push_back({ {len, '-'}});
			NKA[len + 1].push_back({len + 2, '-'});
			NKA.push_back({ {len + 1, str[i]}});
			NKA.push_back({ {len, '-'} });
			NKA[len + 3].push_back({len + 2, '-'});
		}
	}
	return NKA;
}
/*
void Normalize(vector<vector<pair<int, char>>>& list) {
	for (vector<pair<int, char>> now : list) {
		for (auto it : now) {
			if (it.first) {
				it.first++;
			}
		}
	}
	return;
}
*/

void print_NKA(const vector<vector<pair<int, char>>>& list) {
	int counter = 0;
	for (auto now : list) {
		
		for (auto it : now) {
			//if (it.first) {
			cout << it.first << " " << it.second << " " << counter << endl;
			
		}
		counter++;
	}
	return;
}