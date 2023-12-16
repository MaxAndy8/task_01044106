#include "Handler.h"

AbstractHandler::AbstractHandler() : next_handler_(nullptr) {
}
Handler* AbstractHandler::SetNext(Handler* handler) {
	this->next_handler_ = handler;
	// Повернення обробника звідси дозволить нам зв’язати обробники зручним способом
	// таким чином:
	// $monkey->setNext($squirrel)->setNext($dog);
	return handler;
}
ShopOrder& AbstractHandler::GiveDiscount(ShopOrder& order) {
	if (this->next_handler_) {
		return this->next_handler_->GiveDiscount(order);
	}

	return order;
}

/**
  * Знижка на процент
  */
PercentageDiscount::PercentageDiscount(int discountPer)
	: discountPercentage(discountPer) { }

ShopOrder& PercentageDiscount::GiveDiscount(ShopOrder& order) {

	double discountSum = 0.0;
	for (const auto& item : order.getItems())
	{
		if (item.product_ptr)
		{
			discountSum += item.price * item.quantity * discountPercentage / 100;
		}
	}

	if (discountSum > 0) {
		order.addDiscountSum(discountSum);
	}
	return AbstractHandler::GiveDiscount(order);
}

/**
  * Знижка процентом на конкретну позицію
  */
PositionDiscount::PositionDiscount(std::shared_ptr<Product> prod, int discountPer)
	: product(prod), discountPercentage(discountPer) { }

ShopOrder& PositionDiscount::GiveDiscount(ShopOrder& order) {

	double discountSum = 0.0;
	for (const auto& item : order.getItems())
	{
		if (item.product_ptr && item.product_ptr.get() == product.get() )
		{
           discountSum += item.price * item.quantity * discountPercentage / 100;
		}		
	}

	if (discountSum > 0) {
		order.addDiscountSum(discountSum);
	}
	return AbstractHandler::GiveDiscount(order);
}





