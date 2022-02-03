/* 배열 접근 방식에 따른 캐시 성능 측정과 루프 언롤링  by nuna90@naver.com 학번 32204236, 이름 정현우, 최초작성일 12월 15일 마지막 수정일 12월 16일*/
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
#define unrollI 0
#define unrollJ 1
#define unrollK 2


int loop(int array[100][100][100], int select, int unroll) {
        int i, j, k;
        int sum = 0;
	
	switch(select) {
		case kji:
			if ( unroll == unrollI ) {
				for ( i = 0; i < 100; i = i + 2 ) {
                                	for ( j = 0; j < 100; j++ ) {
                                        	for( k = 0; k < 100; k++ ) {
                                                	sum = sum + array[k][j][i];
							sum = sum + array[k][j][i + 1];
                                        	}
                                	}
                        	}
			} else if ( unroll == unrollJ ) {
				for ( i = 0; i < 100; i++ ) {
                                        for ( j = 0; j < 100; j = j + 2 ) {
                                                for( k = 0; k < 100; k++ ) {
                                                        sum = sum + array[k][j][i];
							sum = sum + array[k][j + 1][i];
                                                }
                                        }
                                }
			} else if ( unroll == unrollK ) {
				for ( i = 0; i < 100; i++ ) {
                                        for ( j = 0; j < 100; j++ ) {
                                                for( k = 0; k < 100; k = k + 2 ) {
                                                        sum = sum + array[k][j][i];
							sum = sum + array[k + 1][j][i];
                                                }
                                        }
                                }
			}
		break;
		case ijk:
                        if ( unroll == unrollI ) {
                                for ( i = 0; i < 100; i = i + 2 ) {
                                        for ( j = 0; j < 100; j++ ) {
                                                for( k = 0; k < 100; k++ ) {
                                                        sum = sum + array[i][j][k];
                                                        sum = sum + array[i + 1][j][k];
                                                }
                                        }
                                }
                        } else if ( unroll == unrollJ ) {
                                for ( i = 0; i < 100; i++ ) {
                                        for ( j = 0; j < 100; j = j + 2 ) {
                                                for( k = 0; k < 100; k++ ) {
                                                        sum = sum + array[i][j][k];
                                                        sum = sum + array[i][j + 1][k];
                                                }
                                        }
                                }
                        } else if ( unroll == unrollK ) {
                                for ( i = 0; i < 100; i++ ) {
                                        for ( j = 0; j < 100; j++ ) {
                                                for( k = 0; k < 100; k = k + 2 ) {
                                                        sum = sum + array[i][j][k];
                                                        sum = sum + array[i][j][k + 1];
                                                }
                                        }
                                }
                        }
		break;
		case kij:
                        if ( unroll == unrollI ) {
                                for ( i = 0; i < 100; i = i + 2 ) {
                                        for ( j = 0; j < 100; j++ ) {
                                                for( k = 0; k < 100; k++ ) {
                                                        sum = sum + array[k][i][j];
                                                        sum = sum + array[k][i + 1][j];
                                                }
                                        }
                                }
                        } else if ( unroll == unrollJ ) {
                                for ( i = 0; i < 100; i++ ) {
                                        for ( j = 0; j < 100; j = j + 2 ) {
                                                for( k = 0; k < 100; k++ ) {
                                                        sum = sum + array[k][i][j];
                                                        sum = sum + array[k][i][j + 1];
                                                }
                                        }
                                }
                        } else if ( unroll == unrollK ) {
                                for ( i = 0; i < 100; i++ ) {
                                        for ( j = 0; j < 100; j++ ) {
                                                for( k = 0; k < 100; k = k + 2 ) {
                                                        sum = sum + array[k][i][j];
                                                        sum = sum + array[k + 1][i][j];
                                                }
                                        }
                                }
                        }
		break;
		case jik:
                       	if ( unroll == unrollI ) {
                                for ( i = 0; i < 100; i = i + 2 ) {
                                        for ( j = 0; j < 100; j++ ) {
                                                for( k = 0; k < 100; k++ ) {
                                                        sum = sum + array[j][i][k];
                                                        sum = sum + array[j][i + 1][k];
                                                }
                                        }
                                }
                        } else if ( unroll == unrollJ ) {
                                for ( i = 0; i < 100; i++ ) {
                                        for ( j = 0; j < 100; j = j + 2 ) {
                                                for( k = 0; k < 100; k++ ) {
                                                        sum = sum + array[j][i][k];
                                                        sum = sum + array[j + 1][i][k];
                                                }
                                        }
                                }
                        } else if ( unroll == unrollK ) {
                                for ( i = 0; i < 100; i++ ) {
                                        for ( j = 0; j < 100; j++ ) {
                                                for( k = 0; k < 100; k = k + 2 ) {
                                                        sum = sum + array[j][i][k];
                                                        sum = sum + array[j][i][k + 1];
                                                }
                                        }
                                }
                        }
		break;	
		case ikj:
                        if ( unroll == unrollI ) {
                                for ( i = 0; i < 100; i = i + 2 ) {
                                        for ( j = 0; j < 100; j++ ) {
                                                for( k = 0; k < 100; k++ ) {
                                                        sum = sum + array[i][k][j];
                                                        sum = sum + array[i + 1][k][j];
                                                }
                                        }
                                }
                        } else if ( unroll == unrollJ ) {
                                for ( i = 0; i < 100; i++ ) {
                                        for ( j = 0; j < 100; j = j + 2 ) {
                                                for( k = 0; k < 100; k++ ) {
                                                        sum = sum + array[i][k][j];
                                                        sum = sum + array[i][k][j + 1];
                                                }
                                        }
                                }
                        } else if ( unroll == unrollK ) {
                                for ( i = 0; i < 100; i++ ) {
                                        for ( j = 0; j < 100; j++ ) {
                                                for( k = 0; k < 100; k = k + 2 ) {
                                                        sum = sum + array[i][k][j];
                                                        sum = sum + array[i][k + 1][j];
                                                }
                                        }
                                }
                        }
		break;
		case jki:
                        if ( unroll == unrollI ) {
                                for ( i = 0; i < 100; i = i + 2 ) {
                                        for ( j = 0; j < 100; j++ ) {
                                                for( k = 0; k < 100; k++ ) {
                                                        sum = sum + array[j][k][i];
                                                        sum = sum + array[j][k][i + 1];
                                                }
                                        }
                                }
                        } else if ( unroll == unrollJ ) {
                                for ( i = 0; i < 100; i++ ) {
                                        for ( j = 0; j < 100; j = j + 2 ) {
                                                for( k = 0; k < 100; k++ ) {
                                                        sum = sum + array[j][k][i];
                                                        sum = sum + array[j + 1][k][i];
                                                }
                                        }
                                }
                        } else if ( unroll == unrollK ) {
                                for ( i = 0; i < 100; i++ ) {
                                        for ( j = 0; j < 100; j++ ) {
                                                for( k = 0; k < 100; k = k + 2 ) {
                                                        sum = sum + array[j][k][i];
                                                        sum = sum + array[j][k + 1][i];
                                                }
                                        }
                                }
                        }

		break;
	}

        return sum;
}


