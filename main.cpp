
#include "TXLib.h"
#include <fstream>

using namespace std;

 struct Form
 {
    string text_queestion;
    int right_answer;
    HDC pic_answer1;
    string text_answer1;
    HDC pic_answer2;
    string text_answer2;
    HDC pic_answer3;
    string text_answer3;

 } ;

 void draw_answer(int x,HDC pic_answer,string text_answer)
 {
    txRectangle (x, 200, x+300, 450);
    txBitBlt(txDC(),x, 200,300,250, pic_answer );
    txDrawText(x, 450, x+300, 550,text_answer.c_str());
 }

 bool Click_answer(int x)
 {
 return(txMouseButtons()== 1 && txMouseX()>x && txMouseX()<x+300 && txMouseY()>200 && txMouseY()<450 );

 }

int main()
{
txCreateWindow (1100, 600);
setlocale (LC_ALL , "Russian");

     Form queestion_buffer;

     Form queest[10];

     string str;
     int n_queestion = 1;
     int kol_queestion=2;
     int kol_right_answer=0;
     int n=0;

    ifstream file("вопросы.txt");

    while(file.good())
{
    getline(file,str);
    int pos2 = -1;
    int pos1 = pos2+1;

    pos2 =str.find(",",pos1);
    queest[n].text_queestion= str.substr(pos1, pos2-pos1);

    pos1 =pos2+1;
    pos2 =str.find(",",pos1);
    queest[n].right_answer =atoi((str.substr(pos1, pos2-pos1)).c_str());

    pos1 =pos2+1;
    pos2 =str.find(",",pos1);
    queest[n].pic_answer1=txLoadImage((str.substr(pos1, pos2-pos1)).c_str());

    pos1 =pos2+1;
    pos2 =str.find(",",pos1);
    queest[n].text_answer1= str.substr(pos1, pos2-pos1);

    pos1 =pos2+1;
    pos2 =str.find(",",pos1);
    queest[n].pic_answer2 =txLoadImage((str.substr(pos1, pos2-pos1)).c_str());

    pos1 =pos2+1;
    pos2 =str.find(",",pos1);
    queest[n].text_answer2=str.substr(pos1, pos2-pos1);

    pos1 =pos2+1;
    pos2 =str.find(",",pos1);
    queest[n].pic_answer3 =txLoadImage((str.substr(pos1, pos2-pos1)).c_str());

    pos1 =pos2+1;
    pos2 =str.find(",",pos1);
    queest[n].text_answer3=str.substr(pos1, pos2-pos1);

    n++;
}

while(n_queestion <=kol_queestion)
{
      txSetColor (TX_BLACK);
      txSetFillColor (TX_BLACK);
      txClear();
      txBegin();

     if(n_queestion ==1) queestion_buffer=queest[0];
     else if (n_queestion ==2) queestion_buffer=queest[1];

    //шаблон
    txSetColor (TX_WHITE);
    txSetFillColor (TX_TRANSPARENT);
    txRectangle (10, 10, 1090, 590);

    txSelectFont("Times New Roman",30);
    txDrawText(0,0,1100,200,queestion_buffer.text_queestion.c_str());

    draw_answer(50,queestion_buffer.pic_answer1 ,queestion_buffer.text_answer1 );
    draw_answer(400,queestion_buffer.pic_answer2 ,queestion_buffer.text_answer2 );
    draw_answer(750,queestion_buffer.pic_answer3 ,queestion_buffer.text_answer3 );

     if( Click_answer(50) )
         {
         if(queestion_buffer.right_answer == 1) kol_right_answer++;
         n_queestion ++;
         }

     if( Click_answer(400) )
         {
         if(queestion_buffer.right_answer == 2) kol_right_answer++;
         n_queestion ++;
         }

     if( Click_answer(750))
         {
         if(queestion_buffer.right_answer == 3) kol_right_answer++;
         n_queestion ++;
         }

//каким путем владеет клара
//каким путем владеет гг в 1 форме
//каким путем владеет химека
//каким путем владеет фельт
//каким путем владеет байлу
//каким путем владеет серебряный волк

    txEnd();
    txSleep(90);


}
    txSetColor (TX_WHITE);
    txSetFillColor (TX_BLACK);
    txClear();
    char par[50];
    sprintf(par,"количиство правильных ответов-%d",kol_right_answer) ;
    txDrawText(0,0,1100,600,par);

    txDeleteDC( queestion_buffer.pic_answer1);
    txDeleteDC( queestion_buffer.pic_answer2);
    txDeleteDC( queestion_buffer.pic_answer3);


txTextCursor (false);
return 0;
}
