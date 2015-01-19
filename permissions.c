#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(char *s1, char *s2){
    char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the zero-terminator
    //in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
char* getCommand(char* command, char *file){
    char* s;
    if (strcmp(command, "-r") == 0){
        s = concat(concat("if [ -r \"",file),"\" ]; then echo can read; else echo cannot read; fi");
    }else if (strcmp(command, "-w") == 0){
        s = concat(concat("if [ -w \"",file),"\" ]; then echo can write; else echo cannot write; fi");
    }else if (strcmp(command, "-f") == 0){
        s = concat(concat("if [ -f \"",file),"\" ]; then echo file exists; else echo file does not exist; fi");
    }
    return s;

}
void* doTest(char *file){
   char* cmd_f = getCommand("-f", file);
   char* cmd_r = getCommand("-r", file);
   char* cmd_w = getCommand("-w", file);

   printf("Whoami:\r\n" );
   system("whoami");

//   printf("Commands to run: \r\n %s \r\n %s \r\n %s \r\n", cmd_f, cmd_r, cmd_w);

   printf("File \"%s\": \r\n", file);
   system(cmd_f);
   system(cmd_r);
   system(cmd_w);
}

int main( int argc, char *argv[] ) {
   if ( argc < 2 ) {
      printf("Please enter the filename \r\n");
      return 1;
   }
   char* file = argv[1];

   doTest(file);

   setuid( getuid() );

   doTest(file);

   return 0;
}
