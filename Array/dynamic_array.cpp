
#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;
    int capacity;

    void resizeCapacity() {
        capacity *= 2;

        int* newData = new int[capacity];

        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    }

public:
    DynamicArray() {
        size = 0;
        capacity = 2;
        data = new int[capacity];
    }

    void push_back(int value) {
        if (size == capacity) {
            resizeCapacity();
        }

        data[size] = value;
        size++;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Invalid index");
        }

        return data[index];
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    ~DynamicArray() {
        delete[] data;
    }
};

int main() {
    DynamicArray arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);

    arr.display();

    cout << "Size: " << arr.getSize() << endl;
    cout << "Capacity: " << arr.getCapacity() << endl;

    return 0;
}
