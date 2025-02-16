#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	/* set the new element's next address to point 
	 *  * to the start of the existing list
	 *   */

	/* set the existing list pointer to point to the new element
	 *  */
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
