#ifndef CHARACTER_H
# define CHARACTER_H

#include "ICharacter.hpp"
#include "AMateria.hpp"

class   Character : public ICharacter
{
	private:
		Character();
		
		std::string _name;
		int equip_id;
		AMateria *materials[4];
	public:
		Character(std::string const &name);
		Character(Character const & src);
		~Character();

		Character &operator=(Character const & rhs);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
