#include <iostream>

class Pointer {
private:
    int* mem_ptr; //Pointer, that keeps a value

public:
    // Ctor,that applies the value
    Pointer(int* ptr) {
        mem_ptr = ptr;
    }

    // Dtor
    ~Pointer() {
        delete mem_ptr;
    }

    // For changing value
    void set_value(int value) {
        *mem_ptr = value; 
    }

    // Reads the value and returns
    int get_value() {
        return *mem_ptr; 
    }

    // For seeing the address
    int* get_address() {
        return mem_ptr;
    }
};


int main() {

    Pointer my_ptr(new int(45));

    
    std::cout << "Address: " << my_ptr.get_address() << "\n";
    std::cout << "Value: " << my_ptr.get_value() << "\n";

    
    my_ptr.set_value(88);

    
    std::cout << "New Value: " << my_ptr.get_value() << "\n";

    return 0;
}
