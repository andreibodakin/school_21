/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klavada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:20:05 by klavada           #+#    #+#             */
/*   Updated: 2020/11/02 16:20:19 by klavada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int     ft_strlen(const char *s);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strcpy(char *dst, const char *src);
char    *ft_strdup(const char *s1);

int     read_test(ssize_t (*f)(int, void *, size_t), char *path, char *buffer, int size)
{
    int     fd;
    int     ret;

    if ((fd = open(path, O_RDONLY)) == -1)
    {
        printf("Can't open file: %s\n", path);
        exit(EXIT_FAILURE);
    }
    if ((ret = f(fd, buffer, size)) == -1)
    {
        printf("read error\n");
        exit(EXIT_FAILURE);
    }
    buffer[ret] = '\0';
    close(fd);
    return (ret);
}

int main(void)
{
    printf(".............TEST.............\n");
    printf("\n***testing ft_strlen***\n");
    printf("Test #1 : %d\n", strlen("") == ft_strlen(""));
    printf("Test #2 : %d\n", strlen("123456") == ft_strlen("123456"));

    printf("\n***testing ft_write***\n");
    ssize_t ret, ret_ft;

    ret = write(1, "Hello from stdout\n", 18);
    ret_ft = ft_write(1, "Hello from stdout\n", 18);
    printf("Test #1 : %d\n", ret == ret_ft);
    fflush (stdout);

    ret = write(2, "Hello from stderr\n", 18);
    ret_ft = ft_write(2, "Hello from stderr\n", 18);
    printf("Test #2 : %d\n", ret == ret_ft);
    fflush (stdout);

    ret = write(9000, "Hello from non existing fd\n", 27);
    ret_ft = ft_write(9000, "Hello from non existing fd\n", 27);
    printf("Test #3 : %d\n", ret == ret_ft);
    fflush (stdout);

    printf("\n***testing ft_read***\n");
    char buffer[1000], buffer_ft[1000];

    ret = read_test(read, "./Makefile", buffer, 10);
    ret_ft = read_test(ft_read, "./Makefile", buffer_ft, 10);
    printf("Test #1 : compare difference: %d, return value : return value : %d\n", strcmp(buffer, buffer_ft), ret == ret_ft);

    ret = read_test(read, "./Makefile", buffer, 100);
    ret_ft = read_test(ft_read, "./Makefile", buffer_ft, 100);
    printf("Test #2 : compare difference: %d, return value : return value : %d\n", strcmp(buffer, buffer_ft), ret == ret_ft);
    
    printf("\n***testing ft_strcmp***\n");
    strcpy(buffer, "");
    printf("Test #1 : compare difference: %d | %d\n", strcmp(buffer, ""), ft_strcmp(buffer, ""));
    strcpy(buffer, "abcdef");
    printf("Test #2 : compare difference: %d | %d\n", strcmp(buffer, "abcdef"), ft_strcmp(buffer, "abcdef"));
    strcpy(buffer, "very long text very long text very long text very long text very long text very long text very long text ");
    printf("Test #2 : compare difference: %d | %d\n", strcmp(buffer, "very long text very long text very long text very long text very long text very long text very long text "),
     ft_strcmp(buffer, "very long text very long text very long text very long text very long text very long text very long text "));

    printf("\n***testing ft_strcpy***\n");
    printf("Test #1 compare difference: %d\n", strcmp(strcpy(buffer, ""), ft_strcpy(buffer_ft, "")));
    printf("Test #2 compare difference: %d\n", strcmp(strcpy(buffer, "abcdef"), ft_strcpy(buffer_ft, "abcdef")));

    printf("\n***testing ft_strdup***\n");
    printf("Test #1 compare difference: %d\n", strcmp(strdup(""), ft_strdup("")));
    printf("Test #2 compare difference: %d\n", strcmp(strdup("abcdef"), ft_strdup("abcdef")));

    return (0);
}
