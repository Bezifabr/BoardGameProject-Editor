//#include "WindowMgr.h"
//#include "Action.h"
//
//sfg::Window::Ptr WND_NPC_Stats::Create()
//{
//	box_["Body"] = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
//	box_["Options"] = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL);
//
//	box_["Options"]->SetSpacing(5.f);
//	box_["Body"]->SetSpacing(5.f);
//
//
//	PackWidget("Body", "Title", sfg::Label::Create(WND_NPC_STATS_TITLE), std::bind(&ActionWindow::Nothing, action_));
//	AddWindowOption("Body", "Texture", sf::Vector2f(200, 0));
//	AddWindowOption("Body", "Frames", sf::Vector2f(200, 0));
//	AddWindowOption("Body", "Strength", sf::Vector2f(200, 0));
//	AddWindowOption("Body", "Agility", sf::Vector2f(200, 0));
//	PackWidget("Options", "Ok", sfg::Button::Create(WND_OK), std::bind(&ActionWindow::Nothing, action_));
//	PackWidget("Options", "Cancel", sfg::Button::Create(WND_CANCEL), std::bind(&ActionWindow::CloseNPCStats, action_));
//
//	box_["Body"]->Pack(box_["Options"]);
//
//	auto window = sfg::Window::Create(sfg::Window::Style::BACKGROUND);
//	window->Add(box_["Body"]);
//	window->SetAllocation(sf::FloatRect(WND_SIZE.x / 2 - 110, WND_SIZE.y / 2 - 200, 300, 100));
//	window->Show(false);
//
//	return window;
//}