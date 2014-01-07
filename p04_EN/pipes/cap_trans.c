#include "cap_trans.h"
int caps(int readend, int writeend)
{
	int i, r;
	char buff[SIZE];

	srand((unsigned)getpid() ^ (unsigned) time(NULL));

	for(;;)
	{
		r = read(readend, buff, SIZE);


		if (r< 0)
			break;					//something went wrong
		else if (r == 0)			//pipe closed
		{
			close(writeend);		//close other one
			return 0;
		}							//some letters to capitals

		printf("Data of %d: %s\n", getpid(),buff);

		for (i=0; buff[i]; i++)
			if (rand() > RAND_MAX/2)
				if (buff[i] >= 'a' && buff[i] <= 'z')
					buff[i] -= ('a' - 'A');
									//send back

		if (write(writeend, buff, 1+strlen(buff)) < 0)
			break;
		
		//return 0;
	}
	perror("caps");
	return -1;
}