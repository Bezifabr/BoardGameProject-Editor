#include "Skill.h"
#include <iostream>
#include "Constants.h"


Skill::Skill()
{
}


Skill::~Skill()
{
}

void Skill::SetID(std::string id)
{
	if(!id.empty())
	id_ = id;
}

const std::string & Skill::GetID()
{
	return id_;
}

void Skill::LoadIcon(sf::Texture & textureOfIcon)
{
	if (textureOfIcon.getSize().x <= 64 && textureOfIcon.getSize().y <= 64)
		icon_.setTexture(textureOfIcon);
	else
		std::cout << "ActionObject::LoadIcon(): texture is too big" << std::endl;
}

sf::Sprite & Skill::GetIcon()
{
	return icon_;
}

void Skill::SetName(std::string name)
{
	if (!name.empty())
		name_ = name;
	else
		std::cout << "ActionObject::SetName(): string is empty" << std::endl;
}

std::string & Skill::GetName()
{
	return name_;
}

void Skill::SetDescription(std::string description)
{
	if (!description.empty())
		description_ = description;
	else
		std::cout << "ActionObject::SetDescription(): argument is empty" << std::endl;
}

std::string & Skill::GetDescription()
{
	return description_;
}

int Skill::GetTimeOfCooldown()
{
	return timeOfCooldown_;
}

void Skill::SetTimeOfCooldown(int cooldown)
{
	if (timeOfCooldown_ != cooldown)
		timeOfCooldown_ = cooldown;
	else
		std::cout << "ActionObject::SetTimeOfCooldown(): value of argument is same as value of variable" << std::endl;
}

bool Skill::IsTargetingSelf()
{
	return targetingSelf_;
}

bool Skill::IsTargetingEnemy()
{
	return targetingEnemy_;
}

bool Skill::IsTargetingAlly()
{
	return targetingAlly_;
}

void Skill::IsTargetingSelf(bool isTargeting)
{
	targetingSelf_ = isTargeting;
}

void Skill::IsTargetingEnemy(bool isTargeting)
{
	targetingEnemy_ = isTargeting;
}

void Skill::IsTargetingAlly(bool isTargeting)
{
	targetingAlly_ = isTargeting;
}

bool Skill::IsUsingImmediately()
{
	return useImmediately_;
}

bool Skill::IsUsingOnTarget()
{
	return useOnTarget_;
}

void Skill::IsUsingImmediately(bool useImmediately)
{
	useImmediately_ = useImmediately;
	useOnTarget_ = !useImmediately;
	if (isUsable_ == false)
		isUsable_ = true;
}

void Skill::IsUsingOnTarget(bool useOnTarget)
{
	useOnTarget_ = useOnTarget;
	useImmediately_ = !useOnTarget;
	if (isUsable_ == false)
		isUsable_ = true;
}

void Skill::IsUsable(bool isUseable)
{
	if (isUseable != isUsable_)
		isUsable_ = isUseable;
	else
		std::cout << "ActionObject::IsUseable(): argument is same as value of the variable" << std::endl;
}

bool Skill::IsUsable()
{
	return isUsable_;
}

void Skill::SetIconTextureID(std::string iconTextureID)
{
	iconTextureID_ = iconTextureID;
}

std::string Skill::GetIconTextureID()
{
	return iconTextureID_;
}
