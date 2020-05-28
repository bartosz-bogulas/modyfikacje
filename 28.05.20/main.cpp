#include <iostream>
#include <cmath>
#include <vector>

#define N 5

class Shape {
public:
    virtual float area() const {
        return 0;
    };

    virtual std::string name() const {
        return "Shape";
    };
};

class Circle : public Shape {
public:
    Circle() = default;
    explicit Circle(float radius) : radius(radius) {}

    float area() const {
        return static_cast<float>(M_PI) * std::pow(radius, 2);
    }

    std::string name() const {
        return "Circle";
    }

private:
    float radius;
};

class Rectangle : public Shape {
public:
    Rectangle() = default;
    explicit Rectangle(float width, float height) : width(width), height(height) {}

    float area() const {
        return width * height;
    }

    std::string name() const {
        return "Rectangle";
    }

private:
    float width;
    float height;
};

std::ostream& operator<<(std::ostream& out, const Shape& shape) {
    out << "type: " << shape.name() << ", area: " << shape.area();
    return out;
}

int main() {
    std::vector<Circle> v1;
    std::vector<Rectangle> v2;

    for (int i = 1; i <= N; i++) {
        v1.emplace_back(i);
        v2.emplace_back(i, i + 2);
    }

    for (auto& x : v1)
        std::cout << x << std::endl;

    for (auto& x : v2)
        std::cout << x << std::endl;

    std::vector<Shape*> v3;

    for (int i = 1; i <= N; i++) {
        v3.push_back(new Circle(i + 1));
        v3.push_back(new Rectangle(i, i + 3));
    }

    for (auto x : v3)
        std::cout << *x << std::endl;
}