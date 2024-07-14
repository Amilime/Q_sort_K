#include<iostream>

using namespace std;
int n, Q[10000001],k;
void Qsort(int L,int R){
    if(L>=R) return;//当L最后也和R一样（剩一个数值没得比了）结束
    int l=L,r=R;
    int mid=Q[(l+r)/2];
    while(l<r){//从中间开始，l还不等于r时执行转换操作
        while(Q[l]<mid) l++;
        while(Q[r]>mid) r--;//不满足条件游标就前进
        if(l<=r){//l小于r的时候都可以切换
            int num=Q[l];Q[l]=Q[r];Q[r]=num;
            l++;r--;
        }
    }//换完了一轮，跑到了右边的l和R，左边的L和r开始继续排序
    if(l<R) Qsort(l,R);
    if(r>L) Qsort(L,r);
}
int main(){
    cout<<"请分别输入数组长度和需要寻找的第k个数:"<<endl;
    cin>>n>>k;
    cout<<"请输入数组:"<<endl;
    for(int i=1;i<=n;i++){
        cin>>Q[i];
    }
    Qsort(1,n);
    cout<<Q[k];//快速排序好后直接找某一个
    return 0;
}