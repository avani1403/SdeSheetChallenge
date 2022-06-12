#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
  int num1 = -1;
  int num2 = -2;
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i<arr.size(); i++)
    {
        if(arr[i] == num1) count1++;
        else if(arr[i] == num2) count2++;
        else if(count1 == 0){
            num1 = arr[i];
            count1 = 1;
        }
        else if(count2 == 0)
        {
            num2 = arr[i];
            count2 = 1;
        }
        else{
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for(int i = 0; i<arr.size(); i++)
    {
        if(arr[i] == num1) count1++;
        if(arr[i] == num2) count2++;
    }
    vector<int> ans;
    if(count1 > n/3) ans.push_back(num1);
    if(count2 > n/3) ans.push_back(num2);
    return ans;

}
