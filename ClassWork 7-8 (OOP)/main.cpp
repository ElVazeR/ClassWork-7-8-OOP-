#include <iostream>

class Point {
public:
	double x;
	double y;
	Point() : Point(.0, .0) {}
	Point(double x, double y) :x(x), y(y) {}
	Point(const Point& oP) : Point(oP.x, oP.y) {}
	void print() const {
		std::cout << '(' << x << "; " << y << ")\n";
	}

	double distanceTo(const Point oP) const {
		return sqrt(
			pow(oP.x - x, 2) +
			pow(oP.y - y, 2)
		);
	}

	Point operator+(double num) const {
		return Point(x + num, y + num);
	}

	Point operator+(const Point oP) const {
		return Point(x + oP.x, y + oP.y);
	}

	Point& operator++()  {
		++x; ++y;
		return *this;
	}
	
	Point operator++(int) {
		Point tmp = *this;
		++x; ++y;
		return tmp;
	}

	bool operator==(const Point oP) {
		return x == oP.x && y == oP.y;
	}
	bool operator!=(const Point oP) {
		return x != oP.x || y != oP.y;
		//return !(*this == oP); Хороший вариант.
	}
	bool operator>(const Point oP) {
		return distanceTo(Point(0., 0.)) > oP.distanceTo(Point(0., 0.));
	}

	bool operator<(const Point oP) {
		return distanceTo(Point(0., 0.)) < oP.distanceTo(Point(0., 0.));
	}
};

class Array {
private:
	int* pointer;
	size_t length;
public:
	Array() : pointer(nullptr), length(0){}
	Array(size_t length) {
		if (length == 0) {
			this->pointer = nullptr;
			this->length = 0;
			return;
		}
		this->pointer = new int[length]{};
		this->length = length;
	}
	Array(const Array& other) {
		length = other.length;
		if (other.pointer == nullptr) {
			pointer = nullptr;
			return;
		 }
		pointer = new int[length];
		for (size_t i = 0; i < length; ++i)
			pointer[i] = other[i];
		
	}
	~Array() {
		delete[] pointer;
	}

	void app(int num) {
		if (pointer == nullptr) {
			pointer = new int[1] {num};
			length = 1;
			return;
		}
		
			int* tmp = new int[length + 1];
			for (size_t i = 0; i < length ; ++i) {
				tmp[i] = pointer[i];
			tmp[length] = num;
			
			delete[] pointer;
			pointer = tmp;
			++length;
		}
	}
	size_t size() const { return length; }

	int& operator[](size_t index)  {
		//if (index >= length)
			//throw "Error";
		return pointer[index];
	}
	int operator[](size_t index) const {
		return pointer[index];
	}
	void operator=(const Array& other) {
		delete[] pointer;
		length = other.length;
		if (other.pointer == nullptr) {
			pointer = nullptr;
			return;
		}
		pointer = new int[length];
		for (size_t i = 0; i < length; ++i)
			pointer[i] = other[i];
	}
};


int main() {
	setlocale(LC_ALL, "Russian");

	// Перегрузка базовых операторов
	/*Point p1(4, 5), p2(8, 10);
	p1.print();
	p2.print();
	(p1 + 1).print();
	(p1 + p2).print();
	Point p3(2, 1);
	(++p3).print();
	(p3++).print();
	p3.print();

	if (p1 > p2)
		std::cout << "Первая точка дальше!\n";
	else
		std::cout << "Первая точка не дальше!\n";*/


	Array arr1(3);
	Array arr2;
	for (size_t i = 0; i < arr1.size(); ++i)
		arr1[i] = (i + 1) * 10;
	
	std::cout << "Массив 1:\n";
	for (size_t i = 0; i < arr1.size(); ++i)
		std::cout << arr1[i] << ' ';
	std::cout << std::endl;

	Array arr3 = arr1;
	std::cout << "Массив 3:\n";
	for (size_t i = 0; i < arr3.size(); ++i)
		std::cout << arr3[i] << ' ';
	std::cout << std::endl;

	arr3[1] = 100;
	std::cout << "--------------------------\n";

	std::cout << "Массив 1:\n";
	for (size_t i = 0; i < arr1.size(); ++i)
		std::cout << arr1[i] << ' ';
	std::cout << std::endl;

	
	std::cout << "Массив 3:\n";
	for (size_t i = 0; i < arr3.size(); ++i)
		std::cout << arr3[i] << ' ';
	std::cout << std::endl;

	std::cout << "--------------------------\n";
	arr2 = arr1;
	arr1[1] = 100;

	std::cout << "Массив 2:\n";
	for (size_t i = 0; i < arr2.size(); ++i)
		std::cout << arr2[i] << ' ';
	std::cout << std::endl;

	return  0;
}