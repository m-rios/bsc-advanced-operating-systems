#include "commands.h"

void mypwd(char* path)
{
	//getcwd(path, sizeof(path));
	//	perror(path);
}
char* myls(char* dir,char* arg)
{
	char* _ls = "";
	char* _wd = NULL;
	DIR* _dirp;
	struct dirent* _entry;

	if (dir == NULL)
	{
		//_wd = current directory
	}else
		_wd = dir;

	if ((_dirp = opendir(_wd)) == NULL) //something goes wrong
		perror(_wd);

	if (arg == NULL)
	{
		while((_entry = readdir(_dirp)) != NULL)
		{
			if (_entry->d_name[0] != '.')
			{
				//add somehow d_name to _ls
			}
		}
	}
	else if (strcmp(arg,"-l") == 0) //detailed mode
	{
		while((_entry = readdir(_dirp)) != NULL)
		{
			//do something
		}
	}
	else
		printf("Argument unknown: %s\n",arg );
	

	if (closedir(_dirp) != 0) //something goes wrong
		perror("error when closing directory");
}
void mymkdir(char* dir)
{	
	if (mkdir(dir,0775))
		perror(dir);
}
void myrmdir(char* dir)
{
	if (rmdir(dir))
		perror(dir);
}
void mycd(char* path)
{
	if (chdir(path))
		perror(path);
}
char* mycat(char* _path)
{
	//open file
	int _fd = open(_path,O_RDONLY);
	if (_fd == -1)
		perror(_path);

	//size of the file to read
	char* _file = "";
	int _fileSize = lseek(_fd,0,SEEK_END);
	if (_fileSize != 0)
		_file = (char*) mmap(NULL,_fileSize,PROT_READ,MAP_PRIVATE,_fd,0);

	if (close(_fd)!=0)
		perror("Problem closing file");

	return _file;
}
void mycp(char* source, char* origin)
{
	//create new file
	
}
void myrm(char* file)
{

}