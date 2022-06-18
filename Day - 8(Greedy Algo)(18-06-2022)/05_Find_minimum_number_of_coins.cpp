int findMinimumCoins(int amount) 
{
    // Write your code here
    
    vector<int> valued_coins = {1,2,5,10,20,50,100,500,1000};
    int count = 0;
    int n = valued_coins.size();
    
    for(int i = n-1; i>=0; i--)
    {
        if(amount == valued_coins[i])
        {
            count++;
            break;
        }
        else if(amount < valued_coins[i]) continue;
        else if(amount > valued_coins[i]) {
            int times = amount/valued_coins[i];
            amount -= (times*valued_coins[i]);
            count += times;
        }else break;
    }
    
    return count;
    
}
