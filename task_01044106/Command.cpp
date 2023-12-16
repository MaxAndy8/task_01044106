#include "Command.h"
#include "MenuState.h"
#include "ShopOrder.h"

/**
 * Вивести список замовлень
 */
PrintOrdersCommand::PrintOrdersCommand() {
}

void PrintOrdersCommand::Execute() const {

	for (const auto& order : orders) {
		std::cout << *order << std::endl;
	}

}

/**
 * Для замовлення "Сніданок комплексний №1"
 */
OrderBreakfast1Command::OrderBreakfast1Command() {
}

void OrderBreakfast1Command::Execute() const {

	std::string produkt_name = "Сніданок комплексний №1";

	std::shared_ptr<Product> prod1;
	for (const auto& product : products) {
		std::string curren_name = product->getName();
		if (curren_name == produkt_name) {
			prod1 = product;
		}
	}

	if (!prod1) {
		prod1 = std::make_shared<Product>(produkt_name, 170);
		products.push_back(prod1);
	}

	ShopOrder* order = new ShopOrder();
	order->addItem(prod1, prod1->getPrice(), 1);
	orders.push_back(std::shared_ptr<ShopOrder>(order));

	std::cout << *order << std::endl;

}

/**
 * Для замовлення "Сніданок комплексний №2"
 */
OrderBreakfast2Command::OrderBreakfast2Command() {
}

void OrderBreakfast2Command::Execute() const {

	std::string produkt_name = "Сніданок комплексний №2";

	std::shared_ptr<Product> prod1;
	for (const auto& product : products) {
		std::string curren_name = product->getName();
		if (curren_name == produkt_name) {
			prod1 = product;
		}
	}

	if (!prod1) {
		prod1 = std::make_shared<Product>(produkt_name, 180);
		products.push_back(prod1);
	}

	


	ShopOrder* order = new ShopOrder();
	order->addItem(prod1, prod1->getPrice(), 1);
    orders.push_back( std::shared_ptr<ShopOrder>(order) );

	std::cout << *order << std::endl;

}


