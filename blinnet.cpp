#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

int findNode(int u, vector<int>& parents) {
	if(parents[u] != u) {
		parents[u] = findNode(parents[u], parents);
	}
	return parents[u];
}

void unionNodes(int u, int v, vector<int>& parents, vector<int>& rank) {
	int x = findNode(u, parents);
	int y = findNode(v, parents);
	
	if(rank[x] < rank[y]) {
		parents[x] = y;
	} else if(rank[x] > rank[y]) {
		parents[y] = x;
	} else {
		parents[x] = y;
		rank[y]++;
	}
}

int main() {
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		vector<int> parents(n + 1);
		vector<int> rank(n + 1, 1);
		vector<pair<int, ii> > edges;
		for(int i = 1; i <= n; ++i) {
			parents[i] = i;
			string city;
			cin >> city;	
			int neighbours;
			scanf("%d", &neighbours);
			for(int j = 0; j < neighbours; ++j) {
				int neighbour, cost;
				scanf("%d %d", &neighbour, &cost);
				edges.push_back(make_pair(cost, make_pair(i, neighbour)));
			}
		}
		int res = 0;
		sort(edges.begin(), edges.end());
		
		int curr = 0;
		int e = 0;
		while(e < n - 1) {
			pair<int, ii> edge = edges[curr++];
			int u = edge.second.first;
			int v = edge.second.second;
			if(findNode(v, parents) != findNode(u, parents)) {
				unionNodes(u, v, parents, rank);
				res += edge.first;
				e++;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
