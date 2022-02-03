/* 배열 접근을 달리하여 캐시 성능을 측정하는 프로그램 by nuna90@naver.com 학번 32204236, 이름 정현우, 최초 작성일 12월 15일, 마지막 수정일 12월 16일*/
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <stdlib.h>

#define kji 0
#define ijk 1
#define kij 2
#define jik 3
#define ikj 4
#define jki 5



int loop(int array[100][100][100], int select) {
        int i, j, k;
        int sum = 0;
	
	switch(select) {
		case kji:
			for ( i = 0; i < 100; i++ ) {
                		for ( j = 0; j < 100; j++ ) {
                        		for( k = 0; k < 100; k++ ) {
                                		sum = sum + array[k][j][i];
                        		}
                		}
        		}
		break;
		case ijk:
                        for ( i = 0; i < 100; i++ ) {
                                for ( j = 0; j < 100; j++ ) {
                                        for( k = 0; k < 100; k++ ) {
                                                sum = sum + array[i][j][k];
                                        }
                                }
                        }
		break;
		case kij:
                        for ( i = 0; i < 100; i++ ) {
                                for ( j = 0; j < 100; j++ ) {
                                        for( k = 0; k < 100; k++ ) {
                                                sum = sum + array[k][i][j];
                                        }
                                }
                        }
		break;
		case jik:
                        for ( i = 0; i < 100; i++ ) {
                                for ( j = 0; j < 100; j++ ) {
                                        for( k = 0; k < 100; k++ ) {
                                                sum = sum + array[j][i][k];
                                        }
                                }
                        }
		break;	
		case ikj:
                        for ( i = 0; i < 100; i++ ) {
                                for ( j = 0; j < 100; j++ ) {
                                        for( k = 0; k < 100; k++ ) {
                                                sum = sum + array[i][k][j];
                                        }
                                }
                        }
		break;
		case jki:
                        for ( i = 0; i < 100; i++ ) {
                                for ( j = 0; j < 100; j++ ) {
                                        for( k = 0; k < 100; k++ ) {
                                                sum = sum + array[j][k][i];
                                        }
                                }
                        }
		break;
	}

        return sum;
}


int main(int argc, char *argv[]) {
	int i, j;
	int result;
	int array[100][100][100];
	long sum = 0;
	struct timeval stime, etime, gap;
	char *type[6];
	type[0] = "k j i";
	type[1] = "i j k";
	type[2] = "k i j";
	type[3] = "j i k";
	type[4] = "i k j";
	type[5] = "j k i";
	
	if (argc != 1) {
                printf("Usage: command\n");
                exit(-1);
        }
	
	for(i = 0; i < 6; i++) {
		printf("%s 방식 접근:\t", type[i]);
		for(j = 0; j < 1000; j++) {
			gettimeofday(&stime, NULL);
			result = loop(array, i);
			gettimeofday(&etime, NULL);
			gap.tv_sec = etime.tv_sec - stime.tv_sec;
			gap.tv_usec = etime.tv_usec - stime.tv_usec;
			sum = sum + gap.tv_sec * 1000000 + gap.tv_usec; 
		}
		printf("%ldusec\n", sum/1000);
        	sum = 0;
	}
	
	return 0;
}
