#include<algorithm>
#include<iostream>
using namespace std;
bool func(int mid, int *array, int n , int c);

int main(){
	int test;
	cin>>test;
	while(test-->0){
		int n,c;
		cin>>n>>c;
		int array[n];
		for(int i = 0 ; i< n ; i++)
		cin>>array[i];
		sort(array,array+n);
		int low = 0, high = array[n-1];
		while(low<=high){
			int mid  =  low+ (high-low)/2;
			if(func(mid,array,n,c))
			{
				low=mid+1;
			}
			else
			high=mid-1;
		}
		cout<<low-1<<endl;
	}
	
}

bool func(int mid, int *array, int n , int c){
	int pre = array[0],required = 1;
	for(int i = 1 ; i< n ; i++){
		if(array[i]-pre >= mid)
		{
			pre=array[i];
			required++;
			if(required==c)
			break;
		}
	}
	if(required >= c)
	return true;
	else
	return false;
}
