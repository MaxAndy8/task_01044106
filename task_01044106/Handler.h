#pragma once
#include "ShopOrder.h"
/**
  * Інтерфейс Handler оголошує метод для побудови ланцюжка обробників.
  * Він також оголошує метод для виконання запиту.
  */
class Handler {
public:
    virtual Handler* SetNext(Handler* handler) = 0;
    virtual ShopOrder& GiveDiscount(ShopOrder& order) = 0;
};
/**
  * Поведінка ланцюжка за замовчуванням може бути реалізована всередині базового класу обробника.
  */
class AbstractHandler : public Handler {
    /**
     * @var Handler
     */
private:
    Handler* next_handler_;

public:
    AbstractHandler();
    Handler* SetNext(Handler* handler) override;
    ShopOrder& GiveDiscount(ShopOrder& order) override;
};
/**
  * Знижка на процент
  */
class PercentageDiscount : public AbstractHandler {
private:
    int discountPercentage = 0;
public:
    PercentageDiscount(int discountPer = 0);
    ShopOrder& GiveDiscount(ShopOrder& order) override;
};

/**
  * Знижка процентом на конкретну позицію
  */
class PositionDiscount : public AbstractHandler {
private:
    int discountPercentage = 0;
    std::shared_ptr<Product> product;
public:
    PositionDiscount(std::shared_ptr<Product> prod, int discountPer = 0);
    ShopOrder& GiveDiscount(ShopOrder& order) override;
};






