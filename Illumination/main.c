//
//  main.c
//  Illumination
//
//  Created by 太田　一毅 on 2015/07/07.
//  Copyright (c) 2015年 太田一毅. All rights reserved.
//

#include <stdio.h>
#include <math.h>


int DATA_W;
int DATA_H;
int DATA[104][104];
int i;
int j;
int queue_x[10816];
int queue_y[10816];
int howmany_queue;
int number_of_checked_queue;
int a;
int map_marked[104][104];
int ans;

//int number_of_checking_x;
//int number_of_checking_y;


int main(int argc, const char * argv[]) {
    
    
    scanf("%d",&DATA_W);
    scanf("%d",&DATA_H);
    
    
    while (j < DATA_H) {
        printf("now:%d,%d\n",i,j);
        scanf("%d",&DATA[i+2][j+2]);
        if (DATA[i+2][j+2] == 1) {
            map_marked[i+2][j+2] = 2;
        }
        j = j+(i+1)/DATA_W;
        i = (i+1)%DATA_W;
    }
    
    for (j = 0; j < DATA_H+4; j ++) {
        
        if (j%2 == 0) {
            printf(" ");
        }
        
        for (i = 0; i < DATA_W+4; i ++) {
            printf("%d ",map_marked[i][j]);
        }
        printf("\n");
    }
    
    printf("\n\n");
    
    //    number_of_checking_x = 0;
    //    number_of_checking_y = 0;
    
    howmany_queue = 1;
    number_of_checked_queue = 0;
    queue_x[0] = 1;
    queue_y[0] = 1;
    map_marked[1][1] = 1;
    
    while (howmany_queue > number_of_checked_queue) {
        
        printf("queue:{");
        for (i = number_of_checked_queue; i < howmany_queue; i ++) {
            printf("(%d,%d)",queue_x[i],queue_y[i]);
        }
        printf("}\n");
        
        
        a = number_of_checked_queue;
        
        if (queue_x[a] >= 1 &&
            queue_x[a] <= DATA_W+3 &&
            queue_y[a] >= 1 &&
            queue_y[a] <= DATA_H+3
            ) {
            
            
            
            if (queue_y[a]%2 == 1) {
                if (map_marked[queue_x[a]-1][queue_y[a]-1] == 0) {
                    map_marked[queue_x[a]-1][queue_y[a]-1] = 1;
                    queue_x[howmany_queue] = queue_x[a]-1;
                    queue_y[howmany_queue] = queue_y[a]-1;
                    howmany_queue ++;
                }
                
                if (map_marked[queue_x[a]-1][queue_y[a]-0] == 0) {
                    map_marked[queue_x[a]-1][queue_y[a]-0] = 1;
                    queue_x[howmany_queue] = queue_x[a]-1;
                    queue_y[howmany_queue] = queue_y[a]-0;
                    howmany_queue ++;
                }
                
                if (map_marked[queue_x[a]-1][queue_y[a]+1] == 0) {
                    map_marked[queue_x[a]-1][queue_y[a]+1] = 1;
                    queue_x[howmany_queue] = queue_x[a]-1;
                    queue_y[howmany_queue] = queue_y[a]+1;
                    howmany_queue ++;
                }
                
                if (map_marked[queue_x[a]-0][queue_y[a]-1] == 0) {
                    map_marked[queue_x[a]-0][queue_y[a]-1] = 1;
                    queue_x[howmany_queue] = queue_x[a]-0;
                    queue_y[howmany_queue] = queue_y[a]-1;
                    howmany_queue ++;
                }
                
                //            if (map_marked[queue_x[a]-0][queue_y[a]-0] == 0) {
                //                map_marked[queue_x[a]-0][queue_y[a]-0] = 1;
                //                queue_x[howmany_queue] = queue_x[a]-0;
                //                queue_y[howmany_queue] = queue_y[a]-0;
                //                howmany_queue ++;
                //            }
                
                if (map_marked[queue_x[a]-0][queue_y[a]+1] == 0) {
                    map_marked[queue_x[a]-0][queue_y[a]+1] = 1;
                    queue_x[howmany_queue] = queue_x[a]-0;
                    queue_y[howmany_queue] = queue_y[a]+1;
                    howmany_queue ++;
                }
                
                //            if (map_marked[queue_x[a]+1][queue_y[a]-1] == 0) {
                //                map_marked[queue_x[a]+1][queue_y[a]-1] = 1;
                //                queue_x[howmany_queue] = queue_x[a]+1;
                //                queue_y[howmany_queue] = queue_y[a]-1;
                //                howmany_queue ++;
                //            }
                
                if (map_marked[queue_x[a]+1][queue_y[a]-0] == 0) {
                    map_marked[queue_x[a]+1][queue_y[a]-0] = 1;
                    queue_x[howmany_queue] = queue_x[a]+1;
                    queue_y[howmany_queue] = queue_y[a]-0;
                    howmany_queue ++;
                }
                
                //            if (map_marked[queue_x[a]+1][queue_y[a]+1] == 0) {
                //                map_marked[queue_x[a]+1][queue_y[a]+1] = 1;
                //                queue_x[howmany_queue] = queue_x[a]+1;
                //                queue_y[howmany_queue] = queue_y[a]+1;
                //                howmany_queue ++;
                //            }
                
                
                
            } else {
                
//                if (map_marked[queue_x[a]-1][queue_y[a]-1] == 0) {
//                    map_marked[queue_x[a]-1][queue_y[a]-1] = 1;
//                    queue_x[howmany_queue] = queue_x[a]-1;
//                    queue_y[howmany_queue] = queue_y[a]-1;
//                    howmany_queue ++;
//                }
                
                if (map_marked[queue_x[a]-1][queue_y[a]-0] == 0) {
                    map_marked[queue_x[a]-1][queue_y[a]-0] = 1;
                    queue_x[howmany_queue] = queue_x[a]-1;
                    queue_y[howmany_queue] = queue_y[a]-0;
                    howmany_queue ++;
                }
                
//                if (map_marked[queue_x[a]-1][queue_y[a]+1] == 0) {
//                    map_marked[queue_x[a]-1][queue_y[a]+1] = 1;
//                    queue_x[howmany_queue] = queue_x[a]-1;
//                    queue_y[howmany_queue] = queue_y[a]+1;
//                    howmany_queue ++;
//                }
                
                if (map_marked[queue_x[a]-0][queue_y[a]-1] == 0) {
                    map_marked[queue_x[a]-0][queue_y[a]-1] = 1;
                    queue_x[howmany_queue] = queue_x[a]-0;
                    queue_y[howmany_queue] = queue_y[a]-1;
                    howmany_queue ++;
                }
                
                //            if (map_marked[queue_x[a]-0][queue_y[a]-0] == 0) {
                //                map_marked[queue_x[a]-0][queue_y[a]-0] = 1;
                //                queue_x[howmany_queue] = queue_x[a]-0;
                //                queue_y[howmany_queue] = queue_y[a]-0;
                //                howmany_queue ++;
                //            }
                
                if (map_marked[queue_x[a]-0][queue_y[a]+1] == 0) {
                    map_marked[queue_x[a]-0][queue_y[a]+1] = 1;
                    queue_x[howmany_queue] = queue_x[a]-0;
                    queue_y[howmany_queue] = queue_y[a]+1;
                    howmany_queue ++;
                }
                
                            if (map_marked[queue_x[a]+1][queue_y[a]-1] == 0) {
                                map_marked[queue_x[a]+1][queue_y[a]-1] = 1;
                                queue_x[howmany_queue] = queue_x[a]+1;
                                queue_y[howmany_queue] = queue_y[a]-1;
                                howmany_queue ++;
                            }
                
                if (map_marked[queue_x[a]+1][queue_y[a]-0] == 0) {
                    map_marked[queue_x[a]+1][queue_y[a]-0] = 1;
                    queue_x[howmany_queue] = queue_x[a]+1;
                    queue_y[howmany_queue] = queue_y[a]-0;
                    howmany_queue ++;
                }
                
                            if (map_marked[queue_x[a]+1][queue_y[a]+1] == 0) {
                                map_marked[queue_x[a]+1][queue_y[a]+1] = 1;
                                queue_x[howmany_queue] = queue_x[a]+1;
                                queue_y[howmany_queue] = queue_y[a]+1;
                                howmany_queue ++;
                            }
                
                
                
            }
        }
        number_of_checked_queue ++;
        
        
        
        
        for (j = 0; j < DATA_H+4; j ++) {
            
            if (j%2 == 0) {
                printf(" ");
            }
            
            for (i = 0; i < DATA_W+4; i ++) {
                /*if (map_marked[i][j] == 1) {
                 map_marked[i][j] = 0;
                 }*/
                printf("%d ",map_marked[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        
        
    }
    
    
    for (j = 0; j < DATA_H+4; j ++) {
        
        if (j%2 == 0) {
            printf(" ");
        }
        
        for (i = 0; i < DATA_W+4; i ++) {
            /*if (map_marked[i][j] == 1) {
             map_marked[i][j] = 0;
             }*/
            printf("%d ",map_marked[i][j]);
        }
        printf("\n");
    }
    
    for (j = 2; j < DATA_H + 2; j ++) {
        for (i = 2; i < DATA_W + 2; i ++) {
            if (map_marked[i][j] == 2) {
                if (j % 2 == 1) {
                    if (map_marked[i-1][j-1] == 1) {
                        ans ++;
                    }
                    if (map_marked[i-1][j-0] == 1) {
                        ans ++;
                    }
                    if (map_marked[i-1][j+1] == 1) {
                        ans ++;
                    }
                    if (map_marked[i-0][j-1] == 1) {
                        ans ++;
                    }
                    //                    if (map_marked[i-0][j-0] == 1) {
                    //                        ans ++;
                    //                    }
                    if (map_marked[i-0][j+1] == 1) {
                        ans ++;
                    }
                    //                    if (map_marked[i+1][j-1] == 1) {
                    //                        ans ++;
                    //                    }
                    if (map_marked[i+1][j-0] == 1) {
                        ans ++;
                    }
                    //                    if (map_marked[i+1][j+1] == 1) {
                    //                        ans ++;
                    //                    }
                } else {
                    //                    if (map_marked[i-1][j-1] == 1) {
                    //                        ans ++;
                    //                    }
                    if (map_marked[i-1][j-0] == 1) {
                        ans ++;
                    }
                    //                    if (map_marked[i-1][j+1] == 1) {
                    //                        ans ++;
                    //                    }
                    if (map_marked[i-0][j-1] == 1) {
                        ans ++;
                    }
                    //                    if (map_marked[i-0][j-0] == 1) {
                    //                        ans ++;
                    //                    }
                    if (map_marked[i-0][j+1] == 1) {
                        ans ++;
                    }
                    if (map_marked[i+1][j-1] == 1) {
                        ans ++;
                    }
                    if (map_marked[i+1][j-0] == 1) {
                        ans ++;
                    }
                    if (map_marked[i+1][j+1] == 1) {
                        ans ++;
                    }
                    
                }
            }
        }
    }
    
    printf("%d",ans);
    
    return 0;
}
