#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int num,money;
int index=0;
int indexmin;
int loop=0;
/*5 13 2 4 5 7 9*/
/*iostream里面是NULL
stdio里面是  null*/
string ans[10];
string ansmin[10];
int min2=9999;
void findequal(int *shuzhu,int value,int length){
	int sumup=0;
	for(int i=loop;i<length;i++){
		
		sumup=sumup+shuzhu[i];
		if(sumup==value){
			int trans=loop+1;
			ans[index]=trans+"-"+i; 
			index++;
			loop++;
		}
		if(sumup>value){
			int max=sumup-value;
				/*如果等于就indexmin+1*/
			if(max==min2){
				int trans2=loop+1;
                ansmin[indexmin]=trans2+"-";//
				ansmin[indexmin].append(i+"-");
				indexmin++;
			    loop++;
			}
			if(max<min2){
				min2=max;
				indexmin =0; 
				int trans2=loop+1;
				ansmin[indexmin]=trans2+"-";//
				ansmin[indexmin].append(i+"-");
				indexmin++;
			    loop++;
			}
		
			/*对于找等于接着找*/
		   for(int j=0;j<=i;j++){
		    sumup=sumup-shuzhu[j];
		    /*如果减去开头等于成立那么我们就没有必要
			一个一个的慢慢加了  直接使得loop=这使得index+1*/
	    	if(sumup==value){
	    		int trans=loop+1;
	    		ans[index]=trans+"-";//
				ans[index].append(i+"-");
//			    ans[index]=trans+"-"+i; 
		     	index++;
			    loop=trans;
			}
			 }
		}
	}
}
int main(){
	cin>>num>>money;
	int array[num];
	for(int i=0;i<num;i++){
		cin>>array[i];
	}
	findequal(array,money,num);
	for(int i=0;i<index;i++){
		cout<<ans[i]<<endl;
	}
		for(int i=0;i<indexmin;i++){
		cout<<ansmin[i]<<endl;
	}
	return 0;
} 
