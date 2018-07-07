/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// WindowBuilder.cpp
// Purpose: Contains definitions of WindowBuilder methods that creates unique object of Window class from WindowBase.h file.
// It is a part of building pattern.
//
// Copyright (C) Maciej Saranda 2016 (Bezifabr@gmail.com)
// Code written only for use by Mighty Gorilla Studio.
//
//
//
/// ////////////////////////////////////////////////////////////////////////////

////////////////////
// HEADERS
////////////////////
#include "WindowBuilder.h"

void gui::WindowBuilder::AddWindowOption(std::string boxKey, std::string optionName, sf::Vector2f requisition)
{
		std::string _boxKey = optionName;
		box_[_boxKey + "_Box"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
		box_[_boxKey + "_Box"]->SetRequisition(requisition);

		label_[_boxKey] = sfg::Label::Create(optionName);
		box_[_boxKey + "_Box"]->Pack(label_[_boxKey]);

		entry_[_boxKey] = sfg::Entry::Create();
		box_[_boxKey + "_Box"]->Pack(entry_[_boxKey]);

		entry_[_boxKey]->SetRequisition(requisition - sf::Vector2f(requisition.x / 3, 0));
		label_[_boxKey]->SetRequisition(requisition - sf::Vector2f(requisition.x / 3 * 2, 0));
		box_[boxKey]->Pack(box_[_boxKey + "_Box"]);
}

void gui::WindowBuilder::AddWindowCombo(std::string boxKey, std::string comboName, sf::Vector2f requisition)
{
	box_[comboName] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
	combo_[comboName] = sfg::ComboBox::Create();
	label_[comboName] = sfg::Label::Create(comboName);

	label_[comboName]->SetRequisition(requisition - sf::Vector2f(requisition.x / 3 * 2, 0));
	combo_[comboName]->SetRequisition(requisition - sf::Vector2f(requisition.x / 3 , 0));

	box_[comboName]->Pack(label_[comboName]);
	box_[comboName]->Pack(combo_[comboName]);
	box_["Body"]->Pack(box_[comboName]);
}

void gui::WindowBuilder::PackWidget(std::string boxKey, std::string widgetKey, sfg::Widget::Ptr widgetPtr, std::function<void()> delegate)
{
	widget_[widgetKey] = widgetPtr;
	widget_[widgetKey]->GetSignal(sfg::Widget::OnLeftClick).Connect(delegate);
	box_[boxKey]->Pack(widget_[widgetKey]);
}
