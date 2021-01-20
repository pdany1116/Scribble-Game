//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Source.h"
#include "HowToPlay.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGRID"
#pragma resource "*.dfm"
TInterfata *Interfata;
//---------------------------------------------------------------------------
__fastcall TInterfata::TInterfata(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TInterfata::ExitClick(TObject *Sender)
{
        exit(0);        
}
//---------------------------------------------------------------------------
void __fastcall TInterfata::StartClick(TObject *Sender)
{
    Joc=new GameScribble();
    SendLinie="";
    SendGuma="";
    SendGaletusa="";
    SendCerc="";
    SendDreptunghi="";
}
//---------------------------------------------------------------------------
void __fastcall TInterfata::PanzaMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Joc->poz->setX(X);
        Joc->poz->setY(Y);

        if(Creion->Down)
        {
            Joc->fig->InitPen();
            Joc->mousedown=true;

            SendLinie+='L';
            String strMarime=IntToStr(Joc->fig->intMarime);
            SendLinie+=strMarime; SendLinie+='#';

            String strColIndex = IntToStr(Joc->fig->intColIndex);
            SendLinie+=strColIndex; SendLinie+='#';
        }

        if(Galetusa->Down)
        {
            Joc->fig->Umplere();
            SendGaletusa+='F';

            String strColIndex = IntToStr(Joc->fig->intColIndex);
            SendGaletusa+=strColIndex; SendGaletusa+='#';
             
            String strx,stry;
            strx=IntToStr(Interfata->Joc->poz->getX());
            stry=IntToStr(Interfata->Joc->poz->getY());
            SendGaletusa+=strx;
            SendGaletusa+=';';
            SendGaletusa+=stry;
            SendGaletusa+=';';


            Interfata->clSocket->Socket->SendText(SendGaletusa);
            SendGaletusa="";
        }

        if(Guma->Down)
        {
            Joc->fig->InitGuma();
            Joc->mousedown=true;

            SendGuma+='G';
            String strMarime=IntToStr(Joc->fig->intMarime);
            SendGuma+=strMarime; SendGuma+='#';
        }

        if(Cerc->Down)
        {
            Joc->fig->InitPen();

            SendCerc+='O';
            String strMarime=IntToStr(Joc->fig->intMarime);
            SendCerc+=strMarime; SendCerc+='#';

            String strColIndex = IntToStr(Joc->fig->intColIndex);
            SendCerc+=strColIndex; SendCerc+='#';
        }

        if(Dreptunghi->Down)
        {
            Joc->fig->InitPen();

            SendDreptunghi+='D';
            String strMarime=IntToStr(Joc->fig->intMarime);
            SendDreptunghi+=strMarime; SendDreptunghi+='#';

            String strColIndex = IntToStr(Joc->fig->intColIndex);
            SendDreptunghi+=strColIndex; SendDreptunghi+='#';
        }

        Joc->fig->setXaj(X);
        Joc->fig->setYaj(Y);

}
//---------------------------------------------------------------------------

void __fastcall TInterfata::PanzaMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        if(Creion->Down && Joc->mousedown)
        {
                Panza->Canvas->LineTo(X,Y);

                String strx,stry;
                strx=IntToStr(X);
                stry=IntToStr(Y);
                SendLinie+=strx;
                SendLinie+=';';
                SendLinie+=stry;
                SendLinie+=';';
        }

        if(Guma->Down && Joc->mousedown)
        {
                Panza->Canvas->LineTo(X,Y);

                String strx,stry;
                strx=IntToStr(X);
                stry=IntToStr(Y);
                SendGuma+=strx;
                SendGuma+=';';
                SendGuma+=stry;
                SendGuma+=';';
        }
}

//---------------------------------------------------------------------------

void __fastcall TInterfata::PanzaMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Joc->poz->setX(X);
        Joc->poz->setY(Y);

        if(Creion->Down)
        {
                Joc->mousedown=false;
                Panza->Canvas->Pen->Width=0;
                SendLinie+=" ";
                Interfata->clSocket->Socket->SendText(SendLinie);
                SendLinie="";
        }

        if(Guma->Down)
        {
                Joc->mousedown=false;
                Panza->Canvas->Pen->Width=0;
                SendGuma+=" ";
                Interfata->clSocket->Socket->SendText(SendGuma);
                SendGuma="";
        }

        Joc->fig->Desen();


        Interfata->clSocket->Socket->SendText(SendDreptunghi);
        Interfata->clSocket->Socket->SendText(SendCerc);
        SendCerc="";
        SendDreptunghi="";

}
//---------------------------------------------------------------------------

