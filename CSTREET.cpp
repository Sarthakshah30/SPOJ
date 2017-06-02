#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

class UnionFindDisjointSet{
	
	private:
		vector<int> rank, parent;
		
	public:
		UnionFindDisjointSet(int N){
			rank.assign(N,0);
			parent.assign(N,0);
			for(int i = 0 ; i< N ; i++)
			parent[i]=i;
		}
		
		int findSet(int i){
			return ((parent[i]==i) ? i : (parent[i]=findSet(parent[i])));
		}
		
		bool isSameSet(int i,int j){
			return findSet(i)==findSet(j);
		}
		
		void Union(int i,int j){
			if(!isSameSet(i,j)){
				int x = parent[i];
				int y = parent[j];
				if(rank[x]>rank[y])
				parent[y]=x;
				else{
					parent[x]=y;
					if(rank[x]==rank[y])
					rank[y]++;
				}
			}
		}		
};

int main(){
	int test;
	cin>>test;
	while(test-->0){
		int weight,n,m;
		cin>>weight>>n>>m;
		vector< pair<int, pair<int,int> > > edgeList;
		for(int i = 0 ; i < m ; i++){
			int x,y,w;
			cin>>x>>y>>w;
			x--;
			y--;
			edgeList.push_back(make_pair(w, make_pair(x,y)));
		}
		sort(edgeList.begin(),edgeList.end());
		int total=0;
		UnionFindDisjointSet UDFS(n);
		for(int i=0 ; i< m ; i++){
			int x = edgeList[i].second.first;
			int y = edgeList[i].second.second;
			int w = edgeList[i].first;
			if(!UDFS.isSameSet(x,y)){
				total+=w;
				UDFS.Union(x,y);
			}
		}
		cout<<total*weight<<endl;
	}
}
