#include "ProductFactory.h"


    std::shared_ptr<Product> CoffeeFactory::createProduct() const {
        std::string coffeeType;
        double price;

        // ������� ��� � ����������� ��� � ������ �������
        // � ������ �������, ������ ������� ��� ������, ��� ����� ��������������� ���� ������ �����
        std::cout << "Enter coffee type: ";
        std::cin >> coffeeType;

        std::cout << "Enter price: ";
        std::cin >> price;

        return std::make_unique<Coffee>(coffeeType, price);
    };


    std::shared_ptr<Product> TeaFactory::createProduct() const {
        std::string teaType;
        double price;

        // ������� ��� � ����������� ��� � ������ �������
        // � ������ �������, ������ ������� ��� ������, ��� ����� ��������������� ���� ������ �����
        std::cout << "Enter tea type: ";
        std::cin >> teaType;

        std::cout << "Enter price: ";
        std::cin >> price;

        return std::make_unique<Tea>(teaType, price);
    };


    std::shared_ptr<Product> CookieFactory::createProduct() const {
        std::string cookieType;
        double price;

        // ������� ��� � ����������� ��� � ������ �������
        // � ������ �������, ������ ������� ��� ������, ��� ����� ��������������� ���� ������ �����
        std::cout << "Enter cookie type: ";
        std::cin >> cookieType;

        std::cout << "Enter price: ";
        std::cin >> price;

        return std::make_unique<Cookie>(cookieType, price);
    };

    // ��������� ����� ��� ��������� ��'���� Product
    std::shared_ptr<Product> createProduct(const std::string& type) {
        std::shared_ptr<Product> pro;
        if (type == "Coffee") {
            pro = std::make_shared<Coffee>();            
        }
        else if (type == "Tea") {
            pro = std::make_shared<Tea>();
        }
        else if (type == "Cookie") {
            pro = std::make_shared<Cookie>();
        }
        else {
            throw std::runtime_error("Unknown product type");
        }
        
        std::cin >> *pro;
        return pro;
    }