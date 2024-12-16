#include <iostream>
using namespace std;

class Cuboid {
private:
    double length, width, height;
    double volume, lateralSurfArea, perimeter, diagonal, totSurfArea, baseArea;

public:

    Cuboid(double l, double w, double h) : length(l), width(w), height(h) {
        compute();
    }

    Cuboid(const Cuboid& c) : length(c.length), width(c.width), height(c.height) {
        compute();
    }

    ~Cuboid() {}

    double getVolume() const { return volume; }
    double getLateralSurfaceArea() const { return lateralSurfArea; }
    double getPerimeter() const { return perimeter; }
    double getDiagonal() const { return diagonal; }
    double getTotalSurfaceArea() const { return totSurfArea; }
    double getBaseArea() const { return baseArea; }

    friend ostream& operator<<(ostream& out, const Cuboid& c);

    friend istream& operator>>(istream& in, Cuboid& c);

private:
    void compute() {
        volume = length * width * height;
        lateralSurfArea = 2 * (length * width + width * height + height * length);
        perimeter = 4 * (length + width + height);
        diagonal = sqrt(length * length + width * width + height * height);
        totSurfArea = 2 * (length * width + width * height + height * length);
        baseArea = length * width;
    }
};

istream& operator>>(istream& in, Cuboid& c) {
    cout << "Enter length, width, height: ";
    in >> c.length >> c.width >> c.height;
    c.compute();
    return in;
}

ostream& operator<<(ostream& out, const Cuboid& c) {
    out << "\nVolume: " << c.volume;
    out << "\nLateral Surface Area: " << c.lateralSurfArea;
    out << "\nPerimeter: " << c.perimeter;
    out << "\nDiagonal: " << c.diagonal;
    out << "\nTotal Surface Area: " << c.totSurfArea;
    out << "\nBase Area: " << c.baseArea << endl;
    return out;
}
class Node {
public:
    Cuboid cuboid;
    Node* next;
    Node(const Cuboid& c, Node* n = nullptr) : cuboid(c), next(n) {}
};

class CuboidList{
private:
    Node* head;
public:
    CuboidList() : head(nullptr) {}
    ~CuboidList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(const Cuboid& c) {
        Node* temp = new Node(c);
        if (head == nullptr || head->cuboid.getVolume() > c.getVolume()) {
            temp->next = head;
            head = temp;
        }
        else {
            Node* prev = head;
            Node* current = head->next;
            while (current != nullptr && current->cuboid.getVolume() < c.getVolume()) {
                prev = current;
                current = current->next;
            }
            temp->next = current;
            prev->next = temp;
        }
    }

    void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->cuboid;
            temp = temp->next;
        }
    }

    Cuboid* search(double volume) const {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->cuboid.getVolume() == volume)
                return &(temp->cuboid);
            temp = temp->next;
        }
        return nullptr;
    }

    void deleteCuboid(double volume) {
        if (head == nullptr)
            return;

        if (head->cuboid.getVolume() == volume) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = head;
        Node* current = head->next;
        while (current != nullptr && current->cuboid.getVolume() != volume) {
            prev = current;
            current = current->next;
        }

        if (current != nullptr) {
            prev->next = current->next;
            delete current;
        }
    }

    double AvgVolume() const {
        if (head == nullptr) {
            return 0;
        }

        double sum = 0;
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            sum += temp->cuboid.getVolume();
            count++;
            temp = temp->next;
        }

        return sum / count;
    }
};

int main() {
    int numCuboids;
    cout << "Enter the number of cuboids: ";
    cin >> numCuboids;

    CuboidList cuboid;

    for (int i = 0; i < numCuboids; i++) {
        double length, width, height;

        cout << "Enter dimensions for cuboid " << i + 1 << " (length width height): ";
        cin >> length >> width >> height;

        Cuboid c(length, width, height);
        cuboid.insert(c);
    }

    cout << "Cuboid List: " << endl;
    cuboid.display();

    double averageVolume = cuboid.AvgVolume();
    cout << "\nAverage Volume: " << averageVolume << endl;

    int searchVol;
    cout << "\nenter the volume of the item you want to search :";
    cin >> searchVol;
    cout << "\nsearching for cuboid with volume :"<<searchVol;
    Cuboid* result = cuboid.search(searchVol);
    if (result != nullptr)
        cout << *result;
    else
        cout << "\ndoesnt exist";

    return 0;
}
