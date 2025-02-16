#include "libft.h"
/* use the delete function on the element's content */
/* free the element */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
