//Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element. 

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int countTriplet(int arr[], int n){
            std::sort(arr,arr+n);
            int count = 0;
            int i,j,k,l;
            for(i=n-1; i>=2; i--){
                j=0;k=i-1;
                while(j<k){
                    l = arr[j]+arr[k];
                    if(l>arr[i])
                        k--;
                    else if(l<arr[i])
                        j++;
                    else{
                        count++;
                        k--;
                        j++;
                    }
                }
            }
            return count;
        }
};

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.countTriplet(arr,n)<<endl;
    }
    return 0;
}