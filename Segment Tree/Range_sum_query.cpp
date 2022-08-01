#include<bits/stdc++.h>
using namespace std;
using namespace std;
vector<int> getArray(string s){
    vector<int>arr;
    int size = s.size();
    int i=0, j=size-1;
    if(s[i] == ',') i++;
    while (s[i]==' ' || s[i] == '[') i++;
    while (s[j] == ' ' || s[j] == ']') j--;
    s = s.substr(i,j-i+1);
    stringstream ss(s);
    string tmp;
    while(getline(ss,tmp,',')) arr.push_back(stoi(tmp));
    return arr;
}
// method-1 
// class NumArray {
// public:
// //    space O(4*N)
//     vector<int>segment_tree;
//     int total_size;
//     // time complexity O(N)
//     void build_sg(int parent, vector<int>&nums, int left, int right){
//         if(left == right){
//             segment_tree[parent] = nums[left];
//             return ;
//         }
//         int mid = (left + right)/2;
//         build_sg(2*parent+1, nums, left, mid);
//         build_sg(2*parent+2, nums, mid+1, right);
//         segment_tree[parent] = segment_tree[2*parent+1] + segment_tree[2*parent+2];
//     }
//     // time complexity O(no_of_query * log(N))
//     int get_range_sum(int parent, int start, int end, int left, int right){
//         if(end < left  || start > right) return 0;
//         if(start >= left && end <= right) return segment_tree[parent];
        
//         int mid = (start + end)/2;
//         return get_range_sum(2*parent+1, start, mid, left, right) 
//              + get_range_sum(2*parent+2, mid+1, end, left, right);
//     }
//     // time complexity O(no_of_update * log(N))
//     void get_update(int curr, int start, int end, int index, int val){
//         if(index < start || index > end ) return ;
//         if(start == end){
//             if(start == index)
//             segment_tree[curr] = val;
//             return;
//         }
//         int mid = (start + end)/2;
//         get_update(2*curr+1, start, mid, index, val);
//         get_update(2*curr+2, mid+1, end, index, val);
//         segment_tree[curr] = segment_tree[2*curr+1] + segment_tree[2*curr+2];
//     }
    
//     NumArray(vector<int>& nums) {
//         total_size= nums.size();
//         segment_tree = vector<int>(4*total_size);
//         build_sg(0,nums, 0, total_size-1);
//     }
    
//     void update(int index, int val) {
//         get_update(0, 0, total_size-1, index,val);
//     }
    
//     int sumRange(int left, int right) {
//         return get_range_sum(0, 0, total_size-1, left, right);
//     }
// };



// method-2: Efficient Segment tree with space O(2*N)
// time complexity for query sum O(no_of_query * log(N))
// time complexity O(no_of_update * log(N))

class NumArray {
public:
    vector<int>sg;
    int size;
    NumArray(vector<int>& nums) {
        size = nums.size();
        sg = vector<int>(2*size);
        for(int i = 0; i < size; i++) sg[i+size] = nums[i];
        for(int i = size-1; i > 0; i--) sg[i] = sg[i<<1] + sg[i<<1|1];
    }
    
    void update(int index, int val) {
        index += size;
        sg[index] = val;
        while(index > 0){
            index >>= 1;
            sg[index] = sg[2*index] + sg[2*index+1];
        }
    }
    
    int sumRange(int left, int right) {
        left += size;
        right += size;
        int sum{};
        while(left <= right){
            if(left&1) sum += sg[left++];
            if((right&1 )== 0) sum += sg[right--];
            left >>= 1;
            right >>= 1;
        }
        return sum;
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main(){
    // leetcode input type
    string s, s2;
    cin>>s>>s2;
    stringstream instruction(s.substr(1,s.size()-2)), data_array(s2.substr(0,s2.size()-1));
    string inst, data;
    getline(instruction,inst,',');
    getline(data_array, data,']');
    vector<int>arr = getArray(data); 
    getline(data_array, data,']');
    NumArray obj(arr);

    while(getline(instruction, inst, ',')){
        getline(data_array, data, ']');
        vector<int>tmp = getArray(data);
        if(inst == "\"update\"") obj.update(tmp[0], tmp[1]);
        else if(inst == "\"sumRange\"") cout<<obj.sumRange(tmp[0], tmp[1])<<",";
    }
    cout<<endl;
    return 0;
}