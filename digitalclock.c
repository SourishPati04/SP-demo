#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int main (){
time_t rawtime;
struct tm*timeinfo;
while(1){
time(&rawtime);
timeinfo = localtime (&rawtime);
printf("\r%02d:%02d:%02d:",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
fflush(stdout);
sleep(1);

}

return 0;
}
