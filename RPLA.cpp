#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

int main(){
	int test;
	scanf("%d",&test);
	for(int sc = 1 ; sc<=test;sc++){
		int n,m;
		scanf("%d%d",&n,&m);
		vector<int> indegree(n,0);
		vector<int> adj[n];
		for(int i = 0 ; i < m ; i++){
			int x,y;
			cin>>y>>x;
			adj[x].push_back(y);
			indegree[y]++;
		}
		vector<int> rank(n,-1);
		vector< pair<int,int> > sortedRank;
		queue<int> q;
		int curr=1;
		while(true){
			for(int i = 0 ; i< n ; i++){
				if(!indegree[i] && rank[i]==-1) 
				q.push(i);
			}
			if(q.empty())
			break;
			while(!q.empty()){
				int x = q.front(); q.pop();
				rank[x]=curr;
				sortedRank.push_back(make_pair(curr,x));
				for(int j = 0 ; j<adj[x].size() ; j++){
					indegree[adj[x][j]]--;
				}
			}
			curr++;
		}
		sort(sortedRank.begin(),sortedRank.end());
		printf("Scenario #%d:\n",sc);
		for(int i = 0 ; i< n ; i++){
			printf("%d %d\n",sortedRank[i].first,sortedRank[i].second);
		}
	}
}
