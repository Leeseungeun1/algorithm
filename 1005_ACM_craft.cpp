#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int N, K, X, Y, W;
		cin >> N >> K;
		vector<vector<int>> adj(N + 1);
		vector<int> time(N + 1);
		vector<int> indegree(N + 1);
		vector<int> add(N + 1);
		queue<int> Q;

		for (int i = 1; i <= N; i++) {
			cin >> time[i];
		}
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			adj[X].push_back(Y);
			indegree[Y]++;
		}
		for (int i = 1; i <= N; i++) {
			if (indegree[i] == 0)Q.push(i);
		}
		while (!Q.empty()) {
			int size = Q.size();
			for (int i = 0; i < size; i++) {
				int num = Q.front();
				Q.pop();
				for (int j : adj[num]) {
					add[j] = max(add[j], add[num] + time[num]);
					indegree[j]--;
					if (indegree[j] == 0) Q.push(j);
				}
			}
		}
		cin >> W;
		cout << time[W]+add[W] << "\n";
	}
	return 0;
}