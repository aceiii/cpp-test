#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <cmath>

class Shape {
public:
    virtual int getArea() const {
        return 0;
    }
};

class Rectangle: public Shape {
    int width;
    int height;
public:
    Rectangle(int w, int h):width(w),height(h) {}
public:
    int getArea() const {
        return width * height;
    }
};

class Triangle: public Shape {
    int base;
    int height;
public:
    Triangle(int base, int height):base(base),height(height) {}
public:
    int getArea() const {
        return (base * height) / 2;
    }
};

class Circle: public Shape {
    int radius;
public:
    Circle(int radius):radius(radius) {}
public:
    virtual int getArea() const {
        return int(M_PI * radius * radius);
    }
};

void non_virtual_methods() {
    auto p1 = std::make_unique<Shape>();
    auto p2 = std::make_unique<Rectangle>(2, 3);
    auto p3 = std::make_unique<Triangle>(4, 5);

    std::cout << p1->getArea() << std::endl;
    std::cout << p2->getArea() << std::endl;
    std::cout << p3->getArea() << std::endl;

    std::unique_ptr<Shape> p4 = std::make_unique<Rectangle>(6, 6);
    std::unique_ptr<Circle> p5 = std::make_unique<Circle>(10);
    std::unique_ptr<Shape> p6 = std::make_unique<Circle>(12);

    std::cout << p4->getArea() << std::endl;
    std::cout << p5->getArea() << std::endl;
    std::cout << p6->getArea() << std::endl;
}

int main(int argc, char** argv) {
    non_virtual_methods();

    return 0;
}


