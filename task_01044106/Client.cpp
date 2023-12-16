#include "Client.h"

Client::Client(const std::string& name) : name(name) {}

void Client::addOrder(std::shared_ptr<ShopOrder> order_ptr) {  
    orderHistory.push_back(order_ptr);
}

void Client::viewOrderHistory() const {    
    std::cout << "������ ��������� ��� " << name << ":" << std::endl;
    for (const auto& order : orderHistory) {
        order->displayOrder();
    }
}

void Client::setMediator(Mediator* med) {
    mediator = med;
}

std::ostream& operator<<(std::ostream& os, const Client& client) {
    os << "�볺��: " << client.name << std::endl;
    for (const auto& order : client.orderHistory) {
        os << *order << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Client& client) {

    bool first = true;
    std::cout << "������ ��'� �볺���: ";
    do {
        std::getline(is, client.name);

        // ��������, �� ������� ��������� �����
        if (client.name.empty() && !first) {
            std::cout << "��'� �볺��� �� ���� ���� �������. ���� �����, ������ �� ���." << std::endl;
        }
        first = false;
    } while (client.name.empty());

    return is;
}








