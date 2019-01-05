#include <iostream>
#include <algorithm>
using namespace std;
int main (){
	int p,many;
	cin>>many>>p;
	int array[many];
	for(int i=0;i<many;i++){
		cin>>array[i];
	}
	sort(array,array+many);
	int left=0,right=many-1,mid,max=array[many-1];
	if(left==right)left=many;
	while(left<right){
	mid=(left+right)/2;
	long long lim=array[mid]*p;
	if(lim<max){
		left=mid+1;
	}	
	else{
		right=mid;
	}
	}
	cout<<many-left<<endl;
	return 0; 
} 
