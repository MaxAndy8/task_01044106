#include "MenuState.h"
#include "Command.h"
#include "Handler.h"
#include <iostream>

// Визначення глобальних змінних
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
std::vector< std::shared_ptr<Product> >   products ;
std::vector< std::shared_ptr<Client> >    clients  ;
std::vector< std::shared_ptr<Mediator> >  mediators;
std::vector< std::shared_ptr<ShopOrder> > orders   ;

void GoToXY(short x, short y) {
	SetConsoleCursorPosition(hStdOut, { x, y });
}

void ConsoleCursorVisible(bool show, short size) {
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;
	structCursorInfo.dwSize = size;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

MenuState* MainMenuState::handleInput(char input) {
	switch (input) {
	case UP:
		if (activeItem > 0)
			activeItem--;
		break;
	case DOWN:
		if (activeItem < menuItems.size() - 1)
			activeItem++;
		break;
	case ENTER:
		if (activeItem == 0) {
			return new ProductsCreationMenuState();
		}
		if (activeItem == 1) {
			return new ClientMenuState();
		}
		if (activeItem == 2) {
			return new OrderMenuState();
		}
		if (activeItem == 3) {
			return new DiscountMenuState();
		}
		if (activeItem == 4) {
			return new SendPayMenuState();
		}
		if (activeItem == 5) {			

			exit(0);
		}
		// Check if the selected menu item has a submenu
		if (activeItem < menuItems.size()) {
			//stateStack.push(subMenus[activeItem]); // Push the submenu onto the stack
			//return subMenus[activeItem];
		}
		break;
	}
	return this;
}

MenuState* ProductsCreationMenuState::handleInput(char input) {

	auto clearInputBuffer = []() {
		char ch;
		do {
			ch = _getch();
		} while (ch == EOF || ch == 0);
	};

	switch (input) {
	case UP:
		if (activeItem > 0)
			activeItem--;
		break;
	case DOWN:
		if (activeItem < menuItems.size() - 1)
			activeItem++;
		break;
	case ENTER:
		if (activeItem == 0) {
			system("CLS");
			//std::cin.ignore();

			products.push_back(createProduct("Coffee"));

			std::cout << "Натисніть будь-яку клавішу для продовження..." << std::endl;
			clearInputBuffer();

			system("CLS");
		}
		if (activeItem == 1) {
			system("CLS");

			products.push_back(createProduct("Tea"));

			std::cout << "Натисніть будь-яку клавішу для продовження..." << std::endl;
			clearInputBuffer();

			system("CLS");
		}
		if (activeItem == 2) {
			system("CLS");
			//clearInputBuffer();  // Очистити буфер введення            
			
			products.push_back(createProduct("Cookie"));

			std::cout << "Натисніть будь-яку клавішу для продовження..." << std::endl;
			clearInputBuffer();

			system("CLS");
		}
		if (activeItem == 3) {
			system("CLS");
			//clearInputBuffer();  // Очистити буфер введення            

			// Виведення даних про продукти
			for (const auto& product : products) {
				std::cout << *product << std::endl;
			}

			std::cout << "Натисніть будь-яку клавішу для продовження..." << std::endl;
			clearInputBuffer();

			system("CLS");
		}

		if (activeItem == 4) {
			return new MainMenuState();
		}

		break;
	}
	return this;
}

MenuState* ClientMenuState::handleInput(char input) {

	auto clearInputBuffer = []() {
		char ch;
		do {
			ch = _getch();
		} while (ch == EOF || ch == 0);
	};

	switch (input) {
	case UP:
		if (activeItem > 0)
			activeItem--;
		break;
	case DOWN:
		if (activeItem < menuItems.size() - 1)
			activeItem++;
		break;
	case ENTER:
		// "1. Заповнити початкові дані клієнтів та їх замовлень",
		if (activeItem == 0) {
			system("CLS");

			std::shared_ptr<Product> prod1 = std::make_shared<Coffee>("Еспресо 40 мл", 40);
			products.push_back(prod1);

			std::shared_ptr<Product> prod2 = std::make_shared<Coffee>("Рістретто 20 мл", 40);
			products.push_back(prod2);

			std::shared_ptr<Product> prod3 = std::make_shared<Coffee>("Американо 120 мл", 40);
			products.push_back(prod3);

			std::shared_ptr<Product> prod4 = std::make_shared<Coffee>("Капучіно 180 мл", 53);
			products.push_back(prod4);

			std::shared_ptr<Product> prod5 = std::make_shared<Coffee>("Латте 200 мл", 60);
			products.push_back(prod5);

			std::shared_ptr<Product> prod6 = std::make_shared<Tea>("Чай листовий 300 мл", 50);
			products.push_back(prod6);

			std::shared_ptr<Product> prod7 = std::make_shared<Tea>("Чай листовий 500 мл", 70);
			products.push_back(prod7);

			{
				std::shared_ptr<Client> client = std::make_shared<Client>("Петро");
				clients.push_back(client);

				std::shared_ptr<ShopOrder> order = std::make_shared<ShopOrder>();
				orders.push_back(order);

				std::shared_ptr<Mediator> mediator = std::make_shared<Mediator>(client, order);
				mediators.push_back(mediator);
				

				mediator->addProduct(prod1, 1);
				mediator->addProduct(prod2, 2);
				mediator->addProduct(prod3, 3);
				mediator->addProduct(prod4, 1);
				mediator->addProduct(prod5, 1);
			}
			{
				std::shared_ptr<Client> client = std::make_shared<Client>("Марія");
				clients.push_back(client);

				std::shared_ptr<ShopOrder> order = std::make_shared<ShopOrder>();
				orders.push_back(order);

				std::shared_ptr<Mediator> mediator = std::make_shared<Mediator>(client, order);
				mediators.push_back(mediator);

				mediator->addProduct(prod6, 2);
				mediator->addProduct(prod7, 3);
				mediator->addProduct(prod4, 1);
				mediator->addProduct(prod5, 1);
			}


			std::cout << "Натисніть будь-яку клавішу для продовження..." << std::endl;
			clearInputBuffer();

			system("CLS");
		}
		// "2. Створити клієнта",
		if (activeItem == 1) {
			system("CLS");
			//std::cin.ignore();
			std::shared_ptr<Client> client = std::make_shared<Client>();

			std::cin >> *client;

			clients.push_back(client);

			std::cout << "Натисніть будь-яку клавішу для продовження..." << std::endl;
			clearInputBuffer();

			system("CLS");
		}
		// "3. Вивести список клієнтів та їх замовлення",
		if (activeItem == 2) {
			system("CLS");
			// Очищуємо буфер введення
			//std::cin.ignore();

			// Виведення даних про продукти
			for (const auto& client : clients) {
				std::cout << *client << std::endl;
			}

			std::cout << "Натисніть будь-яку клавішу для продовження..." << std::endl;
			clearInputBuffer();

			system("CLS");
		}
		// "4. Повернутися назад"
		if (activeItem == 3) {
			return new MainMenuState();
		}

		break;
	}
	return this;
}

MenuState* OrderMenuState::handleInput(char input) {

	auto clearInputBuffer = []() {
		char ch;
		do {
			ch = _getch();
		} while (ch == EOF || ch == 0);
	};

	switch (input) {
	case UP:
		if (activeItem > 0)
			activeItem--;
		break;
	case DOWN:
		if (activeItem < menuItems.size() - 1)
			activeItem++;
		break;
	case ENTER:
		if (activeItem == 0) {
			system("CLS");

			OrderBreakfast1Command command;
			command.Execute();

			std::cout << "Натисніть будь-яку клавішу для продовження..." << std::endl;
			clearInputBuffer();

			system("CLS");
		}
		if (activeItem == 1) {
			system("CLS");
			
			OrderBreakfast2Command command;
			command.Execute();

			std::cout << "Натисніть будь-яку клавішу для продовження..." << std::endl;
			clearInputBuffer();

			system("CLS");
		}
		if (activeItem == 2) {
			system("CLS");

			PrintOrdersCommand command;
			command.Execute();

			std::cout << "Натисніть будь-яку клавішу для продовження..." << std::endl;
			clearInputBuffer();

			system("CLS");
		}
		if (activeItem == 3) {
			return new MainMenuState();
		}

		break;
	}
	return this;
}

MenuState* DiscountMenuState::handleInput(char input) {

	auto clearInputBuffer = []() {
		char ch;
		do {
			ch = _getch();
		} while (ch == EOF || ch == 0);
	};

	switch (input) {
	case UP:
		if (activeItem > 0)
			activeItem--;
		break;
	case DOWN:
		if (activeItem < menuItems.size() - 1)
			activeItem++;
		break;
	case ENTER:
		if (activeItem == 0) {
			system("CLS");
			
			auto findProduct = [](std::string produkt_name) {
				std::shared_ptr<Product> prod;
				for (const auto& product : products) {
					std::string curren_name = product->getName();
					if (curren_name == produkt_name) {
						prod = product;
					}
				}

				if (!prod) {
					prod = std::make_shared<Product>(produkt_name, 170);
					products.push_back(prod);
				}
				return prod;
			};

            std::shared_ptr<Product> prod1 = findProduct("Сніданок комплексний №1");    
			std::shared_ptr<Product> prod2 = findProduct("Сніданок комплексний №2");
			//TODO
			Handler* pd1 = new PercentageDiscount(5);
			Handler* pd2 = new PositionDiscount(prod1, 10);
			Handler* pd3 = new PositionDiscount(prod2, 5);
			
			pd1->SetNext(pd2)->SetNext(pd3);

			for (const auto& order : orders) {
				pd1->GiveDiscount(*order);
			}

			PrintOrdersCommand command;
			command.Execute();

			std::cout << "Натисніть будь-яку клавішу для продовження..." << std::endl;
			clearInputBuffer();

			system("CLS");
		}		
		if (activeItem == 1) {
			return new MainMenuState();
		}

		break;
	}
	return this;
}

MenuState* SendPayMenuState::handleInput(char input) {

	auto clearInputBuffer = []() {
		char ch;
		do {
			ch = _getch();
		} while (ch == EOF || ch == 0);
	};

	switch (input) {
	case UP:
		if (activeItem > 0)
			activeItem--;
		break;
	case DOWN:
		if (activeItem < menuItems.size() - 1)
			activeItem++;
		break;
	case ENTER:
		if (activeItem == 0) {
			system("CLS");					

			for (const auto& order : orders) {
				order->setPaed(true);
			}

			PrintOrdersCommand command;
			command.Execute();

			std::cout << "Натисніть будь-яку клавішу для продовження..." << std::endl;
			clearInputBuffer();

			system("CLS");
		}
		if (activeItem == 1) {
			system("CLS");

			for (const auto& order : orders) {
				order->setSented(true);
			}

			PrintOrdersCommand command;
			command.Execute();

			std::cout << "Натисніть будь-яку клавішу для продовження..." << std::endl;
			clearInputBuffer();

			system("CLS");
		}
		if (activeItem == 2) {
			return new MainMenuState();
		}

		break;
	}
	return this;
}






