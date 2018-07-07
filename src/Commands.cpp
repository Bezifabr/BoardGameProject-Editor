#include "Commands.h"
#include <iostream>
#include <algorithm>
using namespace std;


std::string ConvertToString(bool booleanVariable)
{
	if (booleanVariable == true)
		return "true";
	return "false";
}

std::string ConvertToString(int integerVariable)
{
	return std::to_string(integerVariable);
}

bool ConvertToBoolean(std::string stringVariable)
{
	if (stringVariable == "true" || stringVariable == "True" || stringVariable == "1")
		return true;
	return false;
}

bool ConvertToBoolean(int integerVariable)
{
	if (integerVariable == 1)
		return true;
	return false;
}

Commands::Commands()
{
}

Commands::~Commands()
{
}

const std::string& Commands::RunGameObjects()
{
	GetInputData();
	if(commandsList_.count(inputText_) == 1)
		CallCommand(inputText_);
	return inputText_;
}

void Commands::SetCommands()
{

	commandsList_["AddEffect"] = &Commands::AddEffect;
	commandsList_["ShowEffects"] = &Commands::ShowEffects;
	commandsList_["RemoveEffects"] = &Commands::RemoveEffects;
	commandsList_["ChangeEffects"] = &Commands::ChangeEffects;
	commandsList_["ShowOrders"] = &Commands::ShowOrders;
	commandsList_["SetEffectID"] = &Commands::SetEffectID;
	commandsList_["LoadEffects"] = &Commands::LoadEffects;
	commandsList_["SaveEffects"] = &Commands::SaveEffects;

	commandsList_["AddItem"] = &Commands::AddItem;
	commandsList_["ChangeItem"] = &Commands::ChangeItem;
	commandsList_["RemoveItem"] = &Commands::RemoveItem;
	commandsList_["ShowItems"] = &Commands::ShowItems;
	commandsList_["ShowItemStats"] = &Commands::ShowItemStats;
	commandsList_["SetItemName"] = &Commands::SetItemName;
	commandsList_["SetItemDesc"] = &Commands::SetItemDesc;
	commandsList_["SetItemIcon"] = &Commands::SetItemIcon;
	commandsList_["SetItemCooldown"] = &Commands::SetItemCooldown;
	commandsList_["SetItemTargSelf"] = &Commands::SetItemTargSelf;
	commandsList_["SetItemTargEnemy"] = &Commands::SetItemTargEnemy;
	commandsList_["SetItemTargAlly"] = &Commands::SetItemTargAlly;
	commandsList_["SetItemUseImmediately"] = &Commands::SetItemUseImmediately;
	commandsList_["SetItemUseOnTarget"] = &Commands::SetItemUseOnTarget;
	commandsList_["SetItemPerm"] = &Commands::SetItemPerm;
	commandsList_["SetItemUsable"] = &Commands::SetItemUsable;
	commandsList_["SetItemCharges"] = &Commands::SetItemCharges;
	commandsList_["SetItemPrice"] = &Commands::SetItemPrice;
	commandsList_["LoadItems"] = &Commands::LoadItems;
	commandsList_["SaveItems"] = &Commands::SaveItems;

	commandsList_["AddSkill"] = &Commands::AddSkill;
	commandsList_["ChangeSkill"] = &Commands::ChangeSkill;
	commandsList_["RemoveSkill"] = &Commands::RemoveSkill;
	commandsList_["ShowSkills"] = &Commands::ShowSkills;
	commandsList_["ShowSkillStats"] = &Commands::ShowSkillStats;
	commandsList_["SetSkillName"] = &Commands::SetSkillName;
	commandsList_["SetSkillDesc"] = &Commands::SetSkillDesc;
	commandsList_["SetSkillIcon"] = &Commands::SetSkillIcon;
	commandsList_["SetSkillCooldown"] = &Commands::SetSkillCooldown;
	commandsList_["SetSkillTargSelf"] = &Commands::SetSkillTargSelf;
	commandsList_["SetSkillTargEnemy"] = &Commands::SetSkillTargEnemy;
	commandsList_["SetSkillTargAlly"] = &Commands::SetSkillTargAlly;
	commandsList_["SetSkillUseImmediately"] = &Commands::SetSkillUseImmediately;
	commandsList_["SetSkillUseOnTarget"] = &Commands::SetSkillUseOnTarget;
	commandsList_["SetSkillUsable"] = &Commands::SetSkillUsable;
	commandsList_["LoadSkills"] = &Commands::LoadSkills;
	commandsList_["SaveSkills"] = &Commands::SaveSkills;

	SetCommandsDescriptions();

	isRunning_ = true;
}


