// student id: 20481838

#include "Playlist.h"

using namespace std;

Playlist::Playlist()
{
    Playlist::Song_Entry s(-1, "HEAD");
    
    Playlist::Node *nde = new Playlist::Node(s);
    
    _head = nde;
    _tail = nde;
    _prev_to_current = nde;
    
    _size = 0;
}

Playlist::~Playlist()
{
    clear();
    
    delete _head;
    
    _size = 0;
}

Playlist *Playlist::insert_at_cursor(const Song_Entry &s)
{
    Node *nde = new Node(s);
    
    if (_prev_to_current -> get_next() == nullptr)
    {
        _tail = nde;
    }
    
    _prev_to_current -> insert_next(nde);

    _size++;
    
    return this;
}

Playlist *Playlist::push_back(const Song_Entry& s)
{
    Node *nde = _prev_to_current;
    
    _prev_to_current = _tail;
    
    insert_at_cursor(s);
    
    _prev_to_current = nde;
    
    return this;
}

Playlist *Playlist::push_front(const Song_Entry& s)
{
    _prev_to_current = _head;
    
    insert_at_cursor(s);
    
    return this;
}

Playlist *Playlist::advance_cursor()
{
    if (_prev_to_current == _tail)
    {
        return nullptr;
    }
    
    _prev_to_current = _prev_to_current -> get_next();
    
    return this;
}

Playlist *Playlist::circular_advance_cursor()
{
    if (_prev_to_current == _tail)
    {
        _prev_to_current = _head -> get_next();
        
        return this;
    }
        _prev_to_current = _prev_to_current -> get_next();
    
        return this;
}

Playlist::Song_Entry &Playlist::get_current_song() const
{
    if (_prev_to_current -> get_next() != nullptr)
    {
        return _prev_to_current -> get_next() -> get_song();
    }
    
    return this -> _head -> get_song();
}

Playlist *Playlist::remove_at_cursor()
{
    if (_prev_to_current -> get_next() == nullptr)
    {
        return this;
    }
    if (_prev_to_current -> get_next() == _tail)
    {
        _tail = _prev_to_current;
    }
    
    _prev_to_current -> remove_next();
    
    _size--;

    return this;
}

Playlist *Playlist::rewind()
{
    _prev_to_current = _head;

    return this;
}

Playlist *Playlist::clear()
{
    rewind();
    
    while (_head != _tail)
    {
        remove_at_cursor();
    }
    
    _prev_to_current = _head;
    
    _head -> get_next();
    
    _size = 0;
    
    return this;
}

Playlist::Song_Entry &Playlist::find_by_id(int id) const
{
    Node *nde = _head -> get_next();
    
    while (nde != nullptr)
    {
        if (nde -> get_song().get_id() == id)
        {
            return nde -> get_song();
        }
        
        nde = nde -> get_next();
    }
    
    return this -> _head -> get_song();
}

Playlist::Song_Entry& Playlist::find_by_name(string songName) const
{
    Node *nde = _head -> get_next();

    while (nde != nullptr)
    {
        string result = nde -> get_song().get_name();

        if (nde -> get_song().get_name() == songName)
        {
            return nde -> get_song();
        }

        nde = nde -> get_next();
    }

    return _head -> get_song();
}

std::string Playlist::to_string() const
{
    Node *nde = _head;
    
    std::string s = "";
    
    std::string size = std::to_string(get_size());
    
    s += "Playlist: " + size + " entries.\n";
    
    
    for (int c = 0; c < 25; c++)
    {
        if (nde -> get_next() != nullptr)
        {
            std::string id = std::to_string(nde -> get_next() -> get_song().get_id());
            
            s += "{ id: " + id + ", name: " + nde -> get_next() -> get_song().get_name() + " }";
            
            if (nde -> get_next() == _prev_to_current)
            {
                s += " [P]";
            }
            if (nde -> get_next() == _tail)
            {
                s += " [T]";
            }
            
            s += "\n";
            
            nde = nde -> get_next();
        }
    }
    
    if (_size > 25)
    {
        s += "...\n";
    }
    
    return s;
}
