class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, long long budget) {
        int n = items.size();
        
        long long cheapest = LLONG_MAX;
        int max_factor = 0;
        
        for (const auto& item : items) {
            cheapest = min(cheapest, (long long)item[1]);
            max_factor = max(max_factor, item[0]);
        }
        
        vector<int> freq(max_factor + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }
        
        for (int i = 1; i <= max_factor; ++i) {
            if (freq[i] > 0) {
                for (int multiple = 2 * i; multiple <= max_factor; multiple += i) {
                    freq[i] += freq[multiple];
                }
            }
        }
        
        map<long long, long long> cost_count;
        for (const auto& item : items) {
            long long factor = item[0];
            long long cost = item[1];
            long long count = freq[factor] - 1; 
            
            if (count > 0 && cost <= 2 * cheapest) {
                cost_count[cost] += count;
            }
        }
        
        long long total_items = 0;
        
        for (auto& entry : cost_count) {
            long long cost = entry.first;
            long long count = entry.second;
            
            long long include = min(count, budget / cost);
            total_items += 2 * include; 
            budget -= include * cost;
        }
        
        total_items += budget / cheapest;
        
        return total_items;
    }
};
