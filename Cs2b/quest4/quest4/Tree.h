// student id: 20481838

#ifndef Tree_h
#define Tree_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tree
{
private:
    struct Node
    {
        string _data;
        
        Node* _sibling, * _child;

        Node(string s = "") : _data(s), _sibling(nullptr), _child(nullptr)
        {
        }
        
        Node(const Node& that)
        {
            *this = that;
        }
        
        const Node& operator=(const Node& that);
        
        ~Node();

        string get_data() const { return _data; }
        void set_data(string s) { _data = s; }

        Node* insert_sibling(Node* p);
        Node* insert_child(Node* p);

        string to_string() const;

        bool operator==(const Node& that) const;
        bool operator!=(const Node& that) const;

        static bool is_equal(const Node* p1, const Node* p2);
    };

    Node* _root;

public:
    Tree();
    ~Tree();

    Tree(const Tree& that) { *this = that; }
    Tree& operator=(const Tree& that);

    string to_string() const;
    void make_special_config_1(const vector<string>& names);

    bool operator==(const Tree& that) const
    {
        bool output = false;

        if (Node::is_equal(_root, that._root))
        {
            output = true;
        }

        return output;
    }
    
    bool operator!=(const Tree& that) const
    {
        return !(*this == that);
    }

    friend ostream& operator<<(ostream& os, const Tree& tree)
    {
        os << tree.to_string();
        return os;
    }

    friend class Tests;
};

#endif
