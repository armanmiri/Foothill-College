//student id: 20481838

#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

template <typename T>
class Queue {
private:
    std::vector<T> _data;
    size_t _head, _tail;
    static T _sentinel;

public:
    static const int MAX_DISP_ELEMS = 100;

    Queue(size_t size);

    static void set_sentinel(const T &elem) { _sentinel = elem; }
    static T get_sentinel() { return _sentinel; }

    bool is_empty() const;
    
    size_t size() const
    {
        if (_tail < _head)
        {
            return _tail - _head + _data.size();
        }
        
        return _tail - _head;
        
        }
    
    void resize(size_t size);

    const T &peek() const
    {
        if (is_empty())
        {
            return _sentinel;
        }
        else
        {
            
        return _data[_head];
        
        }
    }
    
    bool dequeue();
    bool enqueue(const T &elem);

    std::string to_string(size_t limit = MAX_DISP_ELEMS) const;

    friend class Tests; // Don't remove this line
};

template <typename T> T Queue<T>::_sentinel = T();

// TODO - Fill in the missing implementations. Experiment with the aesthetics by moving
// some of these implementations inline (into your class def above). See which gives
// you more readable code.

template <typename T> Queue<T>::Queue(size_t size)
{
    _data.resize(size+1);
    
    _head = 0;
    
    _tail = 0;
}

template <typename T> bool Queue<T>::enqueue(const T& elem)
{
    if (size() == 0 || _head != (_tail + 1) % _data.size())
    {
        _data[_tail] = elem;
        
        _tail = 1 % _data.size() + _tail;
    
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T> bool Queue<T>::dequeue()
{
    if (!is_empty())
    {
        _data[_head] = 0;
        
        _head++;
        
        return true;
    }
    else
    {
        return false;
    }
}


template <typename T> bool Queue<T>::is_empty() const
{
    if (_head == _tail || size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T> void Queue<T>::resize(size_t size)
{
    Queue <T> temp(size);
    
    size_t h = _head;
    
    while (!is_empty())
    {
        temp.enqueue(_data[h % _data.size()]);
        
        dequeue();
        
        h++;
    }
    
    _data = temp._data;
    
    _head = temp._head;
    
    _tail = temp._tail;
}


template <typename T> void popalot(Queue<T>& q)
{
    while (!q.is_empty())
    {
        q.dequeue();
    }
}


template <typename T> string Queue<T>::to_string(size_t lim) const
{
    string strg = "";

    strg += "# Queue - size = ";

    strg += std::to_string(size()) + "\n";

    strg += "data :";
    
    if (lim >= size())
    {
        for (size_t n = _head; n < size(); n++)
        {
            strg += " " + std::to_string(_data[n % _data.size()]);
        }
    }
    else if (lim < size())
    {
        for (size_t n = _head; n < lim; n++)
        {
            strg += " " + std::to_string(_data[n % _data.size()]);
        }
        
        strg += " ...";
    }
    
    strg += "\n";
    
    return strg;
}


#endif /* Queue_h */
