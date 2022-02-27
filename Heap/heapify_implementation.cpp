#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void maxHeapify(vector<int>&arr, int root_index){
    int leftchild = 2*root_index+1;
    int rightchild = 2* root_index+2;
    int largest{root_index};
    if(leftchild<arr.size() && arr[largest]<arr[leftchild]){
        largest=leftchild;
    }
    if(rightchild<arr.size() && arr[largest]<arr[rightchild]){
        largest=rightchild;
    }
    if(largest!=root_index) {
    swap(arr[largest],arr[root_index]);
    maxHeapify(arr,largest);
    }
        
    return;
}

int main()
{
    vector<int>arr={3,2,6,1,9,10,23,0,4};
    int i=(arr.size()/2) -1;
    for(i; i>=0; i--){
        maxHeapify(arr,i);
    }
    arr[0]=5;
    maxHeapify(arr,0);
    for(auto it:arr){
        cout<<it<<" ";
    }

    return 0;
}