void __fastcall TInterfata::ClearClick(TObject *Sender)
{
        Panza->Picture=Joc->PanzaAlba;
        String SendClear="clear";
        Interfata->clSocket->Socket->SendText(SendClear);
}
//---------------------------------------------------------------------------

void __fastcall TInterfata::RaspunsKeyPress(TObject *Sender, char &Key)
{
        if(Key==13)
        {
                 if(Raspuns->Text == "")
                 {
                      return;
                 }
                 else if(Raspuns->Text == Cuvant->Caption)
                 {
                      Raspunsuri->Lines->Add("Ai ghicit!");
                      (Joc->cl_scor)++;
                      clSocket->Socket->SendText("@");
                      Raspuns->Enabled=false;
                      clSocket->Socket->SendText("R AM GHICIT!");
                 }
                 else
                 {
                      String SendRaspuns="R";
                      SendRaspuns+=Raspuns->Text;
                      clSocket->Socket->SendText(SendRaspuns);
                      Raspunsuri->Lines->Add("You: " + Raspuns->Text);
                 }

                 Raspuns->Text="";
        }
}
//---------------------------------------------------------------------------








void __fastcall TInterfata::clSocketRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
        String recv=Socket->ReceiveText();
        char *receiveChar = recv.c_str();

//------------------------------------------------------------------------------

        if(receiveChar[0]=='@')
        {
                (Joc->srv_scor)++;
                return;
        }

//------------------------------------------------------------------------------

        else if(recv=="clear")
        {
                Panza->Picture=Joc->PanzaAlba;
        }

//------------------------------------------------------------------------------

        else if(receiveChar[0]=='C')
        {
                int aux;
                String cuvant;

                for(int i=1;i<recv.Length();i++)
                {
                        if(receiveChar[i]!='#')
                        {
                                cuvant+=receiveChar[i];
                        }
                        if(receiveChar[i]=='#')
                        {
                                aux=StrToInt(receiveChar[i+1]);
                                break;
                        }
                }

                Interfata->Cuvant->Caption=cuvant;
                Joc->turn=aux;
                Joc->Play();
        }

//------------------------------------------------------------------------------

        else if(receiveChar[0]=='L')
        {
                //Prelucrare string pentru Marimea Liniei

                String strMarime="";
                int j=1;
                while(receiveChar[j]!='#')
                {
                        strMarime+=receiveChar[j];
                        j++;
                }
                int intMarime = StrToInt(strMarime);
                Interfata->Marime->Position=intMarime;
                Interfata->Panza->Canvas->Pen->Width=intMarime;
                j++;

                //Prelucrare string pentru Culoarea Liniei

                String strColIndex="";
                while(receiveChar[j]!='#')
                {
                        strColIndex+=receiveChar[j];
                        j++;
                }
                int intColIndex= StrToInt(strColIndex);
                Interfata->Culori->ForegroundIndex=intColIndex;
                Interfata->Panza->Canvas->Pen->Color=Interfata->Culori->ForegroundColor;
                j++;

                //Prelucrare coordonate Linie

                int intx=0,inty=0;
                String auxLinie="";
                int i=j;
                while(i<recv.Length() && receiveChar[i]!=' ')
                {
                     if(i==j)
                     {
                        while(receiveChar[i]!=';')
                        {
                                auxLinie+=receiveChar[i];
                                i++;
                        }
                        i++;
                        intx=StrToInt(auxLinie);
                        auxLinie="";

                        while(receiveChar[i]!=';')
                        {
                                auxLinie+=receiveChar[i];
                                i++;
                        }
                        i++;
                        inty=StrToInt(auxLinie);
                        auxLinie="";

                        Interfata->Panza->Canvas->MoveTo(intx,inty);
                     }

                     if(receiveChar[i]==' ')
                     {
                        Interfata->Panza->Canvas->LineTo(intx,inty);
                        Interfata->Panza->Canvas->MoveTo(intx,inty);
                        return;
                     }

                     while(receiveChar[i]!=';' && receiveChar[i]!=' ')
                     {
                        auxLinie+=receiveChar[i];
                        i++;
                     }
                     i++;
                     intx=StrToInt(auxLinie);
                     auxLinie="";

                     while(receiveChar[i]!=';' && receiveChar[i]!=' ')
                     {
                        auxLinie+=receiveChar[i];
                        i++;
                     }
                     i++;
                     inty=StrToInt(auxLinie);
                     auxLinie="";

                     Interfata->Panza->Canvas->LineTo(intx,inty);
                     Interfata->Panza->Canvas->MoveTo(intx,inty);
                }

        }

