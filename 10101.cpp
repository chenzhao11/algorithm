#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include<cstring>
using namespace std;
typedef long long ll;
long long Map[256]; 
void init(){
 for(char i='0';i<='9';i++){
 	Map[i]=i-'0';
 }
 for(char i='a';i<='z';i++){
	Map[i]=i-'a'+10;
 }
}






/*
map<int ,string> maplive;  
   1.maplive.insert(pair<int,string>(102,"aclive"));
   2.maplive.insert(map<int,string>::value_type(321,"hai"));
   3, maplive[112]="April";//map�������õĲ�����ӣ�


*/












/*��ʮ����ת��*/
long long zhuhua (string str,ll jz){
	long long ans=0;
	const char * stri=str.c_str();
	int length=strlen(stri);
	
	/*for(int i=length,q=0;i>0;i--,q++){
		ans=ans+(Map[stri[i]]*pow(jz,q));
	}
*/
	
	for(int i=0;i<length;i++){
		
//	    if(stri[i]!='\0')
//		ans=ans+Map[stri[i]]*pow(jz,i);

		ans=ans*jz+Map[stri[i]];

	}
	return ans;
}
/*���ַ����в��ҽ���*/
/*num��ʮ���Ƶ�
int type ���δ֪�����ڵĻ����ұ��� type Ϊ2   �ж�left
��֮... 
*/
long long serch(ll left,ll right,ll num,int type){
	
	if(type==1){
	   ll ori=right;
	} 
	else {
       ll ori=left;
	}
	ll ori=right;
	
	while(left<right){
		ll mid=left+(left+right)/2;
		if(mid>=num)right=mid;
		else left++;
	}
	if(ori==1&&ori==right)return -1;
	if(ori==2&&ori==left)return -1;
	return left;
} 
/*n1num ����֪���Ƶ�
n2num��Ҫ���*/
int main (){
	init();
	string  n1,n2;
	int who;
	ll type1;
	ll n1num,n2num;
	ll answer;
	cin>>n1>>n2>>who>>type1;
	if(who==1){
		n1num=zhuhua(n1,type1);
		
		n2num=zhuhua(n2,type1);
		
	
	}
	
	if(who==2){
		n1num=zhuhua(n2,type1);
		n2num=zhuhua(n1,type1);
	}
	if(n1num==n2num){
		cout<<type1;
	} 
	if(n1num>n2num){
		answer=serch(type1+1,pow(2,31)-1,n1num,2);
		if(answer==-1){
		cout<<"imposible";
			return 0;
		
		}cout<<answer; 
	} 
	if(n1num<n2num){
		answer=serch(2,type1-1,n1num,1);
		if(answer==-1){
			cout<<"Impossible";
			return 0;
		}
		cout<<answer;
		
	} 
	
	
	
	return 0;
}










