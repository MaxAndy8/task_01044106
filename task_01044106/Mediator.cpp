#include "Mediator.h"

Mediator::Mediator(std::shared_ptr<Client> cl, std::shared_ptr<ShopOrder> ord)
    : client(cl), order(ord) {
    client->setMediator(this);
    client->addOrder(ord);
    order->setMediator(this);
}

void Mediator::addProduct(std::shared_ptr<Product> product, int quantity) {
    order->addItem(product, product->getPrice(), quantity);
}

void Mediator::changeClient(std::shared_ptr<Client> newClient) {
    client = newClient;
    client->setMediator(this);
}
