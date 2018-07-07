#include "GameObjects.h"

class Commands
{
	typedef void(Commands::*FnPtr)();
public:

	Commands();
	~Commands();

	const std::string& RunGameObjects();

	void SetCommands();
	void ShowCommands();
	void SetDescription(std::string commandName, std::string commandDescription);
	
	void CallCommand(std::string commandName);

	void LoadGameObjects(GameObjects* gameObjects);
private:
	std::map<std::string, Commands::FnPtr> commandsList_;
	std::map<std::string, std::string> commandsDescriptions_;
	
	void SetCommandsDescriptions();

	bool isRunning_;

	std::string inputText_;

	GameObjects* gameObjects_;
	void ShowOrders(Effect effect);

	const std::string& GetInputData();
	const std::string& GetInputData(std::string outputText);
	
	void AddEffect();
	void ShowEffects();
	void RemoveEffects();
	void ChangeEffects();
	void ShowOrders();
	void SetEffectID();
	void LoadEffects();
	void SaveEffects();

	void AddItem();
	void ChangeItem();
	void RemoveItem();
	void ShowItems();
	void ShowItemStats();
	void SetItemName();
	void SetItemDesc();
	void SetItemIcon();
	void SetItemCooldown();
	void SetItemTargSelf();
	void SetItemTargEnemy();
	void SetItemTargAlly();
	void SetItemUseImmediately();
	void SetItemUseOnTarget();
	void SetItemPerm();
	void SetItemUsable();
	void SetItemCharges();
	void SetItemPrice();
	void LoadItems();
	void SaveItems();

	void AddSkill();
	void ChangeSkill();
	void RemoveSkill();
	void ShowSkills();
	void ShowSkillStats();
	void SetSkillID();
	void SetSkillName();
	void SetSkillDesc();
	void SetSkillIcon();
	void SetSkillCooldown();
	void SetSkillTargSelf();
	void SetSkillTargEnemy();
	void SetSkillTargAlly();
	void SetSkillUseImmediately();
	void SetSkillUseOnTarget();
	void SetSkillUsable();
	void LoadSkills();
	void SaveSkills();


};
