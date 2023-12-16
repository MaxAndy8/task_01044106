#pragma once
#include <iostream>
#include <string>

class Product {
public:
    Product(const std::string& name, double price);
    virtual ~Product() = default;

    std::string getName() const;
    double getPrice() const;

    virtual void input(std::istream& is);
    virtual std::string presentation() const;  // Метод для виводу деталей продукту

    //friend std::ostream& operator<<(std::ostream& os, const Product& product);

protected:
    std::string name;
    double price;
};

// Перегрузка оператору << для виведення даних в потік
std::ostream& operator<<(std::ostream& os, const Product& product);
// Перегрузка оператору >> для введення даних з потоку
std::istream& operator>>(std::istream& is, Product& product);

class Coffee : public Product {
public:
    Coffee(const std::string& coffeeType = "", double price = 0);
    std::string presentation() const override;
    void input(std::istream& is) override;
private:
    std::string coffeeType;
};

class Tea : public Product {
public:
    Tea(const std::string& teaType = "", double price = 0);
    std::string presentation() const override;
    void input(std::istream& is) override;
private:
    std::string teaType;
};

class Cookie : public Product {
public:
    Cookie(const std::string& cookieType = "", double price = 0);
    std::string presentation() const override;
    void input(std::istream& is) override;
private:
    std::string cookieType;
};

