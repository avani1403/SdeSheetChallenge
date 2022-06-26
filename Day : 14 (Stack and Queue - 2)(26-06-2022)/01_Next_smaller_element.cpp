//https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
	//first stack top element is -1
	s.push(-1);
	vector<int> ans(n);
	
	for(int i = n-1; i>=0; i--){
		int curr = arr[i];
		while(curr <= s.top()){
			s.pop();
		}
		//ans is top of the stack
		ans[i] = s.top();
		s.push(curr);
	}
	return ans;
}
