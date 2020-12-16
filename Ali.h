
bool kdp;
int8_t SholatNow = -1;
bool azzan = false;
int width = 64;
uint8_t dispj;

char namaWaktuSholat[][8] = {"IMSYAK", "SUBUH", "TERBIT", "DHUHA", "DZUHUR", "ASHAR", "MAGHRIB", "ISYA"};
void serialWithDelay(String msg, uint16_t dely);

void tombol();

void identitas(uint8_t& next) {
  static uint32_t lsRn;
  uint32_t tmr = millis();
  static uint8_t Kecepatan = 20;
  static uint32_t x;
  Disp.drawRect(-1, 2, 65, 13);
  char msg[54];
  sprintf(msg, "Jam Waktu Sholat Teknik Elektro Universitas Pertamina");
  

  int width = Disp.width();
  Disp.setFont(Font6x7);
  int fullScroll = Disp.textWidth(msg) + width;


  if (tmr - lsRn > Kecepatan) {

    lsRn = tmr;

    if (x < fullScroll) {

      ++x;

    } else {
      x = 0;
//      tmpjws = 0;
      next += 1;
      Disp.clear();

    }
    
    Disp.drawText(width - x, 4, msg);

  }

}


void dispTanggal(uint8_t type, uint8_t& next) { //0 masehi 1 hijriah

  static uint32_t pM;
  uint32_t cM = millis();
  static uint8_t Kecepatan = 35;
  static uint32_t x;

  char msg[20];
  if (type == 0) {
    sprintf(msg, "%s, %d %s %i", namaHari[rHar], rTgl, namaBulan[rBul], rTah);
  }
  else if (type == 1) {
    sprintf(msg, "%d %s %i", Hjr_Date, bulanHijriah[Hjr_Month], Hjr_Year);
  }

  //  int width = Disp.width();
  Disp.setFont(kecil3x6);
  int fullScroll = Disp.textWidth(msg) + width;



  if (cM - pM > Kecepatan) {

    pM = cM;

    if (x < fullScroll) {

      ++x;

    } else {

      x = 0;
      Disp.clear();
//      tmpjws = 0;
      next += 1;

    }

    Disp.drawText(width - x, 9, msg);

  }

}


void dispInfo(uint8_t& next) { //0 masehi 1 hijriah

  static uint32_t pM;
  uint32_t cM = millis();
  static uint8_t Kecepatan = 35;
  static uint32_t x;
  static bool type;

  char msg[60];
  if (type == 0) {
    sprintf(msg, "%s", configjws.namamasjid);
  }
  else if (type == 1) {
    sprintf(msg, "%s", configjws.informasi);
  }

  //  int width = Disp.width();
  Disp.setFont(kecil3x6);
  int fullScroll = Disp.textWidth(msg) + width;



  if (cM - pM > Kecepatan) {

    pM = cM;

    if (x < fullScroll) {

      ++x;

    } else {

      x = 0;
      Disp.clear();
      type= !type;
//      tmpjws = 0;
      next += 1;

    }

    Disp.drawText(width - x, 9, msg);

  }

}

void jamNormal(int x) {
  char jam[3];
  char menit[3];
  char detik[3];
  char buff[8];
  if (kdp) {
    sprintf(buff, "%02d;%02d;%02d", rJam, rMen, rDet);
  }
  else {
    sprintf(buff, "%02d|%02d|%02d", rJam, rMen, rDet);
  }

  Disp.setFont(Font6x7);
  Disp.drawText(x + 9, 1, buff);

}

