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
    HDC pic_answer1;
    string text_answer1;
    HDC pic_answer2;
    string text_answer2;
    HDC pic_answer3;
    string text_answer3;

 } ;


int main()
{
txCreateWindow (1100, 600);

     Form queestion_buffer;

     Form queest1={"��� �� ����� ������?",txLoadImage("������.bmp"),"1",txLoadImage("������_2.bmp"),"2",txLoadImage("kal.bmp"),"3"} ;
     Form queest2={"��� �� ���������� ����� ���� ��������?",txLoadImage("5_star_air.bmp"),"�����",
     txLoadImage("4_star_fizic.bmp"),"�������",txLoadImage("Blaidic.bmp"),"����"};


     int n_queestion = 1;
     int kol_queestion=2;

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

    txRectangle (50, 200, 350, 450);
    txBitBlt(txDC(),50, 200,300,250,queestion_buffer. pic_answer1 );
    txDrawText(50, 450, 350, 550,queestion_buffer.text_answer1.c_str());

    txRectangle (400, 200, 700, 450);
    txBitBlt(txDC(),400, 200,300,250,queestion_buffer. pic_answer2 );
    txDrawText(400, 450, 700, 550, queestion_buffer.text_answer2.c_str());

    txRectangle (750, 200, 1050, 450);
    txDrawText(750, 450, 1050, 550,queestion_buffer.text_answer3.c_str());
    txBitBlt(txDC(),750, 200,300,250, queestion_buffer.pic_answer3);

     if(txMouseButtons()== 1 &&
         txMouseX() > 50 && txMouseX() < 350 &&
         txMouseY() > 200 && txMouseY() < 450 )
         {
         n_queestion ++;
         }

     if(txMouseButtons()== 1 &&
         txMouseX() > 400 && txMouseX() < 700 &&
         txMouseY() > 200 && txMouseY() < 450 )
         {
         n_queestion ++;
         }

     if(txMouseButtons()== 1 &&
         txMouseX() > 750 && txMouseX() < 1050 &&
         txMouseY() > 200 && txMouseY() < 450 )
         {
         n_queestion ++;
         }

//����� ����� ������� �����
//����� ����� ������� �� � 1 �����
//����� ����� ������� ������
//����� ����� ������� �����
//����� ����� ������� �����
//����� ����� ������� ���������� ����

    txEnd();
    txSleep(100);


}

    txDeleteDC( queestion_buffer.pic_answer1);
    txDeleteDC( queestion_buffer.pic_answer2);
    txDeleteDC( queestion_buffer.pic_answer3);

txTextCursor (false);
return 0;
}

