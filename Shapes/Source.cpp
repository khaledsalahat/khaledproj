#include <iostream>
#include <string>

using namespace std;

class Shape3D {
protected:
    double side_length;

public:
    Shape3D(double side_length) : side_length(side_length) {}

    virtual double getarea() const = 0;
    virtual double getSurfaceArea() const = 0;
    virtual double getvolume() const = 0;
    virtual bool IsA(const string& type) const = 0;
    virtual void print() const = 0;
    virtual void read() = 0;
};

class Cube : public Shape3D {
public:
    Cube(double side_length) : Shape3D(side_length) {}

    double getarea() const override {
        return side_length * side_length;
    }

    double getSurfaceArea() const override {
        return 6 * side_length * side_length;
    }

    double getvolume() const override {
        return side_length * side_length * side_length;
    }

    bool IsA(const string& type) const override {
        return type == "Cube";
    }

    void print() const override {
        cout << "Cube with side length " << side_length << endl;
    }

    void read() override {
        cout << "Enter side length: ";
        cin >> side_length;
    }
};

class Cone : public Shape3D {
public:
    Cone(double side_length) : Shape3D(side_length) {}

    double getarea() const override {
        return 3.14159 * side_length * side_length;
    }

    double getSurfaceArea() const override {
        return 3.14159 * side_length + 3.14159 * side_length * sqrt(3);
    }

    double getvolume() const override {
        return (1.0 / 3) * 3.14159 * side_length * side_length * side_length;
    }

    bool IsA(const string& type) const override {
        return type == "Cone";
    }

    void print() const override {
        cout << "Cone with side length " << side_length << endl;
    }

    void read() override {
        cout << "Enter side length: ";
        cin >> side_length;
    }
};

class Pyramid : public Shape3D {
public:
    Pyramid(double side_length) : Shape3D(side_length) {}

    double getarea() const override {
        return 4 * 3.14159 * side_length * side_length / 2;
    }

    double getSurfaceArea() const override {
        return 4 * 3.14159 * side_length * side_length / 2 + 3.14159 * side_length * sqrt(2);
    }

    double getvolume() const override {
        return (1.0 / 3) * 3.14159 * side_length * side_length * side_length;
    }

    bool IsA(const string& type) const override {
        return type == "Pyramid";
    }

    void print() const override {
        cout << "Pyramid with side length " << side_length << endl;
    }

    void read() override {
        cout << "Enter side length: ";
        cin >> side_length;
    }
};

class Cuboid : public Shape3D {
public:
    Cuboid(double side_length) : Shape3D(side_length) {}

    double getarea() const override {
        return 4 * side_length * side_length;
    }

    double getSurfaceArea() const override {
        return 6 * side_length * side_length;
    }

    double getvolume() const override {
        return side_length * side_length * side_length;
    }

    bool IsA(const string& type) const override {
        return type == "Cuboid";
    }

    void print() const override {
        cout << "Cuboid with side length " << side_length << endl;
    }

    void read() override {
        cout << "Enter side length: ";
        cin >> side_length;
    }
};

class Sphere : public Shape3D {
public:
    Sphere(double side_length) : Shape3D(side_length) {}

    double getarea() const override {
        return 4 * 3.14159 * side_length * side_length;
    }

    double getSurfaceArea() const override {
        return 4 * 3.14159 * side_length * side_length;
    }

    double getvolume() const override {
        return (4.0 / 3) * 3.14159 * side_length * side_length * side_length;
    }

    bool IsA(const string& type) const override {
        return type == "Sphere";
    }

    void print() const override {
        cout << "Sphere with side length " << side_length << endl;
    }

    void read() override {
        cout << "Enter side length: ";
        cin >> side_length;
    }
};

class Cylinder : public Shape3D {
public:
    Cylinder(double side_length) : Shape3D(side_length) {}

    double getarea() const override {
        return 2 * 3.14159 * side_length * side_length;
    }

    double getSurfaceArea() const override {
        return 2 * 3.14159 * side_length * side_length + 2 * 3.14159 * side_length;
    }

    double getvolume() const override {
        return 3.14159 * side_length * side_length * side_length;
    }

    bool IsA(const string& type) const override {
        return type == "Cylinder";
    }

    void print() const override {
        cout << "Cylinder with side length " << side_length << endl;
    }

    void read() override {
        cout << "Enter side length: ";
        cin >> side_length;
    }
};

void ReadInfo(Shape3D* shapes[], int count) {
    int i = 0;
    if (count == 0) {
        cout << "The list is empty please add a shape then read its value" << endl;
        return;
    }
    for (i = 0; i < count; i++) {
        cout << "Enter information for Shape " << i + 1 << ":\n";
        shapes[i]->read();
        cout << endl;
    }
}

