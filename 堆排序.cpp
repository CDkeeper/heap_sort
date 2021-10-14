#include<iostream>
#include<bits/stdc++.h>  //����ͷ�ļ�����������ͷ�ļ� 
using namespace std;
const int n=10000; //Ĭ�������СΪ�̶���10000 
int r[n]; //�������������飬��ָ����С 
void SiftHeap(int r[],int k,int n){
	int i,j,temp;
	i=k;j=2*i+1;          //iΪҪɸѡ�Ľ�㣬jΪi������ 
	while(j<n){          //����δɸѡ��Ҷ�� 
		if(j<n-1&&r[j]<r[j+1])j++;     //�Ƚ�i�����Һ��ӣ��������ֵ����j 
		if(r[i]>r[j])    //�������ͬʱ�������Һ���ʱ 
		break;
		else{
			temp=r[i];r[i]=r[j];r[j]=temp;   //��ɸѡ����j���� 
			i=j;j=2*i+1;         //�˿�ɸѡ���λ��j�� 
		}
	} 
}
void HeapSort(int r[],int n){
	int i,temp; 
	for(i=(n-1)/2;i>=0;i--)    //������ʼ�ѣ��˿�ѡ��(n-1)/2Ϊ��ʼ�±� 
	SiftHeap(r,i,n);
	for(i=1;i<=n-1;i++){     //ִ�жѶ����߲����Ѳ��� 
		temp=r[0];r[0]=r[n-i];r[n-i]=temp;
		SiftHeap(r,0,n-i);    // ���˿̵ĸ������гɶѵ��� 
	}
}
int main(){
	srand(unsigned(time(0)));  //������������� 
	for(int i=0;i<n;i++){      //�����������������ķ�Χ������ 
		r[i]=rand();
	}
	HeapSort(r,n);     //���ж����� 
	for(int i=0;i<n;i++){
		cout<<r[i];      //���δ�ӡ��� 
		if((i+1)%10==0)   //��ʮ���� 
			cout<<endl;
		else cout<<" ";  //δ��ʮ���ӡ�ո� 
	}
	return 0;
}
