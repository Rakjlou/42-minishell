---------SIMPLE COMMAND------------
ARGS:
	>> mdr"salut
	>> '
	>> '
	>> *
	>> '*'
	>> oui"
-----------------------------------

- STEP 3
	Pathname expansion shall be performed
	Si IFS est set, pas de pathname expansion

	opendir:
	DIR *opendir(const char *name);
	--> return NULL si error (errno est set)
	--> free ptr??

	readdir:
	struct dirent *readdir(DIR *dirp);
	--> return un pointeur sur structure
	    struct dirent 
			{
               ino_t          d_ino;       /* Inode number */				guaranted by POSIX
               char           d_name[256]; /* Null-terminated filename */	guaranted by POSIX
			   unsigned short d_reclen;    /* Length of this record */

           };
	-->return NULL si plus rien a lire ou erreur
	--> free ptr??
	--> exclure . et ..

	closedir:
	int closedir(DIR *dirp);
	--> return -1 if error

---------SIMPLE COMMAND------------
ARGS:
	>> mdr"salut
	>> '
	>> '
	>> Makefile
	>> libft/
	>> inc/
	>> src/
	>> ...
	>> '*'
	>> oui"
-----------------------------------