void Commands::SetDescription(std::string commandName, std::string commandDescription)
{
	commandsDescriptions_[commandName] = commandDescription;
}

void Commands::ShowCommands()
{
	for (auto itr = commandsDescriptions_.begin(), end = commandsDescriptions_.end(); itr != end; itr++)
	{
		std::cout 
			<< itr->first 
			<< " - "
			<< commandsDescriptions_[itr->first] 
			<< 
		std::endl;
	}
}

void Commands::AddEffect()
{
		cout << "Add orders (to finish write \".\")" << endl;
		bool orders = true;
		Effect tempEffect;

		while (orders == true)
		{
			if (GetInputData() != ".")
				tempEffect.PushOrder(inputText_);
			else
				orders = false;
		}
		cout << "Type Effect's id" << std::endl;
		GetInputData();
		gameObjects_->AddEffect(inputText_, tempEffect);

		cout << "Effect '" << inputText_ << "' has been created!" << endl
			<< "List of orders: " << endl;
		ShowOrders(tempEffect);
		inputText_.clear();
}

void Commands::ShowEffects()
{
		if (!gameObjects_->GetEffectsKeys().empty())
		{
			cout << "Effects:" << endl;
			for (auto i = 0; i < gameObjects_->GetEffectsKeys().size(); i++)
			{
				std::string key = gameObjects_->GetEffectsKeys()[i];
				cout << "-" << key << endl;
			}
		}
		else std::cout << "There are no effects :(" << std::endl;
}

void Commands::RemoveEffects()
{
		cout << "Type ID of Effect to remove" << endl;
		GetInputData();
		gameObjects_->RemoveEffect(inputText_);
		cout << "Effect '" << inputText_ << "' remove" << endl;

}

void Commands::ChangeEffects()
{
		cout << "Type ID of Effect to change" << endl;
		GetInputData();
		std::string id = inputText_;

		cout << "Type ID of overriding Effect" << endl;
		GetInputData();

		gameObjects_->ChangeEffect(id, gameObjects_->GetEffect(inputText_));
		cout << "Changing from '" << id << "' to '" << inputText_ << "' finished!" << endl;

}

void Commands::ShowOrders()
{
	GetInputData("Type ID of Effect");
		if (gameObjects_->DidEffectExists(inputText_) == true)
			ShowOrders(gameObjects_->GetEffect(inputText_));

}

void Commands::SetEffectID()
{
	
	std::string currentID = GetInputData("Type current ID of Effect");
	gameObjects_->SetEffectID(currentID, GetInputData("Type new ID of Effect"));
}

void Commands::LoadEffects()
{
	gameObjects_->LoadEffects();
}

void Commands::SaveEffects()
{
	gameObjects_->SaveEffects();
}

void Commands::AddItem()
{
	Item tempItem;
	tempItem.SetName(GetInputData("Set Name ="));
	tempItem.SetDescription(GetInputData("Write description (type \\n to break line) = "));
	tempItem.SetIconTextureID(GetInputData("Icon texture (texture id) = "));
	tempItem.SetTimeOfCooldown(atoi(GetInputData("Cooldown (leave 0 if it has no cooldown) = ").c_str()));

	tempItem.IsTargetingSelf(ConvertToBoolean(GetInputData("IsTargetingSelf = ")));
	tempItem.IsTargetingEnemy(ConvertToBoolean(GetInputData("IsTargetingEnemy = ")));
	tempItem.IsTargetingAlly(ConvertToBoolean(GetInputData("IsTargetingAlly = ")));
	tempItem.IsUsingImmediately(ConvertToBoolean(GetInputData("UseImmediately = ")));
	tempItem.IsUsingOnTarget(ConvertToBoolean(GetInputData("UseOnTarget = ")));
	tempItem.IsPermament(ConvertToBoolean(GetInputData("IsPermament = ")));
	tempItem.IsUsable(ConvertToBoolean(GetInputData("IsUsable = ")));

	if (tempItem.IsPermament() == false)
		tempItem.SetAmountOfCharges(atoi(GetInputData("AmountOfCharges = ").c_str()));

	tempItem.SetPrice(atoi(GetInputData("Price = ").c_str()));
	tempItem.SetID(GetInputData("Type ID of Item "));

	gameObjects_->AddItem(inputText_, tempItem);

	cout << "Item '" << tempItem.GetID() << "' has been created!" << endl;
	inputText_.clear();
}

