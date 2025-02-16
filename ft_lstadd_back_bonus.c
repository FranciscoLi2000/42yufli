#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	/* get the last element of the list */
	/* set the last->next variable to point to the new element */
	/* if last is NULL, make the list pointer point to the new element */
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}
