#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	new_list = NULL;
	/* check if lst or f or del is NULL */
	if (!lst || !f || !del)
		return (NULL);
	/* loop over lst */
	while (lst)
	{
		/* create a new element */
		new_node = ft_lstnew(f(lst->content));
		/* if new elem is null, clear the new list */
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		/* add the new element to the back of the list */
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	/* finally, return the new list */
	return (new_list);
}
