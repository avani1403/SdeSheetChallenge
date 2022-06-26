// // Stack class.
// class Stack {
    
// public:
//     vector<int> arr;
//     int len;
//     Stack(int capacity) {
        
//         len = capacity;
//         arr.clear();
//     }

//     void push(int num) {
//       if(arr.size() < len) arr.push_back(num);
//     }

//     int pop() {
//         int top = -1;
//         if(!arr.empty())
//         {
//             top = arr[arr.size()-1];
//             arr.pop_back();
            
//         }
//         return top;
//     }
    
//     int top() {
//         int top = -1;
//         if(!arr.empty())
//         {
//             top = arr[arr.size() - 1];
//         }
//         return top;
//     }
    
//     int isEmpty() {
     
//         if(arr.empty()) return 1;
//         return 0;
//     }
    
//     int isFull() {
      
//         if(arr.size() == len) return 1;
//         else return 0;
//     }
    
// };



//*************************************************************




// Stack class.
class Stack {
    
public:
    vector<int> arr;
    int len;
    int tp;
    Stack(int capacity) {
       arr.resize(capacity);
        len = capacity;
        tp = -1;
      //  arr.clear();
    }

    void push(int num) {
   
        if(tp >= len-1 ) return; //use functions isFull()
        else
        {        
                tp++;
                arr[tp] = num;       
        }
    }

    int pop() {
   
        if(tp == -1) return -1; //use function isEmpty()
        else 
        {
            int ele = arr[tp];
            tp--;
        //    arr.pop_back();
            return ele;
        }
    }
    
    int top() {
 
        if(tp == -1) return -1;
        else return arr[tp];
    }
    
    int isEmpty() {
     
        if(tp == -1 ) return 1;
        return 0;
    }
    
    int isFull() {
      
        if(tp == len-1) return 1;
        else return 0;
    }
    
};




