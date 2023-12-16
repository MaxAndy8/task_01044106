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

class ShopOrder // ����������
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
    // ����������� ���������
	ShopOrder(const ShopOrder& other);
    // ����������� ����������
	ShopOrder(ShopOrder&& other) noexcept;
    // �������� ������������
	ShopOrder& operator=(const ShopOrder& other);
    // �������� ������������ � �����������
	ShopOrder& operator=(ShopOrder&& other) noexcept;

    virtual ~ShopOrder() {
		static int t = 0;
		t++;
	};

	// ��������� ������ �� ����������
	void addItem(std::shared_ptr<Product> pro_ptr, double price, int quantity);
	// ��������� �������� ������� �� ����������
	double getTotalCost() const;
	// ��������� ���������� �� �����
	void displayOrder() const;

	void setMediator(Mediator* med);

	void addDiscountSum(double discSum);
	const std::vector<Item>& getItems() { return items; }

	void setSented(bool sented_) { sented = sented_; }
	void setPaed(bool paed_)     { paed = paed_; }
	
};

// ���������� ��������� << ��� ��������� ����� � ����
std::ostream& operator<<(std::ostream& os, const ShopOrder& order);