#pragma once
#include "ShopOrder.h"
#include "Mediator.h"
#include <memory>

class Mediator;
class ShopOrder;

class Client {
public:
    Client(const std::string& name = "" /*, Mediator& mediator*/);
    void addOrder(std::shared_ptr<ShopOrder> order_ptr);
    void viewOrderHistory() const;
    void setMediator(Mediator* med);
    //void receiveOrderUpdate(const Order& order);
    // 
    // Перегрузка оператору << для виведення даних в потік
    friend std::ostream& operator<<(std::ostream& os, const Client& client);
    // Перегрузка оператору >> для введення даних з потоку
    friend std::istream& operator>>(std::istream& is, Client& client);

private:
    std::string                               name        ;
    std::vector< std::shared_ptr<ShopOrder> > orderHistory;
    Mediator*                                 mediator    ;
};
