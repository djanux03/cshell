#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
void readFromFolder();
int main(void)
{

  printf("=====================================\n");
  printf("=====================================\n");
  printf("start of directory program\n");


  char input[128]; 
  char *argv[] = {"sh", "-c", input, 0}; 
  if(fgets(input, 128, stdin) != 0)
  {
    execvp(argv[0], argv);
    fprintf(stderr, "Failed to exec shell on %s", input);
    return 1;
  }

  return 0;
}

void readFromFolder()
{
  DIR *directory;
  struct dirent *entry;

  directory = opendir("/usr/bin/");

  if(directory == NULL)
  {
    printf("Error opening directory.\n");
  }
  while((entry = readdir(directory)) != NULL)
  {
    printf("%s\n", entry->d_name);
  }

  if(closedir(directory) == -1)
  {
    printf("Error closing directory.\n");
  }

}
