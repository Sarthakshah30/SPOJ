#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#define INF 99999999

using namespace std;

int N,M,Q;
vector< pair<int,int> > adj[600000];
pair<int,int> dijkstra(int src);

int main(){
	scanf("%d%d%d",&N,&M,&Q);
	for(int i = 0 ; i < M ; i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		adj[x].push_back(make_pair(y,w));
		adj[y].push_back(make_pair(x,w));
	}
	for(int i = 0 ; i < Q ; i++){
		int src;
		scanf("%d",&src);
		pair<int,int> ans=dijkstra(src);
		printf("%d %d\n",ans.first,ans.second);
	}
}

pair<int,int> dijkstra(int src){
	priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > > pq;
	vector<int> dist(N,INF);
	dist[src]=0;
	int counter,maxdist=0;
	counter=maxdist;
	pq.push(make_pair(src,0));
	while(!pq.empty()){
		pair<int,int> temp=pq.top(); pq.pop();
		int u = temp.first;
		int d = temp.second;
		if(d > dist[u])
		continue;
		if(dist[u]>maxdist)
		maxdist=dist[u];
		for(int i = 0 ; i < adj[u].size() ; i++){
			pair<int,int> adjacent=adj[u][i];
			if(dist[u]+adjacent.second < dist[adjacent.first]){
				dist[adjacent.first]=dist[u]+adjacent.second;
				pq.push(make_pair(adjacent.first,dist[adjacent.first]));
			}
		}
	}
	for(int i = 0 ; i<N ; i++){
		if(dist[i]==maxdist)
		counter++;
	}
	int i;
	int maxdist2=0;
	for(i = 0 ; i < adj[src].size() ; i++){
		pair<int,int> adjacent=adj[src][i];
		if(adjacent.first==src){
			if(adjacent.second>maxdist2)
			maxdist2=adjacent.second;
		}		
		else
		break;
	}
	if(i==adj[src].size()){
		return make_pair(maxdist2,1);
	}
	for(i = 0 ; i < adj[src].size() ; i++){
		pair<int,int> adjacent=adj[src][i];
		if(adjacent.first==src){
			if(adjacent.second>maxdist)
			counter++;
			break;
		}		
;
	}
	return make_pair(maxdist,counter);
}
