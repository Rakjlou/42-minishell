Signals:
- Ctrl + C
- Ctrl + D
- Ctrl + \

	sighandler_t signal(int signum, sighandler_t handler);  
signal() renvoie la valeur précédente du gestionnaire de signaux, ou SIG_ERR en cas d'erreur.  
Si le gestionnaire est SIG_DFL, l'action par défaut associé à ce signal est entreprise, comme décrit dans signal(7).
Si le gestionnaire est SIG_IGN, le signal est ignoré.


	int sigaction(int signum, const struct sigaction *act,
              struct sigaction *oldact);



• In interactive mode:
◦ ctrl-C displays a new prompt on a new line.
◦ ctrl-D exits the shell.
◦ ctrl-\ does nothing.



SIGNALS:
"A signal is managed in a cascading manner. It's sent to the application or script, then if the application doesn't have a specific handler (signal management or response function), it's pushed back to the shell or operating system"

Ctrl+D: EOF
Close the bash shell. This sends an EOF (End-of-file) marker to bash, and bash exits when it receives this marker. This is similar to running the exit command.

Ctrl+C: SIGINT
"Interrupt (kill) the current foreground process running in in the terminal. This sends the SIGINT signal to the process, which is technically just a request—most processes will honor it, but some may ignore it."
- A la ligne en mode interactif
- return 1 en mode interactif


Ctrl + \: SIGQUIT
