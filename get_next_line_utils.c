/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:11:15 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/05/04 23:01:53 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*t;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	t = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (t == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		t[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		t[i++] = s2[j++];
	t[i] = '\0';
	free(s1);
	return (t);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	size;

	i = 0;
	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	while (i <= size)
	{
		if (s[i] == ((char)(c)))
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
