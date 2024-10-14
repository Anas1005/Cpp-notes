#include <iostream>
#include <memory> // For unique_ptr

using namespace std;

/*
 * Notes on unique_ptr:
 *
 * 1. unique_ptr is a smart pointer in C++ that ensures exclusive ownership of an object.
 *    - Only one unique_ptr can own a given resource at any time.
 *    - When the unique_ptr goes out of scope, the resource is automatically deallocated.
 *
 * 2. Key Operations:
 *    - Creation: Use make_unique<Type>() to initialize and manage a new object.
 *    - Access: Use -> or * operators to access the managed object.
 *    - Ownership Transfer: Use std::move() to transfer ownership from one unique_ptr to another.
 *    - Reset: Replace the current object or release it by passing nullptr.
 *    - Release: Releases ownership and returns a raw pointer. The caller must manage deletion.
 *
 * 3. Real-Life Analogy:
 *    - A car has an engine. The car owns the engine exclusively.
 *    - When the car is destroyed, the engine should be destroyed too.
 *    - If the engine needs to be transferred to another car, we can transfer ownership.
 */

class Engine {
public:
    Engine() {
        cout << "Engine created.\n";
    }
    ~Engine() {
        cout << "Engine destroyed.\n";
    }
    void start() {
        cout << "Engine started.\n";
    }
};

class Car {
private:
    unique_ptr<Engine> engine; // Unique ownership of an Engine

public:
    // Constructor that initializes the car with a unique Engine
    Car() : engine(make_unique<Engine>()) { 
        cout << "Car created with its own engine.\n";
    }

    // Function to start the car's engine if it exists
    void startCar() {
        if (engine) {
            engine->start(); // Access the engine through unique_ptr
        } else {
            cout << "No engine available to start.\n";
        }
    }

    // Transfer the engine ownership to another unique_ptr
    void transferEngineOwnership(unique_ptr<Engine>& newOwner) {
        newOwner = move(engine); // Ownership transferred, 'engine' is now nullptr
        cout << "Engine ownership transferred.\n";
    }

    // Reset the engine with a new one
    void replaceEngine() {
        engine = make_unique<Engine>(); // Replace the current engine
        cout << "Car got a new engine.\n";
    }

    // Release the engine and return a raw pointer
    Engine* releaseEngine() {
        Engine* rawPtr = engine.release(); // Release ownership
        cout << "Engine released from car management.\n";
        return rawPtr;
    }

    ~Car() {
        cout << "Car destroyed.\n";
    }
};

int main() {
    // Scenario 1: Creating a Car object that manages its own Engine
    unique_ptr<Car> car1 = make_unique<Car>(); // Car created
    car1->startCar(); // Start the car's engine

    // Scenario 2: Transferring the engine ownership to another unique_ptr
    unique_ptr<Engine> separateEngine;
    car1->transferEngineOwnership(separateEngine);
    if (!car1->releaseEngine()) {
        cout << "Car no longer has an engine.\n";
    }
    if (separateEngine) {
        cout << "Engine is now managed separately.\n";
        separateEngine->start(); // Start the engine independently
    }

    // Scenario 3: Resetting the engine with a new one
    car1->replaceEngine(); // Car gets a new engine
    car1->startCar(); // Start the new engine

    // Scenario 4: Releasing the engine and manually managing it
    Engine* manualEngine = car1->releaseEngine();
    if (manualEngine) {
        manualEngine->start(); // Access the engine manually
        delete manualEngine; // Manually delete since ownership was released
    }

    return 0;
}
