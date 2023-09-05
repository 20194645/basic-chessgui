#include <SDL2/SDL.h>
#include<stdio.h>
#include<vector>
#include <cstring>
#include<iostream>
#include <stdlib.h>
#include <string.h>
#include "connector.hpp"
using namespace std;
int squareSize = 75;
typedef struct piece{
    pair<int,int> coord;
    string filename;
    char symbol;
    char color;
    int castle = 0;
    int enqassant = 0;
    int paw1st = 0;
    vector<pair<int,int>> legalmove;
}piece;
vector<piece*> chessboard;
int board[8][8] = 
    {-1,-2,-3,-4,-5,-3,-2,-1,
     -6,-6,-6,-6,-6,-6,-6,-6,
      0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0,
      6, 6, 6, 6, 6, 6, 6, 6,
      1, 2, 3, 4, 5, 3, 2, 1};
void countdot(string a,string &b)
{
  int i = 0;
  int count = 0;
  while(0==0)
  {
    if(a[i]=='\0')
    {
      if(count!=0)
      {
        b.push_back(count+48);
      } 
      break;
    }
    if(a[i]=='.'){count++;}
    if(a[i]!='.'){
      if(count!=0)
      {
        b.push_back(count+48);
      }
      b.push_back(a[i]);
      count = 0;
    }
    i++;
  }
}
int checklegalmove(piece*p,int  x, int y){
  if (p!=nullptr){
    for(pair<int,int> it : p->legalmove){
    if(it.first== x && it.second == y){
        return 1;
    }
   }
  }
  return 0;
}
int checkpromotion(char &color){
  for (auto& p : chessboard){
    if (p->coord.second==7&&p->color=='b'&&p->symbol=='p'||p->coord.second==0&&p->color=='w'&&p->symbol=='p'){
      color = p->color;
      return 1;
    }
  }
  return 0;
}
void showpromotion(SDL_Renderer* &renderer,char color){
  if (color == 'b')
  {
    SDL_Surface* imageSurface1 = SDL_LoadBMP("D:\\MinGW64\\chess\\image\\bq.bmp");
    SDL_Texture* imageTexture1 = SDL_CreateTextureFromSurface(renderer, imageSurface1);
    SDL_Rect imageRect1 = {150,225, 70, 70};
    SDL_RenderCopy(renderer, imageTexture1, NULL, &imageRect1);
    SDL_DestroyTexture(imageTexture1);
    SDL_FreeSurface(imageSurface1);
    SDL_Surface* imageSurface2 = SDL_LoadBMP("D:\\MinGW64\\chess\\image\\br.bmp");
    SDL_Texture* imageTexture2 = SDL_CreateTextureFromSurface(renderer, imageSurface2);
    SDL_Rect imageRect2 = {225,225, 70, 70};
    SDL_RenderCopy(renderer, imageTexture2, NULL, &imageRect2);
    SDL_DestroyTexture(imageTexture2);
    SDL_FreeSurface(imageSurface2);
    SDL_Surface* imageSurface3 = SDL_LoadBMP("D:\\MinGW64\\chess\\image\\bn.bmp");
    SDL_Texture* imageTexture3 = SDL_CreateTextureFromSurface(renderer, imageSurface3);
    SDL_Rect imageRect3 = {300,225, 70, 70};
    SDL_RenderCopy(renderer, imageTexture3, NULL, &imageRect3);
    SDL_DestroyTexture(imageTexture3);
    SDL_FreeSurface(imageSurface3);
    SDL_Surface* imageSurface4 = SDL_LoadBMP("D:\\MinGW64\\chess\\image\\bb.bmp");
    SDL_Texture* imageTexture4 = SDL_CreateTextureFromSurface(renderer, imageSurface3);
    SDL_Rect imageRect4 = {375,225, 70, 70};
    SDL_RenderCopy(renderer, imageTexture4, NULL, &imageRect4);
    SDL_DestroyTexture(imageTexture4);
    SDL_FreeSurface(imageSurface4);
  }
  if (color == 'w')
  {
    SDL_Surface* imageSurface1 = SDL_LoadBMP("D:\\MinGW64\\chess\\image\\wq.bmp");
    SDL_Texture* imageTexture1 = SDL_CreateTextureFromSurface(renderer, imageSurface1);
    SDL_Rect imageRect1 = {150,225, 70, 70};
    SDL_RenderCopy(renderer, imageTexture1, NULL, &imageRect1);
    SDL_DestroyTexture(imageTexture1);
    SDL_FreeSurface(imageSurface1);
    SDL_Surface* imageSurface2 = SDL_LoadBMP("D:\\MinGW64\\chess\\image\\wr.bmp");
    SDL_Texture* imageTexture2 = SDL_CreateTextureFromSurface(renderer, imageSurface2);
    SDL_Rect imageRect2 = {225,225, 70, 70};
    SDL_RenderCopy(renderer, imageTexture2, NULL, &imageRect2);
    SDL_DestroyTexture(imageTexture2);
    SDL_FreeSurface(imageSurface2);
    SDL_Surface* imageSurface3 = SDL_LoadBMP("D:\\MinGW64\\chess\\image\\wn.bmp");
    SDL_Texture* imageTexture3 = SDL_CreateTextureFromSurface(renderer, imageSurface3);
    SDL_Rect imageRect3 = {300,225, 70, 70};
    SDL_RenderCopy(renderer, imageTexture3, NULL, &imageRect3);
    SDL_DestroyTexture(imageTexture3);
    SDL_FreeSurface(imageSurface3);
    SDL_Surface* imageSurface4 = SDL_LoadBMP("D:\\MinGW64\\chess\\image\\wb.bmp");
    SDL_Texture* imageTexture4 = SDL_CreateTextureFromSurface(renderer, imageSurface3);
    SDL_Rect imageRect4 = {375,225, 70, 70};
    SDL_RenderCopy(renderer, imageTexture4, NULL, &imageRect4);
    SDL_DestroyTexture(imageTexture4);
    SDL_FreeSurface(imageSurface4);
  }
  
}
void chosepromotion(int x,int y){
   float i = (float)x/75;
   float j = (float)y/75;
   for (auto& p : chessboard){
    if (p->coord.second==7&&p->color=='b'&&p->symbol=='p'||p->coord.second==0&&p->color=='w'&&p->symbol=='p'){
     if (p->color=='b'){
       if (i>2&&i<3&&j>3&&j<4){
        p->symbol ='q';
        p->filename = "D:\\MinGW64\\chess\\image\\bq.bmp";
       } 
       if (i>3&&i<4&&j>3&&j<4){
        p->symbol ='r';
        p->filename = "D:\\MinGW64\\chess\\image\\br.bmp";
       }
       if (i>4&&i<5&&j>3&&j<4){
        p->symbol ='n';
        p->filename = "D:\\MinGW64\\chess\\image\\bn.bmp";
       }
       if (i>5&&i<6&&j>3&&j<4){
        p->symbol ='b';
        p->filename = "D:\\MinGW64\\chess\\image\\bb.bmp";
       }
     }
     if (p->color=='w'){
      if (i>2&&i<3&&j>3&&j<4){
        p->symbol ='q';
        p->filename = "D:\\MinGW64\\chess\\image\\wq.bmp";
       } 
       if (i>3&&i<4&&j>3&&j<4){
        p->symbol ='r';
        p->filename = "D:\\MinGW64\\chess\\image\\wr.bmp";
       }
       if (i>4&&i<5&&j>3&&j<4){
        p->symbol ='n';
        p->filename = "D:\\MinGW64\\chess\\image\\wn.bmp";
       }
       if (i>5&&i<6&&j>3&&j<4){
        p->symbol = 'b';
        p->filename = "D:\\MinGW64\\chess\\image\\wb.bmp";
       }
     }
    }
  }
}
void makeboard(){
    int i,j;
    for(i=0;i<8;i++)
    {
     for ( j = 0; j < 8; j++)
     {
        if(board[i][j]==-6)
        {
         piece* bpawn = new piece;
         bpawn->filename = "D:\\MinGW64\\chess\\image\\bp.bmp";
         bpawn->symbol='p';
         bpawn->color = 'b';
         bpawn->paw1st = 1;
         bpawn->coord= make_pair(j,i);
         chessboard.push_back(bpawn);
        }
        if(board[i][j]==6)
        {
         piece* wpawn = new piece();
         wpawn->filename = "D:\\MinGW64\\chess\\image\\wp.bmp";
         wpawn->symbol='p';
         wpawn->color = 'w';
         wpawn->paw1st = 1;
         wpawn->coord= make_pair(j,i);
         chessboard.push_back(wpawn);
        }
        if (board[i][j]==1)
        {
         piece* wrock = new piece;
         wrock->filename = "D:\\MinGW64\\chess\\image\\wr.bmp";
         wrock->symbol='r';
         wrock->color = 'w';
         wrock->coord= make_pair(j,i);
         chessboard.push_back(wrock);
        }
        if (board[i][j]==-1)
        {
         piece* brock = new piece;
         brock->filename = "D:\\MinGW64\\chess\\image\\br.bmp";
         brock->symbol='r';
         brock->color = 'b';
         brock->coord= make_pair(j,i);
         chessboard.push_back(brock);
        }
        if (board[i][j]==2)
        {
         piece* wknight = new piece;
         wknight->filename = "D:\\MinGW64\\chess\\image\\wn.bmp";
         wknight->symbol='n';
         wknight->color = 'w';
         wknight->coord= make_pair(j,i);
         chessboard.push_back(wknight);
        }
        if (board[i][j]==-2)
        {
         piece* bknight = new piece;
         bknight->filename = "D:\\MinGW64\\chess\\image\\bn.bmp";
         bknight->symbol='n';
         bknight->color = 'b';
         bknight->coord= make_pair(j,i);
         chessboard.push_back(bknight);
        }
        if (board[i][j]==3)
        {
         piece* wbishop = new piece;
         wbishop->filename = "D:\\MinGW64\\chess\\image\\wb.bmp";
         wbishop->symbol='b';
         wbishop->color = 'w';
         wbishop->coord= make_pair(j,i);
         chessboard.push_back(wbishop);
        }
        if (board[i][j]==-3)
        {
         piece* bbishop = new piece;
         bbishop->filename = "D:\\MinGW64\\chess\\image\\bb.bmp";
         bbishop->symbol='b';
         bbishop->color = 'b';
         bbishop->coord= make_pair(j,i);
         chessboard.push_back(bbishop);
        }
        if (board[i][j]==4)
        {
         piece* wqueen = new piece;
         wqueen->filename = "D:\\MinGW64\\chess\\image\\wq.bmp";
         wqueen->symbol='q';
         wqueen->color = 'w';
         wqueen->coord= make_pair(j,i);
         chessboard.push_back(wqueen);
        }
        if (board[i][j]==-4)
        {
         piece* bqueen = new piece;
         bqueen->filename = "D:\\MinGW64\\chess\\image\\bq.bmp";
         bqueen->symbol='q';
         bqueen->color = 'b';
         bqueen->coord= make_pair(j,i);
         chessboard.push_back(bqueen);
        }
        if (board[i][j]==5)
        {
         piece* wking = new piece;
         wking->filename = "D:\\MinGW64\\chess\\image\\wk.bmp";
         wking->symbol='k';
         wking->color = 'w';
         wking->coord= make_pair(j,i);
         chessboard.push_back(wking);
        }
        if (board[i][j]==-5)
        {
         piece* bking = new piece;
         bking->filename = "D:\\MinGW64\\chess\\image\\bk.bmp";
         bking->symbol='k';
         bking->color = 'b';
         bking->coord= make_pair(j,i);
         chessboard.push_back(bking);
        }
     }
     
    }
}
void updatelistmove(piece* it){
    if(it->symbol == 'p' && it->color=='b'){
        it->legalmove.clear();
        if(it->paw1st == 1){
         int blockrow = 8,i;
         for (auto& p : chessboard){
          if (p->coord.first==it->coord.first&&p->coord.second<blockrow&&p->coord.second>it->coord.second){
            blockrow = p->coord.second;
          }
         }
         if ((blockrow - it->coord.second)>2){
          it->legalmove.push_back(make_pair(it->coord.first,it->coord.second+1));
          it->legalmove.push_back(make_pair(it->coord.first,it->coord.second+2));
         }
         else{
          for(i=0;i<(blockrow - it->coord.second);i++){
            it->legalmove.push_back(make_pair(it->coord.first,it->coord.second+i));
          }
         }
         for (auto& p : chessboard){
          if (p->coord.second==it->coord.second+1){
            if (p->coord.first == it->coord.first -1){
             it->legalmove.push_back(make_pair( p->coord.first,p->coord.second));
            }
            if (p->coord.first == it->coord.first + 1){
             it->legalmove.push_back(make_pair( p->coord.first,p->coord.second));
            }
          }
         }
         it->paw1st = 0;
        }
        if (it->paw1st==0){
          int blockrow = 8,i;
          for (auto& p : chessboard){
          if (p->coord.first==it->coord.first&&p->coord.second<blockrow&&p->coord.second>it->coord.second){
            blockrow = p->coord.second;
           }
          }
          if ((blockrow - it->coord.second)>1){
            it->legalmove.push_back(make_pair(it->coord.first,it->coord.second+1));
          }
          for (auto& p : chessboard){
           if (p->coord.second==it->coord.second+1){
            if (p->coord.first == it->coord.first -1){
             it->legalmove.push_back(make_pair( p->coord.first,p->coord.second));
            }
            if (p->coord.first == it->coord.first + 1){
             it->legalmove.push_back(make_pair( p->coord.first,p->coord.second));
            }
           }
          }
        }
    }
    if(it->symbol == 'p' && it->color=='w'){
        it->legalmove.clear();
        if(it->paw1st == 1){
         int blockrow = -1,i;
         for (auto& p : chessboard){
          if (p->coord.first==it->coord.first&&p->coord.second>blockrow&&p->coord.second<it->coord.second){
            blockrow = p->coord.second;
          }
         }
         if ((it->coord.second - blockrow)>2){
          it->legalmove.push_back(make_pair(it->coord.first,it->coord.second-1));
          it->legalmove.push_back(make_pair(it->coord.first,it->coord.second-2));
         }
         else{
          for(i=0;i<(it->coord.second - blockrow);i++){
            it->legalmove.push_back(make_pair(it->coord.first,it->coord.second - i));
          }
         }
         for (auto& p : chessboard){
          if (p->coord.second==it->coord.second-1){
            if (p->coord.first == it->coord.first -1){
             it->legalmove.push_back(make_pair( p->coord.first,p->coord.second));
            }
            if (p->coord.first == it->coord.first + 1){
             it->legalmove.push_back(make_pair( p->coord.first,p->coord.second));
            }
          }
         }
         it->paw1st = 0;
        }
        if (it->paw1st==0){
          int blockrow = -1,i;
          for (auto& p : chessboard){
          if (p->coord.first==it->coord.first&&p->coord.second>blockrow&&p->coord.second<it->coord.second){
            blockrow = p->coord.second;
           }
          }
          if ((it->coord.second - blockrow)>1){
            it->legalmove.push_back(make_pair(it->coord.first,it->coord.second - 1));
          }
          for (auto& p : chessboard){
           if (p->coord.second==it->coord.second-1){
            if (p->coord.first == it->coord.first -1){
             it->legalmove.push_back(make_pair( p->coord.first,p->coord.second));
            }
            if (p->coord.first == it->coord.first + 1){
             it->legalmove.push_back(make_pair( p->coord.first,p->coord.second));
            }
           }
          }
        }
    }
    if(it->symbol== 'r'){
      it->legalmove.clear();
      int i;
      int firstrow = -1,lastrow = 8,firstcol =-1,lastcol =8;
      for (auto& p : chessboard)
      {
        if (p->coord.first==it->coord.first){
          if (p->coord.second>it->coord.second&&p->coord.second<lastrow){
            lastrow = p->coord.second;
          }
          if (p->coord.second<it->coord.second&&p->coord.second>firstrow){
            firstrow = p->coord.second;
          }
        }
        if (p->coord.second==it->coord.second){
          if (p->coord.first>it->coord.first&&p->coord.first<lastcol){
           lastcol = p->coord.first;
          }
          if (p->coord.first<it->coord.first&&p->coord.first>firstcol){
           firstcol = p->coord.first;
          }
        }
      }
      for ( i = firstrow; i <= lastrow; i++)
      {
        it->legalmove.push_back(make_pair( it->coord.first,i));
      }
      for ( i = firstcol; i <= lastcol; i++)
      {
        it->legalmove.push_back(make_pair( i,it->coord.second));
      }
    }
    if (it->symbol=='b')
    {
      it->legalmove.clear();
      int i;
      int firstdia1=-8,lastdia1=8,firstdia2=-8,lastdia2=8;
      for (auto& p : chessboard)
      {
        int k = p->coord.first-it->coord.first;
        int j =  p->coord.second - it->coord.second;
        if (k == j){
          if (k>0&&k<lastdia1){
            lastdia1 = k;
          }
          if (k<0&&k>firstdia1){
            firstdia1 = k;
          }
        }
        if (k == -j){
          if (k>0&&k<lastdia2){
            lastdia2 = k;
          }
          if (k<0&&k>firstdia2){
            firstdia2 = k;
          }
        }
      }
      for ( i = firstdia1; i <= lastdia1; i++){
        it->legalmove.push_back(make_pair(it->coord.first+i,it->coord.second+i));
      }
      for ( i = firstdia2; i <= lastdia2; i++){
        it->legalmove.push_back(make_pair(it->coord.first+i,it->coord.second-i));
      }
      
    }
    if (it->symbol == 'n')
    {
       it->legalmove.clear();
       it->legalmove.push_back(make_pair(it->coord.first+1,it->coord.second+2)  );
       it->legalmove.push_back( make_pair(it->coord.first+1,it->coord.second-2)  );
       it->legalmove.push_back( make_pair(it->coord.first-1,it->coord.second-2) );
       it->legalmove.push_back( make_pair(it->coord.first-1,it->coord.second+2)  );
       it->legalmove.push_back( make_pair(it->coord.first-2,it->coord.second-1)  );
       it->legalmove.push_back( make_pair(it->coord.first-2,it->coord.second+1) );
       it->legalmove.push_back( make_pair(it->coord.first+2,it->coord.second-1)  );
       it->legalmove.push_back( make_pair(it->coord.first+2,it->coord.second+1)  );
    }
    if (it->symbol == 'k')
    {
       it->legalmove.clear();
       it->legalmove.push_back(make_pair(it->coord.first+1,it->coord.second+1)  );
       it->legalmove.push_back( make_pair(it->coord.first+1,it->coord.second-1)  );
       it->legalmove.push_back( make_pair(it->coord.first-1,it->coord.second-1) );
       it->legalmove.push_back( make_pair(it->coord.first-1,it->coord.second+1)  );
       it->legalmove.push_back( make_pair(it->coord.first-1,it->coord.second)  );
       it->legalmove.push_back( make_pair(it->coord.first+1,it->coord.second) );
       it->legalmove.push_back( make_pair(it->coord.first,it->coord.second-1)  );
       it->legalmove.push_back( make_pair(it->coord.first,it->coord.second+1)  );
    }
    if (it->symbol=='q')
    {
       it->legalmove.clear();
       int i;
       int firstrow = -1,lastrow = 8,firstcol =-1,lastcol =8;
       for (auto& p : chessboard)
       {
        if (p->coord.first==it->coord.first){
          if (p->coord.second>it->coord.second&&p->coord.second<lastrow){
            lastrow = p->coord.second;
          }
          if (p->coord.second<it->coord.second&&p->coord.second>firstrow){
            firstrow = p->coord.second;
          }
        }
        if (p->coord.second==it->coord.second){
          if (p->coord.first>it->coord.first&&p->coord.first<lastcol){
           lastcol = p->coord.first;
          }
          if (p->coord.first<it->coord.first&&p->coord.first>firstcol){
           firstcol = p->coord.first;
          }
        }
       }
       for ( i = firstrow; i <= lastrow; i++){
        it->legalmove.push_back(make_pair( it->coord.first,i));
       }
       for ( i = firstcol; i <= lastcol; i++){
        it->legalmove.push_back(make_pair( i,it->coord.second));
       }
       int firstdia1=-8,lastdia1=8,firstdia2=-8,lastdia2=8;
       for (auto& p : chessboard)
       {
        int k = p->coord.first-it->coord.first;
        int j =  p->coord.second - it->coord.second;
        if (k == j){
          if (k>0&&k<lastdia1){
            lastdia1 = k;
          }
          if (k<0&&k>firstdia1){
            firstdia1 = k;
          }
        }
        if (k == -j){
          if (k>0&&k<lastdia2){
            lastdia2 = k;
          }
          if (k<0&&k>firstdia2){
            firstdia2 = k;
          }
        }
       }
       for ( i = firstdia1; i <= lastdia1; i++){
        it->legalmove.push_back(make_pair(it->coord.first+i,it->coord.second+i));
       }
       for ( i = firstdia2; i <= lastdia2; i++){
        it->legalmove.push_back(make_pair(it->coord.first+i,it->coord.second-i));
       }
    }    
}

