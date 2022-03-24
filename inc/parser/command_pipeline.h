/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_pipeline.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 01:33:07 by nsierra-          #+#    #+#             */
/*   Updated: 2022/03/24 17:38:41 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_PIPELINE_H
# define COMMAND_PIPELINE_H

# define PIPE_WRITE 1
# define PIPE_READ 0

typedef struct s_command	t_command;
typedef struct s_iter		t_iter;
typedef struct s_parser		t_parser;

typedef struct s_command_pipeline
{
	int	fds[2];
}	t_command_pipeline;

void		command_pipeline_run(t_command *command);
void		command_pipeline_build(t_parser *parser, t_iter *i, t_command **c);
void		command_pipeline_debug(t_command *command);

void		pipeline_close(void);
int			pipeline_is_active(void);
int			pipeline_is_first(void);
int			pipeline_is_middle(void);
int			pipeline_is_last(void);
int			pipeline_handle(t_command *command);
void		pipeline_fork_parent(t_command *command);
t_command	*pipeline_get_parent(t_command *command);
t_command	*pipeline_get_previous(t_command *command);

#endif
