#include <iostream>

template <typename T>
class Vector {
private:
    T* data;          
    int size;        
    int capacity;    

    void reserve(int new_capacity) {
        T* new_data = new T[new_capacity]; 
        
        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];         
        }

        delete[] data;                     
        data = new_data;                   
        capacity = new_capacity;          
    }

public:
    Vector() {
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    ~Vector() {
        delete[] data;
    }

    void push_back(T value) {
        if (size == capacity) {
            int new_capacity = (capacity == 0) ? 1 : capacity * 2;
            reserve(new_capacity);
        }
        data[size] = value;
        size++;
    }

    void insert(int index, T value) {
        if (size == capacity) {
            int new_capacity = (capacity == 0) ? 1 : capacity * 2;
            reserve(new_capacity);
        }

        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }

        data[index] = value; 
        size++;
    }

    void erase(int index) {
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    void pop_back() {
        if (size > 0) {
            size--;
        }
    }

    T& operator[](int index) {
        return data[index];
    }

    int ret_size() {
        return size;
    }
};


template <typename DataType>
void process_vector(int n) {
    Vector<DataType> v;
    std::cout << "Enter " << n << " elements:\n";
    
    for (int i = 0; i < n; i++) {
        DataType val;
        std::cin >> val;
        v.push_back(val);
    }

    std::cout << "Your vector: ";
    for (int i = 0; i < v.ret_size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cout << "Select data type:\n";
    std::cout << "1 - int\n2 - double\n3 - float\n4 - char\n5 - bool\n";
    std::cout << "Your choice: ";
    int choice;
    std::cin >> choice;

    int n;
    std::cout << "How many elements do you want to enter? ";
    std::cin >> n;

    switch (choice) {
        case 1:
            process_vector<int>(n);
            break;
        case 2:
            process_vector<double>(n);
            break;
        case 3:
            process_vector<float>(n);
            break;
        case 4:
            process_vector<char>(n);
            break;
        case 5:
            process_vector<bool>(n);
            break;
        default:
            std::cout << "Invalid choice!\n";
            break;
    }

    return 0;
}
