#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

enum class PointType
{
    cartesian,
    polar
};

class Point {
protected:
    // data
    float xc, yc;

public:
    // class method to create points.
    static Point& createPoint(float a, float b, PointType type = PointType::cartesian);
    std::ostream& operator<<(const Point &c);
    
    float get_x() const { return xc;};
    float get_y() const { return yc;};
    
};

std::ostream& operator<<(std::ostream &output, const Point &c) {
       output << c.get_x() << std::endl;;
       output << c.get_y() << std::endl;;
       return output;
};


class Cartesian : public Point {

protected:
    using Point::xc;
    using Point::yc;
public:
    Cartesian(const float x, const float y) {
        xc = x;
        yc = y;
    };
    std::ostream& operator<<(const Cartesian &c); 
};


class Polar : public Point {

    // specific to this class, dont know if we want to do polar based operations like rotate.
    float radius;
    float theta;
protected:
    // base class data
    using Point::xc;
    using Point::yc;
public:
    Polar(const float r, const float theta) : radius(r), theta(theta) {
        xc = cos(theta) * r;
        yc = sin(theta) * r;
    };
    std::ostream& operator<<(const Polar &c);
    float get_radius() const { return radius;};
    float get_theta() const { return theta;};
};

std::ostream& operator<<(std::ostream &output, const Polar &c) {
       output << c.get_radius() << std::endl;;
       output << c.get_theta() << std::endl;;
       return output;
};



// TBD can we have switch here ? 
Point& Point::createPoint(float a, float b, PointType type) {
    if (type == PointType::cartesian) {
        return *( new Cartesian(a,b));
    }
    else {
        return *(new Polar(a,b));
    }
}

int main()
{
    // will not work
    //Point p{ 1,2 };

    Point& p1 = Point::createPoint(5, M_PI_4,PointType::polar);
    std::cout << p1 << std::endl;


    Point& p2 = Point::createPoint(12,56,PointType::cartesian);
    std::cout << p2 << std::endl;

    Polar p3(5, M_PI_4);
    std::cout << p3 << std::endl;

    // p2 = p3;


    return 0;
}



