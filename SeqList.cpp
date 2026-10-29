#include <iostream>
#include <stdexcept>

template <typename T>
class SeqList {
public:
    SeqList(int initCapacity = 10)
        : data(new T[initCapacity]), capacity(initCapacity), length(0) {}

    SeqList(const SeqList& other)
        : data(new T[other.capacity]), capacity(other.capacity), length(other.length) {
        for (int i = 0; i < length; ++i) data[i] = other.data[i];
    }

    SeqList& operator=(const SeqList& other) {
        if (this != &other) {
            T* newData = new T[other.capacity];
            for (int i = 0; i < other.length; ++i) newData[i] = other.data[i];
            delete[] data;
            data = newData;
            capacity = other.capacity;
            length = other.length;
        }
        return *this;
    }

    ~SeqList() { delete[] data; }

    int size() const { return length; }
    bool empty() const { return length == 0; }

    void clear() { length = 0; }

    void pushBack(const T& value) { insert(length, value); }

    void insert(int index, const T& value) {
        if (index < 0 || index > length)
            throw std::out_of_range("insert index out of range");
        if (length == capacity) resize(capacity * 2);
        for (int i = length; i > index; --i) data[i] = data[i - 1];
        data[index] = value;
        ++length;
    }

    void erase(int index) {
        if (index < 0 || index >= length)
            throw std::out_of_range("erase index out of range");
        for (int i = index; i < length - 1; ++i) data[i] = data[i + 1];
        --length;
    }

    T& operator[](int index) {
        if (index < 0 || index >= length)
            throw std::out_of_range("index out of range");
        return data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= length)
            throw std::out_of_range("index out of range");
        return data[index];
    }

    int find(const T& value) const {
        for (int i = 0; i < length; ++i)
            if (data[i] == value) return i;
        return -1;
    }

    void modify(int index, const T& value) {
        if (index < 0 || index >= length)
            throw std::out_of_range("modify index out of range");
        data[index] = value;
    }

    void print() const {
        std::cout << "[";
        for (int i = 0; i < length; ++i) {
            std::cout << data[i];
            if (i != length - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }

private:
    void resize(int newCapacity) {
        T* newData = new T[newCapacity];
        for (int i = 0; i < length; ++i) newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    T* data;
    int capacity;
    int length;
};

int main() {
    SeqList<int> list;

    std::cout << "--- 增 ---" << std::endl;
    for (int i = 0; i < 5; ++i) list.pushBack(i * 10);
    list.insert(2, 99);
    list.print();

    std::cout << "--- 删 ---" << std::endl;
    list.erase(0);
    list.print();

    std::cout << "--- 查 ---" << std::endl;
    std::cout << "find(30) = " << list.find(30) << std::endl;
    std::cout << "list[1] = " << list[1] << std::endl;

    std::cout << "--- 改 ---" << std::endl;
    list.modify(1, 555);
    list.print();

    std::cout << "size = " << list.size() << std::endl;

    return 0;
}
