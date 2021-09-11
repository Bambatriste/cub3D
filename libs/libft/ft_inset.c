/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aedouard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:44:01 by aedouard          #+#    #+#             */
/*   Updated: 2021/05/26 11:56:32 by aedouard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_inset(char c, char *set)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (set[i])
	{
		if (set[i] == c)
			ret = 1;
		i++;
	}
	return (ret);
}
