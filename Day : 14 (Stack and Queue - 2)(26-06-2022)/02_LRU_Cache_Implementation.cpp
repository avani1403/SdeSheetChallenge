#include<bits/stdc++.h>

class LRUCache {
public:
    //creating doubly linkedlist
    class node{
      public:
        int key;
        int val;
        node* next;
        node* prev;
        
        //constructor
        node(int key, int val)
        {
            this -> key = key;
            this -> val = val;
        }
            
    };
    
       
        node* head = new node(-1, -1);
        node* tail = new node(-1, -1);
        
    int size;
    unordered_map<int, node*> mp;
    
    LRUCache(int capacity) {
        this -> size = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
       //check if key exists
        if(mp.find(key) != mp.end())
        {
            //take node address
            node* addr = mp[key];
            int value = addr -> val;
            //remove key
            mp.erase(key);
            
            //then delete node in LL
            deletenode(addr);
            //add node right after head
            addnode(addr);
            mp[key] = head -> next;
            return value;
        }
        //else returning -1
        return -1;
    }
    
    void put(int key, int value) {
        //if exists get the address of the node
        if(mp.find(key) != mp.end())
        {
            node* existingnode = mp[key];
            mp.erase(key);
            deletenode(existingnode);
        }
        if(mp.size() == size )
        {
            mp.erase(tail -> prev -> key);
            deletenode(tail -> prev);
        }
        
        addnode(new node(key, value));
        mp[key] = head -> next;
    }
    
    
    void addnode(node* newnode)
    {
        node* temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }
    
    void deletenode(node* delnode)
    {
        node* delprev = delnode -> prev;
        node* delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
