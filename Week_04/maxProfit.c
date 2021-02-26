
// 122. 买卖股票的最佳时机 II


int maxProfit(int* prices, int pricesSize) {
    int ans = 0;
    for (int i=1; i<pricesSize; ++i)
        ans += prices[i]-prices[i-1]>0?prices[i]-prices[i-1]:0;
    return ans;
}