int main(int argc, char *argv[]) {
	int i, j, k;
	int result;
	int array[100][100][100];
	long sum = 0;
	struct timeval stime, etime, gap;
	char *type[6];
	char unr[3];

	type[0] = "k j i";
	type[1] = "i j k";
	type[2] = "k i j";
	type[3] = "j i k";
	type[4] = "i k j";
	type[5] = "j k i";

	unr[0] = 'i';
	unr[1] = 'j';
	unr[2] = 'k';
	
	if (argc != 1) {
                printf("Usage: command\n");
                exit(-1);
        }
	
	for(i = 0; i < 6; i++) {
		for(j = 0; j < 3; j++) {
			printf("%s 방식 접근, %c 언롤링:\t", type[i], unr[j]);
			for(k = 0; k < 1000; k++) {
				gettimeofday(&stime, NULL);
				result = loop(array, i, j);
				gettimeofday(&etime, NULL);
				gap.tv_sec = etime.tv_sec - stime.tv_sec;
				gap.tv_usec = etime.tv_usec - stime.tv_usec;
				sum = sum + gap.tv_sec * 1000000 + gap.tv_usec; 
			}
			printf("%ldusec\n", sum/1000);
        		sum = 0;
		}
		printf("\n");
	}
	
	return 0;
}
