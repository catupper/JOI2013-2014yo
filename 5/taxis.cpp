#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;
typedef long long Int;
typedef pair<Int, Int> P;

vector<P> edge[2][5250];
Int c[5250], r[5250];
bool come[5250];
Int dist[5250];
void bfs(int x){
    queue<int> q;
    fill(come, come + 5250, false);
    q.push(x);
    for(int i = 0;!q.empty() && i <= r[x];i++){
	for(int j = q.size() - 1;j >= 0;j--){
	    int tmp = q.front();q.pop();
	    if(come[tmp])continue;
	    come[tmp] = true;
	    edge[0][x].push_back(P(tmp, c[x]));
	    for(int k = 0;k < edge[1][tmp].size();k++){
		q.push(edge[1][tmp][k].first);
	    }
	}
    }
}

void dijkstra(int start){
    priority_queue<P, vector<P>, greater<P> > pq;
    fill(dist, dist + 5250, 1LL << 60);
    dist[start] = 0;
    pq.push(P(0, start));
    while(!pq.empty()){
	P tmp = pq.top();pq.pop();
	int from = tmp.second;
	Int cost = tmp.first;
	if(dist[from] < cost)continue;
	for(int i = 0;i < edge[0][from].size();i++){
	    int to = edge[0][from][i].first;
	    Int cc = edge[0][from][i].second;
	    if(dist[from] + cc < dist[to]){
		dist[to] = dist[from] + cc;
		pq.push(P(dist[to], to));
	    }
	}
    }
}

int main(){
    int n, k, a, b;
    cin >> n >> k;
    for(int i = 0;i < n;i++){
	cin >> c[i] >> r[i];
    }
    for(int i = 0;i < k;i++){
	cin >> a >> b;
	a--, b--;
	edge[1][a].push_back(P(b,0));
	edge[1][b].push_back(P(a,0));
    }
    for(int i = 0;i < n;i++){
	bfs(i);
    }
    dijkstra(0);
    cout << dist[n - 1] << endl;
    return 0;
}
