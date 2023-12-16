#include "ShopOrder.h"
#include <iomanip>

extern std::vector< std::shared_ptr<ShopOrder> >  orders;

ShopOrder::ShopOrder() : mediator(nullptr), client_ptr(nullptr) {
	static int num = 0;
	num++;
	number = num;	
}

// Додавання товару до замовлення
void ShopOrder::addItem(std::shared_ptr<Product> pro_ptr, double price, int quantity)
{
	items.emplace_back(pro_ptr, price, quantity);
}

// Отримання загальної вартості за замовлення
double ShopOrder::getTotalCost() const
{
	double totalCost = 0.0;
	for (const auto& item : items)
	{
		totalCost += item.price * item.quantity;
	}
	return totalCost;
}

// Виведення замовлення на екран
void ShopOrder::displayOrder() const
{
	std::cout << "Замовлення " << number << std::endl;
	std::cout << "Деталі:" << std::endl;
	for (const auto& item : items)
	{ 
		std::cout << std::left << std::setw(25) << item.product_ptr->presentation();
		std::cout << ", Ціна: $" << std::fixed << std::setprecision(2) << item.price
			      << ", Кількість: " << item.quantity << std::endl;
	}
	std::cout << "Загальна вартість: $" << getTotalCost() << "\n";
	std::cout << "Сума знижки: $"       << discountSum    << "\n";
	if (sented) {
		std::cout << "Відправлений."    << "\n";
	} else {
		std::cout << "Не відправлений." << "\n";
	}
	if (paed) {
		std::cout << "Оплачений." << "\n";
	}
	else {
		std::cout << "Не оплачений." << "\n";
	}
}


// Конструктор копіювання
ShopOrder::ShopOrder(const ShopOrder& other) : number(other.number), items(other.items), client_ptr(other.client_ptr) {}

// Конструктор переміщення
ShopOrder::ShopOrder(ShopOrder&& other) noexcept
	: number(std::exchange(other.number, 0)), items(std::move(other.items)), client_ptr(std::move(other.client_ptr)) {}

// Оператор присвоювання
ShopOrder& ShopOrder::operator=(const ShopOrder& other) {
	if (this != &other) {
		number = other.number;
		items = other.items;
		client_ptr = other.client_ptr;
	}
	return *this;
}

// Оператор присвоювання з переміщенням
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

// Перегрузка оператору << для виведення даних в потік
std::ostream& operator<<(std::ostream& os, const ShopOrder& order) {	
	order.displayOrder();
    os << std::endl;
	return os;
}