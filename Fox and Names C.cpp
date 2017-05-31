#include<iostream>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;
vector<int> adj[26];
stack<int> st;
vector<int> color(26,0);
vector<int> visited(26,0);

int cycle(int src){
	color[src]=1;
	for(int i = 0; i <adj[src].size() ;i++){
		int y = adj[src][i];
		if(color[y]==0 && cycle(y)==999)
		return 999;
		else if(color[y]==1)
		return 999;
		else
		continue;
	}
	color[src]=2;
	return 12;
}

void topological(int src){
	visited[src]=true;
	for(int i = 0 ; i<adj[src].size() ; i++){
		if(!visited[adj[src][i]])
		topological(adj[src][i]);
	}
	st.push(src);
}


int main(){
	int lines;
	cin>>lines;
	vector<string> names;
	for(int i = 0 ; i<lines ; i++){
		string str;
		cin>>str;
		names.push_back(str);
	}
	bool imp=false;
	for(int i = 0 ; i<lines-1 ; i++){
		int j;
		for(j=0 ; j<names[i].size() && j<names[i+1].size() ; j++){
			if(names[i][j]==names[i+1][j])
			continue;
			adj[names[i][j]-'a'].push_back(names[i+1][j]-'a');
			break;
		}
		if(j==names[i+1].size() && names[i].size()>names[i+1].size())
		imp=true;
	}
	if(imp){
		cout<<"Impossible"<<endl;
		return 0;
	}
	for(int i = 25 ; i>=0 ; i--)
	if(color[i]==0)
	if(cycle(i)==999){
		label:
		cout<<"Impossible"<<endl;
		return 0;
	}
	
	for(int i = 25 ; i>=0 ; i--){
		if(!visited[i])
		topological(i);
	}
	
	while(!st.empty()){
		cout<<char(st.top()+'a');
		st.pop();
	}
	
}
