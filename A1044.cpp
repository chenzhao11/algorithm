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
/*iostream������NULL
stdio������  null*/
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
				/*������ھ�indexmin+1*/
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
		
			/*�����ҵ��ڽ�����*/
		   for(int j=0;j<=i;j++){
		    sumup=sumup-shuzhu[j];
		    /*�����ȥ��ͷ���ڳ�����ô���Ǿ�û�б�Ҫ
			һ��һ������������  ֱ��ʹ��loop=��ʹ��index+1*/
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
