//https://leetcode.com/problems/lru-cache/
#include <time.h>
#include <iostream>
#include <map>

using namespace std;


struct Node{
    int key;
    int value;
    Node* next, *prev;
    Node(int k, int v){ key = k; value = v; next = prev = NULL; }
};
class DoubleLinkedNode{
private:
    Node *pHead, *pTail;
    int size;
public:
    DoubleLinkedNode(){ pHead = pTail = NULL; size = 0; }
    ~DoubleLinkedNode(){
        while (pHead != NULL){
            Node* p = pHead;
            pHead = pHead->next;
            delete p;
        }
    }
    int Size(){ return size; }
    void MoveToBegin(Node* n)
    {
        UnLink(n);
        AddToBegin(n);
    }
    void AddToBegin(Node* n)
    {
        size++;
        if (pHead == NULL)
        {
            pHead = n;
            pTail = n;
            return;
        }
        n->prev = NULL;
        n->next = pHead;
        pHead->prev = n;
        pHead = n;
    }
    void UnLink(Node* n)
    {
        auto befor = n->prev;
        auto next = n->next;
        if (befor)
        {
            befor->next = next;
        }
        if (next)
        {
            next->prev = befor;
        }
        if (pHead == n)
        {
            pHead = pHead->next;
        }
        else if (pTail == n)
        {
            pTail = pTail->prev;
        }
        size--;
    }
    void Delete(Node* n)
    {
        UnLink(n);
        delete n;
    }
    void DeleteLast()
    {
        Delete(pTail);
    }
    Node* GetTailNode()
    {
        return pTail;
    }
};
class LRUCache{
private:
    DoubleLinkedNode cachelist;
    map<int, Node*> cachemap;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (cachemap.find(key) != cachemap.end())
        {
            cachelist.MoveToBegin(cachemap[key]);
            return cachemap[key]->value;
        }
        return -1;
    }

    void set(int key, int value) {
        if (cachemap.find(key) != cachemap.end())
        {
            cachemap[key]->value = value;
            cachelist.MoveToBegin(cachemap[key]);
        }
        else
        {
            Node* n = new Node(key, value);
            cachemap[key] = n;
            cachelist.AddToBegin(n);
            if (cachelist.Size() > cap)
            {
                cachemap.erase(cachelist.GetTailNode()->key);
                cachelist.DeleteLast();
            }
        }
    }
};
int main()
{
    srand(time(0));
    int cap = 10;
    LRUCache cache(cap);
    for (int i = 0; i < cap*2; i++)
    {
        cache.set(i, i);
        cout << "set " << i << ":" <<endl;
        int v = rand() % cap;

        cout << "get " << v << ":"<< cache.get(v)<<endl;
    }
    int v;
    cin >> v;
    return 0;
}