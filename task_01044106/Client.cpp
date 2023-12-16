#include "Client.h"

Client::Client(const std::string& name) : name(name) {}

void Client::addOrder(std::shared_ptr<ShopOrder> order_ptr) {  
    orderHistory.push_back(order_ptr);
}

void Client::viewOrderHistory() const {    
    std::cout << "≤стор≥€ замовлень дл€ " << name << ":" << std::endl;
    for (const auto& order : orderHistory) {
        order->displayOrder();
    }
}

void Client::setMediator(Mediator* med) {
    mediator = med;
}

std::ostream& operator<<(std::ostream& os, const Client& client) {
    os << " л≥Їнт: " << client.name << std::endl;
    for (const auto& order : client.orderHistory) {
        os << *order << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Client& client) {

    bool first = true;
    std::cout << "¬вед≥ть ≥м'€ кл≥Їнта: ";
    do {
        std::getline(is, client.name);

        // ѕерев≥рка, чи введено непорожню назву
        if (client.name.empty() && !first) {
            std::cout << "≤м'€ кл≥Їнта не може бути порожн≥м. Ѕудь ласка, введ≥ть ще раз." << std::endl;
        }
        first = false;
    } while (client.name.empty());

    return is;
}