void runAzzan(uint8_t& next, bool rst) {
  static uint32_t lsRn;
  static uint32_t lsRnd;
  static uint16_t det;
  uint32_t tmr = millis();
  BunyiBeep(2, 8);
  if(rst){
    det = 0;
  }


  if (tmr - lsRn >= 1000) {
    det++;
    lsRn = tmr;
    lsRnd = tmr;
  }
  if (det < 10) {
    if (kdp) {
      Disp.drawRect(1, 2, 62, 13);
      Disp.setFont(Font6x7);
      Disp.drawText(14, 1, "ADZAN");
      char Msg[8];
      sprintf(Msg, "%s", namaWaktuSholat[SholatNow]);
      int center = int((Disp.width() - Disp.textWidth(Msg)) / 2);
      Disp.drawText(center, 9, Msg);
      digitalWrite(2, kdp);
    } else
      Disp.clear();
      digitalWrite(2, kdp);
  }
  else if (det == 10){
    Disp.clear();
    det++;
    digitalWrite(2, LOW);
  }
  else if (det > 10) {
//    Disp.drawRect(1, 2, 62, 13);
    digitalWrite(2, LOW);
    jamNormal(0);
    Disp.setFont(kecil3x6);
    char Msg[15];
    if (!kdp) {
      sprintf(Msg, "ADZAN %s", namaWaktuSholat[SholatNow]);
    } else {
      sprintf(Msg, "               ");
    }

    int center = int((Disp.width() - Disp.textWidth(Msg)) / 2);
    Disp.drawText(center, 9, Msg);
    //      String sholat = namaWaktuSholat[SholatNow];
    //      digitalWrite(2, HIGH);
    //      Serial.println("tampil azzan "+ sholat+" Selesai");

  }
  if(floatnow>(stimeFloat[SholatNow] + (float)configjws.durasiadzan/60)){
    Disp.clear();
    azzan = false;
    det = 0;
    next--;
  }

}

void check_azzan()
{ 
  for (int i = 0; i <= 7; i++)
  {
    if (i != 0 and i != 2 and i != 3) // bukan terbit dan bukan dhuha
    {
      if (floatnow >= stimeFloat[i])
      {
        if (!azzan and (floatnow > stimeFloat[i]) and (floatnow < (stimeFloat[i] + 0.03)))
        {
          //                    if(daynow ==6 and SholatNow ==4 and Prm.MT==1) {jumat=true;}
          Disp.clear();
          SholatNow = i;
          if(i==6){
            TanggalHijriah();
          }
          
          azzan = true;
          tmputama = 1;
          runAzzan(tmputama, true);
          String sholat = namaWaktuSholat[i];
          digitalWrite(2, LOW);
          Serial.println("waktu sholat " + sholat);
        }

      }
    }
  }
}

void kedip() {
  static uint32_t   timerSave, lastSecond;
  uint32_t          nowmilis = millis();
  if (lastSecond != rDet) {
    lastSecond = rDet;
    kdp = true;
    timerSave = nowmilis;
  }
  //  Serial.println(kdp);
  //  Serial.print("----");
  if ((nowmilis - timerSave) > 500) {
    //    Serial.println("ganti");
    kdp = false;
  }
}




void dispJadwal(uint8_t& next) {

  static uint8_t    y;
  static uint8_t    s; // 0=in, 1=out
  static uint32_t   lsRn;
  static uint8_t    sNum;
  uint32_t          Tmr = millis();
  if (sNum == 0 and !configjws.dispimsyak) sNum = 1;
  if (sNum == 2) sNum = 3;
  if (sNum == 3 and !configjws.dispdhuha) sNum = 4;

  if ((Tmr - lsRn) > 30)
  {
    if (s == 0 and y < 8) {
      lsRn = Tmr;
      y++;
    }
    if (s == 1 and y > 0) {
      lsRn = Tmr;
      y--;
    }
  }
  if ((Tmr - lsRn) > 2000 and y == 8) {
    s = 1;
    //    Serial.println(stimeInt[1][0]);

  }
  if (y == 0 and s == 1) {
    s = 0;
    if (sNum < 7) {
      sNum++;
    } else {
      sNum = 0;
      next = next + 1;
    }


  }
  Disp.setFont(ElektronMart5x6);
  char buffJ[10];
  sprintf(buffJ, "%02s %02i:%02i", namaWaktuSholat[sNum], stimeInt[sNum][0], stimeInt[sNum][1]);
  int   tw = Disp.textWidth((String)buffJ);
  int   c = int((64 - tw) / 2);
  Disp.drawText(c, 16 - y, buffJ);

}




void waktuSholatNow() {
  for (int i = 7; i >= 7; i--) {
    if (floatnow > waktuSholat(i)) {
      SholatNow = i;
      break;
    }
  }
  Serial.printf("waktu sekarang adalah %d", SholatNow);
  Serial.println();

}
