#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>
#include <string.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

void listfiles(int a, ...){
	va_list args;
	va_start(args, a);
	char *location, *fileend;
	if (a==1) {
		location = va_arg(args, char*);
		if (memchr(location,'/',1) == NULL) {
			printf("./listfiles 'path starting with /' 'search query'\n            ^^^^^^^^^^^^^^^^^^^^^^\n              you got this wrong\n");
			exit(1);
		}
	}
	else if (a==2) {
		location = va_arg(args, char*);
		if (memchr(location,'/',1) == NULL) {
			printf("./listfiles 'path starting with /' 'search query'\n            ^^^^^^^^^^^^^^^^^^^^^^\n              you got this wrong\n");
			exit(1);
		}
		fileend = va_arg(args, char*);
	}
	else location = ".";
	DIR *d;
  	struct dirent *dir;
  	d = opendir(location);
  	if (d) {
  		while ((dir = readdir(d)) != NULL) {
    		if (dir->d_type == DT_REG)
		{
			if (a==1 || a==0) printf("%s/%s\n", location, dir->d_name);
			else {
				char *find = strstr(dir->d_name,fileend);
				if (find != NULL) printf("%s/%s\n", location, dir->d_name);
			}
		}
		if (dir -> d_type == DT_DIR && strcmp(dir->d_name,".")!=0 && strcmp(dir->d_name,"..")!=0)
		{
			//printf("%s/%s\n", location, dir->d_name);
			char temp[254];
			sprintf(temp,"%s/%s",location,dir->d_name);
			if (a==2) listfiles(2,temp,fileend);
			else listfiles(1,temp);
		}
		}
	closedir(d);
	}
}

int main(int argc, char *argv[]) {
	if (argc==2) 
		listfiles(1,argv[1]);
	else if (argc==3)
		listfiles(2,argv[1],argv[2]);
	else listfiles(0);
	return(0);
}
