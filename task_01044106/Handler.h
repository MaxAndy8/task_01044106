#pragma once
#include "ShopOrder.h"
/**
  * ��������� Handler ������� ����� ��� �������� �������� ���������.
  * ³� ����� ������� ����� ��� ��������� ������.
  */
class Handler {
public:
    virtual Handler* SetNext(Handler* handler) = 0;
    virtual ShopOrder& GiveDiscount(ShopOrder& order) = 0;
};
/**
  * �������� �������� �� ������������� ���� ���� ���������� �������� �������� ����� ���������.
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
  * ������ �� �������
  */
class PercentageDiscount : public AbstractHandler {
private:
    int discountPercentage = 0;
public:
    PercentageDiscount(int discountPer = 0);
    ShopOrder& GiveDiscount(ShopOrder& order) override;
};

/**
  * ������ ��������� �� ��������� �������
  */
class PositionDiscount : public AbstractHandler {
private:
    int discountPercentage = 0;
    std::shared_ptr<Product> product;
public:
    PositionDiscount(std::shared_ptr<Product> prod, int discountPer = 0);
    ShopOrder& GiveDiscount(ShopOrder& order) override;
};






