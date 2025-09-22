#include "Character.hpp"

Character::Character(std::string const &name)
{
	this->_name = name;
	this->equip_id = 0;
	for (int i = 0; i < 4; i++)
		this->materials[i] = NULL;
}

Character::Character(Character const & src)
{
	this->_name = src._name;
	this->equip_id = 0;
	for (int i = 0; i < src.equip_id; i++)
		this->equip(src.materials[i]->clone());
	for (int i = this->equip_id; i < 4; i++)
		this->materials[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < this->equip_id; i++)
		delete this->materials[i];
}

Character &Character::operator=(Character const & rhs)
{
	this->_name = rhs._name;
	for (int i = 0; i < this->equip_id; i++)
		delete this->materials[i];
	this->equip_id = 0;
	for (int i = 0; i < rhs.equip_id; i++)
		this->equip(rhs.materials[i]->clone());
	for (int i = this->equip_id; i < 4; i++)
		this->materials[i] = NULL;
	return(*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (this->equip_id >= 4 || !m)
		return ;
	for (int i = 0; i < this->equip_id; i++)
		if (this->materials[i] == m)
			return ;
	this->materials[this->equip_id++] = m;
}

void Character::unequip(int idx)
{
	if (idx >= this->equip_id || idx < 0 || !this->materials[idx])
		return ;
	for (int i = idx; i < 3; i++)
	{
		this->materials[i] = this->materials[i + 1];
		this->materials[i + 1] = NULL;
	}
	this->equip_id--;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= this->equip_id || idx < 0 || !this->materials[idx])
		return ;
	this->materials[idx]->use(target);
}
