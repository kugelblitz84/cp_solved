#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long

const int N=2e5+10;
vector<vector<int>> adj_list(N);

map<pair<int,int>,int> cost_map;

void bfs(int n, int dist[], const vector<bool>& hash) {
    map<pair<int, int>, bool> mp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    bool horse = false;
    dist[n] = 0; // Initialize the distance for the starting node
    if (hash[n]) horse = true; // Check if the node has a horse
    q.push({dist[n], n}); // Push the starting node into the queue

    while (!q.empty()) {
        auto parent = q.top();
        q.pop();
        int parent_node = parent.second;
        int distance_parent = parent.first;

        if (hash[parent_node]) horse = true; // Update horse status

        for (auto child : adj_list[parent_node]) {
            // If using horse and edge hasn't been processed yet
            if (horse && !mp[{parent_node, child}]) {
                cost_map[{parent_node, child}] >>= 1; // Halve the cost
                mp[{parent_node, child}] = true; // Mark the edge as processed
                mp[{child, parent_node}] = true; // Mark the reverse edge
            }

            int adj_cst = cost_map[{parent_node, child}]; // Get the cost to the child

            // Update distance if a shorter path is found
            if (dist[child] > distance_parent + adj_cst) {
                dist[child] = distance_parent + adj_cst;
                q.push({dist[child], child}); // Push updated distance to the queue
            }
        }
    }
}

void solve() {
    adj_list.clear();
    cost_map.clear();
    int dist_from_o[N];
    int dist_from_n[N]; 
    fill(dist_from_o, dist_from_o + N, N); // Use LLONG_MAX for initialization
    fill(dist_from_n, dist_from_n + N, N); // Use LLONG_MAX for initialization

    vector<bool> hrs_hash(N);
    int n, m, h;
    cin >> n >> m >> h;
    int hh;

    for (int i = 0; i < h; i++) {
        cin >> hh;
        hrs_hash[hh] = true; // Mark horse presence
    }

    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
        cost_map[{to,from}] = cost;
        cost_map[{from, to}] = cost; // Store the cost
    }

    bfs(1, dist_from_o, hrs_hash); // Perform BFS from node 1
    bfs(n, dist_from_n, hrs_hash); // Perform BFS from node n

    // Output results
    //cout << dist_from_o[0] << " " << dist_from_n[0] << endl;

    int ans = LLONG_MAX; // Initialize answer to maximum possible value
    for (int i = 1; i <= n; i++) {
        ans = min(ans, max(dist_from_n[i], dist_from_o[i])); // Find minimum distance
    }
    //cout << endl;
    cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //memset(dist,k,sizeof(dist));
    //memset(visited,false,sizeof(visited));
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
