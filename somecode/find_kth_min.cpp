/*
*   In a sequence, find the kth smallest number using divide and conquer.
*/
#include<bits/stdc++.h>
using namespace std;

/*
*   Function to find the minimum with divide and a conquer.
*/
int Findmin(int a[], int index, int N){
    int min;
    if (index >= N - 2){
        if( a[index] < a[index + 1])
        {
            return a[index];
        }
        else
        {
             return a[index+1];   
        } 
    }
    min = Findmin(a, index+1, N);

    if(a[index] < min)
    {
        return a[index]; 
    }  
    else
    {
        return min;
    }
}
/*
*   Find the index of the smallest value.
*/
int Findindex(int a[], int min, int N){
    for(int i = 0; i < N; i++){
        if(a[i] == min)
            return i;
    }
}
/*
*   Find the kth smallest value.
*/
int Find_kth_min(int a[], int N, int k){
    for(int i; k > 1; k--){
        i = Findindex(a,Findmin(a,0,N),N);
        a[i] = INT_MAX;
    }
    int kth_min = Findmin(a,0,N);
    return kth_min;
}


int main(){
    int N,k;
    cout<<"The length of sequence: "<<endl;
    cin>>N;
    int list[N];
    cout<<"Input the number one by one: "<<endl;
    for(int i = 0; i<N; i++){
        cin>>list[i];
    }
    cout<<"Input the k value: ";
    cin>>k;
    int kth_min = Find_kth_min(list,N,k);
    cout<<"The "<<k<<"th smallest value is: "<<kth_min<<endl;
    cout<<"Location: "<<Findindex(list,kth_min,N)+1<<endl;
    return 0;
}