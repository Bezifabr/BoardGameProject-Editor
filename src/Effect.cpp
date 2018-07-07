#include "Effect.h"
#include <iostream>



Effect::Effect()
{
}

Effect::~Effect()
{
}

size_t Effect::GetOrdersNumber()
{
	return ordersQueue_.size();
}





void Effect::PushOrder(std::string order)
{
	if (!order.empty()) {
		ordersQueue_.push(order);
		lastOrder_ = ordersQueue_.back();
	}
	else
		std::cout << "Effect::AddOrder(): argument is empty" << std::endl;
}

void Effect::PopOrder()
{
	lastOrder_ = ordersQueue_.front();
	ordersQueue_.pop();
}

std::string Effect::GetLastOrder()
{
	if (!lastOrder_.empty())
		return lastOrder_;
	else
		std::cout << "Effect::GetLastOrder(): Cannot return value of variable due it is empty" << std::endl;
}

std::string Effect::GetFrontOrder()
{
	if (!ordersQueue_.empty())
		return ordersQueue_.front();
	else
		std::cout << "Effect::GetTopOrder(): Cannot return value of variable due orders queue is empty" << std::endl;
}

std::string Effect::GetID()
{
	if (id_.empty())
		std::cout << "Effect::GetID(): string is empty" << std::endl;

	return id_;
}

void Effect::SetID(std::string & id)
{
	if (!id.empty() && id != id_ && id != "")
		id_ = id;
	std::cout << "Effect::SetID(): invalid argument" << std::endl;
}
