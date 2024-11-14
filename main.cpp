#include <iostream>
#include <vector>
#include <memory>
#include <limits>
using namespace std;

// Base class Shape


// Circle Class that inherits from Shape
CCCC

// Square Class that inherits from Shape
class Square : public Shape {
private:
    double side;

public:
    void create() override {
        cout << "Enter side length of the square: ";
        while(!(cin>>side)){
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
            cout<<"Input invalid, please try again.";

        }
    }

    void print() const override {
        cout << "Square with side length: " << side << endl;
    }
};
// Rectangle Class that inherits from Shape
class Rectangle:public Shape{
private:
    int height;
    int width;
public:
    void create() override{
        cout<<"Enter height of the Rectangle: ";
        while(!(cin>>height)){
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
            cout<<"Input invalid, please try again.";

        }
        cout<<"Enter width of the Rectangle: ";
        while(!(cin>>width)){
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
            cout<<"Input invalid, please try again.";

        }
    }
    void print() const override{
        cout<<"Rectangle with height: "<<height<<" and width: "<<width<<endl;

    }
};

int main() {
    // unique_ptr for memory management of shape
    vector<unique_ptr<Shape>> shapes;
    int choice = 0;

    // Main Loop for Displaying menu
    while(choice != 4){
        cout << "\nMenu:\n";
        cout << "1. Show shape list\n";
        cout << "2. Create shape\n";
        cout << "3. Print existing shapes\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Shapes available:\n";
            cout << "1. Circle\n";
            cout << "2. Square\n";
            cout << "3. Rectangle\n";
            break;
        case 2: {
            int shapeChoice;
            cout << "Select a shape to create:\n";
            cout << "1. Circle\n";
            cout << "2. Square\n";
            cout << "3. Rectangle\n";
            cin >> shapeChoice;

            if (shapeChoice == 1) {
                unique_ptr<Shape>circle = make_unique<Circle>();
                circle->create();
                shapes.push_back(std::move(circle));
            } else if (shapeChoice == 2) {
                unique_ptr<Shape> square = make_unique<Square>();
                square->create();
                shapes.push_back(move(square));
            } else if (shapeChoice == 3) {
                unique_ptr<Shape> rectangle = make_unique<Rectangle>();
                rectangle->create();
                shapes.push_back(move(rectangle));
            } else {
                cout << "Invalid choice!\n";
            }
            break;
        }
        case 3:
            // printing the details all existing shapes
            cout << "Existing shapes:\n";
            for (const auto& shape : shapes) {
                shape->print();
            }
            break;
        case 4:
            // existing the program
            cout << "Exiting...\n";
            break;
        default:
            // handling invalid choice
            cout << "Invalid choice! Please try again.\n";
        }
    };

    return 0;
}
