/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:48:03 by mintan            #+#    #+#             */
/*   Updated: 2024/05/28 10:46:56 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/* Description: Allocates with malloc(3) and returns a substring from the
   string s. The substring begins at index 'start' and is of the maximum size
   'len'. */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len <= ft_strlen(s) - start)
		ptr = (char *)malloc((len + 1) * sizeof(char));
	else
		ptr = (char *)malloc((ft_strlen(s) - start + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	if (len <= ft_strlen(s) - start)
	{
		ft_memcpy(ptr, (s + start), len);
		*(ptr + len) = '\0';
	}
	else
	{
		ft_memcpy(ptr, (s + start), ft_strlen(s) - start);
		*(ptr + ft_strlen(s) - start) = '\0';
	}
	return (ptr);
}
