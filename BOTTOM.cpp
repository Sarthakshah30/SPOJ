/*
	Author:- Sarthak Shah
	Algorithm:- Strongly Connected Component
*/
#include<iostream>
#include<stack>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

// Declarations
int n,m;
vector<int> adj[5004];
vector<int> transpose[5004];
int component[5004];
bool visited[5004];
vector< vector<int> > connected_comp;
stack<int> st;
vector<int> temp;
void dfs(int src);
void dfs2(int src,int cmp);
// Declarations end.

int main(){
	while(true){
		cin>>n;
		if(n==0)
		break;
		cin>>m;
		for(int i = 0 ; i<m ; i++){
			int x,y;
			cin>>x>>y;
			x--; y--;
			adj[x].push_back(y);
			transpose[y].push_back(x);
		}
		
		memset(visited,false,sizeof(visited));
		for(int i = 0 ; i< n ; i++){
			if(!visited[i])
			dfs(i);
		}
		
		int cmp=0;
		while(!st.empty()){
			int src = st.top(); st.pop();
			if(visited[src]){
				temp.clear();
				dfs2(src,cmp);
				cmp++;
				connected_comp.push_back(temp);
			}
		}
		
		vector<int> result;
		for(int i = 0 ; i < connected_comp.size() ; i++){
			bool flag=false;
			for(int j = 0 ; j < connected_comp[i].size() ; j++){
				int x = connected_comp[i][j];
				for(int k = 0 ; k< adj[x].size() ; k++){
					int y = adj[x][k];
					if(component[x]!=component[y])
					flag=true;
				}
			}
			if(!flag){
				for(int j = 0 ; j<connected_comp[i].size() ; j++){
					result.push_back(connected_comp[i][j]+1);
				}
			}
		}
		
		sort(result.begin(),result.end());
		for(int i = 0 ; i<result.size() ; i++){
			cout<<result[i]<<" ";
		}
		cout<<endl;
		for(int i = 0 ; i< n ; i++){
			transpose[i].clear();
			adj[i].clear();
		}
		connected_comp.clear();
		temp.clear();
	}
}

void dfs(int src){
	visited[src]=true;
	for(int i = 0 ; i<adj[src].size() ; i++){
		int y = adj[src][i];
		if(!visited[y])
		dfs(y);
	}
	st.push(src);
}

void dfs2(int src,int cmp){
	visited[src]=false;
	component[src]=cmp;
	temp.push_back(src);
	for(int i = 0 ; i < transpose[src].size() ; i++){
		int y = transpose[src][i];
		if(visited[y])
		dfs2(y,cmp);
	}
}
