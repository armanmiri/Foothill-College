// student id: 20481838

#include <iostream>
#include <cmath>
#include <utility>
#include <sstream>

#ifndef BST_h
#define BST_h

using namespace std;

template <typename T>

class BST {

private:
    
    struct Node
    {
        T _data;
    
        Node *_left, *_right;
        
        Node(const T &d, Node *l = nullptr, Node *r = nullptr) : _data(d), _left(l), _right(r) {}
    };
    
    Node *_root;
    
    size_t _size;
    
    static Node *_deep_copy(const Node *p)
    {
        if (!(p == nullptr))
        {
            Node *inprg = new Node (p -> _data);
            
            inprg -> _left = _deep_copy ( p -> _left);
            
            inprg -> _right = _deep_copy ( p -> _right);
            
            return inprg;
        }
        
        return nullptr;
    }
    
    bool _insert(Node *&p, const T &elem)
    {
        if (!(p == nullptr))
        {
            if (p -> _data == elem)
            {
                return false;
            }
            else if (elem < p -> _data)
            {
                return _insert(p -> _left, elem);
            }
            else if (elem > p -> _data)
            {
                return _insert(p -> _right, elem);
            }
        }
        
            p = new Node(elem);
            
            this -> _size++;
            
            return true;
    }
    
    bool _remove(Node *&p, const T &elem)
    {
        if (p == nullptr)
        {
            return false;
        }
        else if (p -> _data == elem)
        {
            if (p -> _right == nullptr && p -> _left == nullptr)
            {
                delete p;
                
                p = nullptr;
                
                _size--;
            }
            else if(p -> _left == nullptr)
            {
                Node* inprg = p -> _right;
                
                delete p;
                
                p = inprg;
                
                _size--;
            }
            else if ( p -> _right == nullptr)
            {
                Node* inprg = p -> _left;
                
                delete p;
                
                p = inprg;
                
                _size--;
            }
            else
            {
                T inprgdata = _find_min( p -> _right) -> _data;
                
                p -> _data = inprgdata;
                
                _remove( p -> _right, inprgdata);
            }
            
            return true;
        }
        else if ( elem < p -> _data)
        {
            return _remove(p -> _left, elem);
        }
        else
        {
            return _remove(p -> _right, elem);
        }
    }
    
    bool _recursive_delete(Node *&p)
    {
        if (!(p == nullptr))
        {
            _recursive_delete(p -> _left);
            
            _recursive_delete(p -> _right);
            
            p = nullptr;
            
            delete p;
            
            _size--;
            
            return true;
        }
            return false;
    }
    
    const Node *_find_min(Node *p) const
    {
        if (!(p == nullptr))
        {
            if (p -> _left != nullptr)
            {
                return _find_min(p -> _left);
            }
            else
            {
                return p;
            }
        }
        else
        {
            return nullptr;
        }
    }
    
    Node *_find(Node *p, const T &elem) const
    {
        if (!(p == nullptr))
        {
            if( elem == p -> _data)
            {
                return p;
            }
            else if ( elem < p -> _data)
            {
                return _find(p -> _left, elem);
            }
            else
            {
                return _find(p -> _right, elem);
            }
        }
        else
        {
            return nullptr;
        }
    };
    
    string _to_string(const Node *p) const
    {
        string empty = "   ";
        
        return empty;
    }
    
public:
    
    
    BST() : _root(nullptr), _size(0) {}
    
    virtual ~BST()
    {
         _recursive_delete(_root);
    }
    
    virtual size_t get_size() const
    {
        return _size;
    }
    
    virtual bool insert(const T &elem)
    {
        return _insert(_root, elem);
    }
    
    virtual bool remove(const T &elem)
    {
        return _remove(_root, elem);
    }
    
    virtual bool clear()
    {
        if(!(_root == nullptr))
        {
            return false;
        }
        
        return true;
    }

    virtual bool contains(const T &elem) const
    {
        return _find(_root, elem) != nullptr;
    }
    
    virtual T &find(const T &elem) const
    {
        Node* search = _find(_root, elem);
        
        if (!(search == nullptr))
        {
            return search -> _data;
        }
        else
        {
            throw Not_found_exception();
        }
    }

    virtual string to_string() const
    {
        std::stringstream strg;
        
        strg << _root->_data;

        string print = "# Tree rooted at " + strg.str() + "\n";
        
        print += "# size = " + std::to_string(get_size()) + "\n";
        
        print += _to_string(_root);
        
        print += "# End of tree\n";
        
        return print;
    }
    
    
    
    class Not_found_exception : public exception {
        
    public:
        
        string to_string()
        {
            return "Not found exception";
        }
    
    };
    
    friend class Tests;

};

#endif
