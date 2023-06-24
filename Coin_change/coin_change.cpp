#include <iostream>
#include <vector>
#include <climits>

int minCoins(std::vector<int>& coins, int target){
  int max = target + 1;
  std::vector<int> dp(max, max);

  dp[0] = 0;

  for(int i = 1; i <= target; i++){
    for(int j = 0; j < coins.size(); j++){
      if(coins[j] <= i && dp[i - coins[j]] != max){
        dp[i] = std::min(dp[i], 1 + dp[i - coins[j]]);
      }
    }
  }
  return dp[target] == max ? -1 : dp[target];
}

int main() {
  std::vector<int> coins = {1};

  int coins_qtd, target, new_coin;
  std::cin >> coins_qtd >> target >> new_coin;

  for(int i = 0; i < coins_qtd; i++){
    int coin;
    std::cin >> coin;
    coins.push_back(coin);
  }

  int minCoinsNeeded = minCoins(coins, target);

  coins.push_back(new_coin);
  int secondMinCoinsNeeded = minCoins(coins, target);

  int new_balance = minCoinsNeeded - secondMinCoinsNeeded;
  if(new_balance == 0){
    std::cout << "indiferente" << std::endl;
  } else {
    std::cout << new_balance << std::endl;
  }

  return 0;
}