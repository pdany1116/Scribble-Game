//---------------------------------------------------------------------------


#pragma hdrstop

#include "ClasaJoc.h"
#include "Source.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
 
GameScribble::GameScribble()
{
      InitButtons();
      InitComponents();
      PanzaAlba = new TPicture;
      PanzaAlba->LoadFromFile("ALB.bmp");

      poz=new Pozitie();
      fig=new Figuri();

      mousedown=false;
      turn=0;
      cl_scor = 0;
      srv_scor = 0;

      RandomCuvant();
      Play();
      Interfata->Timer1->Enabled=true;
}

void GameScribble::RandomCuvant()
{
        srand(time(NULL));
        int b = rand() % nr_cuvinte;
        String S;
        String sendCuvant="";
        string s;
        ifstream is("cuvinte.txt");

        for(int i=0;i<b;i++)
        {
               getline(is,s); //citesc in string ca nu merge sa citesc in AnsiString
        }

        turn++;
        S=s.c_str();
        Interfata->Cuvant->Caption=S;
        sendCuvant += 'C'; sendCuvant += S; sendCuvant += '#'; sendCuvant += IntToStr(turn);
        Interfata->srvSocket->Socket->Connections[0]->SendText(sendCuvant);
        sendCuvant="";
}

void GameScribble::Play()
{
        Interfata->Raspunsuri->Lines->Add("SCOR | Eu : " + IntToStr(srv_scor) +
                               " - " + IntToStr(cl_scor) + " : Oponent");

        if(turn==nr_runde)
        {
                ShowMessage("Sfarsit joc!");
                Interfata->Timer1->Enabled=false;
                Interfata->Cuvant->Visible=false;
                Interfata->Raspunsuri->Lines->Add("       SFARSIT JOC!");
                return;
        }

        Interfata->Raspunsuri->Lines->Add("                  JOCUL " + IntToStr(turn));

        if(turn%2==0)  //server deseneaza
        {
                Interfata->Raspunsuri->Lines->Add("Desenezi...");
                Interfata->Cuvant->Visible=true;
                ShowMessage("Este randul tau sa desenezi!");
                Interfata->Raspunsuri->Enabled=false;
                Interfata->Raspuns->Enabled=false;
                Interfata->Panza->Enabled=true;
                Interfata->Culori->Enabled=true;
                Interfata->Creion->Enabled=true;
                Interfata->Galetusa->Enabled=true;
                Interfata->Guma->Enabled=true;
                Interfata->Cerc->Enabled=true;
                Interfata->Dreptunghi->Enabled=true;
                Interfata->Clear->Enabled=true;
                Interfata->Marime->Enabled=true;
                Interfata->Panza->Picture=PanzaAlba;
        }
        else    //server ghiceste
        {
                Interfata->Raspunsuri->Lines->Add("Ghicesti...");
                Interfata->Cuvant->Visible=false;
                ShowMessage("Este randul tau sa ghicesti!");
                Interfata->Raspunsuri->Enabled=true;
                Interfata->Raspuns->Enabled=true;
                Interfata->Panza->Enabled=false;
                Interfata->Culori->Enabled=false;
                Interfata->Creion->Enabled=false;
                Interfata->Galetusa->Enabled=false;
                Interfata->Guma->Enabled=false;
                Interfata->Cerc->Enabled=false;
                Interfata->Dreptunghi->Enabled=false;
                Interfata->Clear->Enabled=false;
                Interfata->Marime->Enabled=false;
                Interfata->Panza->Picture=PanzaAlba;
        }
}

void GameScribble::InitButtons()
{
      Interfata->Creion->Visible=true;
      Interfata->Galetusa->Visible=true;
      Interfata->Guma->Visible=true;
      Interfata->Cerc->Visible=true;
      Interfata->Dreptunghi->Visible=true;
      Interfata->Clear->Visible=true;
      Interfata->HowToPlay->Visible=false;
}
void GameScribble::InitComponents()
{
      Interfata->Background->Visible=false;
      Interfata->Start->Visible=false;
      Interfata->Panza->Visible=true;
      Interfata->Culori->Visible=true;
      Interfata->Raspunsuri->Visible=true;
      Interfata->Raspuns->Visible=true;
      Interfata->Cuvant->Visible=true;
      Interfata->Marime->Visible=true;
}
