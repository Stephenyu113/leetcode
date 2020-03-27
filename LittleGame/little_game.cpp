/**
 *
 */

#include <stdio.h>
#include <memory.h>

#define MAXIN 75
char board[MAXIN + 2][MAXIN + 2]; // size of rectangular board
int minstep, w, h, to[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};  // direction
bool mark[MAXIN + 2][MAXIN + 2]; // footprint history

void search (int now_x, int now_y, int end_x, int end_y, int step, int f) {
    if (step > minstep) return; // current path greater than ministep
    if (now_x == end_x && now_y == end_y) { // reach end
        if (minstep > step) // update minstep
            minstep = step;
        return;
    }
    for (int i=0; i<4; i++) { // enumerate next direction
        int x = now_x + to[i][0]; // get new pos
        int y = now_y + to[i][1];
        if ((x>-1)&&(x<w+2) && (y>-1)&&(y<h+2)
            && (((board[y][x]==' ') && (!mark[y][x]))
            || ((x==end_x)&&(y==end_y)&&(board[y][x]=='X')))) {
            mark[y][x] = true;
            // check boundaries
            if (f == i) search(x, y, end_x, end_y, step, i);
            else search(x, y, end_x, end_y, step + 1, i);
            mark[y][x] = false; // reverse,
        }
    }
}

int main() {
    int Boardnum = 0;
    while (scanf("%d %d", &w, &h)) {
        if (w==0 && h==0) break;
        Boardnum ++;
        printf("Board #%d:\n", Boardnum);
        int i, j;
        for (i=0; i<MAXIN+2; i++)
            board[0][i] = board[i][0] = ' ';
        for (i=1; i<=h; i++) { // input 'X' or '_'
            getchar();
            for (j=1; j<=w; j++)
                board[i][j] = getchar();
        }
        // padding
        for (i=0; i<=w; i++)
            board[h+1][i+1] = ' ';
        for (i=0; i<=h; i++)
            board[i+1][w+1] = ' ';
        int begin_x, begin_y, end_x, end_y, count=0;
        while (scanf("%d %d %d %d", &begin_x, &begin_y, &end_x, &end_y)
                && begin_x>0) { // read start and end pos
            count++;
            minstep = 100000; // initialize to a large num
            memset(mark, false, sizeof(mark));
            // recursive searcj
            search(begin_x, begin_y, end_x, end_y, 0, -1);
            // output result
            if (minstep<100000) printf("Pair %d: %d segment.\n", count, minstep);
            else printf("Pair %d: impossible.\n", count);
        }
        printf("\n");
    }
    return 0;
}

