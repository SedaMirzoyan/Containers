
#include <iostream>

class Vector {
private:
    int* ptr;
    int size;

public:
    Vector()
    {
        std::cout << "Default constructor\n";
        size = 0;
        ptr = nullptr;
    }

    Vector(int n)
    {
        std::cout << "Parametrized constructor\n";
        size = n;
        ptr = new int[size];
    }

    ~Vector()
    {
        std::cout << "Destructor\n";
        delete[]ptr;
    }

    Vector(const Vector& ob)
    {
        std::cout << "Copy constructor\n";
        this->size = ob.size;

        this->ptr = new int[size];

        for (int i = 0; i < size; i++)
        {
            this->ptr[i] = ob.ptr[i];
        }
    }

    Vector& operator=(const Vector& ob)
    {
        if (this != &ob)
        {
            std::cout << "Operator assignment\n";
            this->size = ob.size;
            delete[]ptr;

            this->ptr = new int[this->size];

            for (int i = 0; i < size; i++)
            {
                this->ptr[i] = ob.ptr[i];
            }
        }
        return *this;
    }

    int* genElements()
    {
        for (int i = 0; i < size; i++)
        {
            ptr[i] = rand() % 100 + 1;
        }
        return ptr;
    }

    void printVector()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << "element[" << i << "] = " << ptr[i] << std::endl;
        }
    }
};


int main()
{
    int n;
    std::cout << "Enter the number of elements\n";
    std::cin >> n;

    Vector ob(n);
    ob.genElements();
    ob.printVector();

    Vector ob_cp(ob);

    Vector ob1;
    ob1 = ob_cp;

    return 0;
}

