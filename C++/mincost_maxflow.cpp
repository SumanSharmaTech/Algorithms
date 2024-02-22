struct edge {
    int next, capacity, cost;

    edge() {}

    edge(int a, int b, int c) {
        next = a, capacity = b, cost = c;
    }
};

vector<edge> e;
vector<vector<int>> adj;
const int INF = 1e9;
int edge_cnt = 0;

void add_edge(int x, int y, int c, int w) {
    //edge_cnt is the real edge and edge_cnt^1 will be the back edge

    adj[x].push_back(edge_cnt);
    // e[edge_cnt++] = edge(y, c, w);
    e.push_back(edge(y, c, w));
    edge_cnt++;

    adj[y].push_back(edge_cnt);
    // e[edge_cnt++] = edge(x, 0, -w);
    e.push_back(edge(x, 0, -w));
    edge_cnt++;
}

void SPFA(int n, int src, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    p.assign(n, -1);
    vector<int> cnt(n, 0);
    d[src] = 0;
    vector<bool> in_queue(n, false);
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;
        for (int eid : adj[u]) {
            int nxt = e[eid].next;
            if (e[eid].capacity > 0 && d[nxt] > d[u] + e[eid].cost) {
                d[nxt] = d[u] + e[eid].cost;
                p[nxt] = eid;
                if (!in_queue[nxt]) {
                    in_queue[nxt] = true;
                    q.push(nxt);
                    if (cnt[nxt] > n) {
                        cout << "negative cycle\n";
                        return ;
                    }
                }
            }
        }
    }
}

//change req_flow to infinity to make it maxflow
int min_cost_flow(int node_count, vector<vector<int>> &adj, int req_flow, int src, int sink) {

    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < req_flow) {
        SPFA(node_count, src, d, p);
        if (d[sink] == INF)
            break;

        // find max flow on that path
        int path_flow = req_flow - flow;
        int cur = sink;
        while (cur != src) {
            path_flow = min(path_flow, e[p[cur]].capacity);
            cur = e[p[cur] ^ 1].next;
        }

        // apply flow
        flow += path_flow;
        cost += path_flow * d[sink];
        cur = sink;
        while (cur != src) {
            e[p[cur]].capacity -= path_flow;
            e[p[cur] ^ 1].capacity += path_flow;
            cur = e[p[cur] ^ 1].next;
        }
    }

    if (flow < req_flow)
        return -1;
    else
        return cost;
}

//min cut - set of edges between 2 disjoint sets of vertex
//1st set are the nodes which are reachable by dfs starting at source on the residue graph after getting maxflow
//2nd set are the nodes which arent there in 1st set