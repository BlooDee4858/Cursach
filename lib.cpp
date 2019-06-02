#include "header.h"


int IsChecker(int ip,int jp,int map[8][8])
{
    if(map[ip][jp] == 1)
    {
        return 1;
    } else if(map[ip][jp] == 1)
        return 2;

    if(map[ip][jp] == 0)
        return 0;

}
void Step(int step[],int map[8][8], int* s)
{
    int tmp;
    if(*s == 1)
    {
        if(map[step[2]][step[3]] == 0 && (abs(step[0] - step[2]) == 1) &&(abs(step[1] - step[3]) == 1) && (step[0] < step[2]))
        {
            tmp = map[step[0]][step[1]];
            map[step[0]][step[1]] = 0;
            map[step[2]][step[3]] = tmp;

            if(*s == 2)
            {
                *s = 1;
            }
            else
                *s = 2;
        }
    }else
    {
        if(map[step[2]][step[3]] == 0 && (abs(step[0] - step[2]) == 1) &&(abs(step[1] - step[3]) == 1) && (step[0] > step[2]))
        {
            tmp = map[step[0]][step[1]];
            map[step[0]][step[1]] = 0;
            map[step[2]][step[3]] = tmp;

            if(*s == 2)
            {
                *s = 1;
            }
            else
                *s = 2;
        }
    }
    for(int i = 0; i < 4; i++)
    {
        step[i] = 0;
    }


}

int kill(int map[8][8], int step[4], int* s) {
    if (map[step[2]][step[3]] == 0 && (abs(step[0] - step[2]) == 2) && (abs(step[1] - step[3]) == 2)) {

        if(*s == 2) {//Чёрные шашки
            if (step[1] > step[3] && step[0] > step[2]) { //Бьёт вперёд влево
                if (map[step[0] - 1][step[1] - 1] != map[step[0]][step[1]] && map[step[0] - 1][step[1] - 1] != 0) {
                    map[step[2]][step[3]] = map[step[0]][step[1]];
                    map[step[0]][step[1]] = 0;
                    map[step[0] - 1][step[1] - 1] = 0;

                    if(*s == 2 && !KillCheckOne(map,step,*s))
                    {
                        *s = 1;
                    }
                    else if(!KillCheckOne(map,step,*s))
                        *s = 2;
                    return 1;
                }
            } else if(step[1] < step[3] && step[0] > step[2]) {//Бьёт вперёд вправо
                if (map[step[0] - 1][step[1] + 1] != map[step[0]][step[1]] && map[step[0] - 1][step[1] + 1] != 0) {
                    map[step[2]][step[3]] = map[step[0]][step[1]];
                    map[step[0]][step[1]] = 0;
                    map[step[0] - 1][step[1] + 1] = 0;

                    if(*s == 2 && !KillCheckOne(map,step,*s))
                    {
                        *s = 1;
                    }
                    else if(!KillCheckOne(map,step,*s))
                        *s = 2;
                    return 1;
                }

            } else if(step[1] > step[3] && step[0] < step[2])//Бьёт назад влево
            {

                if (map[step[0] + 1][step[1] - 1] != map[step[0]][step[1]] && map[step[0] + 1][step[1] - 1] != 0) {
                    map[step[2]][step[3]] = map[step[0]][step[1]];
                    map[step[0]][step[1]] = 0;
                    map[step[0] + 1][step[1] - 1] = 0;

                    if(*s == 2 && !KillCheckOne(map,step,*s))
                    {
                        *s = 1;
                    }
                    else if(!KillCheckOne(map,step,*s))
                        *s = 2;
                    return 1;
                }
            } else if(step[1] < step[3] && step[0] < step[2])//Бьёт назад вправо
            {
                if (map[step[0] + 1][step[1] + 1] != map[step[0]][step[1]] && map[step[0] + 1][step[1] + 1] != 0) {
                    map[step[2]][step[3]] = map[step[0]][step[1]];
                    map[step[0]][step[1]] = 0;
                    map[step[0] + 1][step[1] + 1] = 0;

                    if(*s == 2 && !KillCheckOne(map,step,*s))
                    {
                        *s = 1;
                    }
                    else if(!KillCheckOne(map,step,*s))
                        *s = 2;
                    return 1;
                }

            }
        }
        else //Белые шашки
        {
            if (step[1] < step[3] && step[0] < step[2]) {
                if (map[step[0] + 1][step[1] + 1] != map[step[0]][step[1]] && map[step[0] + 1][step[1] + 1] != 0) {
                    map[step[2]][step[3]] = map[step[0]][step[1]];
                    map[step[0]][step[1]] = 0;
                    map[step[0] + 1][step[1] + 1] = 0;

                    if(*s == 2 && !KillCheckOne(map,step,*s))
                    {
                        *s = 1;
                    }
                    else if(!KillCheckOne(map,step,*s))
                        *s = 2;
                    return 1;
                }
            } else if(step[1] > step[3] && step[0] < step[2]){
                if (map[step[0] + 1][step[1] - 1] != map[step[0]][step[1]] && map[step[0] + 1][step[1] - 1] != 0) {
                    map[step[2]][step[3]] = map[step[0]][step[1]];
                    map[step[0]][step[1]] = 0;
                    map[step[0] + 1][step[1] - 1] = 0;

                    if(*s == 2 && !KillCheckOne(map,step,*s))
                    {
                        *s = 1;
                    }
                    else if(!KillCheckOne(map,step,*s))
                        *s = 2;
                    return 1;
                }

            } else if(step[1] < step[3] && step[0] > step[2])
            {
                if (map[step[0] - 1][step[1] + 1] != map[step[0]][step[1]] && map[step[0] - 1][step[1] + 1] != 0) {
                    map[step[2]][step[3]] = map[step[0]][step[1]];
                    map[step[0]][step[1]] = 0;
                    map[step[0] - 1][step[1] + 1] = 0;

                    if(*s == 2 && !KillCheckOne(map,step,*s))
                    {
                        *s = 1;
                    }
                    else if(!KillCheckOne(map,step,*s))
                        *s = 2;
                    return 1;
                }
            } else if(step[1] > step[3] && step[0] > step[2])
            {
                if (map[step[0] - 1][step[1] - 1] != map[step[0]][step[1]] && map[step[0] - 1][step[1] - 1] != 0) {
                    map[step[2]][step[3]] = map[step[0]][step[1]];
                    map[step[0]][step[1]] = 0;
                    map[step[0] - 1][step[1] - 1] = 0;

                    if(*s == 2 && !KillCheckOne(map,step,*s))
                    {
                        *s = 1;
                    }
                    else if(!KillCheckOne(map,step,*s))
                        *s = 2;
                    return 1;
                }
            }


        }


    }
    return 0;
}

