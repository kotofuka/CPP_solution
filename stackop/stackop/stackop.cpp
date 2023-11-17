#include <iostream>
using namespace std;

void read_matrix(int n, int m, int x[]);
/*
void stack(int n) {
    if (n <= 0) {
        return;
    }
    int a;
    cin >> a;
    stack(n - 1);
    cout << a;
}
*/
/*
void stack(int n) {
    if (n < 0) {
    }
    int a;
    cin >> a;
    cout << stack(n - 1) << " " << a;
}
*/

void input_mass(int n, int x[]) {
    if (n < 0) {
        return;
    }

    input_mass(n - 1, x);
    cin >> x[n];
}

void reaf_matrix(int n, int m, int x[]) {
    if (m < 0) {
        return;
    }
    input_mass(n - 1, x[m]);
    read_matrix(int n, int m - 1, int x);
}


int main()
{
    /*
    int b;
    cin >> b;
    int mass[100] = {};
    input_mass(b - 1, mass);
    for (int i = 0; i < b; i++) {
        cout << mass[i] << " ";
    }
    */
    int n, m;
    cin >> n >> m;
    int mass[100][100];
    read_matrix(n, m - 1, mass[][100]);
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mass[i][j];
            
        }
        
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }
    */

}
