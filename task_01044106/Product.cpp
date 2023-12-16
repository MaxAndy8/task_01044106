#include "Product.h"
#include <limits>

// Реалізація Product

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
    std::cout << "Введіть назву продукту: ";
    do {        
        std::getline(is, name);

        // Перевірка, чи введено непорожню назву
        if (name.empty() && !first) {
            std::cout << "Назва продукту не може бути порожньою. Будь ласка, введіть ще раз." << std::endl;
        }
        first = false;
    } while (name.empty());

    // Введення ціни товару
    std::cout << "Введіть ціну товару: ";
    is >> price;

    // Перевірка на коректність вводу ціни
    while (is.fail() || price < 0) {
        std::cout << "Невірне введення. Введіть правильну ціну: ";
        is.clear(); // Скидання прапорців помилок
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищення буфера введення
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

// Реалізації для Coffee, Tea, Cookie
//------------------------------------------------------------------------------------
Coffee::Coffee(const std::string& coffeeType, double price)
    : Product("Кава", price), coffeeType(coffeeType) {}

std::string Coffee::presentation() const {
    return name + ": " + coffeeType;    
}

void Coffee::input(std::istream& is) { 
    bool first = true;
    std::cout << "Введіть тип кави: ";
    do {        
        std::getline(is, coffeeType);

        // Перевірка, чи введено непорожню назву
        if (coffeeType.empty() && !first) {
            std::cout << "Тип не може бути порожній. Будь ласка, введіть ще раз." << std::endl;
        }
        first = false;
    } while (coffeeType.empty());

    std::cout << "Введіть ціну товару: ";
    is >> price;

    // Перевірка на коректність вводу ціни
    while (is.fail() || price < 0) {
        std::cout << "Невірне введення. Введіть правильну ціну:";
        is.clear(); // Скидання прапорців помилок
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищення буфера введення
        is >> price;
    }
}
//------------------------------------------------------------------------------------

Tea::Tea(const std::string& teaType, double price)
    : Product("Чай", price), teaType(teaType) {}

std::string Tea::presentation() const {
    return name + ": " + teaType;
}

void Tea::input(std::istream& is) {
    bool first = true;
    std::cout << "Введіть тип чаю: ";
    do {        
        std::getline(is, teaType);

        // Перевірка, чи введено непорожню назву
        if (teaType.empty() && !first) {
            std::cout << "Тип не може бути порожній. Будь ласка, введіть ще раз." << std::endl;
        }
        first = false;
    } while (teaType.empty());

    std::cout << "Введіть ціну товару: ";
    is >> price;

    // Перевірка на коректність вводу ціни
    while (is.fail() || price < 0) {
        std::cout << "Невірне введення. Введіть правильну ціну:";
        is.clear(); // Скидання прапорців помилок
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищення буфера введення
        is >> price;
    }
}
//------------------------------------------------------------------------------------
Cookie::Cookie(const std::string& cookieType, double price)
    : Product("Печево", price), cookieType(cookieType) {}

std::string Cookie::presentation() const {
    return name + ": " + cookieType;    
}

void Cookie::input(std::istream& is) {
    bool first = true;
    std::cout << "Введіть тип печева: ";
    do {        
        std::getline(is, cookieType);

        // Перевірка, чи введено непорожню назву
        if (cookieType.empty() && !first) {

            std::cout << "Тип не може бути порожній. Будь ласка, введіть ще раз." << std::endl;
        }
        first = false;
    } while (cookieType.empty());

    std::cout << "Введіть ціну товару: ";
    is >> price;

    // Перевірка на коректність вводу ціни
    while (is.fail() || price < 0) {
        std::cout << "Невірне введення. Введіть правильну ціну:";
        is.clear(); // Скидання прапорців помилок
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищення буфера введення
        is >> price;
    }
}


// + " Ціна: " + std::to_string(price)