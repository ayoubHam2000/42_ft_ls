/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_permission.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:07:26 by aben-ham          #+#    #+#             */
/*   Updated: 2024/09/04 10:07:35 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	set_permission(int val, char c)
{
	if (val)
		return (c);
	return ('-');
}
