//========================================================================
//! @file       Main.cpp
//{=======================================================================
//!
//! @brief      <���������>\n
//! @brief      <������������>
//!
//! @version    [Version 0.01 alpha, build 1]
//! @author     Copyright (C) <�����>, <���> (<���> <�����>)
//! @date       <����>
//!
//! @par        ��������������
//!           - (TODO: ������ ��������)
//!
//! @todo     - (TODO: ������ ��������� ������ �� ����� �����)
//!
//! @bug      - (TODO: ������ ��������� ������ � ���� �����)
//!
//! @par        ������� ��������� �����
//!           - ������ 0.01 Alpha
//!             - ������ ��� ��������� ����
//!
//}=======================================================================

#include "TXLib.h"

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

     Form queestion_buffer;

     Form queest1={"��� �� ����� ������?",2,txLoadImage("������.bmp"),"1",txLoadImage("������_2.bmp"),"2",txLoadImage("kal.bmp"),"3"} ;
     Form queest2={"��� �� ���������� ����� ���� ��������?",2,txLoadImage("5_star_air.bmp"),"�����",
     txLoadImage("4_star_fizic.bmp"),"�������",txLoadImage("Blaidic.bmp"),"����"};


     int n_queestion = 1;
     int kol_queestion=2//9;
     int kol_right_answer=0;
      while(n_queestion <=kol_queestion)
{
      txSetColor (TX_BLACK);
      txSetFillColor (TX_BLACK);
      txClear();
      txBegin();

     if(n_queestion ==1) queestion_buffer=queest1;
     else if (n_queestion ==2) queestion_buffer=queest2;

    //������
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

//����� ����� ������� �����?,1,PAZ.bmp,����������,IZOB.bmp,��������,�PYD.bmp,���������
//����� ����� ������� �� ���� ���.?,3,NEBOT.bmp,�������,IZOB.bmp,��������,PAZ.bmp,����������
//����� ����� ������� ������?,1,�PYD.bmp,���������,NEBOT.bmp,�������,IZOB.bmp,��������
//����� ����� ������� �����?,3,PAZ.bmp,����������,IZOB.bmp,��������,NEBOT.bmp,�������
//����� ����� ������� �����?,1,IZOB.bmp,��������,NEBOT.bmp,�������,PAZ.bmp,����������
//����� ����� ������� ���������� ����?,1,NEBOT.bmp,�������,�PYD.bmp,���������,PAZ.bmp,����������
//����� ����� ������� ������?,3,NEBOT.bmp,�������,IZOB.bmp,��������,�PYD.bmp,���������

    txEnd();
    txSleep(90);


}
    txSetColor (TX_WHITE);
    txSetFillColor (TX_BLACK);
    txClear();
    char par[50];
    sprintf(par,"���������� ���������� �������-%d",kol_right_answer) ;
    txDrawText(0,0,1100,600,par);


    txDeleteDC( queestion_buffer.pic_answer1);
    txDeleteDC( queestion_buffer.pic_answer2);
    txDeleteDC( queestion_buffer.pic_answer3);

txTextCursor (false);
return 0;
}
