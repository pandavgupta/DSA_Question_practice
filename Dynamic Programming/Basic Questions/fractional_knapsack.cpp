#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<iomanip>

using namespace std;

bool sortbysecdesc(const pair<float,int> &a,
                   const pair<float,int> &b)
{
       return a.first>b.first;
}

float fractional_knapsack(int size, vector<float>&weight,vector<float>&val,int cap){
    vector<pair<float,int>>price(size);
    float max_profit{},max_weight{};
    for(int i=0; i<size; i++){
    price[i].first=float(val[i])/weight[i];
    price[i].second=i;
    
    }
    

     sort(price.begin(),price.end(),sortbysecdesc);

    for(int i=0; i<size && max_weight<=cap;i++ ){

        if(weight[int(price[i].second)]+max_weight<=cap){
            max_weight+=weight[int(price[i].second)];
            max_profit+=val[int(price[i].second)];
        }
        else{
            float rem=cap-max_weight;

           return max_profit+=rem*price[i].first;
           

        }

    }


    return 0;
}


int main(){
    int size,cap;
    cin>>size;
    vector<float>weight(size),val(size);

    for(int i=0; i<size; i++)
     cin>>val[i];
    for(int i=0; i<size; i++)
     cin>>weight[i];
     
     cin>>cap;

    cout<<fixed<<setprecision(2)<<fractional_knapsack( size, weight,val, cap);
    return 0;

}