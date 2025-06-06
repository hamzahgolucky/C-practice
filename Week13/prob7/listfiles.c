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
	char *location;
	if (a) location = va_arg(args, char*);
	else location = ".";
	DIR *d;
  	struct dirent *dir;
  	d = opendir(location);
  	if (d) {
  		while ((dir = readdir(d)) != NULL) {
    		if (dir->d_type == DT_REG)
		{
			//printf("%ld ",fsize(location));
			printf("%s/%s\n", location, dir->d_name);
		}
		if(dir -> d_type == DT_DIR && strcmp(dir->d_name,".")!=0 && strcmp(dir->d_name,"..")!=0 )
		{
			printf("%s/%s\n", location, dir->d_name);
			char temp[254];
			sprintf(temp,"%s/%s",location,dir->d_name);
			listfiles(1,temp);
		}
	}
	closedir(d);
	}
}

int main(int argc, char *argv[]) {
	if (argc>1) 
		listfiles(1,argv[1]);
	else listfiles(0);
	return(0);
}
