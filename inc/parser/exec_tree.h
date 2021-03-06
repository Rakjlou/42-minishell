/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tree.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/21 20:20:29 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_TREE_H
# define EXEC_TREE_H

typedef struct s_command	t_command;
typedef struct s_iter		t_iter;
typedef struct s_parser		t_parser;

void	exec_tree_run(t_command *tree);
void	exec_tree_dispatch(t_command *node);
void	exec_tree_print(t_command *tree, int level);
void	exec_tree_build(t_parser *parser);
void	exec_tree_build_recursive(t_parser *parser, t_iter *i, t_command **cmd);
void	exec_tree_destroy(t_command *command);

#endif
