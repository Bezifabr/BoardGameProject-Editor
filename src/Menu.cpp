/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// Menu.cpp
// Purpose: Contains definitions of Menu methods.
// It is a part of builder pattern.
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
#include "MenuBase.h"

sf::Vector2f gui::Menu::position_ = sf::Vector2f(-150, 0);

gui::Menu::Menu()
{
	position_ = position_ + sf::Vector2f(150, 0);
	menuButton_ = sfg::Button::Create("");
	menuButton_->SetPosition(position_);
	menuButton_->SetRequisition(sf::Vector2f(150, 40));
	SetHandledInput();
}
gui::Menu::Menu(std::string label)
{
	position_ = position_ + sf::Vector2f(150, 0);
	menuButton_ = sfg::Button::Create(label);
	menuButton_->SetPosition(position_);
	menuButton_->SetRequisition(sf::Vector2f(150, 40));  //TODO: Change it by argument
	SetHandledInput();
	
}

void gui::Menu::SetHandledInput()
{
	menuButton_->GetSignal(sfg::Button::OnMouseEnter).Connect(std::bind(&Menu::UnWrap, this));
	menuButton_->GetSignal(sfg::Button::OnMouseLeave).Connect(std::bind(&Menu::Wrap, this));
	menuButton_->GetSignal(sfg::Button::OnMouseLeftRelease).Connect(std::bind(&Menu::WrapInstantly, this));
}

void gui::Menu::AddChild(sfg::Button::Ptr button)
{
	button->GetSignal(sfg::Button::OnMouseEnter).Connect(std::bind(&Menu::UnWrap, this));
	button->GetSignal(sfg::Button::OnMouseLeave).Connect(std::bind(&Menu::Wrap, this));
	button->GetSignal(sfg::Button::OnMouseLeftRelease).Connect(std::bind(&Menu::WrapInstantly, this));
	button->Show(false);
	button->SetRequisition(sf::Vector2f(150, 40));
	button->SetPosition(menuButton_->GetAbsolutePosition() + sf::Vector2f(0, 40 * buttons_.size()) + sf::Vector2f(0, 40));
	buttons_.push_back(button);
}
void gui::Menu::UnWrap()
{
		for (size_t IT = 0; IT != buttons_.size(); IT++)
			buttons_[IT]->Show(true);
		isMenuOpened_ = true;
}
void gui::Menu::Wrap()
{
	if (sf::Mouse::getPosition(window_->Get()).y > buttons_.size() * 40 + 40
		||
		sf::Mouse::getPosition(window_->Get()).x > menuButton_->GetAbsolutePosition().x + 150
		||
		sf::Mouse::getPosition(window_->Get()).x < menuButton_->GetAbsolutePosition().x)
	{
		for (uint8_t IT = 0; IT != buttons_.size(); IT++)
			buttons_[IT]->Show(false);
		isMenuOpened_ = false;
	}
}
void gui::Menu::WrapInstantly()
{
	for (uint8_t IT = 0; IT != buttons_.size(); IT++)
		buttons_[IT]->Show(false);
	isMenuOpened_ = false;
}

