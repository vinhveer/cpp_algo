#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n;
vector<vector<int>> adj;

void readInput()
{
    cin >> n;

    adj.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];
}

void dijkstra(int start)
{
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);

    dist[start] = 0;

    for (int i = 0; i < n; ++i)
    {
        int u = -1;
        int minDist = INF;

        for (int j = 0; j < n; ++j) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (adj[u][v] != INF && !visited[v]) {
                dist[v] = min(dist[v], dist[u] + adj[u][v]);
            }
        }
    }

    // Print results
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        if (dist[i] == INF)
        {
            cout << "-";
        } else {
            cout << dist[i];
        }
        cout << endl;
    }
}

int main()
{
    readInput();
    dijkstra(0);
    return 0;
}