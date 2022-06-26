//https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1

void sortedInsert(stack<int> &s, int num){
	if(s.empty() || s.top()<num){
		s.push(num);
		return;
	}
	
	int n = s.top();
	s.pop();
	
	//recursive call
	sortedInsert(s,num);
	
	s.push(n);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	//base case
	if(stack.empty()) return;
	
	int num = stack.top();
	stack.pop();
	
	//recursive call
	sortStack(stack);
	
	sortedInsert(stack, num);
	
}
