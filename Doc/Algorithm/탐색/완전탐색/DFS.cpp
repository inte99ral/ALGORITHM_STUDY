#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void DFS(int start, vector<int> graph[], bool check[]) {
  check[start] = true;
  cout << endl
       << "[START] : " << start;
  for (int i = 0; i < graph[start].size(); i++) {
    int next = graph[start][i];
    if (check[next] == false) {
      DFS(next, graph, check);
    }
  }
}

int main() {
  int n, m, start;
  cin >> n >> m >> start;
  vector<int>* graph = new vector<int>[n + 1];

  bool* check = new bool[n + 1];
  fill(check, check + n + 1, false);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  DFS(start, graph, check);
  cout << endl;

  return 0;
}