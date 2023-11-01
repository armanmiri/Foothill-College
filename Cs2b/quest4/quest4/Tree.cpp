// student id: 20481838

#include "Tree.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const Tree::Node& Tree::Node::operator=(const Tree::Node& that)
{
    if (this != &that)
    {
        _data = that._data;
        _child = nullptr;
        _sibling = nullptr;
        
        if (that._child != nullptr)
        {
            _child = new Node(*that._child);
        }
        
        if (that._sibling != nullptr)
        {
            _sibling = new Node(*that._sibling);
        }
        
        
    }

    return *this;
}

Tree::Node::~Node()
{
    
    if (_child != nullptr)
    {
        delete _child;
        _child = nullptr;
    }

    if (_sibling != nullptr)
    {
        delete _sibling;
        _sibling = nullptr;
    }
}

Tree::Node* Tree::Node::insert_sibling(Node* p)
{
    Node* inprg = this;

    while (inprg -> _sibling != nullptr)
    {
        inprg = inprg -> _sibling;
    }

    inprg -> _sibling = p;
    
    return p;
}

Tree::Node* Tree::Node::insert_child(Node* p)
{
    if (_child == nullptr)
    {
        _child = p;
    }
    else
    {
        _child -> insert_sibling(p);
    }
    
    return p;
}

string Tree::Node::to_string() const
{
    string output = _data + " :";
    
    Node* inprg = _child;

    while (inprg != nullptr)
    {
        output += " " + inprg -> _data;
        
        inprg = inprg -> _sibling;
    }

    output += "\n";
    
    inprg = _child;

    if (inprg != nullptr)
    {
        output += "# Child of " + _data + "\n";
        
        output += inprg -> to_string();
    }

    inprg = _sibling;

    if (inprg != nullptr)
    {
        output += "# Next sib of " + _data + "\n";
        
        output += inprg -> to_string();
    }

    return output;
}

bool Tree::Node::operator==(const Node& that) const
{
    return is_equal(this, &that);
}

bool Tree::Node::operator!=(const Node& that) const
{
    return !(*this == that);
}

bool Tree::Node::is_equal(const Node* p1, const Node* p2)
{
    bool output = false;
    
    if (p1 == nullptr && p2 == nullptr)
    {
        output = true;
    }
    else if (p1 != nullptr && p2 != nullptr)
    {
        output = true;
        
        if (p1 -> _data.compare(p2 ->_data) != 0)
        {
            output = false;
        }
        else if (!is_equal(p1 -> _sibling, p2 -> _sibling))
        {
            output = false;
        }
        else if (!is_equal(p1 -> _child, p2 -> _child))
        {
            output = false;
        }
    }

    return output;
}

Tree::Tree()
{
    _root = new Node("ROOT");
}

Tree::~Tree()
{
    delete _root;
    
    _root = nullptr;
}

Tree& Tree::operator=(const Tree& that)
{
    if (this != &that)
    {
        _root = nullptr;

        if (that._root != nullptr)
        {
            _root = new Node(*that._root);
        }
    }

    return *this;
}

string Tree::to_string() const
{
    string output = "# Tree rooted at " + _root->_data + "\n";
    
    output += "# The following lines are of the form:\n";
    
    output += "#   node: child1 child2...\n";
    
    output += _root->to_string();
    
    output += "# End of Tree\n";
    
    return output;
}

void Tree::make_special_config_1(const vector<string>& names)
{
    Node* cfig = _root->insert_sibling(new Node(names[0]));
    
    cfig->insert_child(new Node(names[4]))->insert_child(new Node(names[12]));
    cfig->insert_child(new Node(names[5]))->insert_child(new Node(names[13]));
    
    cfig = _root->insert_sibling(new Node(names[1]));
    cfig->insert_child(new Node(names[6]))->insert_child(new Node(names[14]));
    cfig->insert_child(new Node(names[7]))->insert_child(new Node(names[15]));
    
    cfig = _root->insert_sibling(new Node(names[2]));
    cfig->insert_child(new Node(names[8]))->insert_child(new Node(names[16]));
    cfig->insert_child(new Node(names[9]))->insert_child(new Node(names[17]));
    
    cfig = _root->insert_sibling(new Node(names[3]));
    cfig->insert_child(new Node(names[10]))->insert_child(new Node(names[18]));
    cfig->insert_child(new Node(names[11]))->insert_child(new Node(names[19]));
}

