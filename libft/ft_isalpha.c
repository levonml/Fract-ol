/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 11:44:53 by lstepany          #+#    #+#             */
/*   Updated: 2020/07/07 10:35:09 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (((c <= 'Z') && (c >= 'A')) || ((c <= 'z') && (c >= 'a')))
		return (1);
	return (0);
}
