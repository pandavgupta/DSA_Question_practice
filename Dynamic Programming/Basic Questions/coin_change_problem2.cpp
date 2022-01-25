#include <iostream>
#include <vector>

int allCoins(std::vector<int> &coins, int lastIndex, std::vector<std::vector<int>>& dp, int amount) {
    if (dp[lastIndex][amount] != -1) 
        return (dp[lastIndex][amount]);
    if (amount == 0)
        return dp[lastIndex][amount]=1;
    else if (amount < 0 || lastIndex < 0)
        return dp[lastIndex][amount]= 0;
    return dp[lastIndex][amount] = allCoins(coins, lastIndex, dp, amount - coins[lastIndex]) + allCoins(coins, lastIndex - 1, dp, amount);    
}

int dpAllCoins(std::vector<int>&coins, int amount){
    std::vector<std::vector<int>>dp(coins.size()+1,std::vector<int>(amount+1,-1));
    return allCoins(coins, coins.size()-1,dp,amount);
}
int main() {
    int n{}; std::cin >> n;
    std::vector<int> coins(n);
    for (int i = 0; i < n; ++i) { std::cin >> coins[i]; }
    int amount{}; std::cin >> amount;

    //std::cout << allCoins(coins, n - 1, amount) << "\n";
    std::cout << dpAllCoins(coins, amount) << std::endl;

    return 0;
}