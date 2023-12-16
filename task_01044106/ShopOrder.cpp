#include "ShopOrder.h"
#include <iomanip>

extern std::vector< std::shared_ptr<ShopOrder> >  orders;

ShopOrder::ShopOrder() : mediator(nullptr), client_ptr(nullptr) {
	static int num = 0;
	num++;
	number = num;	
}

// ��������� ������ �� ����������
void ShopOrder::addItem(std::shared_ptr<Product> pro_ptr, double price, int quantity)
{
	items.emplace_back(pro_ptr, price, quantity);
}

// ��������� �������� ������� �� ����������
double ShopOrder::getTotalCost() const
{
	double totalCost = 0.0;
	for (const auto& item : items)
	{
		totalCost += item.price * item.quantity;
	}
	return totalCost;
}

// ��������� ���������� �� �����
void ShopOrder::displayOrder() const
{
	std::cout << "���������� " << number << std::endl;
	std::cout << "�����:" << std::endl;
	for (const auto& item : items)
	{ 
		std::cout << std::left << std::setw(25) << item.product_ptr->presentation();
		std::cout << ", ֳ��: $" << std::fixed << std::setprecision(2) << item.price
			      << ", ʳ������: " << item.quantity << std::endl;
	}
	std::cout << "�������� �������: $" << getTotalCost() << "\n";
	std::cout << "���� ������: $"       << discountSum    << "\n";
	if (sented) {
		std::cout << "³����������."    << "\n";
	} else {
		std::cout << "�� �����������." << "\n";
	}
	if (paed) {
		std::cout << "���������." << "\n";
	}
	else {
		std::cout << "�� ���������." << "\n";
	}
}


// ����������� ���������
ShopOrder::ShopOrder(const ShopOrder& other) : number(other.number), items(other.items), client_ptr(other.client_ptr) {}

// ����������� ����������
ShopOrder::ShopOrder(ShopOrder&& other) noexcept
	: number(std::exchange(other.number, 0)), items(std::move(other.items)), client_ptr(std::move(other.client_ptr)) {}

// �������� ������������
ShopOrder& ShopOrder::operator=(const ShopOrder& other) {
	if (this != &other) {
		number = other.number;
		items = other.items;
		client_ptr = other.client_ptr;
	}
	return *this;
}

// �������� ������������ � �����������
ShopOrder& ShopOrder::operator=(ShopOrder&& other) noexcept {
	if (this != &other) {
		number = std::exchange(other.number, 0);
		items = std::move(other.items);
		client_ptr = std::move(other.client_ptr);
	}
	return *this;
}

void ShopOrder::setMediator(Mediator* med) {
	mediator = med;
}

void ShopOrder::addDiscountSum(double discSum) {
	if (discSum > 0) {
		double totalCost = getTotalCost();

		discountSum += discSum;
		if (discountSum > totalCost) {
			discountSum = totalCost;
		}

	}
}

// ���������� ��������� << ��� ��������� ����� � ����
std::ostream& operator<<(std::ostream& os, const ShopOrder& order) {	
	order.displayOrder();
    os << std::endl;
	return os;
}