void Commands::ChangeItem()
{
	cout << "Type name of Item to change" << endl;
	GetInputData();
	std::string id = inputText_;

	cout << "Type name of overriding Item" << endl;
	GetInputData();

	gameObjects_->ChangeItem(id, gameObjects_->GetItem(inputText_));
	cout << "Changing from '" << id << "' to '" << inputText_ << "' finished!" << endl;

}

void Commands::RemoveItem()
{
	cout << "Type ID of Item to remove" << endl;
	GetInputData();
	gameObjects_->RemoveItem(inputText_);
	cout << "Item '" << inputText_ << "' removed." << endl;
}

void Commands::ShowItems()
{
	if (!gameObjects_->GetItemsKeys().empty())
	{
		cout << "Items:" << endl;
		for (auto i = 0; i < gameObjects_->GetItemsKeys().size(); i++)
		{
			std::string key = gameObjects_->GetItemsKeys()[i];
			cout << "-" << key << endl;
		}
	}
	else std::cout << "There are no items :(" << std::endl;
}

void Commands::ShowItemStats()
{
	cout << "Type Item ID ";
	std::string name = GetInputData();
	if (gameObjects_->DidItemExists(inputText_) == true)
	{
		cout << "Name: " << gameObjects_->GetItem(name).GetName() << endl
			<< "Description: " << gameObjects_->GetItem(name).GetDescription() << endl
			<< "IconTextureID: " << gameObjects_->GetItem(name).GetIconTextureID() << endl
			<< "Cooldown: " << to_string(gameObjects_->GetItem(name).GetTimeOfCooldown()) << endl;

		cout << "IsTargetingSelf: "
		<< ConvertToString(gameObjects_->GetItem(name).IsTargetingSelf()) << endl;
		cout << "IsTargetingEnemy: "
		<< ConvertToString(gameObjects_->GetItem(name).IsTargetingEnemy()) << endl;
		cout << "IsTargetingAlly: "
		<< ConvertToString(gameObjects_->GetItem(name).IsTargetingAlly()) << endl;
		cout << "UseImmediately: "
		<< ConvertToString(gameObjects_->GetItem(name).IsUsingImmediately()) << endl;
		cout << "UseOnTarget: "
		<< ConvertToString(gameObjects_->GetItem(name).IsUsingOnTarget()) << endl;
		cout << "IsPermament: "
		<< ConvertToString(gameObjects_->GetItem(name).IsPermament()) << endl;
		cout << "IsUsable: "
		<< ConvertToString(gameObjects_->GetItem(name).IsUsable() ) << endl;

		cout << "Amount Of Charges: " << to_string(gameObjects_->GetItem(name).GetAmounOfCharges()) << endl
			<< "Price: " << to_string(gameObjects_->GetItem(name).GetPrice()) << endl;
	}
}

void Commands::SetItemName()
{
	std::string name = GetInputData("Type Item name ");
	gameObjects_->GetItem(name).SetName(GetInputData("Type new name "));
}

void Commands::SetItemDesc()
{
	std::string name = GetInputData("Type item name ");
	gameObjects_->GetItem(name).SetDescription(GetInputData("Type new description "));
}

void Commands::SetItemIcon()
{
	std::string name = GetInputData("Type item name ");
	gameObjects_->GetItem(name).SetIconTextureID(GetInputData("Type new Icon texture ID "));
}

void Commands::SetItemCooldown()
{
	std::string name = GetInputData("Type item name ");
	gameObjects_->GetItem(name).
		SetTimeOfCooldown(atoi(GetInputData("Type new cooldown value ").c_str()));
}

void Commands::SetItemTargSelf()
{
	std::string name = GetInputData("Type item name ");
	GetInputData("Is '" + name + "' targeting caster? ");
	gameObjects_->GetItem(name).IsTargetingSelf(ConvertToBoolean(inputText_));

}

void Commands::SetItemTargEnemy()
{
	std::string name = GetInputData("Type item name ");
	GetInputData("Is '" + name + "' targeting enemy? ");
	gameObjects_->GetItem(name).IsTargetingEnemy(ConvertToBoolean(inputText_));
}

void Commands::SetItemTargAlly()
{
	std::string name = GetInputData("Type item name ");
	GetInputData("Is '" + name + "' targeting caster? ");
	gameObjects_->GetItem(name).IsTargetingAlly(ConvertToBoolean(inputText_));
}

