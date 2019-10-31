/**
 * Description: Dijkstra (Find shortest path from single source)
 * Usage: dijkstra O((V + E) lg(V))
 * Source: https://github.com/dragonslayerx
 */

// We mark the distance of src 0 initially nad all other verticies as infinity. When we pop element from queue we check if we can make 
// distance less than the current distance. 
// If finally distance of some node if infinity that means it is not reachable from source.

const int MAX = 100050;
const int INF = 1e9;

void dijkstra(vector< vector< pair<int,int> > > &G, int vertexCount, int src, int dist[]){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    bool isvisited[MAX];

    for (int i = 0; i < vertexCount; i++) {
        dist[i] = INF;
        isvisited[i] = false;
    }

    dist[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty()){
        pair<int, int> tp = pq.top();
        pq.pop();
        int node = tp.second;
        int d = tp.first;
        if (!isvisited[node]) {
            isvisited[node] = true;
            for (int i = 0; i < G[node].size(); i++) {
                int v = G[node][i].first;
                int w = G[node][i].second;
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }
}
