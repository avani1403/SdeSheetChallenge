#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int minpri = INT_MAX;
    int maxpro = INT_MIN;;
    for(int i = 0; i<prices.size(); i++)
    {
        minpri = min(minpri, prices[i]);
        maxpro = max(maxpro, prices[i] - minpri);
    }
    return maxpro;
}