void updatepos(int prex,int prey,int nextx,int nexty){
    if(prex!=nextx&&prey!=nexty){
     int posx,posy,i,c1,c2;
     piece* p = nullptr;
     posx = prex/75;
     posy=prey/75;
     int x =nextx/75;
     int y = nexty/75;
     for (auto&it :chessboard)
     {
        if (it->coord.first == posx&&it->coord.second==posy){
            c1 = it->color;
            p = it;
        }
        if(it->coord.first==nextx/75&&it->coord.second==nexty/75){
            c2 =it->color;
        }
     }
     if (p!=nullptr)
     {
      updatelistmove(p);
     }
     if (checklegalmove(p,x,y)==1)
     {
      for(i=0;i<chessboard.size();i++)
      {
        if(chessboard.at(i)->coord.first==nextx/75&&chessboard.at(i)->coord.second==nexty/75&&c1!=c2){
            chessboard.erase(chessboard.begin()+i);
        }
      }
      for (auto& it : chessboard)
      {
        if (it->coord.first == posx&&it->coord.second==posy&&c1!=c2)
        {  
            it->coord.first = x;
            it->coord.second = y;
        }
      }
     }
    }
}
void drawlistmove(SDL_Renderer* &renderer){

}
void drawpiece(SDL_Renderer* &renderer){
  for(auto& it : chessboard)
  {
    SDL_Surface* imageSurface = SDL_LoadBMP(it->filename.c_str());
    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_Rect imageRect = {it->coord.first*75,it->coord.second*75, 70, 70};
    SDL_RenderCopy(renderer, imageTexture, NULL, &imageRect);
    SDL_DestroyTexture(imageTexture);
    SDL_FreeSurface(imageSurface);
  }
}
void drawboard(SDL_Renderer* &renderer){
  int i,j;
  for ( i = 0; i < 8; i++) {
        for ( j = 0; j < 8; j++) {
            SDL_Rect squareRect = { j * squareSize, i * squareSize, squareSize, squareSize };
            if ((i + j) % 2 == 0) {
                SDL_SetRenderDrawColor(renderer,200,210,200,100);
                SDL_RenderFillRect(renderer, &squareRect);
                
            }
            else{
                SDL_SetRenderDrawColor(renderer,0,150,50,0);
                SDL_RenderFillRect(renderer, &squareRect);
            }
        }
    }
}
string makefen(int turn){
    string newstring;
    char fen[8][10] = {
        {'.', '.', '.', '.', '.', '.', '.', '.', '/'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '/'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '/'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '/'},
        {'.', '.', '.', '.', '.', '.', '.', '.','/'},
        {'.', '.', '.', '.', '.', '.', '.', '.','/'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '/'},
        {'.', '.', '.', '.', '.', '.', '.', '.'}
    };
    for(auto&it : chessboard){
        if(it->color=='w'){
          fen[it->coord.second][it->coord.first]=(it->symbol - 32);
        }
        if(it->color=='b'){
         fen[it->coord.second][it->coord.first] = it->symbol;
        }      
    }
    for (int i = 0; i < 8; i++) {
        newstring += fen[i];
    } 
    string fenstring;
    countdot(newstring,fenstring);
    if(turn%2==1){
     fenstring.push_back(' ');
     fenstring.push_back('b');
    }
    if(turn%2==0){
     fenstring.push_back(' ');
     fenstring.push_back('w');
    }
    return fenstring;
}
// đoạn này đang cần sửa 

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    makeboard();
    char stockfishPath[] = "D:\\stockfish\\stockfish-windows-x86-64-avx2.exe";
    ConnectToEngine(stockfishPath);
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL Initialization Error: %s\n", SDL_GetError());
        return -1;
    }

    // Create a window and renderer
    SDL_Window* window = SDL_CreateWindow("Moving Image with Mouse", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Load an image as an SDL_Texture (replace "image.bmp" with your image file)
   
    SDL_Surface* imageSurface = SDL_LoadBMP("D:\\MinGW64\\chess\\image\\wp.bmp");
    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_Rect imageRect = { 150,75, 70, 70}; // Initial position and size
    
    // Variables to track mouse state
    
    
    
    int isMousePressed = 2;

    // Event loop
    char color;
    int turn = 0;
    int quit = 0;
    SDL_Event e;
    while (!quit) {
        int mouseX, mouseY;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            } 
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    // Mouse left button pressed
                    mouseX = e.button.x;
                    mouseY = e.button.y;
                    if (checkpromotion(color)==1)
                    {
                      chosepromotion(mouseX ,mouseY);
                    }
                    isMousePressed = 1;
                }
            } 
            if (e.type == SDL_MOUSEBUTTONUP && isMousePressed == 1) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    // Mouse left button released
                    isMousePressed = 0;
                }
            }
        }

        // Update the image's position if the mouse button is pressed
        if (isMousePressed==0) {
            turn++;
            int mouseX1, mouseY1;
            SDL_GetMouseState(&mouseX1, &mouseY1);
            updatepos(mouseX,mouseY,mouseX1,mouseY1);
            string fen = makefen(turn);
            //getNextMove(fen);
            isMousePressed = 2;
        }

        // Clear the screen (usually done once per frame)
        // Set background color (black)
        
        SDL_RenderClear(renderer);
       if (checkpromotion(color)==0){
          drawboard(renderer);
        // Render the image at the updated position 
          drawpiece(renderer);
        // Update the screen
         SDL_RenderPresent(renderer);
        }
        if (checkpromotion(color)==1){
          SDL_SetRenderDrawColor(renderer,200,210,200,100);
          showpromotion(renderer,color);
          SDL_RenderPresent(renderer);
        }
    }

    // Clean up resources
    CloseConnection();
    SDL_DestroyTexture(imageTexture);
    SDL_FreeSurface(imageSurface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
