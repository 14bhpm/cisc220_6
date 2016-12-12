/* Rawan Alsaadi 10081442		*
 * Omar Toutounji 10169506		*
 * Beltan Michel 10169162			*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int userCar = 0;
int *userPtr = &userCar;
int car2 = 0, car3 = 0, car4 = 0, car5 = 0;
int *car2Ptr = &car2, *car3Ptr = &car3, *car4Ptr = &car4, *car5Ptr = &car5;

void *userCarThread(void *threadid) {
while (*userPtr<40){
	getchar();
	*userPtr = *userPtr + 1;
}
pthread_exit(NULL);
}

void *car2Thread(void *threadid){
	
	while (*car2Ptr<40){
		*car2Ptr = *car2Ptr + 1;
		usleep(10000*(rand()%100));
	}
pthread_exit(NULL);
}

void *car3Thread(void *threadid){
	
	while (*car3Ptr<40){
		*car3Ptr = *car3Ptr + 1;
		usleep(10000*(rand()%100));
	}
pthread_exit(NULL);
}

void *car4Thread(void *threadid){
	
	while (*car4Ptr<40){
		*car4Ptr = *car4Ptr + 1;
		usleep(10000*(rand()%100));
	}
pthread_exit(NULL);
}

void *car5Thread(void *threadid){
	
	while (*car5Ptr<40){
		*car5Ptr = *car5Ptr + 1;
		usleep(10000*(rand()%100));
	}
pthread_exit(NULL);
}

void *printThread(void *threadid){

	while (1){
	system("clear");
	printf("%.*s%s%.*s# Line 1 #\n", *userPtr, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", "|->", 40-*userPtr, "                                        ");
	printf("%.*s%s%.*s# Line 2 #\n", *car2Ptr, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", "|->", 40-*car2Ptr, "                                          ");
	printf("%.*s%s%.*s# Line 3 #\n", *car3Ptr, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", "|->", 40-*car3Ptr, "                                          ");
	printf("%.*s%s%.*s# Line 4 #\n", *car4Ptr, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", "|->", 40-*car4Ptr, "                                          ");
	printf("%.*s%s%.*s# Line 5 #\n", *car5Ptr, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", "|->", 40-*car5Ptr, "                                          ");
	
	if (*userPtr == 40){
		printf("Player 1 Wins!\n");
		pthread_exit(NULL);
	} else if (*car2Ptr == 40){
		printf("Player 2 Wins!\n");
		pthread_exit(NULL);
	} else if (*car3Ptr == 40){
		printf("Player 3 Wins!\n");
		pthread_exit(NULL);
	} else if (*car4Ptr == 40){
		printf("Player 4 Wins!\n");
		pthread_exit(NULL);
	} else if (*car5Ptr == 40){
		printf("Player 5 Wins!\n");
		pthread_exit(NULL);
	}
	usleep(200000);
}
}

int main(){

	printf("|->                                        # Line 1 #\n");
	printf("|->                                        # Line 2 #\n");
	printf("|->                                        # Line 3 #\n");
	printf("|->                                        # Line 4 #\n");
	printf("|->                                        # Line 5 #\n");
	pthread_t tid, tid2, tid3, tid4, tid5, tid6;
	pthread_create(&tid, NULL, userCarThread, NULL);
	pthread_create(&tid2, NULL, car2Thread, NULL);
	pthread_create(&tid3, NULL, car3Thread, NULL);
	pthread_create(&tid4, NULL, car4Thread, NULL);
	pthread_create(&tid5, NULL, car5Thread, NULL);
	pthread_create(&tid6, NULL, printThread, NULL);
	pthread_join(tid6, NULL);
	exit(0);
	
	
}

