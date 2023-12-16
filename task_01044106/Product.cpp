#include "Product.h"
#include <limits>

// ��������� Product

Product::Product(const std::string& name, double price)
    : name(name), price(price) {}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

void Product::input(std::istream& is) {
    bool first = true;
    std::cout << "������ ����� ��������: ";
    do {        
        std::getline(is, name);

        // ��������, �� ������� ��������� �����
        if (name.empty() && !first) {
            std::cout << "����� �������� �� ���� ���� ���������. ���� �����, ������ �� ���." << std::endl;
        }
        first = false;
    } while (name.empty());

    // �������� ���� ������
    std::cout << "������ ���� ������: ";
    is >> price;

    // �������� �� ���������� ����� ����
    while (is.fail() || price < 0) {
        std::cout << "������ ��������. ������ ��������� ����: ";
        is.clear(); // �������� ��������� �������
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �������� ������ ��������
        is >> price;
    }
}



std::string Product::presentation() const {
    return name;
}

std::ostream& operator<<(std::ostream& os, const Product& product) {
    os << product.presentation();
    return os;
}

std::istream& operator>>(std::istream& is, Product& product) {
    product.input(is);
    return is;
}

// ��������� ��� Coffee, Tea, Cookie
//------------------------------------------------------------------------------------
Coffee::Coffee(const std::string& coffeeType, double price)
    : Product("����", price), coffeeType(coffeeType) {}

std::string Coffee::presentation() const {
    return name + ": " + coffeeType;    
}

void Coffee::input(std::istream& is) { 
    bool first = true;
    std::cout << "������ ��� ����: ";
    do {        
        std::getline(is, coffeeType);

        // ��������, �� ������� ��������� �����
        if (coffeeType.empty() && !first) {
            std::cout << "��� �� ���� ���� �������. ���� �����, ������ �� ���." << std::endl;
        }
        first = false;
    } while (coffeeType.empty());

    std::cout << "������ ���� ������: ";
    is >> price;

    // �������� �� ���������� ����� ����
    while (is.fail() || price < 0) {
        std::cout << "������ ��������. ������ ��������� ����:";
        is.clear(); // �������� ��������� �������
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �������� ������ ��������
        is >> price;
    }
}
//------------------------------------------------------------------------------------

Tea::Tea(const std::string& teaType, double price)
    : Product("���", price), teaType(teaType) {}

std::string Tea::presentation() const {
    return name + ": " + teaType;
}

void Tea::input(std::istream& is) {
    bool first = true;
    std::cout << "������ ��� ���: ";
    do {        
        std::getline(is, teaType);

        // ��������, �� ������� ��������� �����
        if (teaType.empty() && !first) {
            std::cout << "��� �� ���� ���� �������. ���� �����, ������ �� ���." << std::endl;
        }
        first = false;
    } while (teaType.empty());

    std::cout << "������ ���� ������: ";
    is >> price;

    // �������� �� ���������� ����� ����
    while (is.fail() || price < 0) {
        std::cout << "������ ��������. ������ ��������� ����:";
        is.clear(); // �������� ��������� �������
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �������� ������ ��������
        is >> price;
    }
}
//------------------------------------------------------------------------------------
Cookie::Cookie(const std::string& cookieType, double price)
    : Product("������", price), cookieType(cookieType) {}

std::string Cookie::presentation() const {
    return name + ": " + cookieType;    
}

void Cookie::input(std::istream& is) {
    bool first = true;
    std::cout << "������ ��� ������: ";
    do {        
        std::getline(is, cookieType);

        // ��������, �� ������� ��������� �����
        if (cookieType.empty() && !first) {

            std::cout << "��� �� ���� ���� �������. ���� �����, ������ �� ���." << std::endl;
        }
        first = false;
    } while (cookieType.empty());

    std::cout << "������ ���� ������: ";
    is >> price;

    // �������� �� ���������� ����� ����
    while (is.fail() || price < 0) {
        std::cout << "������ ��������. ������ ��������� ����:";
        is.clear(); // �������� ��������� �������
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �������� ������ ��������
        is >> price;
    }
}


// + " ֳ��: " + std::to_string(price)