//------------------------------------------------------------------------------

        else if(receiveChar[0]=='G')
        {
                //Prelucrare string pentru Marimea Gumei

                String strMarime="";
                int j=1;
                while(receiveChar[j]!='#')
                {
                        strMarime+=receiveChar[j];
                        j++;
                }
                int intMarime = StrToInt(strMarime);
                Interfata->Marime->Position=intMarime;
                Interfata->Panza->Canvas->Pen->Width=intMarime;
                j++;

                //Prelucrare string pentru Culoarea Gumei

                Interfata->Panza->Canvas->Pen->Color=clWhite;

                //Prelucrare coordonate Guma

                int intx=0,inty=0;
                String auxGuma="";
                int i=j;
                while(i<recv.Length() && receiveChar[i]!=' ')
                {
                     if(i==j)
                     {
                        //if(receiveChar[i]==' ') return;

                        while(receiveChar[i]!=';')
                        {
                                auxGuma+=receiveChar[i];
                                i++;
                        }
                        i++;
                        intx=StrToInt(auxGuma);
                        auxGuma="";

                        while(receiveChar[i]!=';')
                        {
                                auxGuma+=receiveChar[i];
                                i++;
                        }
                        i++;
                        inty=StrToInt(auxGuma);
                        auxGuma="";

                        Interfata->Panza->Canvas->MoveTo(intx,inty);
                     }

                     if(receiveChar[i]==' ')
                     {
                        Interfata->Panza->Canvas->LineTo(intx,inty);
                        Interfata->Panza->Canvas->MoveTo(intx,inty);
                        return;
                     }

                     while(receiveChar[i]!=';' && receiveChar[i]!=' ')
                     {
                        auxGuma+=receiveChar[i];
                        i++;
                     }
                     i++;
                     intx=StrToInt(auxGuma);
                     auxGuma="";

                     while(receiveChar[i]!=';' && receiveChar[i]!=' ')
                     {
                        auxGuma+=receiveChar[i];
                        i++;
                     }
                     i++;
                     inty=StrToInt(auxGuma);
                     auxGuma="";

                     Interfata->Panza->Canvas->LineTo(intx,inty);
                     Interfata->Panza->Canvas->MoveTo(intx,inty);
                }
        }
//------------------------------------------------------------------------------

        else if(receiveChar[0]=='F')
        {
                //Prelucrare string pentru Culoarea Galetusei

                int j=1;
                String strColIndex="";

                while(receiveChar[j]!='#')
                {
                        strColIndex+=receiveChar[j];
                        j++;
                }
                int intColIndex = StrToInt(strColIndex);
                Interfata->Culori->ForegroundIndex = intColIndex;
                Interfata->Panza->Canvas->Brush->Color = Interfata->Culori->ForegroundColor;
                j++;

                //Prelucrare coordonate Galetusa

                int intx=0,inty=0;
                String auxGaletusa="";
                int i=j;
                while(i<recv.Length() && receiveChar[i]!=' ')
                {
                        if(receiveChar[i]==' ') return;

                         while(receiveChar[i]!=';')
                        {
                                auxGaletusa+=receiveChar[i];
                                i++;
                        }
                        i++;
                        intx=StrToInt(auxGaletusa);
                        auxGaletusa="";

                        if(receiveChar[i]==' ') return;

                        while(receiveChar[i]!=';')
                        {
                                auxGaletusa+=receiveChar[i];
                                i++;
                        }
                        i++;
                        inty=StrToInt(auxGaletusa);
                        auxGaletusa="";
                }
                Joc->poz->setX(intx);
                Joc->poz->setY(inty);
                Joc->fig->Umplere();
        }

