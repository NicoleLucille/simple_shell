#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

int main(void);
extern char **environ;
char **parse_data(char *input_string);
char *_getenv(char *name);
char *real_path(char *command);
void process_command(char **arguments);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strchr(char *str, char ch);
char *_strcat(char *dest, char *src);
char *_strdup(char *source_string);
void free_arguments(char **arguments);

#endif
