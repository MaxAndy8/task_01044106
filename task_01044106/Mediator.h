#pragma once
#include "Client.h"
#include "ShopOrder.h"
#include <memory>

class Client   ;
class ShopOrder;

class Mediator {
public:
    Mediator(std::shared_ptr<Client> cl, std::shared_ptr<ShopOrder> ord);
    
    void addProduct(std::shared_ptr<Product> product, int quantity);

    void changeClient(std::shared_ptr<Client> newClient);

private:
    std::shared_ptr<Client>    client;
    std::shared_ptr<ShopOrder> order ;
};





