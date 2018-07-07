#include "GUIMgr.h"

#define NPCBar npcMgr_->GetNPCTemplate(it)

bool GUIMgr::IsWindowOpened()
{
	return windowMgr_.IsWindowOpened();
}

void GUIMgr::Init(sfg::Desktop * desktop, AppWindow * window, MapMgr * mapMgr, DataMgr * data, FieldMgr* fieldMgr, NPCMgr* npcMgr)
{
	desktop_ = desktop;
	window_ = window;
	mapMgr_ = mapMgr;
	data_ = data;
	fieldMgr_ = fieldMgr;
	npcMgr_ = npcMgr;
	actionWindow_.SetLocationMgr(mapMgr);
	actionMenu_.SetLocationMgr(mapMgr);
	actionWindow_.Init(mapMgr, data);
	actionMenu_.Init(mapMgr, data);
	actionWindow_.SetFieldMgr(fieldMgr);
	actionWindow_.SetNPCMgr(npcMgr);

	InitiateGUI();
	AddToDesktop();

	mapMgr->ResetCurrentKey();
	actionWindow_.InitAction();
}

void GUIMgr::SetConsole(Console * console)
{
	actionMenu_.SetConsole(console);
}

void GUIMgr::HandleEvents(sf::Event & event)
{
	windowLocations_.GetWindow()->GetWindow()->HandleEvent(event);

	for (WBMap::iterator windowBuildersIT = windowBuilders_.begin(); windowBuildersIT != windowBuilders_.end(); windowBuildersIT++)
		windowBuildersIT->second->GetWindow()->GetWindow()->HandleEvent(event);

	for (MBMap::iterator menuBuildersIT = menuBuilders_.begin(); menuBuildersIT != menuBuilders_.end(); menuBuildersIT++)
	{
		menuBuildersIT->second->GetMenu()->GetParent()->HandleEvent(event);
		for (size_t i = 0; i != menuBuildersIT->second->GetMenu()->GetChildren().size(); i++)
			menuBuildersIT->second->GetMenu()->GetChildren()[i]->HandleEvent(event);
	}

	CopyingFieldTemp(event);
	CopyingNPCTemp(event);

}

ActionWindow & GUIMgr::GetActionWindow()
{
	return actionWindow_;
}

bool GUIMgr::IsMenuOpened()
{
	for (MBMap::iterator menuBuildersIT = menuBuilders_.begin(); menuBuildersIT != menuBuilders_.end(); menuBuildersIT++)
		if (menuBuildersIT->second->GetMenu()->IsMenuOpened() == true)
			return true;
	return false;
}

void GUIMgr::InitiateGUI()
{
	InitiateGUIElements();

	for (WBMap::iterator windowBuildersIT = windowBuilders_.begin(); windowBuildersIT != windowBuilders_.end(); windowBuildersIT++)
	{
		windowBuildersIT->second->SetAction(&actionWindow_);
		windowMgr_.CreateWindow(windowBuildersIT->second);
	}

	for (MBMap::iterator menuBuildersIT = menuBuilders_.begin(); menuBuildersIT != menuBuilders_.end(); menuBuildersIT++)
	{
		menuBuildersIT->second->SetAction(&actionMenu_);
		menuMgr_.CreateMenu(menuBuildersIT->second);
		menuBuildersIT->second->SetAppWindow(window_);
	}
}

void GUIMgr::AddToDesktop()
{
	for (WBMap::iterator windowBuildersIT = windowBuilders_.begin(); windowBuildersIT != windowBuilders_.end(); windowBuildersIT++)
		desktop_->Add(windowBuildersIT->second->GetWindow()->GetWindow());

	for (MBMap::iterator menuBuildersIT = menuBuilders_.begin(); menuBuildersIT != menuBuilders_.end(); menuBuildersIT++)
	{
		desktop_->Add(menuBuildersIT->second->GetMenu()->GetParent());

		for (size_t i = 0; i != menuBuildersIT->second->GetMenu()->GetChildren().size(); i++)
			desktop_->Add(menuBuildersIT->second->GetMenu()->GetChildren()[i]);
	}
}

void GUIMgr::InitiateGUIElements()
{

	///TODO: Create windows with <code>new</code> operator
	windowBuilders_["LoadMap"] = &windowLoadMap_;
	windowBuilders_["SaveMap"] = &windowSaveMap_;
	windowBuilders_["FieldProp"] = &windowFieldProperties_;
	windowBuilders_["LocProp"] = &windowLocationProperties_;
	windowBuilders_["locations"] = &windowLocations_;
	windowBuilders_["locationMove"] = &windowLocationMove_;
	windowBuilders_["NPCProp"] = &windowNPCCreating_;
	windowBuilders_["NPCStats"] = &windowNPCStats_;
	windowBuilders_["NPCSpells"] = &windowNPCSpells_;
	windowBuilders_["NPCArmor"] = &windowNPCArmor_;
	windowBuilders_["NPCInventory"] = &windowNPCInventory_;
	windowBuilders_["NPCPosition"] = &windowNPCPosition_;
	windowBuilders_["ReallyClose"] = &windowReallyClose_;
	windowBuilders_["TextureLoading"] = &windowTextureLoading_;
	windowBuilders_["SoundLoading"] = &windowSoundLoading_;
	windowBuilders_["FieldTempTool"] = &windowFieldTempTool_;
	windowBuilders_["NPCTempTool"] = &windowNPCTempTool_;

	actionWindow_.SetWindowBuilders(windowBuilders_);
	actionMenu_.SetWindowBuilders(windowBuilders_);
	actionMenu_.SetAppWindow(&window_->Get());
	actionWindow_.SetWindowsMgr(&windowMgr_);
	actionMenu_.SetWindowsMgr(&windowMgr_);
	actionWindow_.SetAppWindow(&window_->Get());

	menuBuilders_["1MenuFile"] = &menuFile_;
	menuBuilders_["2MenuEdit"] = &menuEdit_;
	menuBuilders_["3MenuTools"] = &menuTools_;
	menuBuilders_["4MenuHelp"] = &menuHelp_;

}