//------------------------------------------------------------------------------
        
        else if(receiveChar[0]=='O')
        {
                //Prelucrare string pentru Marimea Cercului

                String strMarime="";
                int j=1;
                while(receiveChar[j]!='#')
                {
                        strMarime+=receiveChar[j];
                        j++;
                }
                int intMarime = StrToInt(strMarime);
                Interfata->Marime->Position=intMarime;
                Interfata->Panza->Canvas->Pen->Width=intMarime;
                j++;

                //Prelucrare string pentru Culoarea Cercului

                String strColIndex="";
                while(receiveChar[j]!='#')
                {
                        strColIndex+=receiveChar[j];
                        j++;
                }
                int intColIndex= StrToInt(strColIndex);
                Interfata->Culori->ForegroundIndex=intColIndex;
                Interfata->Panza->Canvas->Pen->Color=Interfata->Culori->ForegroundColor;
                j++;

                //Prelucrare coordonate Cerc

                int intx=0,inty=0,intxaj=0,intyaj=0;
                String auxCerc="";
                int i=j;

                while(receiveChar[i]!=';')
                {
                        auxCerc+=receiveChar[i];
                        i++;
                }
                i++;
                intxaj=StrToInt(auxCerc);
                auxCerc="";

                while(receiveChar[i]!=';')
                {
                        auxCerc+=receiveChar[i];
                        i++;
                }
                i++;
                intyaj=StrToInt(auxCerc);
                auxCerc="";

                while(receiveChar[i]!=';')
                {
                        auxCerc+=receiveChar[i];
                        i++;
                }
                i++;
                intx=StrToInt(auxCerc);
                auxCerc="";

                while(receiveChar[i]!=';')
                {
                        auxCerc+=receiveChar[i];
                        i++;
                }
                i++;
                inty=StrToInt(auxCerc);
                auxCerc="";

                Interfata->Panza->Canvas->Arc(intxaj,intyaj,intx,inty,intx,inty,intx,inty);

        }

//------------------------------------------------------------------------------

        else if(receiveChar[0]=='D')
        {
                //Prelucrare string pentru Marimea Dreptunghiului

                String strMarime="";
                int j=1;
                while(receiveChar[j]!='#')
                {
                        strMarime+=receiveChar[j];
                        j++;
                }
                int intMarime = StrToInt(strMarime);
                Interfata->Marime->Position=intMarime;
                Interfata->Panza->Canvas->Pen->Width=intMarime;
                j++;

                //Prelucrare string pentru Culoarea Dreptunghiului

                String strColIndex="";
                while(receiveChar[j]!='#')
                {
                        strColIndex+=receiveChar[j];
                        j++;
                }
                int intColIndex= StrToInt(strColIndex);
                Interfata->Culori->ForegroundIndex=intColIndex;
                Interfata->Panza->Canvas->Pen->Color=Interfata->Culori->ForegroundColor;
                j++;

                //Prelucrare coordonate Dreptunghi

                int intx=0,inty=0,intxaj=0,intyaj=0;
                String auxDreptunghi="";
                int i=j;

                while(receiveChar[i]!=';')
                {
                        auxDreptunghi+=receiveChar[i];
                        i++;
                }
                i++;
                intxaj=StrToInt(auxDreptunghi);
                auxDreptunghi="";

                while(receiveChar[i]!=';')
                {
                        auxDreptunghi+=receiveChar[i];
                        i++;
                }
                i++;
                intyaj=StrToInt(auxDreptunghi);
                auxDreptunghi="";

                while(receiveChar[i]!=';')
                {
                        auxDreptunghi+=receiveChar[i];
                        i++;
                }
                i++;
                intx=StrToInt(auxDreptunghi);
                auxDreptunghi="";

                while(receiveChar[i]!=';')
                {
                        auxDreptunghi+=receiveChar[i];
                        i++;
                }
                i++;
                inty=StrToInt(auxDreptunghi);
                auxDreptunghi="";

                Interfata->Panza->Canvas->Brush->Style=bsClear;
                Interfata->Panza->Canvas->Rectangle(intxaj,intyaj,intx,inty);

        }

//---------------------------------------------------------------------------

        else if(receiveChar[0]=='R')
        {
                String RecvRaspuns="";
                for(int i=1;i<recv.Length();i++)
                {
                       RecvRaspuns+=receiveChar[i];
                }
                Interfata->Raspunsuri->Lines->Add("Oponent: " + RecvRaspuns);
        }
}
//---------------------------------------------------------------------------




void __fastcall TInterfata::HowToPlayClick(TObject *Sender)
{
        How2Play->Show();
}
//---------------------------------------------------------------------------


