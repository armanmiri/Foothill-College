// Student ID: 20481838

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#include "Shapes.h"
using namespace std;

Screen::Screen(size_t w, size_t h)
{
    if (w < 1 || h < 1)
    {
        return;
    }
    
    _pix.resize(h);
    
    for (size_t i = 0; i < h; i++)
    {
        _pix[i].resize(w);
    }
    
    _w = w;
    _h = h;

}

void Screen::fill(char c)
{
    for (size_t i = 0; i < _pix.size(); i++)
    {
        for (size_t n = 0; n < _pix[i].size(); n++)
        {
            _pix[i][n] = c;
        }
    }
}

string Screen::to_string() const
{
    string strg;
    
    for (size_t i = _h; i-- > 0;)
    {
        for (size_t n = 0; n < _w; n++)
        {
            strg += _pix[i][n];
        }
        
        strg += '\n';
    }
    
    return strg;
}

bool Point::draw(Screen &screen, char c)
{
    if (_x < 0 || _x >= screen.get_w() || _y < 0 || _y >= screen.get_h())
    {
        return false;
    }
    
    screen.get_pix()[_y][_x] = c;
    
    return true;
}

// Draw pizels on the screen along the X direction, using the supplied
// char (ch) as the pixel. The number of segments will be abs(y2-y1).
// Each segment will be abs(x2-x1)/abs(y2-y1) pixels long.

bool Line::draw_by_x(Screen &scr, char ch, size_t x1, size_t y1, size_t x2, size_t y2)
{
    if (x1 > x2)
    {
        return draw_by_x(scr, ch, x2, y2, x1, y1);
    }

    double inprg = ((double) y2-y1)/((double) x2-x1);

    bool contained = true;

    double x = x1, y = y1;

    while (x <= x2)
    {
        contained &= Point((size_t) x, (size_t) y).draw(scr, ch);
        
        x++;
        
        y += inprg;
    }
    
    return contained;
}

bool Line::draw_by_y(Screen &scr, char ch, size_t x1, size_t y1, size_t x2, size_t y2)
{
    if (y1 > y2)
    {
        return draw_by_y(scr, ch, x2, y2, x1, y1);
    }

    double inprg = ((double) x2-x1)/((double) y2-y1);

    bool contained = true;

    double x = x1, y = y1;

    while (y <= y2)
    {
        
        contained &= Point((size_t) x, (size_t) y).draw(scr, ch);
        
        x += inprg;
        
        y++;
    }
    
    return contained;
}

size_t Line::get_height_of_line(size_t x1, size_t y1, size_t x2, size_t y2)
{
    int height = y2 - y1;

    return (size_t)abs(height);
}

size_t Line::get_width_of_line(size_t x1, size_t y1, size_t x2, size_t y2)
{
    int width = x2 - x1;

    return (size_t)abs(width);
}

double Line::get_slope(size_t x1, size_t y1, size_t x2, size_t y2)
{
    double product = (double) (y2 - y1) / (double) (x2 - x1);
    
    return product;
}

bool Line::draw(Screen &scr, char ch)
{
    if (get_height_of_line(_x1, _y1, _x2, _y2) > get_width_of_line(_x1, _y1, _x2, _y2))
    {
        draw_by_y(scr, ch, _x1, _y1, _x2, _y2);
    }
    else
    {
        draw_by_x(scr, ch, _x1, _y1, _x2, _y2);
    }
    
    return true;
}

bool Quadrilateral::draw(Screen &scr, char ch)
{
    bool contained = true;
    
    contained &= Line(_x2, _y2, _x3, _y3).draw(scr,ch);
    contained &= Line(_x1, _y1, _x2, _y2).draw(scr,ch);
    contained &= Line(_x3, _y3, _x4, _y4).draw(scr,ch);
    contained &= Line(_x4, _y4, _x1, _y1).draw(scr,ch);

    return  contained;
    
}

Stick_Man::Stick_Man(size_t x, size_t y, size_t w, size_t h)
{
    _parts.clear();
    
    _x = x;
    _y = y;
    _w = w;
    _h = h;

    if (h == 0 || h == 1)
    {
        _h = DEFAULT_H;
    }

    if (w == 0 || w == 1)
    {
        _w = DEFAULT_W;
    }
    
    
    head = new Upright_Rectangle(_x+0, _y+_h/2, _x+_w-1, _y+_h-1);
    torso = new Line(_x+_w/2, _y+_h/2, _x+_w/2,   _y+_h/4);
    leg1 =  new Line(_x+_w/2, _y+_h/2, _x+_w/4,   _y+_h/4);
    leg2 = new Line(_x+_w/2, _y+_h/2, _x+3*_w/4, _y+_h/4);
    arm1 = new Line(_x+_w/2, _y+_h/4, _x, _y);
    arm2 = new Line(_x+_w/2, _y+_h/4, _x+_w-1, _y);

    _parts.push_back(head);
    _parts.push_back(torso);
    _parts.push_back(leg1);
    _parts.push_back(leg2);
    _parts.push_back(arm1);
    _parts.push_back(arm2);
    
}

Stick_Man::~Stick_Man()
{
    for (size_t i = 0; i < _parts.size(); i++)
    {
        delete _parts[i];
    }
}

bool Stick_Man::draw(Screen &scr, char ch)
{
    for (size_t i = 0; i < _parts.size(); i++)
    {
        _parts[i]->draw(scr, ch);
    }
    
    return true;
}
