#include<iostream>
#include<bits/stdc++.h>  //万能头文件，包含所有头文件 
using namespace std;
const int n=10000; //默认数组大小为固定的10000 
int r[n]; //定义待排序的数组，并指定大小 
void SiftHeap(int r[],int k,int n){
	int i,j,temp;
	i=k;j=2*i+1;          //i为要筛选的结点，j为i的左孩子 
	while(j<n){          //当还未筛选到叶子 
		if(j<n-1&&r[j]<r[j+1])j++;     //比较i的左右孩子，并将大的值赋予j 
		if(r[i]>r[j])    //当根结点同时大于左右孩子时 
		break;
		else{
			temp=r[i];r[i]=r[j];r[j]=temp;   //将筛选结点和j交换 
			i=j;j=2*i+1;         //此刻筛选结点位于j处 
		}
	} 
}
void HeapSort(int r[],int n){
	int i,temp; 
	for(i=(n-1)/2;i>=0;i--)    //构建初始堆，此刻选择(n-1)/2为起始下标 
	SiftHeap(r,i,n);
	for(i=1;i<=n-1;i++){     //执行堆顶移走并建堆操作 
		temp=r[0];r[0]=r[n-i];r[n-i]=temp;
		SiftHeap(r,0,n-i);    // 将此刻的根结点进行成堆调整 
	}
}
int main(){
	srand(unsigned(time(0)));  //设立随机数种子 
	for(int i=0;i<n;i++){      //生成随机数，随机数的范围不给定 
		r[i]=rand();
	}
	HeapSort(r,n);     //进行堆排序 
	for(int i=0;i<n;i++){
		cout<<r[i];      //依次打印结果 
		if((i+1)%10==0)   //逢十换行 
			cout<<endl;
		else cout<<" ";  //未逢十则打印空格 
	}
	return 0;
}
