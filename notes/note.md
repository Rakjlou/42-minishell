REFERENCE:
bash --posix

ALLOWED FUNCTIONS:

-I know:
printf, malloc, free, write, , open, read,
close, fork, wait, waitpid, exit, execve,
dup, dup2, pipe, perror, access,
readline, rl_on_new_line,
rl_replace_line, rl_redisplay,
  opendir, readdir, closedir,

-I dont know:
 , rl_clear_history,  add_history,
wait3, wait4, signal,
sigaction, sigemptyset, sigaddset, kill, ,
getcwd, chdir, stat, lstat, fstat, unlink,
strerror, , isatty, ttyname, ttyslot, ioctl,
getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
tgetnum, tgetstr, tgoto, tputs




-Display a prompt when waiting for a new command.
-Have a working history.
-Search and launch the right executable (based on the PATH variable or using a
relative or an absolute path).

Difference between env variable and global/system var?
