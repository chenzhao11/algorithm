#include<iostream>
#include<algorithm>
#include<cstring> 
#include<string>
using namespace std;
bool flag=false;
int sum;





/*

��Ŀ����

Eva loves to collect coins from all over the universe, including some other planets like Mars.  One day she visited a universal shopping mall which could accept all kinds of coins as payments.  However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount.  Since she has as many as 105 coins with her, she definitely needs your help.  You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.


��������:

Each input file contains one test case.  For each case, the first line contains 2 positive numbers: N (<=105, the total number of coins) and M(<=103, the amount of money Eva has to pay).  The second line contains N face values of the coins, which are all positive numbers no more than 500.  All the numbers in a line are separated by a space.



�������:

For each test case, print in one line the two face values V1 and V2 (separated by a space) such that V1 + V2 = M and V1 <= V2.  If such a solution is not unique, output the one with the smallest V1.  If there is no solution, output "No Solution" instead.


��������:

8 15
1 2 8 7 2 4 11 15


�������:

4 11







*/
/*���м��λ��*/
/*�ܽ����
1.����bool flag���жϴ��������жϻ���
2.��ѭ������ʹ��flag��ʱ�����������������������û���������
���Ǽ�����   ����һ��ʼboolֵΪtrue�Ļ����ǲ�������������false
�ٰ��ж�������һ��Ҳ���û����ô�鷳
3.������˼·�ǶԵĵ���������д��ʱ������ʵ�ֹ��������кܶ��3
������һ��д��ʱ��д����һ��  ��Ҫ��Щmid   a��mid�� 
4. ������ʹ�ö��ַ���ʱ������Ҫʹ��left/right=mid�����ķ�ʽ�����
ֱ��+1 ����-1   ����8-9λ��ʱ������ұߵ���˵����ȡ���ڰ�λ��ߵľ�
������ȡ����һλ�ˣ�ӦΪֱ��ȡint  ��ʵ�Ǳ�С�� 

����ֱ��ʹ��right=mid���Ե��ǲ�����ֱ��ʹ��left=mid!!!!!!
while()���������ֵ���Ǹ��ݾ�������Ҫ����Ҫ��һ�������ֵ��
ֱ�Ӽ��ϵ���   ȡleft�Լ�right��Ӧ�ľ�������Ҫ�ҵ������������һ�� 
ֻ�Ƿ���ֽ��ʱ��ע��һ�£��� 




*/
int findpos(int left,int right,int *a){
	
	while(left<=right){
		int mid=(left+right)/2;
		if (a[mid]>(sum/2)){
			right=mid-1;
		}
		else{
			left=mid+1;
		}
	}
	

	return left;
	

	
}
/*�ݹ�����������ͬ����ֱ������  �����µ�min*/
int newmin(int m,int* num,int*a ){
	if(a[m]!=a[m+1])return m;
	else return newmin(m+1,num,a);
}
/*���ֲ�����Ӧ�����ҵ�����1û�ҵ�����-1*/
int search(int left,int right,int*a,int &min1,int sum1){
//     cout<<"sun1ser"<<sum1<<endl;
	while(left<right){
		int mid=(left+right)/2;
		if(a[mid]>sum1){
			right=mid-1;
		}
		if(a[mid]<sum1){
			left=mid+1;
		}
		if(a[mid]==sum1){
			min1=mid;
			flag=false;
			return 1;
		}
	}
	flag=true;
	return -1;	
	
}
int main(){
	
    int min=0;
	int sumnum; 
	cin>>sumnum>>sum;
	 int shuzhu[sumnum];
	for(int i=0;i<sumnum;i++){
		cin>>shuzhu[i];

	} 
    sort(shuzhu,shuzhu+sumnum);

    int middle=findpos(min,sumnum,shuzhu);
    for(int i=0;i<=middle;i++){

    	int sum2=sum-shuzhu[i];

    	int find=search(middle,sumnum-1,shuzhu,min,sum2);
  	    if(flag&& i==middle){
    	if(shuzhu[middle]+shuzhu[middle+1]==sum){
    		cout<<shuzhu[middle]<<" "<< shuzhu[middle];
    		return 0;
		}
		else{
			cout<<"No"; 
			return 0;
		}
		
	}if(!flag)break;
	}

	
	cout<<sum-shuzhu[min]<<" "<<shuzhu[min];
	return 0;
}





