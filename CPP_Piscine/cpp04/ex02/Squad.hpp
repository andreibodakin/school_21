#ifndef SQUAD_H
# define SQUAD_H

#include "ISquad.hpp"

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

class Squad : public ISquad
{
private:
    Squad(Squad const & src);
    int             _count;
    t_list          *_list_ptr;
    ISpaceMarine*   _last;

    t_list          *ft_lstnew(void *content);
    t_list	        *ft_lstlast_check(t_list *lst, t_list *add);
    void            ft_lstadd_back(t_list **lst_ptr, t_list *add);
    void            ft_lstfree(t_list **lst_ptr);

public:
    Squad();
    virtual ~Squad();

    ISpaceMarine *ft_lstN(t_list *lst, int N) const;

    int getCount() const;
    ISpaceMarine* getUnit(int unit) const;
    int push(ISpaceMarine* one);

    Squad & operator=(Squad const & rhs);
};

#endif