void Commands::SetItemUseImmediately()
{
	std::string name = GetInputData("Type item name "); 
	GetInputData("Is '" + name + "' casted immediately? ");
	gameObjects_->GetItem(name).IsUsingImmediately(ConvertToBoolean(inputText_));
}

void Commands::SetItemUseOnTarget()
{
	std::string name = GetInputData("Type item name ");
	GetInputData("Has '" + name + "' to track the target? ");
	gameObjects_->GetItem(name).IsUsingOnTarget(ConvertToBoolean(inputText_));
}

void Commands::SetItemPerm()
{
	std::string name = GetInputData("Type item name ");
	GetInputData("Is '" + name + "' Item permament? ");
	gameObjects_->GetItem(name).IsPermament(ConvertToBoolean(inputText_));
}

void Commands::SetItemUsable()
{
	std::string name = GetInputData("Type item name ");
	GetInputData("Is '" + name + "' Item usable? ");
	gameObjects_->GetItem(name).IsUsable(ConvertToBoolean(inputText_));
}

void Commands::SetItemCharges()
{
	std::string name = GetInputData("Type item name ");
	gameObjects_->GetItem(name).SetAmountOfCharges(atoi(GetInputData("Type amount of charges ").c_str()));
}

void Commands::SetItemPrice()
{
	std::string name = GetInputData("Type item name ");
	gameObjects_->GetItem(name).SetPrice(atoi(GetInputData("Type new Item price ").c_str()));
}

void Commands::LoadItems()
{
	gameObjects_->LoadItems();
}

void Commands::SaveItems()
{
	gameObjects_->SaveItems();
}

void Commands::AddSkill()
{
	Skill tempSkill;
	tempSkill.SetName(GetInputData("Set name = "));
	tempSkill.SetDescription(GetInputData("Set description ( '_' is space) = "));
	tempSkill.SetIconTextureID(GetInputData("Set IconTextureID (Type ID of texture) = "));
	tempSkill.SetTimeOfCooldown(atoi(GetInputData("Set cooldown time = ").c_str()));

	tempSkill.IsTargetingSelf(ConvertToBoolean(GetInputData("Set IsTargetingSelf = ")));
	tempSkill.IsTargetingEnemy(ConvertToBoolean(GetInputData("Set IsTargetingEnemy = ")));
	tempSkill.IsTargetingAlly(ConvertToBoolean(GetInputData("Set IsTargetingAlly = ")));
	tempSkill.IsUsingImmediately(ConvertToBoolean(GetInputData("Set IsUsingImmediately = ")));
	tempSkill.IsUsingOnTarget(ConvertToBoolean(GetInputData("Set IsUsingOnTarget = ")));
	tempSkill.IsUsable(ConvertToBoolean(GetInputData("Set IsUsable = ")));

	tempSkill.SetID(GetInputData("Type Skill's ID = "));

	cout << "Skill '" << tempSkill.GetID() << "' created." << std::endl;

	gameObjects_->AddSkill(inputText_, tempSkill);
}

void Commands::ChangeSkill()
{
	std::string id = GetInputData("Type name of Skill to change");
	GetInputData("Type name of overriding Skill");
	gameObjects_->ChangeSkill(id, gameObjects_->GetSkill(inputText_));
	cout << "Changing from '" << id << "' to '" << inputText_ << "' finished!" << endl;

}

void Commands::RemoveSkill()
{
	GetInputData("Type ID of Skill to remove");
	gameObjects_->RemoveSkill(inputText_);
	cout << "Skill '" << inputText_ << "' removed." << endl;
}

void Commands::ShowSkills()
{
	if (!gameObjects_->GetSkillsKeys().empty())
	{
		cout << "Skills:" << endl;
		for (auto i = 0; i < gameObjects_->GetSkillsKeys().size(); i++)
		{
			std::string key = gameObjects_->GetSkillsKeys()[i];
			cout << "-" << key << endl;
		}
	}
	else std::cout << "There are no Skills :(" << std::endl;
}

