#include <iostream>
#include <vector>

int maxCandies(std::vector<int>& store_candies, int distance_between){
    std::vector<int> dp(store_candies.size());
    
    dp[0] = store_candies[0];
    for(int i = 1; i < store_candies.size(); i++){
        if(i - distance_between >= 0){
            dp[i] = std::max(dp[i - 1], store_candies[i] + dp[i - distance_between]);
        } else {
            dp[i] = std::max(dp[i - 1], store_candies[i]);
        }
    }

    return dp[store_candies.size() - 1];
}

int main(){
    int stores_qtd, distance_between;
    std::cin >> stores_qtd >> distance_between;
    distance_between++;

    std::vector<int> store_candies(stores_qtd);

    for(int i = 0; i < stores_qtd; i++){
        std::cin >> store_candies[i]; 
    }

    std::cout << maxCandies(store_candies, distance_between) << std::endl;
}