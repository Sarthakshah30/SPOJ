#include<iostream>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;
int n,m;
vector<int> adj[9002];
vector<int> transpose[9002];
stack<int> st;
bool visited[9002];
vector<int> temp;
vector< vector<int> > connected_graph;
int component[9002];
int temp1=0;


void dfs(int src){
	visited[src]=true;
	for(int i = 0 ; i< adj[src].size() ; i++){
		int j = adj[src][i];
		if(!visited[j])
		dfs(j);
	}
	st.push(src);
}

void dfs2(int src,int cmp){
	component[src]=cmp;
	visited[src]=false;
	temp.push_back(src);
	for(int i = 0 ; i < transpose[src].size() ; i++){
		int j = transpose[src][i];
		if(visited[j])
		dfs2(j,cmp);
	}
}

void dfs3(int src){
	visited[src]=true;
	temp1+=connected_graph[src].size();
	for(int i = 0 ; i< transpose[src].size() ;i++){
		int j = transpose[src][i];
		if(!visited[j])
		dfs3(j);
	}
}

int main(){
	int test;
	scanf("%d",&test);
	while(test-->0){
		getchar();

		scanf("%d%d",&n,&m);
		for(int i = 0 ; i< m ; i++){
			int x,y;
			scanf("%d %d",&x,&y);
			x--;
			y--;
			adj[y].push_back(x);
			transpose[x].push_back(y);
		}
		memset(visited,false,sizeof(visited));
		for(int i = 0 ; i < n ; i++)
		if(!visited[i])
		dfs(i);
		
		int cmp = 0;
		
		while(!st.empty()){
			int src = st.top();
			st.pop();
			if(visited[src]){
				temp.clear();
				dfs2(src,cmp);
				cmp++;
				connected_graph.push_back(temp);
			}
		}
		
		for(int i = 0 ; i< n ; i++){
			visited[i]=false;
			transpose[i].clear();
		}
		
		for(int i = 0 ; i< connected_graph.size() ; i++){
			for(int j = 0 ; j < connected_graph[i].size() ; j++){
				int x = connected_graph[i][j];
				for(int k = 0 ; k< adj[x].size() ; k++){
					int y = adj[x][k];
					if(component[x]!=component[y]){
						transpose[component[x]].push_back(component[y]);
					}
				}
			}
		}
		
		memset(visited,false,sizeof(visited));
		int max=0;
		temp.clear();
		for(int i = 0 ; i <connected_graph.size() ; i++){
			dfs3(i);
			if(temp1<max){
				temp1=0;
				memset(visited,false,sizeof(visited));
				continue;
			}
			if(temp1>max){
				temp.clear();
				for(int  j = 0 ; j<connected_graph[i].size() ; j++){
					temp.push_back(connected_graph[i][j]);
				}
			}
			else{
				for(int  j = 0 ; j<connected_graph[i].size() ; j++){
					temp.push_back(connected_graph[i][j]);
				}				
			}
			max=temp1;
			temp1=0;
			memset(visited,false,sizeof(visited));
		}
		
		sort(temp.begin(),temp.end());
		for(int i = 0 ; i < temp.size() ; i++){
			cout<<temp[i]+1<<" ";
		}
		cout<<endl;
		
		for(int i = 0 ; i< n ; i++){
		
		adj[i].clear();
		transpose[i].clear();
		}
		connected_graph.clear();
		temp.clear();
	}
}



