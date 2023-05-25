#include "libft.h"

void	ft_dlstadd_down(t_dlist **olst, t_dlist *nlst)
{
	t_dlist *tmp;

	if (!olst || !nlst)
		return ;
	if (*olst == NULL)
	{
		*olst = nlst;
		return ;
	}
	tmp = *olst;
	while (tmp->down)
		tmp = tmp->down;
	tmp->down = nlst;
}
