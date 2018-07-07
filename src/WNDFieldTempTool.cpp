/// ////////////////////////////////////////////////////////////////////////////
//
// Project: 'The Board Game Project'
// WNDFieldTempTool.cpp
// Purpose: Contains definition of Create() method from NWDFieldTempTool class.
// Field templates editing tool.
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
#include "WindowMgr.h"
#include "Action.h"

sfg::Window::Ptr WNDFieldTempTool::Create()
{
	box_["Navi"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
	box_["Properties"] = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	box_["Options"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
	auto boxBody = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);

	boxBody->SetSpacing(5.f);;
	box_["Navi"]->SetSpacing(10.f);
	box_["Options"]->SetSpacing(10.f);
	

	PackWidget("Navi", "Left", sfg::Button::Create("<<"), std::bind(&ActionWindow::FieldTemplateLeft, action_));
	label_["ID"] = sfg::Label::Create("1");
	box_["Navi"]->Pack(label_["ID"]);
	PackWidget("Navi", "Right", sfg::Button::Create(">>"), std::bind(&ActionWindow::FieldTemplateRight, action_));

	AddWindowOption("Properties", "Type", sf::Vector2f(200, 0));
	AddWindowOption("Properties", "Texture", sf::Vector2f(200, 0));

	PackWidget("Options", "Load", sfg::Button::Create(WND_LOAD), std::bind(&ActionWindow::LoadFieldTemplate, action_));
	PackWidget("Options", "Cancel", sfg::Button::Create(WND_CANCEL), std::bind(&ActionWindow::CloseFieldTemplate, action_));
	PackWidget("Options", "Copy", sfg::Button::Create("Copy"), std::bind(&ActionWindow::CopyFieldTemplate, action_));

	boxBody->Pack(box_["Navi"]);
	boxBody->Pack(box_["Properties"]);
	boxBody->Pack(box_["Options"]);

	auto window = sfg::Window::Create(sfg::Window::BACKGROUND);
	window->Add(boxBody);
	window->SetAllocation(sf::FloatRect(WND_SIZE.x / 2 - 125, WND_SIZE.y / 2, 325, 50));
	window->Show(false);

	return window;
}