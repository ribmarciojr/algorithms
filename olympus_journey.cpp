#include <iostream>
#include <vector>

int maxItems(std::vector<int>& items, int bag_weight){
  int dp[51][101];
  
  for(int i = 0; i <= items.size(); i++){
    for(int j = 0; j <= bag_weight; j++){
      if(i == 0 || j == 0){
        dp[i][j] = 0;
      } else if (items[i - 1] <= j){
        dp[i][j] = std::max(dp[i - 1][j], 1 + dp[i - 1][j - items[i - 1]]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
   }
  }

  return dp[items.size()][bag_weight];
};

int main(){
  int golden_item, bag_weight, items_qtd;

  std::cin >> golden_item >> bag_weight >> items_qtd;

  std::vector<int> items;
  
  for(int i = 0; i < items_qtd; i++){
    int item;
    std::cin >> item;
    items.push_back(item);
  }

  int util_weight = bag_weight - golden_item;
  util_weight = util_weight > 0 ? util_weight : 0;

  int max_items = maxItems(items, util_weight);

  std::cout << max_items << std::endl;
}