/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookycho <yookycho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:05:55 by yookycho          #+#    #+#             */
/*   Updated: 2024/08/10 16:27:25 by yookycho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 42

char	*get_next_line(int fd)
{
	static char		*backup;
	char			*line;
	char			*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL); 
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (free(buf), NULL);
	backup = ft_file_read(fd, backup, buf);
	free(buf);
	if (!backup)
		return (NULL);
	line = ft_get_line(backup);
	backup = ft_get_backup(backup);
	return (line);
}

char *ft_get_backup(char *backup)
{
    char *new_backup;
    int i;
    int j;

    i = 0;
    while (backup[i] && backup[i] != '\n')
        i++;
    if (!backup[i])
    {
        free(backup); // Free backup if no newline is found
        return (NULL);
    }
    new_backup = malloc(sizeof(char) * (ft_strlen(backup) - i + 1)); // Allocate memory for new backup
    if (!new_backup)
        return (NULL);
    i++;
    j = 0;
    while (backup[i])
        new_backup[j++] = backup[i++];
    new_backup[j] = '\0';
    free(backup); // Free the old backup
    return (new_backup);
}


char *ft_file_read(int fd, char *backup, char *buf)
{
    char *temp; // Added a temporary pointer
    int eof_check;

    eof_check = 1;
    while (eof_check != 0)
    {
        eof_check = read(fd, buf, BUFFER_SIZE);
        if (eof_check == -1)
            return (free(backup), NULL);
        buf[eof_check] = '\0';
        if (!backup)
        {
            backup = ft_strdup(buf); // Changed to directly assign strdup result
        }
        else
        {
            temp = ft_strjoin(backup, buf); // Use temp to hold new joined string
            free(backup); // Free previous backup
            backup = temp; // Assign new string to backup
        }
        if (ft_strchr(backup, '\n'))
            break ;
    }
    return (backup);
}


char *ft_get_line(char *backup)
{
    char *line;
    int i;

    if (!backup || !*backup)
        return (NULL); // Check if backup is NULL or empty
    i = 0;
    while (backup[i] && backup[i] != '\n')
        i++;
    line = malloc(sizeof(char) * (i + 2)); // Allocate memory for line
    if (!line)
        return (NULL);
    i = 0;
    while (backup[i] && backup[i] != '\n')
    {
        line[i] = backup[i];
        i++;
    }
    if (backup[i] == '\n')
    {
        line[i] = backup[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}


//  #include <fcntl.h>
//  #include <stdio.h> 
 
//  int main(void)
//  {
//    int fd;
//    char *line;

//    fd = open("./test.txt", O_RDONLY);
//    if (fd == -1)
//    {
//      perror("못읽어요 안돼요");
//      return 1;
//    }
// 	int idx = 1;
//    line = get_next_line(fd);   
//    while (line != NULL)
//    {
//      printf("line no.%d = %s", idx,line);
//      free(line);
//      line = get_next_line(fd);
// 	 idx++;
//    }

//    if (line == NULL)
//    {
//      printf("\n");
//    }
//    free(line);
//    close(fd);
//    return 0;
//  }