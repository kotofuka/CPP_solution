# include <iostream>

using namespace std;

typedef int arr_t[100];


void createMatrix(int n, int m, arr_t arr[]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}

int main() {
	int n, m;
	arr_t arr[100];

	cin >> n >> m;

	createMatrix(n, m, arr);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}