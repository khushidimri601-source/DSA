class Solution {
public:
    typedef long long ll;
    typedef pair<ll, int> P;

    bool check(int mid, int n, ll k, unordered_map<int, vector<vector<int>>> &adj) {
        vector<ll> result(n, LLONG_MAX);
        priority_queue<P, vector<P>, greater<P>> pq;

        result[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            ll d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (d > k)
                continue;

            if (node == n - 1)
                return true;

            if (d > result[node])
                continue;

            for (auto &vec : adj[node]) {
                int ngbr = vec[0];
                int cost = vec[1];

                if (cost < mid)
                    continue;

                if (d + cost < result[ngbr]) {
                    result[ngbr] = d + cost;
                    pq.push({result[ngbr], ngbr});
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online, long long k) {
        int n = online.size();

        unordered_map<int, vector<vector<int>>> adj;

        int l = INT_MAX;
        int r = INT_MIN;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            if (!online[u] || !online[v])
                continue;

            adj[u].push_back({v, cost});

            l = min(l, cost);
            r = max(r, cost);
        }

        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(mid, n, k, adj)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};