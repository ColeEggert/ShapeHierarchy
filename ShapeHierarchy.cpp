//Cole Eggert, Shape Hierarchy
#include <iostream>
#include <string>
using namespace std;

class Shape {

public:

    virtual double getArea() const = 0;

    virtual string getName() const = 0;

};

class Moveable {

public:

    virtual void move(double x, double y) {

        cout << "Moving to x: " << x << ", y: " << y << '\n';

    }

};

class TwoDimensionalShape : public Shape {

};

class Circle : public TwoDimensionalShape {

private:

    double radius;

public:

    Circle(double r) : radius(r) {}

    double getArea() const override { return (3.14 * (radius * radius)); }

    string getName() const override { return "Circle"; }

};

class Square : public TwoDimensionalShape {

private:

    double side;

public:

    Square(double s) : side(s) {}

    double getArea() const override { return (side * side); }

    string getName() const override { return "Square"; }

};

class Triangle : public TwoDimensionalShape {

private:

    double base;

    double height;

public:

    Triangle(double b, double h) : base(b), height(h) {}

    double getArea() const override { return (0.5 * (base * height)); }

    string getName() const override { return "Triangle"; }

};

class ThreeDimensionalShape : public Shape {

    virtual double getVolume() const = 0;

};

class Sphere : public ThreeDimensionalShape {

private:

    double radius;

public:

    Sphere(double r) : radius(r) {}

    double getArea() const override { return (4.0 * 3.14 * (radius * radius)); }

    double getVolume() const override { return ((4.0 / 3.0) * 3.14 * (radius * radius * radius)); }

    string getName() const override { return "Sphere"; }

};

class Cube : public ThreeDimensionalShape {

private:

    double side;

public:

    Cube(double s) : side(s) {}

    double getArea() const override { return (6 * (side * side)); }

    double getVolume() const override { return (side * side * side); }

    string getName() const override { return "Cube"; }

};

class Tetrahedron : public ThreeDimensionalShape {

private:

    double side;

public:

    Tetrahedron(double e) : side(e) {}

    double getArea() const override { return (sqrt(3) * (side * side)); }

    double getVolume() const override { return ((side * side * side) / (6.0 * sqrt(2.0))); }

    string getName() const override { return "Tetrahedron"; }

};

class MoveableShape : public Shape, public Moveable {

public:

    virtual void move(int x, int  y) {

        cout << "Shape has been moved to coordinates: (" << x << ", " << y << ")" << '\n';

    };

};

int main() {

    Circle cir(10.0);

    Square sqr(10.0);

    Triangle tri(10.0, 10.0);

    Sphere sph(10.0);

    Cube cube(10.0);

    Tetrahedron tet(10.0);

    Moveable move;

    cout << cir.getName() << " has an area of: " << cir.getArea() << '\n';

    cout << sqr.getName() << " has an area of: " << sqr.getArea() << '\n';

    cout << tri.getName() << " has an area of: " << tri.getArea() << '\n';

    cout << sph.getName() << " has a surface area of: " << sph.getArea() << ", and a volume of: " << sph.getVolume() << '\n';

    cout << cube.getName() << " has a surface area of: " << cube.getArea() << ", and a volume of: " << cube.getVolume() << '\n';

    cout << tet.getName() << " has a surface area of: " << tet.getArea() << ", and a volume of: " << tet.getVolume() << '\n';

    move.move(10, 10);

}