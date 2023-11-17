#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;

using V = set<int>;
using NDFA = map<V, vector<pair<V, char>>>;
using Graph = vector<vector<pair<int, char>>>;

Graph make_NKA(string);
void print_graph(const Graph&);
NDFA determinization_NKA(const Graph&, set<char>);
V DFS(const Graph&, V);
void print_DKA(const NDFA& DKA);


int main() {
	string str;
	cin >> str;

	Graph nka = make_NKA(str);

	print_graph(nka);

	set<char> colection;

	for (auto now : str) {
		if (now != '*') {
			colection.insert(now);
		}
	}

	NDFA DKA = determinization_NKA(nka, colection);
	
	return 0;
}

void print_graph(const Graph& list) {

	int state = 0;
	
	cout << endl << "NKA" << endl;
	
	for (auto i : list) {
		for (auto j : i) {
			std::cout << state << ' ' << j.second << ' ' << j.first << std::endl;
		}
		state++;
	}

}

Graph make_NKA(string str) {
	
	vector<vector<pair<int, char>>> NFA;

	NFA.push_back({});
	int state = 0;

	for (auto chr : str) {
		if (chr != '*') {
			NFA.push_back({});
			NFA.push_back({});
			state += 2;

			NFA[state - 1].push_back({state, chr});
			NFA[state - 2].push_back({ state - 1, '-'});
		}
		else {
			
			NFA.push_back({});
			state++;

			NFA[state - 3].push_back({ state, '-'});
			NFA[state - 1].push_back({ state, '-'});
			NFA[state].push_back({ state - 3, '-'});
		}
	}

	return NFA;
}


NDFA determinization_NKA(const Graph& NKA, set<char> symbol_list) {

	NDFA DKA;
	set<int> start_list = DFS(NKA, { 0 });
	
	stack<set<int>> stack;
	stack.push(start_list);

	while (!stack.empty()) {
		set<int> current = stack.top();
		stack.pop();

		if (DKA.contains(current)) {
			continue;
		}
		
		DKA[current] = {};
		for (auto &s:symbol_list) {
			set<int> next;
			for (auto &v: current) {
				for (auto &e:NKA[v]) {
					if (e.second == s) {
						next.insert(e.first);
					}
				}
			}

			next = DFS(NKA, next);
			if (next.empty()) {
				continue;
			}

			DKA[current].push_back({ next, s });
			stack.push(next);
		}
	}

	print_DKA(DKA);

	return DKA;
}

V DFS(const Graph& list, V visited) {

	stack <int> stack;
	for (int v : visited) {
		stack.push(v);
	}

	while (!stack.empty()) {
		int elem = stack.top();
		stack.pop();

		for (auto edge : list[elem]) {
			if (edge.second == '-') {
				int u = edge.first;

				if (!visited.contains(u)) {
					visited.insert(u);
					stack.push(u);
				}
			}
		}
	}

	return visited;

}

void print_DKA(const NDFA& DKA) {

	map<set<int>, int> dict;
	int q = 0;
	for (auto now : DKA) {
		if (!dict.contains(now.first)){
			dict[now.first] = q;
			q++;
		}
	}
	/*
	for (auto now : dict) {
		cout << now.second << ": ";
		for (auto it : now.first) {
			cout << it << " ";
		}
		cout << endl;
	}
	*/
	cout << endl << "DKA" << endl;
	for(auto list:DKA){
		for (auto now : list.second) {
			cout << dict[list.first] << " " << now.second << " " << dict[now.first] << endl;
		
		}
	}
	
	//std::cout << state << "((" << state << "))" << " -->|" << edge.second << "| " << edge.first << "((" << edge.first << "))" << std::endl; // Печать для mermaid
	return;
}