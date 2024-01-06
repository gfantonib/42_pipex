/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:32:42 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/06 11:31:38 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_move_start(char *start)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\0')
	{
		free(start);
		return (NULL);
	}
	i += (start[i] == '\n');
	new_buff = (char *)malloc(1 + ft_strlen_gnl(start) - i);
	if (!new_buff)
		return (NULL);
	j = 0;
	while (start[i + j])
	{
		new_buff[j] = start[i + j];
		j++;
	}
	new_buff[j] = '\0';
	free (start);
	return (new_buff);
}

char	*ft_readed_line(char *start)
{
	int		i;
	char	*line;

	if (!start || ! start[0])
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\n')
		i++;
	line = (char *)malloc(1 + i * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
	{
		line[i] = start[i];
		i++;
	}
	if (start[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_get_line(int fd, char *tmp, char **start_str)
{
	int			fd_read;

	fd_read = 1;
	while (!(ft_strchr_gnl(*start_str, '\n')) && fd_read != 0)
	{
		fd_read = read(fd, tmp, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(tmp);
			free(*start_str);
			*start_str = NULL;
			return (NULL);
		}
		tmp[fd_read] = '\0';
		*start_str = ft_strjoin_gnl(*start_str, tmp);
	}
	free(tmp);
	tmp = ft_readed_line(*start_str);
	*start_str = ft_move_start(*start_str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	static char	*start_str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp = ft_get_line(fd, tmp, &start_str[fd]);
	return (tmp);
}
