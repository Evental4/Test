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

int main()
{
txCreateWindow (1100, 600);

    HDC Kal=txLoadImage("������.bmp");
    HDC Shed=txLoadImage("������_2.bmp");
    HDC Kal_1=txLoadImage("kal.bmp");

    txSetColor (TX_WHITE);
    txSetFillColor (TX_TRANSPARENT);
    txRectangle (10, 10, 1090, 590);

    txSelectFont("Times New Roman",30);
    txDrawText(0,0,1100,200,"��� �� ����� ������?");

    txRectangle (50, 200, 350, 450);
    txBitBlt(txDC(),50, 200,300,250,Kal );
    txDrawText(50, 450, 350, 550,"1");

    txRectangle (400, 200, 700, 450);
    txBitBlt(txDC(),400, 200,300,250,Shed );
    txDrawText(400, 450, 700, 550,"2");

    txRectangle (750, 200, 1050, 450);
    txDrawText(750, 450, 1050, 550,"3");
    txBitBlt(txDC(),750, 200,300,250,Kal_1 );


    txDeleteDC(Kal);
    txDeleteDC(Kal_1);
    txDeleteDC(Shed);


txTextCursor (false);
return 0;
}
