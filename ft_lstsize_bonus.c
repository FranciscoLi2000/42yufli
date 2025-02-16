#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	/* loop over the list */
	/* return the count */
	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
