#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
#include<utility>

using namespace std;

class UnionFindDisjointSet{
	private:
		vector<int> parent,rank;
	public:
		UnionFindDisjointSet(int N){
			parent.assign(N,0);
			rank.assign(N,0);
			for(int i = 0 ; i<N ; i++){
				parent[i]=i;
			}
		}
		int findSet(int i){
			return ((parent[i]==i) ? i : (parent[i]=findSet(parent[i])));
		}
		
		bool isSameSet(int i,int j){
			return findSet(i)==findSet(j);
		}
		
		void doUnion(int i,int j){
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
	int n,m;
	cin>>n>>m;
	vector< pair<int, pair<int,int> > > edgeList;
	for(int i = 0 ; i< m ; i++){
		int x,y,w;
		cin>>x>>y>>w;
		x--;
		y--;
		edgeList.push_back(make_pair(w, make_pair(x,y)));
	}
	sort(edgeList.begin(),edgeList.end());
	UnionFindDisjointSet UFDS(n);
	long weight=0;
	for(int i = 0 ;i<m ; i++){
		int w = edgeList[i].first;
		int x = edgeList[i].second.first;
		int y = edgeList[i].second.second;
		if(!UFDS.isSameSet(x,y)){
			weight+=w;
			UFDS.doUnion(x,y);
		}
	}
	cout<<weight<<endl;
}
