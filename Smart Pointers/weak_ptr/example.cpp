/*
 * Notes on weak_ptr:
 *
 * 1. weak_ptr is a smart pointer that provides a non-owning reference to an object managed by shared_ptr.
 *    - It does not affect the reference count of the shared object.
 *    - It is useful for breaking circular references.
 *
 * 2. Key Functions:
 *    - lock() : Tries to convert weak_ptr to shared_ptr, returning a shared_ptr if the object is still alive.
 *      (Since, weak_ptr cannot access object members directly like unique_ptr or shared_ptr)
 *    - expired() : Checks if the managed object has been destroyed.
 *    - reset() : Releases the weak_ptr.
 *
 * Circular Dependency in C++
 * 
 * Circular dependencies occur when two or more classes reference each other, 
 * creating a cycle in ownership. This can lead to memory leaks if not handled properly,
 * as the reference count for the involved objects may never reach zero, preventing 
 * them from being destroyed. This is particularly problematic in scenarios where 
 * shared ownership is involved.
 * 
 * Example Scenario:
 * - **Library**: Represents a library managing multiple members.
 * - **Member**: Represents an individual who can borrow books from the library.
 * 
 * In this example, we use `shared_ptr` for members to allow shared ownership, 
 * and `weak_ptr` in the `Member` class to avoid circular dependencies. This ensures that 
 * when a member leaves, the library can still be destroyed properly without memory leaks.
 */

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Library; // Forward declaration

class Member {
public:
    Member(const string& name) : name(name) {
        cout << "Member \"" << name << "\" created.\n";
    }

    ~Member() {
        cout << "Member \"" << name << "\" destroyed.\n";
    }

    void setLibrary(shared_ptr<Library> library) {
        this->library = library; // Shared ownership of Library
    }

    void borrowBook() {
        if (auto lib = library.lock()) { // Locking weak_ptr to access the shared_ptr to the Library if available
            cout << name << " borrowed a book from " << lib->getName() << ".\n";
        } else {
            cout << name << " cannot access the library. It has been destroyed.\n";
        }
    }

private:
    string name; // Name of the member
    weak_ptr<Library> library; // Weak pointer to avoid circular dependency
};

class Library : public enable_shared_from_this<Library> {
public:
    Library(const string& name) : name(name) {
        cout << "Library \"" << name << "\" created.\n";
    }

    ~Library() {
        cout << "Library \"" << name << "\" destroyed.\n";
    }

    string getName() const {
        return name;
    }

    void addMember(shared_ptr<Member> member) {
        members.push_back(member);
        member->setLibrary(shared_from_this()); // Set the library reference in the member
    }

    void notifyMembers() {
        cout << "Notifying members of \"" << name << "\"...\n";
        for (const auto& member : members) {
            member->borrowBook();
        }
    }

private:
    string name; // Name of the library
    vector<shared_ptr<Member>> members; // Shared ownership of members
};

int main() {
    // Create a library using shared_ptr
    shared_ptr<Library> library = make_shared<Library>("City Library");

    // Create members using shared_ptr
    shared_ptr<Member> john = make_shared<Member>("John");
    shared_ptr<Member> alice = make_shared<Member>("Alice");

    // Add members to the library
    library->addMember(john);
    library->addMember(alice);

    // Notify members to borrow books
    library->notifyMembers();

    // Demonstrate weak_ptr functions
    cout << "Reference count for Library: " << library.use_count() << endl;
    cout << "Is library expired? " << (library.use_count() == 0 ? "Yes" : "No") << endl;

    // Reset the library
    library.reset();
    cout << "After reset, is library expired? " << (library == nullptr ? "Yes" : "No") << endl;

    // Attempt to notify members again to check access to the library
    john->borrowBook();
    alice->borrowBook();

    return 0;
}
