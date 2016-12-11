#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

int main() {
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		vector<ii> adj[n + 1];
		unordered_map<string, int> cityToIndex(n + 1);
		
		for(int i = 1; i <= n; ++i) {
			string city;
			cin >> city;	
			cityToIndex[city] = i;
			int neighbours;
			scanf("%d", &neighbours);
			for(int j = 0; j < neighbours; ++j) {
				int neighbour, cost;
				scanf("%d %d", &neighbour, &cost);
				adj[i].push_back(make_pair(neighbour, cost));
			}
		}

		int r;
		scanf("%d", &r);
		for(int i = 0; i < r; ++i) {
			string fromCity, toCity;
			cin >> fromCity >> toCity;
			int from = cityToIndex[fromCity];
			int to = cityToIndex[toCity];
			
			vector<int> dist(n + 1, INT_MAX);
			dist[from] = 0;
		
			priority_queue<ii, vector<ii>, greater<ii> > pq; 
			pq.push(make_pair(0, from));
		
			while(!pq.empty()) {
				int u = pq.top().second;
				pq.pop();
		
				for(vector<ii>::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
					int v = it->first;
					int weight = it->second;
					int newCost = dist[u] + weight;
					if(newCost < dist[v]) {
						dist[v] = newCost;
						pq.push(make_pair(newCost, v));
					}
				}
			}

			printf("%d\n", dist[to]);
		}

	}
	return 0;
}
