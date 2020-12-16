void tombol(){
  static bool lastButtonState;
  static bool buttonState;
  static uint32_t lastDebounceTime;
  uint32_t tmr = millis();
  static bool reading;
  static bool rst;
  
  int sensorValue = analogRead(A0);
  if(sensorValue<200){
    reading = true;
  }else{
    reading = false;
  }

  if (!reading != lastButtonState) {
    lastDebounceTime = tmr;
  }
//  Serial.println(tmr - lastDebounceTime);
  if ((tmr - lastDebounceTime) > 50) {
    if (!reading != buttonState) {
      buttonState = !reading;
      if((tmr - lastDebounceTime)>100){
        return;
      }else{
        if (buttonState == LOW) {
          Disp.clear();
          if(tmputama!=2){
            
            tmputama = 2;
            waktuSholatNow();
            switch(SholatNow){
              case 1:
                menitiqmh = configjws.iqmhs;
                break;
              case 4:
                menitiqmh = configjws.iqmhd;
                break;
              case 5:
                menitiqmh = configjws.iqmha;
                break;
              case 6:
                menitiqmh = configjws.iqmhm;
                break;
              case 7:
                menitiqmh = configjws.iqmhi;
                break;
              default:
                menitiqmh = 0;
                break;        
            }

          }
          else{
            Iqomah(false);
            if(azzan){
              tmputama = 1;
            }else
            tmputama = 0;
          }
          
          Serial.println(millis() - lastDebounceTime);
        }
      }
      
    }
  }
  

  lastButtonState = !reading;
}

void tombolCap(){
  int sensorValue = analogRead(A0);
  static bool buttonState;
  static bool reading;
  static bool st;

  if(sensorValue<200){
    reading = false;
  }else{
    reading = true;
  }

//  if(v<500 and !st){
//    Serial.println("trg");
//    st =true;
//  }else if(v>500 and st){
//    st = false;
//  }

  if(buttonState != reading){
    buttonState = reading;
    if(buttonState==HIGH){
      Serial.println("trg");
      if(tmputama!=2){
        Disp.clear();
        tmputama = 2;
        menitiqmh = 0;
        switch(SholatNow){
          case 1:
            menitiqmh = configjws.iqmhs;
            break;
          case 4:
            menitiqmh = configjws.iqmhd;
            break;
          case 5:
            menitiqmh = configjws.iqmha;
            break;
          case 6:
            menitiqmh = configjws.iqmhm;
            break;
          case 7:
            menitiqmh = configjws.iqmhi;
            break;
          default:
            menitiqmh = 0;
            break;        
        }
      }
      else{
        Disp.clear();
        Iqomah(false);
        tmputama = 0;
      }
      
    }
  }
  
}
