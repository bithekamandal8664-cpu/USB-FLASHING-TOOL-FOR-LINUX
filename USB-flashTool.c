#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
char file[100];
char destination[1000];
int speed;
char command[1000];
char confirmation[10];

printf("WARNING:- THIS PROGRAM OVERWRITES DATA WITHOUT WARNING, USE AT UR OWN RISK");
printf("WANT TO CONTINUE?:-");
fgets(confirmation, sizeof(confirmation), stdin);
confirmation[strlen(confirmation) -1] ='\0';
if (strcmp(confirmation, "yes") == 0) {

chdir("Downloads");
printf("Changed directory for user-friendly improvements\n");
printf("type your filename:-");
fgets(file, sizeof(file), stdin);
file[strlen(file) -1] = '\0';

printf("which destination you want the file to be written?:-");
fgets(destination, sizeof(destination), stdin);
destination[strlen(destination) - 1] = '\0';
printf("how much block size you want (in M)?:-");
scanf("%d", &speed);
if (strstr(destination, "/dev/sda") != NULL) {
printf(" you cant target your main drive!");
return 1;
}
else if (strstr(file, ".exe") != NULL)  {
printf("you are supposed to write .ISO files, not winslop one");
return 1;
}
printf("executing...");
snprintf(command, sizeof(command), "sudo dd if=%s of=%s  bs=%dM status=progress conv=fsync", file, destination, speed);
system(command);
return 0;
}
else if (strcmp(confirmation, "no") == 0) {
printf("exiting... have fun!\n");
system("xdg-open https://m.youtube.com/watch?v=QDia3e12czc&pp=ygUIcmlja3JvbGw%3D");
return 0;
}
return 0;
}
