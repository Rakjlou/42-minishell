
export TEST=mdr"salut   '   '  * '*'     oui"
echo $TEST

---------SIMPLE COMMAND------------
ARGS:
	>> $TEST (WORD)
-----------------------------------

- STEP 1
	Parameter Expansion shall be performed, beginning to end.
	-Param expansion infinie? fonction dans une boucle while?

	input possible:
	- $USER --> ajung
	- ${USER} --> ajung PAS A GERER
	- "$USER" --> ajung (NO FIELDSPLIT, NO PATHNAM EXP)
	- '$USER' --> ajung
	- $ndfjkdnkf --> vide


	If a parameter expansion occurs inside double-quotes:

		-Pathname expansion shall not be performed on the results of the expansion.
		-Field splitting shall not be performed on the results of the expansion.

	

	>> $TEST (WORD) TEST=mdr"salut   '   '  * '*'     oui"

---------SIMPLE COMMAND------------
ARGS:
	>> mdr"salut   '   '  * '*'     oui"
-----------------------------------

>>STEP 1 : ft trouver $ valide et renvoie la var d'env
- find start et end de la var env
- $ est valide si il n'est PAS dans ' '
- $ cas special si $ est dans ""
