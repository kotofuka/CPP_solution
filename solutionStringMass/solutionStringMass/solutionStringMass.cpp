#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main()
{
    /*
    string s1, s2;
    cin >> s1;
    s2 = s1;
    reverse(s1.begin(), s1.end());
    cout << (s1 == s2) << s1;
    */
    /*
    int n;
    set <string> words;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        words.insert(s);
    }

    //for (auto it = words.begin(); it != words.end(); it++){
    //  auto &x = *it;
    //}

    // for each
    for (auto s : words) {
        cout << s << " ";
    }
    */
    /*
    int n;
    map <int, set <string>> groups;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int number;
        cin >> name >> number;
        groups[number].insert(name);
    }
    for (auto i : groups) {
        cout << i.first << ": ";
        for (auto j : i.second) {
            cout << j << " ";
        }
        cout << endl;
    }
    */
    int n;
    string s = "a";
    cin >> n;
    map <string, int> group;
    for (int i = 0; i < n; i++) {
        string name;
        int mark;
        cin >> name >> mark;
        group[name] = mark;
    }
    cout << endl;
    while (s != "end") {

        cin >> s;
        if (group.count(s) > 0) {
            cout << "<<<< " << group[s];
        }
        else if (s == "end") {

        }
        else {
            cout << "<<<< " << "no student";
        }
        cout << endl;
    }
}
