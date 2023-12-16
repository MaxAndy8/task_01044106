#pragma once
#include <iostream>
#include <memory>
#include "Product.h"

class ProductFactory {
public:
    virtual std::shared_ptr<Product> createProduct() const = 0;
    virtual ~ProductFactory() = default;
};

class CoffeeFactory : public ProductFactory {
public:
    std::shared_ptr<Product> createProduct() const override;
};

class TeaFactory : public ProductFactory {
public:
    std::shared_ptr<Product> createProduct() const override;
};

class CookieFactory : public ProductFactory {
public:
    std::shared_ptr<Product> createProduct() const override;
};

// Фабричний метод для створення об'єктів Product
std::shared_ptr<Product> createProduct(const std::string& type);