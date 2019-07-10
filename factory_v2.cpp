#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

enum class PointType
{
    cartesian,
    polar
};

class Point {

    // data
    float xc, yc;
    
public:
    // class method to create points.
    static Point& createPoint(float a, float b, PointType type = PointType::cartesian);
    static Point& NewPolar(float r, float tha);
    static Point& NewCartesian(float x, float y);
    
    std::ostream& operator<<(const Point &c);

    float get_x() const { return xc;};
    float get_y() const { return yc;};
    
};

std::ostream& operator<<(std::ostream &output, const Point &c) {
       output << c.get_x() << std::endl;;
       output << c.get_y() << std::endl;;
       return output;
};


Point& Point::createPoint(float a, float b, PointType type) {
    Point *t = new Point;
    if (type == PointType::cartesian) {
        t->xc = a;
        t->yc = b;
    }
    else {
        t->xc = a*cos(b);
        t->yc = a*sin(b);
    }
    return *t;
}

Point&  Point::NewPolar(float r, float tha) {
    return createPoint(r, tha, PointType::polar);
}

Point& Point::NewCartesian(float x, float y) {
    return createPoint(x, y, PointType::cartesian);
}


int main()
{
    // will not work
    //Point p{ 1,2 };
    
    Point p1 = Point::NewPolar(5, M_PI_4);
    std::cout << p1 << std::endl;
    
    
    Point p2 = Point::NewCartesian(12,56);
    std::cout << p2 << std::endl;    

    return 0;
}
