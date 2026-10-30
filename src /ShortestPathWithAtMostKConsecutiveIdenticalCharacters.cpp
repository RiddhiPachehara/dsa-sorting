class Solution {
public:
    long long shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }


        const long long INF = 1e18;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            if (d > dist[u][count]) continue;

            if (u == n - 1) {
                return d;
            }

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                int new_count = 1;
                if (labels[u] == labels[v]) {
                    new_count = count + 1;
                }

                if (new_count <= k) {
                    long long next_dist = d + w;
                    if (next_dist < dist[v][new_count]) {
                        dist[v][new_count] = next_dist;
                        pq.push({next_dist, v, new_count});
                    }
                }
            }
        }

        long long ans = INF;
        for (int c = 1; c <= k; ++c) {
            ans = min(ans, dist[n - 1][c]);
        }

        return ans == INF ? -1 : ans;
    }
};
