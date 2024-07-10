#include <iostream>
using namespace std;

class Car {
public:
    string model;
    int year;
    // Default Constructor
    // Used when object is created without specifying any parameters
    Car() {
        model = "Unknown";
        year = 0;
    }

    // Parameterized Constructor
    // Used when parameters are specfied during object creation
    // Sets properties to the specified parameters
    Car(string m, int y) {
        model = m;
        year = y;
    }

    // Copy Constructor
    // Creates a new object using information of an existing object
    // Called when an object of class car is explicitly copied using = operator
    // Or when it is passed into a function
    Car(const Car &other) {
        // other is the object from which data is being copied to the new object
        cout<<"Copy constructor called"<<endl;
        model = other.model;
        year = other.year;
    }
    // Displays information about car
    void display() {
        cout << "Model: " << model << ", Year: " << year << endl;
    }
    // This function has been defined from outside the class
    void showAge();
};

// object car of class Car is passed as an argument here
// This will invoke copy constructor
void changeYear(Car car,int year){
    car.year = year;
}

// creating a member function outside of its class
void Car::showAge(){
    int currentYear = 2024;
    cout<<"Age is the car is: "<<currentYear-year<<endl;
}

int main() {
    // Using default constructor
    Car myCar1;
    myCar1.display();

    // Using parameterized constructor
    Car myCar2("Toyota", 2023);
    myCar2.display();

    // Using copy constructor
    Car myCar3 = myCar2;
    cout<<"changeYear function has been called"<<endl;
    myCar2.showAge();
    // Passing myCar3 as function argument will invoke the copy constructor
    changeYear(myCar3,2004);
    cout<<"Year has been changed to "<<myCar3.year<<endl;
    myCar3.display();

    return 0;
}