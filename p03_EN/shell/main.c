#include <stdlib.h>
#include "parser.h"
#include "auxFunc.h"

int main(int argc, char const *argv[])
{
	command C;
	int r;
	int _exit;

	do
	{
		init_command(&C);

		printPrompt();
		r = read_command(&C,stdin);

		if(r < 0)
			fprintf (stderr, "\nError %d: %s\n",
                             -r, err_messages[-r]);
		else
			_exit = callInternal(&C);

		free_command(&C);

	}while(r==0 && !_exit);

	return 0;
}