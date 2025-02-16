#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	/* declare a new list element */
	
	/* allocate memory for it */
	
	/* set the new element variables 
	 *  * new->content = content
	 *   * new->next = NULL
	 *    */
	
	/* return the new element */
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
