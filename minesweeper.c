#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define brd(i) (*(brdptr+i))
#define open(i) (*(openedptr+i))
#define mine(i) (*(minesptr+i))
#define L 2
#define R 4
#define U 16
#define D 64
#define size (sizex*sizey)

void printBoard(int* brdptr, bool* openedptr, int sizex, int sizey) {
    for (int i = 0; i < sizex*sizey; i++) {
        if (open(i)) {printf("%d",brd(i));}
        else {printf("?");}
        if (!((i+1)%sizex)) {printf("\n");}
    }
}

int posflags(int p, int sizex, int sizey) {
    int r = 0;
    if (p<sizex) r |= U;
    if (p>=sizex*(sizey-1)) r |= D;
    if (!(p%sizex)) r|= L;
    if ((p%sizex)+1 == sizex) r |= R;
    return r;
}

void openCell(int* brdptr, bool* openedptr, int sizex, int sizey, int i) {
    open(i) = true;
    if (brd(i)==0) {
        int posFLAG = posflags(i,sizex,sizey);
        if (i-sizex-1 >= 0    && open(i-sizex-1)!=true && !(posFLAG&U) && !(posFLAG&L)){openCell(brdptr, openedptr, sizex, sizey, i-sizex-1);}
        if (i-sizex   >= 0    && open(i-sizex  )!=true && !(posFLAG&U)                ){openCell(brdptr, openedptr, sizex, sizey, i-sizex  );}
        if (i-sizex+1 >= 0    && open(i-sizex+1)!=true && !(posFLAG&U) && !(posFLAG&R)){openCell(brdptr, openedptr, sizex, sizey, i-sizex+1);}
        if (i-1       >= 0    && open(i-1      )!=true && !(posFLAG&L)                ){openCell(brdptr, openedptr, sizex, sizey, i-1      );}
        if (i+1       <  size && open(i+1      )!=true && !(posFLAG&R)                ){openCell(brdptr, openedptr, sizex, sizey, i+1      );}
        if (i+sizex-1 <  size && open(i+sizex-1)!=true && !(posFLAG&D) && !(posFLAG&L)){openCell(brdptr, openedptr, sizex, sizey, i+sizex-1);}
        if (i+sizex   <  size && open(i+sizex  )!=true && !(posFLAG&D)                ){openCell(brdptr, openedptr, sizex, sizey, i+sizex  );}
        if (i+sizex+1 <  size && open(i+sizex+1)!=true && !(posFLAG&D) && !(posFLAG&R)){openCell(brdptr, openedptr, sizex, sizey, i+sizex+1);}
    }
}

bool done(bool* openedptr,bool* minesptr,int sizex, int sizey) {
    for (size_t i = 0; i < size; i++) {
        if (open(i)==mine(i)) return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    if (argc < 2){
        printf("Missing size arg\nUse 1 for 9x9, 2 for 16x16, 3 for 16x30, 4 for custom or 5 for 5x5");
        return 0;
    }
    if (argc < 3) {
        printf("No seed\nThe second argument is the rng seed");
        return 0;
    }
    srand(*argv[2]);

    int sizex;
    int sizey;
    int mines;
    switch (atoi(argv[1])) {
    case 1:
        sizex = 9;
        sizey = 9;
        mines = 10;
        break;
    case 2:
        sizex = 16;
        sizey = 16;
        mines = 40;
        break;
    case 3:
        sizex = 16;
        sizey = 30;
        mines = 99;
        break;
    case 4:
        if (argc < 4) {printf("Not enough params for custom size, add args for w, h, mineCount"); return 0;}
        sizex = atoi(argv[3]);
        sizey = atoi(argv[4]);
        mines = atoi(argv[5]);
        if (sizex<0 || sizey <0) {printf("The board must have positive dimentions"); return 0;}
        if (mines>size) {printf("U can't ahve more mines than the board is big"); return 0;}
        break;
    case 5:
        sizex = 5;
        sizey = 5;
        mines = 3;
        break;
    default:
        printf("Invalid size\nUse 1 for 9x9, 2 for 16x16, 3 for 16x30, 4 for custom (add args for w, h, mineCount) or 5 for 5x5");
        return 0;
    }
    int* brdptr = calloc(size, sizeof(int));
    bool* minesptr = calloc(size,sizeof(bool));

    int minesToPlace = mines;
    while (minesToPlace) {
        int p = rand() % (size);
        if (!mine(p)) {
            mine(p)=true;
            minesToPlace--;
            int posFLAG = posflags(p,sizex,sizey);
            if (p-sizex-1 >= 0    && !mine(p-sizex-1) && !(posFLAG&U) && !(posFLAG&L)){brd(p-sizex-1)++;}
            if (p-sizex   >= 0    && !mine(p-sizex  ) && !(posFLAG&U)                ){brd(p-sizex  )++;}
            if (p-sizex+1 >= 0    && !mine(p-sizex+1) && !(posFLAG&U) && !(posFLAG&R)){brd(p-sizex+1)++;}
            if (p-1       >= 0    && !mine(p-1      ) && !(posFLAG&L)                ){brd(p-1      )++;}
            if (p+1       <  size && !mine(p+1      ) && !(posFLAG&R)                ){brd(p+1      )++;}
            if (p+sizex-1 <  size && !mine(p+sizex-1) && !(posFLAG&D) && !(posFLAG&L)){brd(p+sizex-1)++;}
            if (p+sizex   <  size && !mine(p+sizex  ) && !(posFLAG&D)                ){brd(p+sizex  )++;}
            if (p+sizex+1 <  size && !mine(p+sizex+1) && !(posFLAG&D) && !(posFLAG&R)){brd(p+sizex+1)++;}
        }
    }
    bool* openedptr = calloc(size,sizeof(bool));

    printf("Welocme to minesweeper:\nType 3 4 to open cell (3,4). 0 index cuz ofc\n");
    printBoard(brdptr,openedptr,sizex,sizey);

    while (!done(openedptr,minesptr,sizex,sizey)) {
        int x = -1;
        int y = -1;
        while (x<0 || x>sizex || y<0 || y>sizey) {
            scanf("%d",&x);
            scanf("%d",&y);
        }
        if (mine(x+sizex*y)) {printf("U lose sucker"); return 0;}
        openCell(brdptr, openedptr, sizex, sizey, x+sizex*y);
        printBoard(brdptr,openedptr,sizex,sizey);
    }
    printf("GG, u won");
    free(brdptr);
    free(openedptr);
    free(minesptr);
}