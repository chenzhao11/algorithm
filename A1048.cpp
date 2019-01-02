#include<iostream>
#include<algorithm>
#include<cstring> 
#include<string>
using namespace std;
bool flag=false;
int sum;





/*

题目描述

Eva loves to collect coins from all over the universe, including some other planets like Mars.  One day she visited a universal shopping mall which could accept all kinds of coins as payments.  However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount.  Since she has as many as 105 coins with her, she definitely needs your help.  You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.


输入描述:

Each input file contains one test case.  For each case, the first line contains 2 positive numbers: N (<=105, the total number of coins) and M(<=103, the amount of money Eva has to pay).  The second line contains N face values of the coins, which are all positive numbers no more than 500.  All the numbers in a line are separated by a space.



输出描述:

For each test case, print in one line the two face values V1 and V2 (separated by a space) such that V1 + V2 = M and V1 <= V2.  If such a solution is not unique, output the one with the smallest V1.  If there is no solution, output "No Solution" instead.


输入例子:

8 15
1 2 8 7 2 4 11 15


输出例子:

4 11







*/
/*找中间的位置*/
/*总结错误：
1.对于bool flag的判断处理忘了判断回来
2.在循环里面使用flag的时候就算是满足条件但是里面没有跳出语句
还是继续跑   假如一开始bool值为true的话我们不满足条件就是false
再把判断条件改一下也许就没有这么麻烦
3.这道题的思路是对的但是我们在写的时候具体的实现过程里面有很多的3
错误，下一次写的时候写工整一点  不要光些mid   a【mid】 
4. 我们在使用二分发的时候尽量不要使用left/right=mid这样的方式最好是
直接+1 或者-1   比如8-9位的时候对于右边的来说可以取到第八位左边的就
不可以取到下一位了，应为直接取int  其实是变小了 

所以直接使用right=mid可以但是不可以直接使用left=mid!!!!!!
while()里面的条件值还是根据具体的情况要是需要找一个具体的值就
直接加上等于   取left以及right对应的就是我们要找的数的情况来试一试 
只是返回纸的时候注意一下！！ 




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
/*递归消除后面相同的数直接跳过  返回新的min*/
int newmin(int m,int* num,int*a ){
	if(a[m]!=a[m+1])return m;
	else return newmin(m+1,num,a);
}
/*二分查找相应的数找到传回1没找到传回-1*/
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