int KillCheck(int map[8][8], int s)
{
    int r;
    if(s == 1)
        r = 2;
    else
        r = 1;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(map[i][j] == s)
            {
                if(map[i-1][j-1] == r && map[i-2][j-2] == 0 && (i-2 >= 0) && (j-2 >= 0))
                    return 1;
                if(map[i-1][j+1] == r && map[i-2][j+2] == 0 && (i - 2 >= 0) && (j + 2 < 7))
                    return 1;
                if(map[i+1][j+1] == r && map[i+2][j+2] == 0 && (i + 2 < 7) && (j+2 < 7))
                    return 1;
                if(map[i+1][j-1] == r && map[i+2][j-2] == 0 && (i + 2 < 7) && (j-2 >= 0))
                    return 1;
            }

        }
    }
    return 0;
}

int KillCheckOne(int map[8][8], int step[4], int s)
{
    int r;
    if(s == 1)
        r = 2;
    else
        r = 1;

    if(map[step[2]-1][step[3]-1] == r && map[step[2]-2][step[3]-2] == 0 && (step[2]-2 >= 0) && (step[3]-2 >= 0))
        return 1;
    if(map[step[2]-1][step[3]+1] == r && map[step[2]-2][step[3]+2] == 0 && (step[2]-2 >= 0) && (step[3]+2 < 7))
        return 1;
    if(map[step[2]+1][step[3]+1] == r && map[step[2]+2][step[3]+2] == 0 && (step[2]+2 >= 0) && (step[3]+2 >= 0))
        return 1;
    if(map[step[2]+1][step[3]-1] == r && map[step[2]+2][step[3]-2] == 0 && (step[2]+2 >= 0) && (step[3]-2 >= 0))
        return 1;

    return 0;
}


