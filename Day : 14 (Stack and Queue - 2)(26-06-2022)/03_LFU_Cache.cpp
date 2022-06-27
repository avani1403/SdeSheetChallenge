#include<bits/stdc++.h>
struct Node {
    
    int key;
    int val;
    int freq;
    Node* next;
    Node* prev;
    
    //constructor
    Node(int key, int val)
    {
        this -> key = key;
        this -> val = val;
        freq = 1;
    }
    
};

struct List {
    int size;
    Node* head;
    Node* tail;
    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head -> next = tail;
        tail -> prev = head;
        size = 0;
    }
    
    void addfront(Node* node) {
        Node* temp = head -> next;
        node -> next = temp;
        node -> prev = head;
        head -> next = node;
        temp -> prev = node;
        size++;
    }
    
    void removeNode(Node* delnode) {
        Node* delprev = delnode -> prev;
        Node* delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
        size--;
    }
};

class LFUCache {
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;
    
    
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
            Node* addr = keyNode[key];
            int value = addr -> val;
            //now freq will change so it will move to the other doubly linked list

            updateFreqListMap(addr);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0) return ;
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node -> val = value;
            updateFreqListMap(node);
        }
        else {
            if(curSize == maxSizeCache) {
                List* list = freqListMap[minFreq];
                keyNode.erase(list -> tail -> prev -> key);
                freqListMap[minFreq] -> removeNode(list -> tail -> prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            }
            Node* node = new Node(key, value);
            listFreq -> addfront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
    
    void updateFreqListMap(Node* node) {
        keyNode.erase(node -> key);
        freqListMap[node -> freq] -> removeNode(node);
        if(node->freq == minFreq and freqListMap[node -> freq] -> size == 0 ) {
            minFreq++;
        }
        
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node -> freq + 1) != freqListMap.end()) 
        {
            nextHigherFreqList = freqListMap[node->freq + 1];
        } 
        
        node->freq += 1; 
        nextHigherFreqList -> addfront(node); 
        freqListMap[node->freq] = nextHigherFreqList; 
        keyNode[node->key] = node;
    }
};

