//student id: 20481838

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
#include <math.h>

#ifndef Tree_Algorithms_h
#define Tree_Algorithms_h

using namespace std;

#include "BST.h"

class Tx {
    
private:
    
    template <typename T> static void _splay(typename BST<T>::Node*& p, const T& x)
    {
        typename BST<T>::Node* inprg;
        
        typename BST<T>::Node* leftchildset = nullptr;
        
        typename BST<T>::Node* rightchildset = nullptr;
        
        if (!(p == nullptr))
        {
            while (p -> _data != x)
            {
                if (x < p -> _data)
                {
                    if (!(p -> _left == nullptr))
                    {
                        if (p -> _left -> _data < x)
                        {
                            inprg = p;
                            
                            p = p -> _left;
                            
                            inprg -> _left = nullptr;
                            
                            insert<T>(rightchildset, inprg);
                        }
                        else if (x < p -> _left -> _data)
                        {
                            _rotate_with_left_child<T>(p);
                            
                            if (p -> _left != nullptr)
                            {
                                inprg = p;
                                
                                p = p -> _left;
                                
                                inprg -> _left = nullptr;
                                
                                insert<T>(rightchildset, inprg);
                            }
                        }
                        else
                        {
                            inprg = p;
                            
                            p = p -> _left;
                            
                            inprg -> _left = nullptr;
                            
                            insert<T>(rightchildset, inprg);
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (!(p -> _right == nullptr))
                    {
                        if (p -> _right -> _data > x)
                        {
                            inprg = p;
                            
                            p = p -> _right;
                            
                            inprg -> _right = nullptr;
                            
                            insert<T>(leftchildset, inprg);
                        }
                        else if (p -> _right -> _data < x)
                        {
                            _rotate_with_right_child<T>(p);
                            
                            if (p -> _right != nullptr)
                            {
                                inprg = p;
                                
                                p = p -> _right;
                                
                                inprg -> _right = nullptr;
                                
                                insert<T>(leftchildset, inprg);
                            }
                        }
                        else
                        {
                            inprg = p;
                            
                            p = p -> _right;
                            
                            inprg -> _right = nullptr;
                            
                            insert<T>(leftchildset, inprg);
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                
            }
        }
        else
        {
            return;
        }
        
        typename BST<T>::Node* leftchild = p -> _left;
        
        typename BST<T>::Node* rightchild = p -> _right;
        
        p -> _left = nullptr;
        
        p -> _right = nullptr;
        
        insert<T>(leftchildset, leftchild);
        
        insert<T>(rightchildset, rightchild);
        
        p -> _left = leftchildset;
        
        p -> _right = rightchildset;
        
        return;
    }
    
    template <typename T> static void insert(typename BST<T>::Node*& nde, typename BST<T>::Node *&p)
    // helps simplify to make code for splay easier to write and read
    {
        if (p == nullptr)
        {
            return;
        }
        
        if (nde == nullptr)
        {
            nde = p;
            
            return;
        }
        
        if (p->_data < nde->_data)
        {
            return insert<T>(nde -> _left, p);
        }
        else
        {
            return insert<T>(nde -> _right, p);
        }
    }
    
    template <typename T> static void _rotate_with_left_child(typename BST<T>::Node *&p)
    {
        if (!(p -> _left == nullptr || p == nullptr))
        {
            typename BST<T>::Node* leftchild = p -> _left;
            
            typename BST<T>::Node* rightchild = p -> _left -> _right;
            
            p -> _left = rightchild;
            
            leftchild -> _right = p;
            
            p = leftchild;
            
            return;
        }
        else
        {
            return;
        }
    }
    
    template <typename T> static void _rotate_with_right_child(typename BST<T>::Node *&p)
    {
        if (!(p -> _right == nullptr || p == nullptr))
        {
            typename BST<T>::Node* rightchild2 = p -> _right;
            
            typename BST<T>::Node* leftchild2 = p -> _right -> _left;
            
            p -> _right = leftchild2;
            
            rightchild2 -> _left = p;
            
            p = rightchild2;
            
            return;
        }
        else
        {
            return;
        }
    }
    
public:
   
    template <typename T> static const T& splay_find(BST<T>& tree, const T& x)
    {
        _splay(tree._root, x);

        if (tree._root == nullptr)
        {
            throw typename BST<T>::Not_found_exception();
        }
        else if (tree._root->_data == x)
        {
            return tree._root->_data;
        }
        else
        {
            throw typename BST<T>::Not_found_exception();
        }
    }
    
    template <typename T> static bool splay_contains(BST<T>& tree, const T& x)
    {
        if (!(tree._root == nullptr))
        {
            try
            {
               splay_find(tree, x);
            }
            catch (typename BST<T>::Not_found_exception error)
            {
               cout << error.to_string() << endl;
            }
            if (tree._root->_data == x)
            {
               return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    
    template <typename T> static bool splay_insert(BST<T>& tree, const T& x)
    {
        if (x)
        {
            if (tree._root == nullptr)
            {
                tree.insert(x);
                
                return true;
            }
            
            _splay(tree._root, x);
            
            if (tree._root -> _data == x)
            {
                return false;
            }
            else if (tree._root -> _data < x)
            {
                tree._root = new typename BST<T>::Node(x, tree._root, tree._root -> _right);
            
                tree._root -> _left -> _right = nullptr;
             
                tree._size++;
                
                return true;
            }
            else
            {
                tree._size++;
                
                tree._root = new typename BST<T>::Node(x, tree._root -> _left, tree._root);
                
                tree._root -> _right -> _left = nullptr;
                
                return true;
            }
        }
        else
        {
            return false;
        }
    }
    
    template <typename T> static bool splay_remove(BST<T>& tree, const T& x)
    {
        _splay(tree._root, x);
        
        typename BST<T>::Node* anchor = tree._root;
        
        if (tree._root == nullptr)
        {
            return false;
        }
        else if (tree._root -> _data != x)
        {
            return false;
        }
        else
        {
            if (tree._root -> _left != nullptr)
            {
                _splay(tree._root -> _left, tree._find_max(tree._root -> _left) -> _data);
                // made another helper for find max otherwise became too messy and I got lost in my code
                
                tree._root -> _left -> _right = tree._root -> _right;
                    
                tree._root = tree._root -> _left;
            }
            else
            {
                tree._root = tree._root -> _right;
            }
            
            tree._size--;
            
            delete anchor;
            
            return true;
        }
    }
    
    friend class Tests;
    
};


#endif
