#include <windows.h>
#include <stdio.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {

  int dolnyZakres = 1;
  int gornyZakres = 40;
  int liczba;
  bool znaleziono = false;
  int id;
  char tab[50];
  
  MessageBox(0, "Wybierz liczbe z zakresu 1-40. Wcisnij OK aby rozpoczac gre", "Aplikacja", MB_OK);

  while (!znaleziono) {

    liczba = (dolnyZakres + gornyZakres) / 2;
    sprintf_s(tab,"Czy twoja liczba jest wieksza od %d ?",liczba);
    id = MessageBox(0,tab,"Aplikacja",MB_YESNO | MB_ICONQUESTION);
   
    if (id == IDYES) {
      dolnyZakres = liczba;
     }

    else
      gornyZakres = liczba;

    if ((dolnyZakres + 1) == gornyZakres) {
      if (id == IDYES) {
        liczba = liczba + 1;
        sprintf_s(tab, "Jezeli nie oszukiwales to twoja liczba to: %d", liczba);
        MessageBox(0, tab, "Aplikacja", MB_OK);
        znaleziono = true;
      }

      else {
        sprintf_s(tab, "Czy twoja liczba jest wieksza od %d ?", dolnyZakres);
        id = MessageBox(0, tab, "Aplikacja", MB_YESNO | MB_ICONQUESTION);
        if (id == IDYES) {
          liczba = gornyZakres;
          sprintf_s(tab, "Jezeli nie oszukiwales to twoja liczba to: %d", liczba);
          MessageBox(0, tab, "Aplikacja", MB_OK);
          znaleziono = true;
        }
        else {
          liczba = dolnyZakres;
          sprintf_s(tab, "Jezeli nie oszukiwales to twoja liczba to: %d", liczba);
          MessageBox(0, tab, "Aplikacja", MB_OK);
          znaleziono = true;
        }
      }
    }

  }

  return 0;
}