void GUIMgr::CopyingFieldTemp(sf::Event& event)
{
	if (mapMgr_->IsWaitingForFieldSelection() == true)
	{
		for (auto itr = mapMgr_->GetCurrentLocation()->GetFields().begin(), end = mapMgr_->GetCurrentLocation()->GetFields().end(); itr != end; ++itr)
			if (event.type == sf::Event::MouseButtonPressed	&& event.mouseButton.button == sf::Mouse::Left)
				if (itr->GetSprite().getGlobalBounds().contains(window_->Get().mapPixelToCoords(sf::Mouse::getPosition(window_->Get()))))
				{
					mapMgr_->IsWaitingForFieldSelection(false);
					actionMenu_.OpenFieldTemplate();
					windowBuilders_["FieldTempTool"]->GetEntry()["Type"]->SetText(itr->GetType());
					windowBuilders_["FieldTempTool"]->GetEntry()["Texture"]->SetText(itr->GetTextureID());
				}
	}
}

void GUIMgr::CopyingNPCTemp(sf::Event & event)
{
	if (mapMgr_->IsWaitingForNPCSelection() == true)
	{
		for(auto itr = mapMgr_->GetNPCs().begin(), end = mapMgr_->GetNPCs().end(); itr != end; ++itr)
			if(event.type == sf::Event::MouseButtonPressed&&event.mouseButton.button == sf::Mouse::Left)
				if (itr->GetSprite().getGlobalBounds().contains(window_->Get().mapPixelToCoords(sf::Mouse::getPosition(window_->Get()))))
				{
					mapMgr_->IsWaitingForNPCSelection(false);

					int it = atoi(windowBuilders_["NPCTempTool"]->GetLabel()["ID"]->GetText().toAnsiString().c_str()) - 1;


					NPCBar.SetName(itr->GetName());
					NPCBar.SetLevel(itr->GetLevel());
					NPCBar.SetTextureID(itr->GetTextureID());
					NPCBar.GetSprite().setTexture(data_->GetTexture(NPCBar.GetTextureID()));
					NPCBar.SetType(itr->GetType());

					NPCBar.SetStrength(itr->GetStrength());
					NPCBar.SetAgility(itr->GetAgility());
					NPCBar.SetWillPower(itr->GetWillPower());
					NPCBar.SetIntelligence(itr->GetIntelligence());
					NPCBar.SetHealthPointsMax(itr->GetHealthPointsMax());
					NPCBar.SetMaxSpellFuel(itr->GetMaxSpellFuel());
					NPCBar.SetEndurance(itr->GetEndurance());
					NPCBar.SetSpeed(itr->GetSpeed());
					NPCBar.SetSpell(itr->GetSpell(1), 1);
					NPCBar.SetSpell(itr->GetSpell(2), 2);
					NPCBar.SetSpell(itr->GetSpell(3), 3);
					NPCBar.SetSpell(itr->GetSpell(4), 4);
					NPCBar.SetArmor(itr->GetArmor("Piercing"), "Piercing");
					NPCBar.SetArmor(itr->GetArmor("Cutting"), "Cutting");
					NPCBar.SetArmor(itr->GetArmor("Crushing"), "Crushing");
					NPCBar.SetArmor(itr->GetArmor("Magical"), "Magical");
					NPCBar.ItemSlot(itr->GetItem(1), 1);
					NPCBar.ItemSlot(itr->GetItem(2), 2);
					NPCBar.ItemLoot(itr->GetItemLoot(1), 1);
					NPCBar.ItemLoot(itr->GetItemLoot(2), 2);
					NPCBar.ItemLoot(itr->GetItemLoot(3), 3);
					NPCBar.ItemLoot(itr->GetItemLoot(4), 4);
					NPCBar.SetChanceOfLoot(1, itr->GetChangeOfLoot(1));
					NPCBar.SetChanceOfLoot(2, itr->GetChangeOfLoot(2));
					NPCBar.SetChanceOfLoot(3, itr->GetChangeOfLoot(3));
					NPCBar.SetChanceOfLoot(4, itr->GetChangeOfLoot(4));
				
				}
	}
}
