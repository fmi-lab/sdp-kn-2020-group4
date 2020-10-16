#include<iostream>

class SkipList{
    private:
    struct SkipNode {
        int data;
        SkipNode* next;
        SkipNode* skip;
        SkipNode(const int& _data, SkipNode* _next, SkipNode* _skip): data(_data), next(_next), skip(_skip) {}
    };
    SkipList::SkipNode* start;

    public:
    void push(const int& element) {
        SkipNode* prev = locate(element);
        // add elemnt after prev
        optimize();    
    }
    typename SkipList::SkipNode* locate(const int& element) {

    }
};