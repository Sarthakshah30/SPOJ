#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<map>

using namespace std;
		
vector< pair<int,int> > adj[10002];
int n;
int dijkstra(int src,int dest);

int main(){
	std::ios::sync_with_stdio(false);
	int test;
	cin>>test;
	while(test-->0){
		int q,temp,x,w;
		cin>>n;
		map<string,int> m;
		for(int i = 0 ; i < n ; i++){
			string str;
			cin>>str;
			m[str]=i;
			cin>>temp;
			for(int j = 0 ; j< temp ; j++){
				cin>>x>>w;
				x--;
				adj[i].push_back(make_pair(x,w));
			}
		}
		cin>>q;
		for(int i = 0 ; i<q ; i++){
			string str1,str2;
			cin>>str1>>str2;
			int src = m[str1];
			int dest = m[str2];
			priority_queue< pair<int,int> , vector< pair<int,int> > , greater < pair<int,int> > > pq;
			vector<int> dist(n,1000000000);
			dist[src]=0;
			pq.push(make_pair(src,0));
			while(!pq.empty()){
				pair<int,int> temp = pq.top() ; pq.pop();
				int d = temp.second;
				int u = temp.first;
				if(dist[u]<d)
				continue;
				for(int i = 0 ; i < adj[u].size() ; i++){
					pair<int,int> adjacent = adj[u][i];
					if(dist[u]+adjacent.second < dist[adjacent.first]){
						dist[adjacent.first]=dist[u]+adjacent.second;
						pq.push(make_pair(adjacent.first,dist[adjacent.first]));
					}
				}
				if(u==dest)
				break;
			}
			cout<<dist[dest]<<"\n";
		}
		for(int i = 0 ; i< n ; i++){
			adj[i].clear();
		}
	}
}

int dijkstra(int src,int dest){
	
	return 0;
}
