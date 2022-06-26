
//https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
bool isValidParenthesis(string expression)
{
    stack<char> s;
	for(int i = 0; i< expression.length(); i++){
		char ch = expression[i];
		
		//if opening bracket stack push
		//if closing bracket stack top check and pop
		
	    if(ch == '(' || ch =='[' || ch == '{'){
			s.push(ch);
		}else{
			if(!s.empty()){
				char top = s.top();
				if( (ch == '}' && top == '{') || 
				   (ch == ']' && top == '[') || 
				   (ch ==')' && top == '(') ){
				//	cout<<"avani"<<endl;
					s.pop();
				}else return false;
			}else return false;
		}
	
		
	}
		if(s.empty()) return true;
			 return false;
}


