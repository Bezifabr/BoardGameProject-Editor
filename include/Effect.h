/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Effect.h
// Purpose: Contains Effect class with orders queue.
// Effects are actions done by items or skills
//
// Copyright (C) Maciej Saranda 2016 (Bezifabr@gmail.com)
// Code written only for use by Mighty Gorilla Studio.
//
//
//
/// ////////////////////////////////////////////////////////////////////////////

#include <queue>
#pragma once


class Effect
{
public:
	Effect();
	~Effect();

	/////////////////////
	/// Returns amount of orders
	///
	/// \return size of orders queue
	///
	/////////////////////
	size_t GetOrdersNumber();

	////////////////////
	/// Adds order to back of the orders queue
	/// Calls Push() method
	///
	/// \param order - String type argument. Order's name read by game.
	///
	////////////////////
	void PushOrder(std::string order);

	////////////////////
	/// Removes orders from front of queue
	/// Calls Pop() method.
	///
	////////////////////
	void PopOrder();

	////////////////////
	/// Returns last order's name
	/// Every method in this class sets new lastOrder_ value
	/// 
	/// \return String order's name.
	///
	////////////////////
	std::string GetLastOrder();

	////////////////////
	/// Returns order from front of the queue
	/// Calls Front() method
	///
	/// \return String order's name.
	///
	////////////////////
	std::string GetFrontOrder();

	///////////////////
	/// Returns ID of effect
	/// ID is name used in the editor and map files
	///
	/// return String effect's ID
	///
	///////////////////
	std::string GetID();

	///////////////////
	/// Changes effect's ID
	/// ID is name used in the editor and map files
	///
	///
	///////////////////
	void SetID(std::string& id);
private:

	std::string id_;

	std::queue<std::string> ordersQueue_;
	std::string lastOrder_;
};