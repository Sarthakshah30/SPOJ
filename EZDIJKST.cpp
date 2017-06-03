#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#define INF 99999999
using namespace std;

int main(){
	int test;
	scanf("%d",&test);
	while(test-->0){
		int V,E;
		scanf("%d%d",&V,&E);
		vector< pair<int,int> > adj[V];
		for(int i = 0 ; i <E ; i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			adj[--a].push_back(make_pair(--b,c));
		}
		int src,dest;
		scanf("%d%d",&src,&dest);
		src--; dest--;
		vector<int> dist(V,INF);
		dist[src]=0;
		priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > > pq;
		pq.push(make_pair(src,0));
		while(!pq.empty()){
			pair<int,int> temp = pq.top(); pq.pop();
			int u = temp.first;
			int d = temp.second;
			if(d > dist[u])
			continue;
			for(int i = 0 ; i < adj[u].size() ; i++){
				pair<int,int> adjacent = adj[u][i];
				if(dist[u]+adjacent.second < dist[adjacent.first]){
					dist[adjacent.first]=dist[u]+adjacent.second;
					pq.push(make_pair(adjacent.first,dist[adjacent.first]));
				}
			}
		}
		if(dist[dest]!=INF)
		printf("%d\n",dist[dest]);
		else
		printf("NO\n");
	}
}
