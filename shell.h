#ifndef _SHELL_H
#define _SHELL_H

/*###### environ var ######*/

extern char **environ;

/*##### MACROS ######*/

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))

/*###### LIBS USED ######*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>





/*###### STRING FUNCTION ######*/

char *_stringtoken(char *str, const char *tok);
unsigned int check_diff(char c, const char *str);
char *_stringcopy(char *dest, char *src, int n);
int _stlength(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _stcmp(char *s1, char *s2);
int _isalphabet(int c);
void arr_rv(char *arr, int len);
int intlength(int num);
char *_itoa(unsigned int n);
char *_stct(char *dest, char *src);
char *_stcp(char *dest, char *src);
char *_stchr(char *s, char c);
int _stringcmp(const char *s1, const char *s2, size_t n);
char *_stdp(char *str);

/*###### MEMORIE  MANGMENT ####*/

void free_env(char **env);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void  free_all(char **input, char *line);

/*###### INPUT Function ######*/

void prompt(void);
void signal_to_handel(int sig);
char *_getline(void);

/* ###### Command parser and extractor ###*/

int path_cmd(char **line);
char *_getenv(char *name);
char **p_cmd(char *cmd);
int handle_builtin(char **cmd, int er);
void read_file(char *filename, char **argv);
char *build(char *token, char *value);
int is_builtin(char **cmd);
void creat_envi(char **envi);
int check_cmd(char **tokens, char *line, int count, char **argv);
void treat_file(char *line, int counter, FILE *fd, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);

/* ####BUL FUNC #####*/

void hashtag_handle(char *buff);
int history(char *input);
int history_display(char **cmd, int er);
int ds_envir(char **cmd, int er);
int ch_directory(char **cmd, int er);
int dis_hlp(char **cmd, int er);
int echo_bul(char **cmd, int er);
void  ex_bl(char **cmd, char *input, char **argv, int c);
int pr_echo(char **cmd);

/* ####error handle and Printer ####*/
void print_no(unsigned int n);
void print_no_in(int n);
void print_error(char *line, int c, char **argv);
void _prerror(char **argv, int c, char **cmd);


/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#endif