void Commands::ShowSkillStats()
{
	std::string name = GetInputData("Type Skill ID ");
	if (gameObjects_->DidSkillExists(inputText_) == true)
	{
		cout << "Name: " << gameObjects_->GetSkill(name).GetName() << endl
			<< "Description: " << gameObjects_->GetSkill(name).GetDescription() << endl
			<< "IconTextureID: " << gameObjects_->GetSkill(name).GetIconTextureID() << endl
			<< "Cooldown: " << to_string(gameObjects_->GetSkill(name).GetTimeOfCooldown()) << endl;

		cout << "IsTargetingSelf: ";
		cout << ConvertToString(gameObjects_->GetSkill(name).IsTargetingSelf()) << endl;

		cout << "IsTargetingEnemy: ";
		cout << ConvertToString(gameObjects_->GetSkill(name).IsTargetingEnemy()) << endl;

		cout << "IsTargetingAlly: ";
		cout << ConvertToString(gameObjects_->GetSkill(name).IsTargetingAlly()) << endl;

		cout << "UseImmediately: ";
		cout << ConvertToString(gameObjects_->GetSkill(name).IsUsingImmediately()) << endl;

		cout << "UseOnTarget: ";
		cout << ConvertToString(gameObjects_->GetSkill(name).IsUsingOnTarget()) << endl;

		cout << "IsUsable: ";
		cout << ConvertToString(gameObjects_->GetSkill(name).IsUsable()) << endl;
	}
}

void Commands::SetSkillID()
{
	std::string id = GetInputData("Type Skill's current ID ");
	gameObjects_->GetSkill(id).SetID(GetInputData("Type new Skills' ID "));
}

void Commands::SetSkillName()
{
	std::string id = GetInputData("Type Skill's ID ");
	gameObjects_->GetSkill(id).SetName(GetInputData("Type new Skill's name "));
}

void Commands::SetSkillDesc()
{
	std::string id = GetInputData("Type Skill's ID ");
	gameObjects_->GetSkill(id).SetDescription(GetInputData("Type new Skill's description "));
}

void Commands::SetSkillIcon()
{
	std::string id = GetInputData("Type Skill's ID ");
	gameObjects_->GetSkill(id).SetIconTextureID(GetInputData("Type new Skill's icon "));
}

void Commands::SetSkillCooldown()
{
	std::string id = GetInputData("Type Skill's ID "); 
	GetInputData("Type new Skill's cooldown time ");
	gameObjects_->GetSkill(id).SetTimeOfCooldown(atoi(inputText_.c_str()));
}

void Commands::SetSkillTargSelf()
{
	std::string id = GetInputData("Type Skill's ID ");
	GetInputData("Set IsSkillTargetingSelf variable = ");
	gameObjects_->GetSkill(id).IsTargetingSelf(ConvertToBoolean(inputText_));
}

void Commands::SetSkillTargEnemy()
{
	std::string id = GetInputData("Type Skill's ID ");
	GetInputData("Set IsSkillTargetingEnemy variable = ");
	gameObjects_->GetSkill(id).IsTargetingEnemy(ConvertToBoolean(inputText_));
}

void Commands::SetSkillTargAlly()
{
	std::string id = GetInputData("Type Skill's ID ");
	GetInputData("Set IsSkillTargetingAlly variable = ");
	gameObjects_->GetSkill(id).IsTargetingAlly(ConvertToBoolean(inputText_));
}

void Commands::SetSkillUseImmediately()
{
	std::string id = GetInputData("Type Skill's ID ");
	GetInputData("Set UseImmediately variable = ");
	gameObjects_->GetSkill(id).IsUsingImmediately(ConvertToBoolean(inputText_));
}

void Commands::SetSkillUseOnTarget()
{
	std::string id = GetInputData("Type Skill's ID ");
	GetInputData("Set UseOnTarget variable = ");
	gameObjects_->GetSkill(id).IsUsingOnTarget(ConvertToBoolean(inputText_));
}

void Commands::SetSkillUsable()
{
	std::string id = GetInputData("Type Skill's ID ");
	GetInputData("Set IsUsable variable = ");
	gameObjects_->GetSkill(id).IsUsable(ConvertToBoolean(inputText_));
}

void Commands::LoadSkills()
{
	gameObjects_->LoadSkills();
}

void Commands::SaveSkills()
{
	gameObjects_->SaveSkills();
}

void Commands::ShowOrders(Effect effect)
{
	for (int i = 0; i <= effect.GetOrdersNumber(); i++)
	{
		cout << "- " << effect.GetFrontOrder() << endl;
		effect.PopOrder();
	}
}


void Commands::CallCommand(std::string commandName)
{
	if (commandsList_.count(commandName) == 1)
		(this->*commandsList_[commandName])();
	else
		throw "Commands::CallCommand(): Command doesn't exists";
}

