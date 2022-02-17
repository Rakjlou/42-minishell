REFERENCE:
bash --posix

ALLOWED FUNCTIONS:

-I know:
printf, malloc, free, write, , open, read,
close, fork, wait, waitpid, exit, execve,
dup, dup2, pipe, perror, access,

-I dont know:
 readline, rl_clear_history, rl_on_new_line,
rl_replace_line, rl_redisplay, add_history,
wait3, wait4, signal,
sigaction, sigemptyset, sigaddset, kill, ,
getcwd, chdir, stat, lstat, fstat, unlink,  opendir, readdir, closedir,
strerror, , isatty, ttyname, ttyslot, ioctl,
getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
tgetnum, tgetstr, tgoto, tputs


BUILT-INS:
◦ echo : option -n
◦ cd with only a relative or absolute path
◦ pwd : no options
◦ export : no options
◦ unset : no options
◦ env : no options or arguments
◦ exit : no options

-Display a prompt when waiting for a new command.
-Have a working history.
-Search and launch the right executable (based on the PATH variable or using a
relative or an absolute path).

Difference between env variable and global/system var?
