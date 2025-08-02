#Problem: 121.Best Time to Buy and Sell Stock

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l, r = 0, 1 
        MaxP = 0

        while r < len(prices):
            if prices[l] < prices[r]:
                profit = prices[r] - prices[l]
                MaxP = max(MaxP, profit)
            else:
                l = r
            r += 1  
        return MaxP