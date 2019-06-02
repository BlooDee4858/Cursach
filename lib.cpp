#include "header.h"


int IsChecker(int ip,int jp,int map[8][8])
{
    if(map[ip][jp] == 1)
        return 1;
    if(map[ip][jp] == 2)
        return 2;
    if(map[ip][jp] == 3)
        return 1;
    if(map[ip][jp] == 4)
        return 2;

    if(map[ip][jp] == 0)
        return 0;

}
void Step(int step[],int map[8][8], int* s)
{
    int tmp;
    if(*s == 1 && map[step[0]][step[1]] != 3 && map[step[0]][step[1]] != 4)
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
    }else if(*s == 2 && map[step[0]][step[1]] != 3 && map[step[0]][step[1]] != 4)
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
    } else if(map[step[0]][step[1]] == 3 || map[step[0]][step[1]] == 4)
    {
        printf("QueenStep\n");
        QueenStep(step,map,s);
    }

    for(int i = 0; i < 4; i++)
    {
        step[i] = 0;
    }


}

void QueenStep(int step[], int map[8][8], int* s){
    int tmp;
    int f = 1;

        if(map[step[2]][step[3]] == 0 && (abs(step[0] - step[2]) == abs(step[1] - step[3])))
        {
            for(int i = step[0]+1; i < step[2]; i++)
            {
                for(int j = step[1] + 1; j < step[3]; j++)
                {
                    if(map[i][j] != 0)
                        f = 0;
                }
            }
            if(f == 1)
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

    int f;

    if (map[step[2]][step[3]] == 0 && (abs(step[0] - step[2]) == 2) && (abs(step[1] - step[3]) == 2)) {
        if(*s == 2 && map[step[0]][step[1]] != 3 && map[step[0]][step[1]] != 4) {//Чёрные шашки
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
        else if(map[step[0]][step[1]] != 3 && map[step[0]][step[1]] != 4) //Белые шашки
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
                    else if(*s == 1 && !KillCheckOne(map,step,*s))
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
                    else if(*s == 1 && !KillCheckOne(map,step,*s))
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
                    else if(*s == 1 && !KillCheckOne(map,step,*s))
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
                    else if(*s == 1 && !KillCheckOne(map,step,*s))
                        *s = 2;
                    return 1;
                }
            }
        }

    }
    if((map[step[0]][step[1]] == 3 || map[step[0]][step[1]] == 4) && !KillCheck(map,*s))
    {
        printf("KillerQueen");
        f = KillerQueen(map,step,s);
        return f;
    }
    return 0;
}

