#include <stdio.h>
#include <sys/timeb.h>
#include <time.h>
#include <unistd.h>

int main() {

       // milisec를얻기위한_timeb 구조체
       struct timeb timebuffer;

       // 시간을얻기위한tm 구조체
       struct tm *now;
       time_t ltime;
       int milisec;

		int i = 0;
	   while (i < 100) {

       // timebuffer를채운다
       ftime(&timebuffer);
       // time_t 정보를가져온다
       ltime = timebuffer.time;
       // milisec를구한다
       milisec = timebuffer.millitm;
       // time 정보를채운다
       now = localtime(&ltime);

       	printf("%d시%d분%d초%d입니다.\n", now->tm_hour, now->tm_min, now->tm_sec, milisec);
       	usleep(100000);
		i++;
		}
	   return 0;

} 
