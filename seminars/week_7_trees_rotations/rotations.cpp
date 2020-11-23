#include<iostream>
#include<fstream>
#include<vector>
#include<string>

class BSTree{
    public:
    BSTree();
    bool empty() const;
    bool member(const int&) const;
    void add_iter(const int&);
    void add_rec(const int&);
    void print() const;
    int height() const;
    void visualize(std::ostream&) const;

    private:
    struct BTreeNode{
        int data;
        int height;
        BTreeNode* left;
        BTreeNode* right;
        BTreeNode(const int& _data, BTreeNode* _left = nullptr, BTreeNode* _right = nullptr, int _height = 0): 
            data{_data}, left{_left}, right{_right}, height{_height} {}
    };

    BTreeNode* root;
    bool member_helper(const int&, const BTreeNode*) const;
    void add_helper(const int&, BTreeNode*&);
    void print_helper(const BTreeNode*) const;
    int height_helper(const BTreeNode*) const;
    int balance(BTreeNode*&) const;
    void leftRotate(BTreeNode*&);
    void rightRotate(BTreeNode*&);
    void visualizeHelp (std::ostream& out, BTreeNode *curr) const;
};

BSTree::BSTree():root{nullptr} {}

bool BSTree::empty() const {
    return !root;
}

bool BSTree::member(const int& element) const {
    return member_helper(element, root);
}

bool BSTree::member_helper(const int& element, const BTreeNode* rootNode) const {
    if (!rootNode) {
        return false;
    }
    if (element == rootNode->data) {
        return true;
    }
    if(element < rootNode->data) {
        return member_helper(element, rootNode->left);
    } else {
        return member_helper(element, rootNode->right);
    }
}

void BSTree::add_iter(const int& element) {
    if(empty()) {
        root = new BSTree::BTreeNode{element};
    } else {
        BSTree::BTreeNode* current = root;
        while(current) {
            if(element < current->data && current->left) {
                current = current->left;
            } else if (element < current->data && !current->left){
                current->left = new BSTree::BTreeNode{element};
            } else if(element > current->data && current->right) {
                current = current->right;
            } else {
                current->right = new BSTree::BTreeNode{element};
            }
        }
    }
}

void BSTree::add_rec(const int& element) {
    add_helper(element, root);
}

void BSTree::add_helper(const int& element, BTreeNode*& rootNode) {
    if(!rootNode) {
         rootNode = new BSTree::BTreeNode{element};
    } else {
        if(element < rootNode->data) {
            add_helper(element, rootNode->left);
        } else {
            add_helper(element, rootNode->right);
        }
    }
    rootNode->height = std::max(height_helper(rootNode->left), height_helper(rootNode->right)) + 1;

    int rootBalance = balance(rootNode); // hL - hR
    if (rootBalance < -1 && element > rootNode->right->data) {
        //right right
        leftRotate(rootNode);
    }
    if (rootBalance < -1 && element < rootNode->right->data) {
        //right left
        rightRotate(rootNode->right);
        leftRotate(rootNode);
    }
    if (rootBalance > 1 && element < rootNode->left->data) {
        //left left
        rightRotate(rootNode);
    }
    if (rootBalance > 1 && element > rootNode->left->data) {
        //left right
        leftRotate(rootNode->left);
        rightRotate(rootNode);
    }
}

void BSTree::print_helper(const BTreeNode* rootNode) const {
    if(!rootNode) {
        return;
    }
    print_helper(rootNode->left);
    std::cout << rootNode->data << " ";
    print_helper(rootNode->right);
}

int BSTree::height() const {
    return height_helper(root);
}

int BSTree::height_helper(const BTreeNode* rootNode) const {
    // height ::= max(height(leftSubTree), height(rightSubTree)) + 1
    if(!rootNode) {
        return -1;
    }
    return std::max(height_helper(rootNode->left), height_helper(rootNode->right)) + 1;
}

void BSTree::print() const {
    // We are going to iterate the tree following the Left-Root-Right strategy
    print_helper(root);
}

int BSTree::balance(BTreeNode*& _root) const {
    return height_helper(_root->left) - height_helper(_root->right);
}

void BSTree::leftRotate(BTreeNode*& _root) {
    BTreeNode* rightChild = _root->right;
    BTreeNode* leftGrandChild = rightChild->left;
    BTreeNode* rootCopy = _root;
    _root = rightChild;
    _root->left = rootCopy;
    _root->left->right = leftGrandChild;
}

void BSTree::rightRotate(BTreeNode*& _root) {
    BTreeNode* leftChild = _root->left;
    BTreeNode* rightGrandChild = leftChild->right;
    BTreeNode* rootCopy = _root;
    _root = leftChild;
    _root->right = rootCopy;
    _root->right->left = rightGrandChild;
}

void BSTree::visualize(std::ostream& out) const
{
    out << "digraph G{\n";
    visualizeHelp(out, root);
    out << "}";
}

void BSTree::visualizeHelp (std::ostream& out, BTreeNode *curr) const{
    if (curr)
    {     
        out << (long)curr << "[label=\"" << curr->data << "\"];\n";

        if (curr->left)
        {
            out << (long)curr << "->" << (long)(curr->left) << "[color=blue];\n";
        } 
        if (curr->right)
        {
            out << (long)curr << "->" << (long)(curr->right) << "[color=red];\n";
        }
        visualizeHelp (out, curr->left);
        visualizeHelp (out, curr->right);
    }
}

namespace utils{
    std::string generateStepLogName(int stepCount) {
        std::string result = "step_";
        return (result+(char)('0'+ stepCount)+".dot");
    }
}
int main() {
    BSTree tree;
    std::vector<int> elements = {1,2,3,4,5,6,7,8,9,10};
    int step = 0;
    for(int element : elements) {
        std::string stepName = utils::generateStepLogName(step++);
        std::ofstream fout(stepName.c_str());
        tree.add_rec(element);
        tree.visualize(fout);
    }
}