
void textCenter(int y,String Msg) {
  
  int center = int((Disp.width()-Disp.textWidth(Msg)) / 2);
  Disp.drawText(center,y,Msg);
  
}
//----------------------------------------------------------------------
// HITUNG MUNDUR WAKTU SETELAH ADZAN SAMPAI MULAI IQOMAH

void Iqomah(bool rst) {
  if(!rst){
    detikbeep = 0;
    detikiqmh = 59;
    return;
  }
  
  static uint32_t pM;
  uint32_t cM = millis();
  static char hitungmundur[6];  
  tombol();

  Disp.setFont(ElektronMart5x6);
  textCenter(0, "IQOMAH");

  if (detikiqmh == 60) {
    detikiqmh = 0;
  }

  if (cM - pM >= 1000) {
    pM = cM;
    detikiqmh--;

    if (menitiqmh == 0 && detikiqmh == 0) {
      Disp.clear();
      detikbeep = 0;
      detikiqmh = 59;
      tmputama = 3;
      azzan = false;
    }

    if (detikiqmh < 0) {
      detikiqmh = 59;
      menitiqmh--;
    }
    
  }

  sprintf(hitungmundur, "%02d:%02d", menitiqmh, detikiqmh);
  Disp.setFont(ElektronMart6x8);
  textCenter(8, hitungmundur);
  
}



//----------------------------------------------------------------------
// TAMPILAN SAAT SHOLAT

void TampilSaatSholat() {

  BunyiBeep(1,4);

  static uint32_t pM;
  uint32_t cM = millis();
  static uint32_t durasi = 10; // Detik
  static uint32_t det;

  Disp.setFont(ElektronMart5x6);
  textCenter(0, "LURUSKAN DAN");
  textCenter(8, "RAPATKAN SHAF");

  if (cM - pM >= 1000) {
    pM = cM;
    det++;

    if (durasi == det) {
      Disp.clear();
      detikbeep = 0;
      det = 0;
      tmputama = 0;
    }
  }  
  
}
