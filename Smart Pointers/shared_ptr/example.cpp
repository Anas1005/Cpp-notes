#include <iostream>
#include <memory>
#include <vector>

using namespace std;

/*
 * Notes on shared_ptr:
 *
 * 1. shared_ptr is a smart pointer that allows multiple ownership of a single object. 
 *    - Multiple shared_ptr instances can point to the same object.
 *    - The object will only be destroyed when the last shared_ptr instance is destroyed or reset.
 *    - shared_ptr keeps a reference count to track how many instances share the object.
 *
 * 2. Key Functions:
 *    - make_shared<Type>() : Creates and initializes a new object managed by shared_ptr.
 *    - use_count() : Returns the number of shared_ptr instances managing the object.
 *    - reset() : Releases ownership or replaces the managed object.
 *
 * 3. Real-Life Analogy:
 *    - A single car (ride) can be shared by multiple passengers.
 *    - The car remains available as long as at least one passenger (shared_ptr instance) is still sharing it.
 *    - Once all passengers (shared_ptr instances) leave the car, the car is no longer needed and is destroyed.
 */

class Car {
public:
    Car(const string& model) : model(model) {
        cout << "Car " << model << " created.\n";
    }
    ~Car() {
        cout << "Car " << model << " destroyed.\n";
    }
    void drive() {
        cout << "Car " << model << " is being driven.\n";
    }

private:
    string model;
};

class Passenger {
public:
    Passenger(const string& name) : name(name) {
        cout << "Passenger " << name << " created.\n";
    }
    ~Passenger() {
        cout << "Passenger " << name << " destroyed.\n";
    }
    void shareRide(shared_ptr<Car>& car) {
        sharedCar = car;
        cout << name << " is sharing the car.\n";
    }

    void leaveRide() {
        cout << name << " is leaving the car.\n";
        sharedCar.reset();  // Release ownership of the car
    }

    void driveSharedCar() {
        if (sharedCar) {
            sharedCar->drive();
        } else {
            cout << name << " has no car to drive.\n";
        }
    }

private:
    string name;
    shared_ptr<Car> sharedCar;
};

int main() {
    {
        // Create a shared car
        shared_ptr<Car> car1 = make_shared<Car>("Tesla Model S");
    
        // Create multiple passengers who will share the car
        Passenger passenger1("Alice");
        Passenger passenger2("Bob");
        Passenger passenger3("Charlie");

        // Passengers share the same car
        passenger1.shareRide(car1);
        passenger2.shareRide(car1);
        passenger3.shareRide(car1);

        cout << "Number of shared_ptr instances owning the car: " << car1.use_count() << endl;

        // Each passenger drives the shared car
        passenger1.driveSharedCar();
        passenger2.driveSharedCar();
        passenger3.driveSharedCar();

        // Bob decides to leave the ride
        passenger2.leaveRide();
        cout << "Number of shared_ptr instances owning the car after Bob leaves: " << car1.use_count() << endl;

        // Alice and Charlie still drive the car
        passenger1.driveSharedCar();
        passenger3.driveSharedCar();

        // Charlie leaves the ride as well
        passenger3.leaveRide();
        cout << "Number of shared_ptr instances owning the car after Charlie leaves: " << car1.use_count() << endl;

        // Only Alice is left, so the car still exists
        passenger1.driveSharedCar();

        // Alice leaves the ride
        passenger1.leaveRide();
        cout << "Number of shared_ptr instances owning the car after Alice leaves: " << car1.use_count() << endl;

        // At this point, the car should be destroyed since no one owns it anymore
    }
    
    cout << "End of main function. Car should be destroyed if no one is sharing it.\n";

    return 0;
}
