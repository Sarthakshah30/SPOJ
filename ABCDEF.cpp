#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> vec1;
vector<int> vec2;

int main(){
	int n;
	scanf("%d",&n);
	int array[n];
	for(int i = 0 ; i < n ; i++)
	scanf("%d",&array[i]);
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j< n ; j++){
			for(int k = 0 ; k < n ; k++){
				vec1.push_back((array[i]*array[j])+array[k]);
				if(array[i]!=0){
					vec2.push_back(array[i]*(array[j]+array[k]));
				}
			}
		}
	}
	
	sort(vec2.begin(),vec2.end());
	sort(vec1.begin(),vec1.end());
	int total=0;
	
	for(int i  = 0 ; i< vec1.size() ; ){
		int x = vec1[i];
		int low = 0,high=vec2.size()-1;
		int mid;
		while(low<=high){
			mid = (low+high)/2;
			if(vec2[mid]==x)
			break;
			else if(vec2[mid]>x)
			high=mid-1;
			else
			low = mid+1;
		}
		if(low<=high){
			while(mid>=0 && vec2[mid]==x)
			mid--;
			mid++;
			int count =0;
			for(int j = mid ; j<vec2.size() && vec2[j]==x;j++){
			count++;
				
			}
			int count2=0;
			int j;
			for(j = i ; j<vec1.size()  && vec1[j]==x ; j++)
			count2++;
			
			total+=(count2*count);
			i=j;
			continue;
		}
		i++;
	}
	printf("%d\n",total)
}
