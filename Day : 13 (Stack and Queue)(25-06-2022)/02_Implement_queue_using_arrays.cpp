//https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908
class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;
public:
    
    Queue() {
        // Implement the Constructor
        size = 100001;
        arr = new int[size];
        rear = 0;
        qfront = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
       if(qfront == rear) return 1;
        else return 0;
    }

    void enqueue(int data) { //push operation
        if(rear == size) cout<<"Queue is full"<<endl;
        else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear) return -1;
        else {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            return ans;   
        }
    }

    int front() {
     if(qfront == rear)  return -1;
        else {
            return arr[qfront];
        }
    }
};
