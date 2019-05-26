/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   brainfuck.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2018/10/19 15:08:03 by exam          #+#    #+#                 */
/*   Updated: 2018/10/19 17:31:28 by exam          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAINFUCK_H
# define BRAINFUCK_H
# include <unistd.h>
# include <stdlib.h>

int		brainfuck(char *str, char *ptr, char end);
#endif
