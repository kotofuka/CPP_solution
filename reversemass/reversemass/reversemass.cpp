#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int a;
	int mass[100];
	string str = "";
	vector <int> din = {};
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> mass[i];
		str += " " + to_string(mass[i]);
		din.push_back(mass[i]);
	}
	for (int i = a - 1; i >= 0; i--) {
		cout << mass[i] << " ";
	}
	cout << endl;
	reverse(din.begin(), din.end());
	reverse(str.begin(), str.end());
	cout << str << endl;
	for (auto now : din) {
		cout << now << " ";
	}
}