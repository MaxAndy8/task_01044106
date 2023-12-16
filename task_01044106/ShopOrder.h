#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "Product.h"
#include "Mediator.h"
//#include "Handler.h"

class Client;
class Mediator;
//class AbstractHandler;

class ShopOrder // Замовлення
{
private:
	struct Item
	{
		std::shared_ptr<Product> product_ptr;
		double price;
		int quantity;

		Item(std::shared_ptr<Product>& pro_ptr, double pri, int qua)
			: product_ptr(pro_ptr), price(pri), quantity(qua)
		{
		}
	};

	int                     number     ;
	std::vector<Item>       items      ;
	std::shared_ptr<Client> client_ptr ;
	Mediator*               mediator   ;
	double                  discountSum = 0.0;
	bool                    sented = false;
	bool                    paed   = false;

public:
	ShopOrder();
    // Конструктор копіювання
	ShopOrder(const ShopOrder& other);
    // Конструктор переміщення
	ShopOrder(ShopOrder&& other) noexcept;
    // Оператор присвоювання
	ShopOrder& operator=(const ShopOrder& other);
    // Оператор присвоювання з переміщенням
	ShopOrder& operator=(ShopOrder&& other) noexcept;

    virtual ~ShopOrder() {
		static int t = 0;
		t++;
	};

	// Додавання товару до замовлення
	void addItem(std::shared_ptr<Product> pro_ptr, double price, int quantity);
	// Отримання загальної вартості за замовлення
	double getTotalCost() const;
	// Виведення замовлення на екран
	void displayOrder() const;

	void setMediator(Mediator* med);

	void addDiscountSum(double discSum);
	const std::vector<Item>& getItems() { return items; }

	void setSented(bool sented_) { sented = sented_; }
	void setPaed(bool paed_)     { paed = paed_; }
	
};

// Перегрузка оператору << для виведення даних в потік
std::ostream& operator<<(std::ostream& os, const ShopOrder& order);