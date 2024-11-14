#include "circle.h"

class Circle : public Shape {
private:
    double radius;

public:
    void create() override {
        cout << "Enter radius of the circle: ";
        while(!(cin>>radius)){
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
            cout<<"Input invalid, please try again.";

        }

    }

    void print() const override {
        cout << "Circle with radius: " << radius << endl;
    }
};
