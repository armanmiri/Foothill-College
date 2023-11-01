// student id : 20481838

#ifndef Shapes_h
#define Shapes_h

#include <iostream>
#include <sstream>
#include <ostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Screen
{
    friend class Shape;

    private:
        size_t _w, _h;
        vector<vector<char> > _pix;
    
    public:
        static const char FG = '*';
        static const char BG = '.';

        Screen(size_t w, size_t h);

        size_t get_w() const { return _w; }
        size_t get_h() const { return _h; }
        vector<vector<char> >& get_pix() { return _pix; }

        void set_w(size_t w) {_w = w;}
        void set_h(size_t h) {_h = h;}

        void clear() {fill(BG);}
        void fill(char c); // TODO - implement in the cpp file
        string to_string() const;

        friend ostream &operator<<(ostream &os, const Screen &scr) {
            return os << scr.to_string();
        };

        friend class Tests;
};

// --------- Shape ---------------------------------
// Anstract base class for circle, rectangle, line, point, triangle, polygon, etc.
//

class Shape
{
    public:
        virtual ~Shape() {};
        virtual bool draw(Screen &scr, char ch = Screen::FG) = 0;
        friend class Tests;
};

// --------- Point ---------------------------------

class Point
{
    private:
        size_t _x, _y;

    public:
        Point(size_t x, size_t y): _x(x), _y(y) {};
        virtual ~Point() {};

        bool draw(Screen &scr, char ch = Screen::FG);

        friend class Tests;
};

// ----------- Line in two point notation ---------------------

class Line : public Shape
{
    private:
        size_t _x1, _y1, _x2, _y2;

        // helpers
        static bool draw_by_x(Screen &scr, char ch, size_t x1, size_t y1, size_t x2, size_t y2);
        static bool draw_by_y(Screen &scr, char ch, size_t x1, size_t y1, size_t x2, size_t y2);

        size_t get_height_of_line(size_t x1, size_t y1, size_t x2, size_t y2);
        size_t get_width_of_line(size_t x1, size_t y1, size_t x2, size_t y2);
        double get_slope(size_t x1, size_t y1, size_t x2, size_t y2);

    public:
        Line(size_t a, size_t b, size_t c, size_t d): _x1(a), _y1(b), _x2(c), _y2(d) {};
        virtual ~Line() {};

        bool draw(Screen &scr, char ch = Screen::FG);

        friend class Tests;
};

// ----------- Quadrilateral -------------------------------------------------
// A general quadrilateral with points (x1,y1) ... (x4,y4), clockwise
// from bottom left. For the special case when x1==x2, y2==y3, x3==x4
// and y4==y1, we'd use an Upright_Rectangle.
//

class Quadrilateral : public Shape
{
    private:
        size_t _x1, _y1, _x2, _y2, _x3, _y3, _x4, _y4;

    public:
        Quadrilateral(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f, size_t g, size_t h) :
            _x1(a), _y1(b), _x2(c), _y2(d), _x3(e), _y3(f), _x4(g), _y4(h) {};

        virtual ~Quadrilateral() {};

        bool draw(Screen &scr, char ch = Screen::FG);

        friend class Tests;
};

// ----------- UprightRectangle, a special Quadrilateral -----------------
// A Rectangle is a special upright Quadrilateral so we don't have to
// parameterize the constructor with a ton of numbers
//

class Upright_Rectangle: public Quadrilateral
{
    public:
        Upright_Rectangle(size_t x1, size_t y1, size_t x2, size_t y2) : Quadrilateral(x1, y1, x1, y2, x2, y2, x2, y1) {};
    
        virtual ~Upright_Rectangle() {};
};

// ----------- StickMan, a composite Shape ------------------------------

class Stick_Man: public Shape
{
    static const size_t DEFAULT_W = 20, DEFAULT_H = 40;

    private:
        
        size_t _x, _y, _w, _h;
    
        vector<Shape *> _parts;
    
        Upright_Rectangle * head = nullptr;
        Line * torso = nullptr;
        Line * leg1 = nullptr;
        Line * leg2 = nullptr;
        Line * arm1 = nullptr;
        Line * arm2 = nullptr;

    public:
        
        Stick_Man(size_t x = 0, size_t y = 0, size_t w = DEFAULT_W, size_t h = DEFAULT_H);
        
        virtual ~Stick_Man(); // Needed to deallocate parts

        const vector<Shape*>& get_parts() const
        {
            return _parts;
        }
    
        bool draw(Screen &scr, char ch = Screen::FG);

        friend class Tests;
};

#endif /* Shapes_h */
