#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
std::string CommonPrefix(const std::vector<std::string>& words);
bool IsEqual(const vector<string>& words, int index);


int main()
{
	int n;
	string x;
	cin >> n;
	vector <string> words;
	for (int i = 0; i < n; i++) {
		cin >> x;
		words.push_back(x);
	}
	string res = CommonPrefix(words);
	cout << res;

}

bool IsEqual(const vector<string>& words, int index) {
	for (int i = 0; i < (int)words.size(); i++) {
		if (words[i][index] != words[0][index]) {
			return false;
		}
	}
	return true;
}


string CommonPrefix(const vector<string>& words){
	string prefix = "";
	int min_len = words[0].size();
	for (int i = 0; i < words.size(); i++) {
		min_len = min(min_len, (int)words[i].size());
	}
	for (int i = 0; i < min_len; i++) {
		if (IsEqual(words, i)) {

			string c(1, words[0][i]);
			//cout << "true " << c << endl;
			prefix += c;
		}
		else {
			return prefix;
		}
	}
	return prefix;
}