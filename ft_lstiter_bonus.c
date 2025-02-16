#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	/* loop over the entire list */
	/* apply the function 'f' to the content of each elements */
	if (!f || !lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
