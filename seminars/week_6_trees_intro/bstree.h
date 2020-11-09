#include<iostream>
#include<cmath>

class BSTree{
    public:
    BSTree();
    bool empty() const;
    bool member(const int&) const;
    void add_iter(const int&);
    void add_rec(const int&);
    void print() const;
    int height() const;

    private:
    struct BTreeNode{
        int data;
        BTreeNode* left;
        BTreeNode* right;
        BTreeNode(const int& _data, BTreeNode* _left = nullptr, BTreeNode* _right = nullptr): data{_data}, left{_left}, right{_right} {}
    };
    BTreeNode* root;
    bool member_helper(const int&, const BTreeNode*) const;
    void add_helper(const int&, BTreeNode*&);
    void print_helper(const BTreeNode*) const;
    int height_helper(const BTreeNode*) const;
};