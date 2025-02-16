#include "libft.h"
/* This functions works similarly as the ft_lstdelone function, but instead of removing only one element,
it removes the element passed as parameter as well as all the following elements */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
