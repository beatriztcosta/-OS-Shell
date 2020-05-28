#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <sys/wait.h>
#include <math.h>
#include <dirent.h>

typedef struct { 
    char msg[100]; 
    int tempo;
} aviso_t;

typedef struct { 
    int in; 
    int out; 
}copiar_t;

typedef struct  {
    ino_t d_ino;/* i node number */
    char d_name[NAME_MAX+1];/* null-terminated filename */

} dirent ;

int parse(char *buf, char **args);

void execute(char **args, int noArgs);

int builtin (char **args, int noArgs);

int socplow(int in, int out);

void *socp(void* args);

void calc(char *value1, char *op, char *value2);

void bits(char *op1, char *op, char *op2);

int isjpg (int fileDescriptor);

int redirects (int numargs, char *args[]);

int containsPipe (int numArgs, char **args);

int ultimo (char **args, int *noArgs);

void aviso(char *xmsg, int tempo);

void *avisowrapper (void *args);

void sols(int argc, char **argv);


/* constantes que podem tornar uteis*/

#define BG 0
#define FG 1
