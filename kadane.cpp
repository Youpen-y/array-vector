#include<iostream>
using namespace std;

int kadane(int arr[], int n){
    int global, current;
    global = current = arr[0];

    for(int i=1;i<n;i++){
        current=max(arr[i],current+arr[i]);
        if(current>global)
            global = current;
    }
    return global;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(auto i:arr)
            cin>>arr[i];
        cout<<kadane(arr,n)<<endl;
    }
    return 0;
}