void Commands::LoadGameObjects(GameObjects * gameObjects)
{
	gameObjects_ = gameObjects;
}
void Commands::SetCommandsDescriptions()
{
	commandsDescriptions_["AddEffect"] = "Creates new Effect.";
	commandsDescriptions_["ShowEffects"] = "Shows all existing Effects.";
	commandsDescriptions_["RemoveEffects"] = "Removes existing Effect.";
	commandsDescriptions_["ChangeEffects"] = "Replaces orders of Effect with other Effect's orders.";
	commandsDescriptions_["ShowOrders"] = "Shows orders of Effect.";
	commandsDescriptions_["SetEffectID"] = "Sets ID of Effect.";
	commandsDescriptions_["LoadEffects"] = "Loads Effects from 'Effects.txt' file.";
	commandsDescriptions_["SaveEffects"] = "Saves Effects to 'Effects.txt' file.";

	commandsDescriptions_["AddItem"] = "Creates new Item.";
	commandsDescriptions_["ChangeItem"] = "Replaces Item's stats with other Item.";
	commandsDescriptions_["RemoveItem"] = "Removes existing Item.";
	commandsDescriptions_["ShowItems"] = "Shows all existing Items.";
	commandsDescriptions_["ShowItemStats"] = "Shows stats of Item.";
	commandsDescriptions_["SetItemName"] = "Sets Item's name.";
	commandsDescriptions_["SetItemDesc"] = "Sets Item's description.";
	commandsDescriptions_["SetItemIcon"] = "Sets the texture of Item's icon.";
	commandsDescriptions_["SetItemCooldown"] = "Sets time of cooldown of Item.";
	commandsDescriptions_["SetItemTargSelf"] = "Set true if Item can target the owner.";
	commandsDescriptions_["SetItemTargEnemy"] = "Set true if Item can target enemy.";
	commandsDescriptions_["SetItemTargAlly"] = "Set true if Item can target ally.";
	commandsDescriptions_["SetItemUseImmediately"] = "Set true if Item is used immediately after click.";
	commandsDescriptions_["SetItemUseOnTarget"] = "Set true if Item is used after focus on the target.";
	commandsDescriptions_["SetItemPerm"] = "Set true if Item is permament.";
	commandsDescriptions_["SetItemUsable"] = "Set true if Item is usable.";
	commandsDescriptions_["SetItemCharges"] = "Changes amount of Item's charges.";
	commandsDescriptions_["SetItemPrice"] = "Changes price of Item in shop.";
	commandsDescriptions_["LoadItems"] = "Loads Items from 'Items.txt' file.";
	commandsDescriptions_["SaveItems"] = "Saves Items to 'Items.txt' file.";

	commandsDescriptions_["AddSkill"] = "Creates new Skill.";
	commandsDescriptions_["ChangeSkill"] = "Replaces Skill's stats with other Skill.";
	commandsDescriptions_["RemoveSkill"] = "Removes existsing Skill.";
	commandsDescriptions_["ShowSkills"] = "Shows all existing Skills.";
	commandsDescriptions_["ShowSkillStats"] = "Shows stats of Skill.";
	commandsDescriptions_["SetSkillName"] = "Sets Skill's name.";
	commandsDescriptions_["SetSkillDesc"] = "Sets Skill's description.";
	commandsDescriptions_["SetSkillIcon"] = "Sets the texture of Skill's icon.";
	commandsDescriptions_["SetSkillCooldown"] = "Sets time of cooldown of Skill.";
	commandsDescriptions_["SetSkillTargSelf"] = "Set true if Skill can target the caster.";
	commandsDescriptions_["SetSkillTargEnemy"] = "Set true if Skill can target enemy.";
	commandsDescriptions_["SetSkillTargAlly"] = "Set true if Skill can target ally.";
	commandsDescriptions_["SetSkillUseImmediately"] = "Set true if Skill is used immediately after click.";
	commandsDescriptions_["SetSkillUseOnTarget"] = "Set true if Skill is used after focus on the target.";
	commandsDescriptions_["SetSkillUsable"] = "Set true if Skill is usable.";
	commandsDescriptions_["LoadSkills"] = "Loads Skills from 'Skills.txt' file.";
	commandsDescriptions_["SaveSkills"] = "Saves Skills to 'Skills.txt' file.";

}
const std::string & Commands::GetInputData()
{
	cin >> inputText_;
	return inputText_;
}

const std::string & Commands::GetInputData(std::string outputText)
{
	cout << outputText;
	cin >> inputText_;
	return inputText_;
}

