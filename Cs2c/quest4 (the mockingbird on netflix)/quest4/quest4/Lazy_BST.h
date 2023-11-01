// student id:

#include <iostream>
#include <cmath>
#include <utility>


#ifndef Lazy_BST_h
#define Lazy_BST_h


template <typename T>

class Lazy_BST {

private:
    
    struct Node {
        
        T _data;
        
        Node *_left, *_right;
        
        bool _is_deleted;
        
        Node(const T &d, Node *l = nullptr, Node *r = nullptr) : _data(d), _left(l), _right(r), _is_deleted(false) {}
    };
    
    Node *_root;
    
    size_t _size, _real_size;

    static Node *_deep_copy(const Node *p)
    {
        return p;
        
    }
    
    
    bool _insert(Node *&p, const T &elem)
    {
        if (!(p == nullptr))
        {
            if(elem == p -> _data)
            {
               if(!(p -> _is_deleted))
               {
                   return false;
               }
               else
               {
                   p -> _is_deleted = false;
                   
                   this -> _size++;
                   
                   return true;
               }
            }
            else if (elem < p -> _data)
            {
                return _insert(p -> _left, elem);
            }
            else
            {
                return _insert(p -> _right, elem);
            }
        }
        else
        {
            p = new Node(elem);
            
            this -> _real_size++;
            
            this -> _size++;
            
            return true;
        }
    }
    
    bool _remove(Node *&p, const T &elem)
    {
        if (!(p == nullptr))
        {
            if(p -> _data == elem)
            {
                if(p -> _is_deleted)
                {
                    return false;
                }
                else
                {
                    this -> _size--;
                
                    p -> _is_deleted = true;
                
                    return true;
                }
            }
            else if (p -> _data > elem)
            {
                return _remove(p -> _left, elem);
            }
            else
            {
                return _remove(p -> _right, elem);
            }
        }
        else
        {
            return false;
        }
    }
    
    bool _recursive_delete(Node *&p)
    {
        return false;
    }
    
    const Node *_find_min(Node *p) const
    {
        if (!(p == nullptr))
        {
            const Node* lmin = _find_min(p -> _left);
            
            if (!(lmin == nullptr))
            {
                return lmin;
            }
            else
            {
                if (p -> _is_deleted)
                {
                    const Node* rmin = _find_min(p -> _right);
                    
                    if (!(rmin == nullptr))
                    {
                        return rmin;
                    }
                    else
                    {
                        return nullptr;
                    }
                }
                else
                {
                    return p;
                }
            }
        }
        else
        {
            return nullptr;
        }
        
    }
    
    
    const Node *_find_real_min(Node *p) const
    {
        if(!(p == nullptr))
        {
            if(p -> _left == nullptr)
            {
                return p;
            }
            else
            {
                return _find_real_min(p -> _left);
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
            if (p -> _data == elem)
            {
                if (p -> _is_deleted)
                {
                    return nullptr;
                }
                else
                {
                    return p;
                }
            }
            else if (p -> _data > elem)
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
    }
    
    
    bool _really_remove(Node *&p, const T &elem)
    {
        if (!(p == nullptr))
        {
            if (p -> _data == elem)
            {
                if (p -> _right == nullptr && p -> _left == nullptr)
                {
                    if (p -> _is_deleted)
                    {
                        return p;
                    }
                    else
                    {
                        _size --;
                        
                        _real_size--;
                        
                        delete p;
                        
                        p = nullptr;
                    }
                }
                else if ( p -> _right == nullptr)
                {
                    if (p -> _is_deleted)
                    {
                        return p;
                    }
                    else
                    {
                        _size --;
                        
                        _real_size--;
                        
                        Node* replace = p -> _left;
                        
                        delete p;
                        
                        p = replace;
                    }
                }
                else if ( p -> _left == nullptr)
                {
                    if (p -> _is_deleted)
                    {
                        return p;
                    }
                    else
                    {
                        _size --;
                        
                        _real_size--;
                        
                        Node* replace = p -> _right;
                        
                        delete p;
                        
                        p = replace;
                    }
                }
                else
                {
                    T newel = _find_real_min(p -> _right) -> _data;
                    
                    p -> _data = newel;
                    
                    _really_remove(p -> _right, newel);
                    
                    p -> _is_deleted = false;
                    
                    _size++;
                }
                
                return true;
            }
            else if (p -> _data > elem)
            {
                return _really_remove(p -> _left, elem);
            }
        
                return _really_remove(p -> _right, elem);
            
        }
        else
        {
            return false;
        }
    }
    
    
    
    string to_string(const Node *p) const
    {
        string empty = "   ";
        
        return empty;
    }
    
    
public:
    
    
    Lazy_BST() : _root(nullptr), _size(0), _real_size(0) {}
    
    virtual ~Lazy_BST()
    {
        _recursive_delete(_root);
    }
    
    virtual size_t get_size() const
    {
        return _size;
        
    }
    
    virtual size_t get_real_size() const
    {
        return _real_size;
    }
    
    bool insert(const T &elem)
    {
        return _insert(_root, elem);
    }
    
    bool remove(const T &elem)
    {
        return _remove(_root, elem);
    }
    
    bool collect_garbage()
    {
        return false;
    }
    
    bool contains(const T &elem) const
    {
        return *_find(_root, elem) != nullptr;
    }
    
    const T &find(const T &elem) const
    {
        return elem;
    }
    
    string to_string() const
    {
        return to_string(_root);
    }
    
    bool clear()
    {
        return false;
    }
    
    
    
    class Not_found_exception : public exception
    {
    
    public:
        
        string to_string()
        {
            return "Element not found exception";
        }
    };
    
    friend class Tests;

};

#endif
