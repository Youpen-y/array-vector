/*
*   This is a little program to find reverse pair and output it.
*/

#include<iostream>

using namespace std;
int reversenum = 0;     //the num of reversenum

/*
*  The solution function
*/
void findsolution(int array[], int N){
    int first, end;
    for(first = 0; first < N; first++){
        for(end = N-1; end > first; end--){
            if(array[first]>array[end]){
                reversenum++;
                cout<<"( "<<array[first]<<" , "<<array[end]<<" )"<<endl;
            }
        }
    }
}

int main(){
    int N;
    cout<<"Input the number: "<<endl;
    cin>>N;
    int list[N];
    cout<<"Input numbers: ";
    for(int i = 0; i<N; i++){
        cin>>list[i];
    }
    findsolution(list,N);
    cout<<"num of reverse sequence pair: "<<reversenum;
    return 0;
}