int KillerQueen(int map[8][8], int step[4], int *s){//This is JoJo reference?
    int ip = abs(step[0] - step[2]);
    int rs;
    int f = 1;
    if(*s == 1)
        rs = 2;
    else
        rs = 1;

    if(map[step[2]][step[3]] == 0 && (abs(step[0] - step[2]) == abs(step[1] - step[3])))
    {
        if(step[0] > step[2] && step[1] > step[3])//Влево вверх
        {
            for(int i = 1; i < ip; i++)
            {
                if((map[step[0]-i][step[1] - i] == rs || map[step[0]-i][step[1] - i] == rs + 2) && map[step[0]-i][step[1] - i] != 0
                && step[0]-i - 1 >= 0 && step[1] - i - 1 >= 0)
                {
                    if(map[step[0]-i - 1][step[1] - i - 1] == 0)
                        map[step[0]-i][step[1] - i] = 0;
                    else
                    {
                        f = 0;
                        break;
                    }
                }
            }
            if(f == 1)
            {
                map[step[2]][step[3]] = map[step[0]][step[1]];
                map[step[0]][step[1]] = 0;

                if(*s == 2 && !QueenCheck(map,*s))
                {
                    *s = 1;
                }
                else if(!QueenCheck(map,*s))
                    *s = 2;
            }

            return 1;
        }
        if(step[0] > step[2] && step[1] < step[3])//Вправо вверх
        {
            for(int i = 1; i < ip; i++)
            {
                if((map[step[0]-i][step[1] + i] == rs || map[step[0]-i][step[1] + i] == rs + 2) && map[step[0]-i][step[1] + i] != 0
                   && step[0]-i - 1 >= 0 && step[1] + i + 1 <= 7)
                {
                    if(map[step[0]-i - 1][step[1] + i + 1] == 0)
                        map[step[0]-i][step[1] + i] = 0;
                    else
                    {
                        f = 0;
                        break;
                    }
                }
            }
            if(f == 1)
            {
                map[step[2]][step[3]] = map[step[0]][step[1]];
                map[step[0]][step[1]] = 0;
                if(*s == 2 && !QueenCheck(map,*s))
                {
                    *s = 1;
                }
                else if(!QueenCheck(map,*s))
                    *s = 2;
            }

            return 1;
        }
        if(step[0] < step[2] && step[1] < step[3])//Вправо вниз
        {
            for(int i = 1; i < ip; i++)
            {
                if((map[step[0] + i][step[1] + i] == rs || map[step[0] + i][step[1] + i] == rs + 2) && map[step[0]+i][step[1] + i] != 0
                   && step[0]+i + 1 <= 7 && step[1] + i + 1 <= 7)
                {
                    if(map[step[0]+i + 1][step[1] + i + 1] == 0)
                        map[step[0]+i][step[1] + i] = 0;
                    else
                    {
                        f = 0;
                        break;
                    }
                }
            }
            if(f == 1)
            {
                map[step[2]][step[3]] = map[step[0]][step[1]];
                map[step[0]][step[1]] = 0;
                if(*s == 2 && !QueenCheck(map,*s))
                {
                    *s = 1;
                }
                else if(!QueenCheck(map,*s))
                    *s = 2;
            }

            return 1;
        }
        if(step[0] < step[2] && step[1] > step[3])//Влево вниз
        {
            for(int i = 1; i < ip; i++)
            {
                if((map[step[0]+i][step[1] - i] == rs || map[step[0]+i][step[1] - i] == rs + 2) && map[step[0]+i][step[1] - i] != 0
                   && step[0]+i + 1 <= 7 && step[1] - i - 1 >= 0)
                {
                    if(map[step[0]+i + 1][step[1] - i - 1] == 0)
                        map[step[0]+i][step[1] - i] = 0;
                    else
                    {
                        f = 0;
                        break;
                    }
                }
            }
            if(f == 1)
            {
                map[step[2]][step[3]] = map[step[0]][step[1]];
                map[step[0]][step[1]] = 0;
                if(*s == 2 && !QueenCheck(map,*s))
                {
                    *s = 1;
                }
                else if(!QueenCheck(map,*s))
                    *s = 2;
            }

            return 1;
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
                if((map[i-1][j-1] == r || map[i-1][j-1] == r+2) && map[i-2][j-2] == 0 && (i-2 >= 0) && (j-2 >= 0) )
                    return 1;
                if((map[i-1][j+1] == r || map[i-1][j+1] == r+2) && map[i-2][j+2] == 0 && (i - 2 >= 0) && (j + 2 < 7))
                    return 1;
                if((map[i+1][j+1] == r || map[i+1][j+1] == r+2) && map[i+2][j+2] == 0 && (i + 2 < 7) && (j+2 < 7))
                    return 1;
                if((map[i+1][j-1] == r || map[i+1][j-1] == r+2) && map[i+2][j-2] == 0 && (i + 2 < 7) && (j-2 >= 0))
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
    if(map[step[2]-1][step[3]+1] == r && map[step[2]-2][step[3]+2] == 0 && (step[2]-2 >= 0) && (step[3]+2 <= 7))
        return 1;
    if(map[step[2]+1][step[3]+1] == r && map[step[2]+2][step[3]+2] == 0 && (step[2]+2 >= 0) && (step[3]+2 >= 0))
        return 1;
    if(map[step[2]+1][step[3]-1] == r && map[step[2]+2][step[3]-2] == 0 && (step[2]+2 >= 0) && (step[3]-2 >= 0))
        return 1;

    return 0;
}

void Queen(int map[8][8])
{
    for(int i = 0; i < 8; i+=7)
    {
        for(int j = 0; j < 8; j++)
        {
            if(map[i][j] == 2 && i == 0)
            {
                map[i][j] = 4;
            }
            if(map[i][j] == 1 && i == 7)
            {
                map[i][j] = 3;
            }
        }
    }
}
int QueenCheck(int map[8][8], int s)
{

    int qs,rs,rqs;
    if(s == 1)
    {
        qs = 3;
        rs = 2;
        rqs = 4;
    }
    else
    {
        qs = 4;
        rs = 1;
        rqs = 4;
    }

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(map[i][j] == qs)
            {
                for(int i1 = 1; i1 < 8; i1++)
                {
                    if(i + i1 + 1 > 7 || j + i1 + 1 > 7)
                        break;
                    if((map[i+i1][j+i1] == rs || map[i+i1][j+i1] == rqs))
                    {
                        if(map[i+i1 + 1][j+i1 + 1] == 0)
                            return 1;
                        else
                            break;
                    }
                }
                for(int i1 = 1; i1 < 8; i1++)
                {
                    if(i + i1 + 1 > 7 || j - i1 - 1 <= 0)
                        break;
                    if((map[i+i1][j-i1] == rs || map[i+i1][j-i1] == rqs))
                    {
                        if(map[i+i1 + 1][j-i1 - 1] == 0)
                            return 1;
                        else
                            break;

                    }
                }
                for(int i1 = 1; i1 < 8; i1++)
                {
                    if(i - i1 - 1 <= 0 || j - i1 - 1 <= 0)
                        break;
                    if((map[i-i1][j-i1] == rs || map[i-i1][j-i1] == rqs))
                    {

                        if(map[i-i1 - 1][j-i1 - 1] == 0)
                            return 1;
                        else
                            break;

                    }

                }
                for(int i1 = 1; i1 < 8; i1++)
                {
                    if(i - i1 - 1 < 0 || j + i1 + 1 > 7)
                        break;
                    if((map[i-i1][j+i1] == rs || map[i-i1][j+i1] == rqs))
                    {
                        if(map[i-i1 - 1][j+i1 + 1] == 0)
                            return 1;
                        else
                            break;
                    }

                }
            }
        }
    }
    return 0;
}