void printInfo(Shape3D* shapes[], int count) {
    for (int i = 0; i < count; i++) {
        cout << "Information for Shape " << i + 1 << ":\n";
        shapes[i]->print();
        cout << "Surface Area: " << shapes[i]->getSurfaceArea() << endl;
        cout << "Volume: " << shapes[i]->getvolume() << endl;
        cout << "--------------------------\n";
    }
}

bool SortSurface(const Shape3D* a, const Shape3D* b) {
    return a->getSurfaceArea() < b->getSurfaceArea();
}

Shape3D* Min(Shape3D* shapes[], int count) {
    Shape3D* minVolumeShape = shapes[0];
    for (int i = 1; i < count; i++) {
        if (shapes[i]->getvolume() < minVolumeShape->getvolume()) {
            minVolumeShape = shapes[i];
        }
    }
    return minVolumeShape;
}

Shape3D* Max(Shape3D* shapes[], int count) {
    Shape3D* maxVolumeShape = shapes[0];
    for (int i = 1; i < count; i++) {
        if (shapes[i]->getvolume() > maxVolumeShape->getvolume()) {
            maxVolumeShape = shapes[i];
        }
    }
    return maxVolumeShape;
}

void Add(Shape3D* shapes[], int& count, Shape3D* newShape) {
    if (count < 10) {
        shapes[count] = newShape;
        count++;
        cout << "Shape added successfully\n";
    }
    else {
        cout << "Cannot add more shapes the list is full.\n";
    }
}

void Delete(Shape3D* shapes[], int& count, int index) {
    if (index >= 0 && index < count) {
        delete shapes[index];
        for (int i = index; i < count - 1; i++) {
            shapes[i] = shapes[i + 1];
        }
        count--;
        cout << "Shape deleted successfully\n";
    }
    else {
        cout << "Invalid index\n";
    }
}

int main() {
    Shape3D* shapes[10];
    int shapeCount = 0;

    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Read information for every object\n";
        cout << "2. Print information for every object\n";
        cout << "3. Sort based on surface area\n";
        cout << "4. Find objects with min and max volume\n";
        cout << "5. Add an object to the array\n";
        cout << "6. Delete an object from the array\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ReadInfo(shapes, shapeCount);
            break;
        case 2:
            printInfo(shapes, shapeCount);
            break;
        case 3:
            for (int i = 0; i < shapeCount - 1; i++) {
                int minIndex = i;
                for (int j = i + 1; j < shapeCount; j++) {
                    if (SortSurface(shapes[j], shapes[minIndex])) {
                        minIndex = j;
                    }
                }
                if (minIndex != i) {
                    Shape3D* temp = shapes[i];
                    shapes[i] = shapes[minIndex];
                    shapes[minIndex] = temp;
                }
            }

            cout << "Shapes sorted by surface area\n";
            printInfo(shapes, shapeCount);
            break;
        case 4:
            if (shapeCount > 0) {
                Shape3D* minVolume = Min(shapes, shapeCount);
                Shape3D* maxVolume = Max(shapes, shapeCount);
                cout << "Shape with minimum volume:\n";
                minVolume->print();
                cout << "Volume: " << minVolume->getvolume() << endl;
                cout << "Shape with maximum volume:\n";
                maxVolume->print();
                cout << "Volume: " << maxVolume->getvolume() << endl;
            }
            else {
                cout << "No shapes in the list\n";
            }
            break;
        case 5:
            if (shapeCount < 10) {
                int shapeType;
                cout << "Select the shape to add:\n";
                cout << "1. Cube\n";
                cout << "2. Cone\n";
                cout << "3. Pyramid\n";
                cout << "4. Cuboid\n";
                cout << "5. Sphere\n";
                cout << "6. Cylinder\n";

                cin >> shapeType;
                Shape3D* newShape = nullptr;

                if (shapeType == 1) {
                    newShape = new Cube(0);
                }
                else if (shapeType == 2) {
                    newShape = new Cone(0);
                }
                else if (shapeType == 3) {
                    newShape = new Pyramid(0);
                }
                else if (shapeType == 4) {
                    newShape = new Cuboid(0);
                }
                else if (shapeType == 5) {
                    newShape = new Sphere(0);
                }
                else if (shapeType == 6) {
                    newShape = new Cylinder(0);
                }
                else {
                    cout << "Invalid shape type\n";
                }

                if (newShape != nullptr) {
                    Add(shapes, shapeCount, newShape);
                }
            }
            else {
                cout << "Cannot add more shapes. The list is already full\n";
            }
            break;
        case 6:
            int index;
            cout << "Enter the index of the shape to delete: ";
            cin >> index;
            Delete(shapes, shapeCount, index);
            break;
        case 0:
            cout << "Exit\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
