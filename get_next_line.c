/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiyauch <rmiyauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:11:18 by rmiyauch          #+#    #+#             */
/*   Updated: 2024/05/05 14:31:25 by rmiyauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer(int fd, char *save_buffer, char *save_line)
{
	int	return_read_bytes;

	return_read_bytes = 1;
	while (!ft_strchr(save_line, '\n') && return_read_bytes != 0)
	{
		return_read_bytes = read(fd, save_buffer, BUFFER_SIZE);
		if (return_read_bytes == -1)
		{
			free(save_buffer);
			return (NULL);
		}
		if (return_read_bytes == 0 && (save_line == NULL
				|| save_line[0] == '\0'))
		{
			free(save_line);
			free(save_buffer);
			return (NULL);
		}
		save_buffer[return_read_bytes] = '\0';
		save_line = ft_strjoin(save_line, save_buffer);
	}
	free(save_buffer);
	return (save_line);
}

char	*extract_line(char *save_line)
{
	unsigned long long	i;
	char				*tmp_line;

	i = 0;
	while (save_line[i] && save_line[i] != '\n')
		i++;
	tmp_line = (char *)malloc(sizeof(char) * (i + 2));
	if (tmp_line == NULL)
		return (NULL);
	i = 0;
	while (save_line[i] && save_line[i] != '\n')
	{
		tmp_line[i] = save_line[i];
		i++;
	}
	if (save_line[i] == '\n')
		tmp_line[i++] = '\n';
	tmp_line[i] = '\0';
	return (tmp_line);
}

char	*update_save_line(char *save_line)
{
	unsigned long long	i;
	unsigned long long	j;
	char				*tmp;

	i = 0;
	while (save_line[i] && save_line[i] != '\n')
		i++;
	if (save_line[i] == '\0')
	{
		free(save_line);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(save_line) - i + 1));
	if (tmp == NULL)
	{
		free(save_line);
		return (NULL);
	}
	i++;
	j = 0;
	while (save_line[i])
		tmp[j++] = save_line[i++];
	tmp[j] = '\0';
	free(save_line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*save_line;
	char		*line;
	char		*save_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save_buffer = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (save_buffer == NULL)
		return (NULL);
	save_line = read_buffer(fd, save_buffer, save_line);
	if (save_line == NULL)
		return (NULL);
	line = extract_line(save_line);
	save_line = update_save_line(save_line);
	return (line);
}
