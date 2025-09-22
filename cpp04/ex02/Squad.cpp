#include "ISquad.hpp"
#include "Squad.hpp"
#include "ISpaceMarine.hpp"

Squad::Squad(Squad const & src)
{
	this->_count = 0;
    this->_last = 0;
    this->_list_ptr = NULL;
	for(int i = 0; i < src.getCount(); i++)
		this->push(src.getUnit(i)->clone());
}

Squad & Squad::operator=(Squad const & rhs)
{
	if (this->_list_ptr)
	{
		ft_lstfree(&this->_list_ptr);
		this->_last = 0;
	}
	this->_count = 0;
	for (int i = 0; i < rhs.getCount(); i++)
		this->push(rhs.getUnit(i)->clone());
	return(*this);
}

Squad::Squad() : ISquad()
{
    this->_count = 0;
    this->_last = 0;
    this->_list_ptr = NULL;
}

Squad::~Squad()
{
	if (this->_last == 0)
		return ;
	else
	{
		ft_lstfree(&this->_list_ptr);
		this->_last = 0;
	}
	return ;
}

int Squad::getCount() const
{
    return (this->_count);
}

ISpaceMarine* Squad::getUnit(int unit) const
{
    return (ft_lstN(_list_ptr, unit));
}

int Squad::push(ISpaceMarine* one)
{
	if (!one)
		return(this->_count);
    if (this->_last == 0)
	{
        this->_list_ptr = ft_lstnew((void *)one);
		this->_last = one;
    	this->_count++;
	}
    else
    {
        t_list *add = ft_lstnew((void *)one);

        ft_lstadd_back(&_list_ptr, add);
    }
    return (this->_count);
}

ISpaceMarine *Squad::ft_lstN(t_list *lst, int N) const
{
	if (!lst)
		return (NULL);
	while (N--)
		lst = lst->next;
	return ((ISpaceMarine *)lst->content);
}

t_list	*Squad::ft_lstnew(void *content)
{
	t_list *new_node;

	new_node = new t_list;
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

t_list	*Squad::ft_lstlast_check(t_list *lst, t_list *add)
{
	if (!lst)
		return (NULL);
	if ((ISpaceMarine *)lst->content == (ISpaceMarine *)add->content)
		{
			std::cout << "You try to add same Unit. Can't do!" << std::endl;
			return (NULL);
		}
	while (lst->next)
	{
		if ((ISpaceMarine *)lst->content == (ISpaceMarine *)add->content)
		{
			std::cout << "You try to add same Unit. Can't do!!" << std::endl;
			return (NULL);
		}
		lst = lst->next;
	}
	return (lst);
}

void	Squad::ft_lstadd_back(t_list **lst_ptr, t_list *add)
{
	t_list *new_node;

	if (!add)
		return ;
	if (!(*lst_ptr))
	{
		*lst_ptr = add;
		return ;
	}
	new_node = ft_lstlast_check(*lst_ptr, add);
	if (!new_node)
		delete add;
	else
	{
		new_node->next = add;
		this->_last = (ISpaceMarine *)add->content;
    	this->_count++;
	}
}

void	Squad::ft_lstfree(t_list **lst_ptr)
{
	t_list *tmp;

	if (!(*lst_ptr))
		return ;
	while (*lst_ptr)
	{
		tmp = *lst_ptr;
		*lst_ptr = ((*lst_ptr)->next);
		delete (ISpaceMarine *)tmp->content;
		delete tmp;
	}
	return ;
}
