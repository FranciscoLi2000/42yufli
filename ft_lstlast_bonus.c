#include "libft.h"
/* For this one, we basically have to do the same thing as for the ft_lstsize function but we don't need to count how many elements are in the list nor return the count, but we directly return the tmp element*/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
