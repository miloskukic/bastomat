
#include <Nextion.h>
#include <DS3231.h>
#include <EEPROM.h>
#include "DHT.h"
#include "timer.h"
#include "EEPROMAnything.h"

Timer timer;
Timer timer2;
Timer timer3;


NexText tempTxt = NexText(0, 7, "t3");
NexText humTxt = NexText(0, 5, "t1");
NexText timeTxt = NexText(0, 1, "t0");

NexText b0 = NexText(0, 11, "b0");

// STRANICA TEMPERATURA

NexButton b403 = NexButton(4, 5, "b403");
NexButton b404 = NexButton(4, 6, "b404");
NexButton b405 = NexButton(4, 7, "b405");
NexButton b406 = NexButton(4, 3, "b406");
NexButton b408 = NexButton(4, 4, "b408");
NexNumber tmpNum = NexNumber(4, 8, "n407");

// STRANICA VLAZNOST VAZDUHA

NexButton b606 = NexButton(6, 4, "b606");
NexButton b607 = NexButton(6, 3, "b607");
NexButton b608 = NexButton(6, 1, "b608");
NexButton b604 = NexButton(6, 5, "b604");
NexButton b605 = NexButton(6, 2, "b605");
NexNumber huNum = NexNumber(4, 8, "n602");

// STRANICA VLAZNOST ZEMLJISTA

NexButton b506 = NexButton(5, 4, "b506");
NexButton b507 = NexButton(5, 3, "b507");
NexButton b508 = NexButton(5, 1, "b508");
NexButton b504 = NexButton(5, 5, "b504");
NexButton b505 = NexButton(5, 2, "b505");
NexNumber huZNum = NexNumber(5, 8, "n502");

// ZIMSKI REZIM

NexButton b807 = NexButton(8, 4, "b807");
NexButton b808 = NexButton(8, 3, "b808");
NexButton b809 = NexButton(8, 1, "b809");
NexButton b804 = NexButton(8, 5, "b804");
NexButton b806 = NexButton(8, 2, "b806");
NexDSButton b802 = NexDSButton(8, 8, "b802");
NexNumber zimNum = NexNumber(8, 9, "n807");
NexButton b106 = NexButton(1, 6, "b106");

// TAJMER

NexButton b909 = NexButton(9, 5, "b909");
NexButton b910 = NexButton(9, 6, "b910");
NexButton b911 = NexButton(9, 7, "b911");
NexButton b903 = NexButton(9, 3, "b902");
NexButton b907 = NexButton(9, 4, "b907");
NexButton b904 = NexButton(9, 8, "b904");
NexButton b908 = NexButton(9, 9, "b908");
NexNumber satNum = NexNumber(9, 11, "n905");
NexNumber minNum = NexNumber(9, 12, "n906");

//MOD RADA

NexButton b302 = NexButton(3, 3, "b302");
NexButton b303 = NexButton(3, 2, "b303");
NexDSButton b304 = NexDSButton(3, 6, "b304");
NexButton b305 = NexButton(3, 1, "b305");
NexButton b109 = NexButton(1, 10, "b109");

//PRIHRANA

NexButton b1004 = NexButton(10, 3, "b1004");
NexButton b1005 = NexButton(10, 4, "b1005");
NexDSButton b1006 = NexDSButton(10, 5, "b1006");
NexButton b1007 = NexButton(10, 6, "b1007");
NexNumber pNum = NexNumber(10, 7, "n1003");
NexButton b108 = NexButton(1, 8, "b108");

//PODESAVANJE VREMENA

NexButton b1602 = NexButton(16, 3, "b1602");
NexButton b1603 = NexButton(16, 7, "b1603");
NexButton b1604 = NexButton(16, 9, "b1604");
NexButton b1605 = NexButton(16, 2, "b1605");
NexButton b1606 = NexButton(16, 6, "b1606");
NexButton b1607 = NexButton(16, 8, "b1607");
NexButton b1608 = NexButton(16, 1, "b1608");
NexNumber vNum1 = NexNumber(16, 12, "n1610");
NexNumber vNum2 = NexNumber(16, 13, "n1612");
NexNumber vNum3 = NexNumber(16, 14, "n1614");

//TASTERI ZA UKLJUCIVANJE

NexDSButton bt201 = NexDSButton(2, 7, "bt201");
NexDSButton bt202 = NexDSButton(2, 8, "bt202");
NexButton b110 = NexButton(1, 11, "b110");

//VENTILATOR

NexButton b706 = NexButton(7, 4, "b706");
NexButton b707 = NexButton(7, 3, "b707");
NexButton b708 = NexButton(7, 1, "b708");
NexButton b704 = NexButton(7, 5, "b704");
NexButton b705 = NexButton(7, 2, "b705");
NexDSButton bt709 = NexDSButton(7, 8, "bt709");
NexNumber n702 = NexNumber(7, 9, "n702");
NexButton b107 = NexButton(1, 7, "b107");

//KALIBRACIJA

NexButton b409 = NexButton(4, 9, "b409");
NexButton b509 = NexButton(5, 9, "b509");
NexButton b609 = NexButton(6, 9, "b609");

// SLIKE

NexPicture  p3 = NexPicture (0, 12, "p3");
NexPicture  p4 = NexPicture (0, 13, "p4");
NexPicture  p5 = NexPicture (0, 14, "p5");
NexPicture  p6 = NexPicture (0, 15, "p6");
NexPicture  p10 = NexPicture (0, 19, "p10");
NexPicture  p8 = NexPicture (0, 17, "p8");
NexPicture  p7 = NexPicture (0, 16, "p7");
NexPicture  p9 = NexPicture (0, 18, "p9");
NexPicture  p11 = NexPicture (0, 20, "p11");

//PODESAVANJE EKRANA

NexButton b1707 = NexButton(17, 3, "b1707");
NexButton b1708 = NexButton(17, 4, "b1708");
NexButton b1709 = NexButton(17, 7, "b1709");
NexButton b1704 = NexButton(17, 8, "b1704");
NexButton b1705 = NexButton(17, 9, "b1705");
NexDSButton bt1701 = NexDSButton(17, 5, "bt1701");
NexDSButton bt1702 = NexDSButton(17, 6, "bt1702");
NexNumber n1703 = NexNumber(17, 10, "n1703");
NexNumber b208 = NexNumber(2, 10, "b208");

#define DHTPIN 2
#define DHTTYPE DHT22


DHT dht(DHTPIN, DHTTYPE);
DS3231  rtc(SDA, SCL);


int i = 0;
int i2 = 0;
int i3 = 0;
int mod = 0;
boolean zimski;
boolean prihrana;
boolean ventilTest = false;
boolean pistalica;
boolean proximity;
boolean ventilator;
boolean offTime;
int brightness;
int screenTime=EEPROM.read(150);
int pocetnoVremeS=EEPROM.read(119);
int pocetnoVremeM = EEPROM.read(120);
int ZavrsnoVremeS = EEPROM.read(121);
int ZavrsnoVremeM = EEPROM.read(122);
int modRada = EEPROM.read(123);

void ucitajVrednosti() {
  modRada = EEPROM.read(123);
  zimski = EEPROM.read(118);
  prihrana = EEPROM.read(124);
  ventilTest = false;
  pistalica = EEPROM.read(128);
  proximity = EEPROM.read(129);
  ventilator = EEPROM.read(132);
  offTime = EEPROM.read(152);
  brightness = EEPROM.read(151);
  pocetnoVremeS = EEPROM.read(119);
  pocetnoVremeM = EEPROM.read(120);
  ZavrsnoVremeS = EEPROM.read(121);
  ZavrsnoVremeM = EEPROM.read(122);
}



NexTouch *nex_listen_list[] = {
  &b404,
  &b403,
  &b405,
  &b406,
  &b408,
  &b606,
  &b607,
  &b608,
  &b604,
  &b605,
  &b505,
  &b506,
  &b507,
  &b508,
  &b504,
  &b505,
  &b807,
  &b808,
  &b809,
  &b804,
  &b806,
  &b802,
  &b106,
  &b909,
  &b910,
  &b911,
  &b903,
  &b907,
  &b904,
  &b908,
  &b302,
  &b303,
  &b304,
  &b305,
  &b109,
  &b1004,
  &b1005,
  &b1006,
  &b1007,
  &b108,
  &b1602,
  &b1603,
  &b1604,
  &b1605,
  &b1606,
  &b1607,
  &b1608,
  &bt201,
  &bt202,
  &bt1701,
  &b110,
  &b706,
  &b707,
  &b708,
  &b704,
  &b705,
  &bt709,
  &b107,
  &b409,
  &b509,
  &b609,
  &b1707,
  &b1708,
  &b1709,
  &b1704,
  &b1705,
  &bt1701,
  &bt1702,
  &n1703,
  &b208,
  &b0,
  NULL
};

/* PODESAVANJE EKRANA KRAJ*/

/***************************
          [FUNKCIJE ]
****************************/

void vremenskoNavodnjavanje() {
  String pocetno_vreme,zavrsno_vreme;
  String trenutno_vreme = rtc.getTimeStr(FORMAT_SHORT);
  if (pocetnoVremeS > 9) {
    pocetno_vreme = String(pocetnoVremeS) + ":" + String(pocetnoVremeM);
    if (pocetnoVremeM < 10) {
      pocetno_vreme = "";
      pocetno_vreme = String(pocetnoVremeS) + ":" + "0" + String(pocetnoVremeM);
    }
  }
  else {
    pocetno_vreme = "0" + String(pocetnoVremeS) + ":" + String(pocetnoVremeM);
    if (pocetnoVremeM < 10) {
      pocetno_vreme = "0" + String(pocetnoVremeS) + ":" + "0" + String(pocetnoVremeM);
    }
  }

  if (ZavrsnoVremeS > 9) {
    zavrsno_vreme = String(ZavrsnoVremeS) + ":" + String(ZavrsnoVremeM);
    if (ZavrsnoVremeM < 10) {
      zavrsno_vreme = String(ZavrsnoVremeS) + ":" + "0" + String(ZavrsnoVremeM);
    }
  }
  else {
    zavrsno_vreme = "0" + String(ZavrsnoVremeS) + ":" + String(ZavrsnoVremeM);
    if (ZavrsnoVremeM < 10) {
    zavrsno_vreme = "0" + String(ZavrsnoVremeS) + ":" + "0" + String(ZavrsnoVremeM);
    }
  }

  if (trenutno_vreme.equals(pocetno_vreme)) {
    digitalWrite(10, LOW);
  }
  if (trenutno_vreme.equals(zavrsno_vreme)) {
    digitalWrite(10, HIGH);
  }
}



void pokretanjePrograma() {
  digitalWrite(10,HIGH);
  switch (modRada) {
    case 0: break;
    case 1: break;
    case 2: vremenskoNavodnjavanje();break;
    case 3: break;
    default: break;
  }
}

/* VREMENSKE (TIMER) FUNKCIJE */

void helloCallback() {
  trenutneVrednosti();
  pokretanjePrograma();
  timeTxt.setText(rtc.getTimeStr(FORMAT_SHORT));
}

void helloCallback2() {
  sendCommand("sleep=1");
  timer3.start();
}

void getProximityStatus() {
  int val = analogRead(A8);
  if (val > 250) {
    sendCommand("sleep=0");
    timer3.stop();
  }

}

/* VREMENSKE FUNKCIJE KRAJ*/

/* STRANICA TEMPERATURA */

void b404PopCallback(void *ptr) {
  int tmp;
  tmp = EEPROM.read(111);
  tmpNum.setValue(tmp);
  i = tmp;
  mod = 1;
}

void b403PopCallback(void *ptr) {
  int tmp;
  tmp = EEPROM.read(110);
  tmpNum.setValue(tmp);
  i = tmp;
  mod = 0;
}


void b409PopCallback (void *ptr) {
  int tmp;
  EEPROM_readAnything(154, tmp);
  Serial.print("n407.val=");
  Serial.print(tmp);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  i = tmp;
  mod = 4;
}


void b405PopCallback(void *ptr) {
  if (mod == 0) {
    EEPROM.write(110, i);
  }
  if (mod == 1) {
    EEPROM.write(111, i);
  }
  if (mod == 4) {
    EEPROM_writeAnything(154, i);
  }
  mod = 3;

}

void b406PopCallback(void *ptr) {

  if (mod == 4) {
    i++;
    Serial.print("n407.val=");
    Serial.print(i);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
  }
  else {
    if (i < 50)
    {
      i++;
      tmpNum.setValue(i);
    } else
    {
      i = 0;
      tmpNum.setValue(i);
    }
  }
}

void b408PopCallback(void *ptr) {
  if (mod == 4) {
    i--;
    Serial.print("n407.val=");
    Serial.print(i);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
  }
  else {
    if (i > 0)
    {
      i--;
      tmpNum.setValue(i);
    } else
    {
      i = 0;
      tmpNum.setValue(i);
    }
  }
}

/* STRANICA TEMPERATURA KRAJ */

/* STRANICA VLAZNOST VAZDUHA */

void b606PopCallback(void *ptr) {
  int tmp;
  tmp = EEPROM.read(113);
  huNum.setValue(tmp);
  i = tmp;
  mod = 1;
}

void b607PopCallback(void *ptr) {
  int tmp;
  tmp = EEPROM.read(112);
  huNum.setValue(tmp);
  i = tmp;
  mod = 0;
}

void b609PopCallback (void *ptr) {
  int tmp;
  EEPROM_readAnything(134, tmp);
  Serial.print("n602.val=");
  Serial.print(tmp);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  i = tmp;
  mod = 4;
}

void b608PopCallback(void *ptr) {
  if (mod == 0) {
    EEPROM.write(112, i);
  }
  if (mod == 1) {
    EEPROM.write(113, i);
  }
  if (mod == 4) {
    EEPROM_writeAnything(134, i);
  }
  mod = 3;

}

void b604PopCallback(void *ptr) {
  if (mod == 4) {
    i++;
    Serial.print("n602.val=");
    Serial.print(i);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
  }
  else {
    if (i < 100)
    {
      i++;
      huNum.setValue(i);
    } else
    {
      i = 0;
      huNum.setValue(i);
    }
  }
}

void b605PopCallback(void *ptr) {
  if (mod == 4) {
    i--;
    Serial.print("n602.val=");
    Serial.print(i);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
  }
  else {
    if (i > 0)
    {
      i--;
      huNum.setValue(i);
    } else
    {
      i = 0;
      huNum.setValue(i);
    }
  }
}

/* STRANICA VLAZNOST VAZDUHA  KRAJ*/

/* STRANICA VLAZNOST ZEMLJISTA */

void b506PopCallback(void *ptr) {
  int tmp;
  tmp = EEPROM.read(115);
  huZNum.setValue(tmp);
  i = tmp;
  mod = 1;
}

void b507PopCallback(void *ptr) {
  int tmp;
  tmp = EEPROM.read(114);
  huZNum.setValue(tmp);
  i = tmp;
  mod = 0;
}


void b509PopCallback (void *ptr) {
  int tmp;
  EEPROM_readAnything(144, tmp);
  Serial.print("n502.val=");
  Serial.print(tmp);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  i = tmp;
  mod = 4;
}

void b508PopCallback(void *ptr) {
  if (mod == 0) {
    EEPROM.write(114, i);
  }
  if (mod == 1) {
    EEPROM.write(115, i);
  }
  if (mod == 4) {
    EEPROM_writeAnything(144, i);
  }
  mod = 3;

}

void b504PopCallback(void *ptr) {
  if (mod = 4) {
    i++;
    Serial.print("n502.val=");
    Serial.print(i);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
  }
  else {
    if (i < 100)
    {
      i++;
      huZNum.setValue(i);
    } else
    {
      i = 0;
      huZNum.setValue(i);
    }
  }

}

void b505PopCallback(void *ptr) {
  if (mod = 4) {
    i--;
    Serial.print("n502.val=");
    Serial.print(i);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
  }
  else {
    if (i > 0)
    {
      i--;
      huZNum.setValue(i);
    } else
    {
      i = 0;
      huZNum.setValue(i);
    }
  }

}

/* STRANICA VLAZNOST ZEMLJISTA KRAJ*/


/* STRANICA ZIMSKI REZIM */

void b808PopCallback(void *ptr) {
  int tmp;
  tmp = EEPROM.read(117);
  zimNum.setValue(tmp);
  i = tmp;
  mod = 1;
}

void b807PopCallback(void *ptr) {
  int tmp;
  tmp = EEPROM.read(116);
  zimNum.setValue(tmp);
  i = tmp;
  mod = 0;
}

void b809PopCallback(void *ptr) {
  if (mod == 0) {
    EEPROM.write(116, i);
  }
  if (mod == 1) {
    EEPROM.write(117, i);
  }
  mod = 3;

}

void b804PopCallback(void *ptr) {
  if (i < 50)
  {
    i++;
    zimNum.setValue(i);
  } else
  {
    i = 0;
    zimNum.setValue(i);
  }
}

void b806PopCallback(void *ptr) {
  if (i > 0)
  {
    i--;
    zimNum.setValue(i);
  } else
  {
    i = 0;
    zimNum.setValue(i);
  }

}

void b802PopCallback(void *ptr) {
  /*int state = EEPROM.read(118);
    uint32_t tmp = 0;
    b802.getValue(&tmp);
    EEPROM.write(118,tmp);*/
  if (zimski == 0) {
    zimski = true;
    EEPROM.write(118, 1);
    digitalWrite(13, HIGH);
  }
  else {
    zimski = false;
    EEPROM.write(118, 0);
    digitalWrite(13, LOW);
  }

}

void b106PopCallback(void *ptr) {
  int state;
  state = EEPROM.read(118);
  b802.setValue(state);
}

/* STRANICA ZIMSKI REZIM KRAJ */


/* STRANICA TAJMER */

void b909PopCallback(void *ptr) {
  int tmp, tmp2;
  tmp = EEPROM.read(119);
  tmp2 = EEPROM.read(120);
  satNum.setValue(tmp);
  minNum.setValue(tmp2);
  i = tmp;
  i2 = tmp2;
  mod = 1;
}

void b910PopCallback(void *ptr) {
  int tmp, tmp2;
  tmp = EEPROM.read(121);
  tmp2 = EEPROM.read(122);
  satNum.setValue(tmp);
  minNum.setValue(tmp2);
  i = tmp;
  i2 = tmp2;
  mod = 0;
}

void b911PopCallback(void *ptr) {
  if (mod == 0) {
    EEPROM.write(121, i);
    EEPROM.write(122, i2);
  }
  if (mod == 1) {
    EEPROM.write(119, i);
    EEPROM.write(120, i2);
  }
  mod = 3;

}

void b903PopCallback(void *ptr) {
  if (i < 23)
  {
    i++;
    satNum.setValue(i);
  } else
  {
    i = 0;
    satNum.setValue(i);
  }
}

void b907PopCallback(void *ptr) {
  if (i > 0)
  {
    i--;
    satNum.setValue(i);
  } else
  {
    i = 0;
    satNum.setValue(i);
  }

}

void b904PopCallback(void *ptr) {
  if (i2 < 59)
  {
    i2++;
    minNum.setValue(i2);
  } else
  {
    i2 = 0;
    minNum.setValue(i2);
  }
}

void b908PopCallback(void *ptr) {
  if (i2 > 0)
  {
    i2--;
    minNum.setValue(i2);
  } else
  {
    i2 = 0;
    minNum.setValue(i2);
  }

}


/* STRANICA TAJMER KRAJ */

void hideStatus() {

  switch (modRada) {
    case 0:
      p3.setVisible(0);
      p4.setVisible(0);
      p5.setVisible(0);
      break;
    case 1:
      p3.setVisible(0);
      p5.setVisible(0);
      p6.setVisible(0);
      break;
    case 2:
      p4.setVisible(0);
      p5.setVisible(0);
      p6.setVisible(0);
      break;
    case 3:
      p3.setVisible(0);
      p4.setVisible(0);
      p6.setVisible(0);
      break;
    default:
      p3.setVisible(0);
      p4.setVisible(0);
      p5.setVisible(0);
      p6.setVisible(0);
      break;
  }
  p10.setVisible(0);
  p8.setVisible(0);
  p7.setVisible(0);
  p9.setVisible(0);
  p11.setVisible(0);
}

/* STRANICA MOD RADA */

void b302PopCallback(void *ptr) {
  modRada = 1;
  EEPROM.write(123, 1);
}

void b303PopCallback(void *ptr) {
  modRada = 2;
  EEPROM.write(123, 2);
}

void b304PopCallback(void *ptr) {
  modRada = 3;
  EEPROM.write(123, 3);
}

void b305PopCallback(void *ptr) {
  modRada = 0;
  EEPROM.write(123, 0);
}

void b109PopCallback(void *ptr) {
  ucitajVrednosti();
  pokretanjePrograma();
  modRada = EEPROM.read(123);
  hideStatus();
  trenutneVrednosti();
  timeTxt.setText(rtc.getTimeStr(FORMAT_SHORT));
  if (offTime == true) {
    timer2.start();
  }
}

/* STRANICA MOD RADA KRAJ */



/* STRANICA PRIHRANA */


void b1007PopCallback(void *ptr) {
  EEPROM.write(124, i);
}

void b1004PopCallback(void *ptr) {
  if (i < 90)
  {
    i++;
    pNum.setValue(i);
  } else
  {
    i = 0;
    pNum.setValue(i);
  }
}

void b1005PopCallback(void *ptr) {
  if (i > 0)
  {
    i--;
    pNum.setValue(i);
  } else
  {
    i = 0;
    pNum.setValue(i);
  }

}

void b1006PopCallback(void *ptr) {
  /*int state = EEPROM.read(118);
    uint32_t tmp = 0;
    b802.getValue(&tmp);
    EEPROM.write(118,tmp);*/
  if (prihrana == 0) {
    prihrana = true;
    EEPROM.write(224, 1);
    digitalWrite(13, HIGH);
  }
  else {
    prihrana = false;
    EEPROM.write(224, 0);
    digitalWrite(13, LOW);
  }

}

void b108PopCallback(void *ptr) {
  int state;
  state = EEPROM.read(224);
  b1006.setValue(state);
  int tmp = EEPROM.read(124);
  pNum.setValue(tmp);
}

/* STRANICA PRIHRANA KRAJ */


/* STRANICA PODESAVANJE VREMENA */

void b1602PopCallback(void *ptr) {
  if (i < 23)
  {
    i++;
    vNum1.setValue(i);
  } else
  {
    i = 0;
    vNum1.setValue(i);
  }
}

void b1603PopCallback(void *ptr) {
  if (i2 < 59)
  {
    i2++;
    vNum2.setValue(i2);
  } else
  {
    i2 = 0;
    vNum2.setValue(i2);
  }
}

void b1604PopCallback(void *ptr) {
  if (i3 < 59)
  {
    i3++;
    vNum3.setValue(i3);
  } else
  {
    i3 = 0;
    vNum3.setValue(i3);
  }
}

void b1605PopCallback(void *ptr) {
  if (i > 0)
  {
    i--;
    vNum1.setValue(i);
  } else
  {
    i = 0;
    vNum1.setValue(i);
  }
}

void b1606PopCallback(void *ptr) {
  if (i2 > 0)
  {
    i2--;
    vNum2.setValue(i2);
  } else
  {
    i2 = 0;
    vNum2.setValue(i2);
  }
}

void b1607PopCallback(void *ptr) {
  if (i3 > 0)
  {
    i3--;
    vNum3.setValue(i3);
  } else
  {
    i3 = 0;
    vNum3.setValue(i3);
  }
}

void b1608PopCallback(void *ptr) {
  EEPROM.write(125, i);
  EEPROM.write(126, i2);
  EEPROM.write(127, i3);
  rtc.setTime(i, i2, i3);
}


/* STRANICA PODESAVANJE VREMENA KRAJ */


/* STRANICA TASTERI ZA UKLJUCIVANJE */


void bt201PopCallback(void *ptr) {
  if (ventilTest == false) {
    ventilTest = true;
    digitalWrite(10, LOW);
  }
  else {
    ventilTest = false;
    digitalWrite(10, HIGH);
  }
}

void bt202PopCallback(void *ptr) {
  if (pistalica == false) {
    pistalica = true;
    EEPROM.write(128, 1);
  }
  else {
    pistalica = false;
    EEPROM.write(128, 0);
  }
}



void b110PopCallback(void *ptr) {
  bt201.setValue(ventilTest);
  bt202.setValue(pistalica);
}

/* STRANICA TASTERI ZA UKLJUCIVANJE KRAJ */

/* VENTILATOR */

void b706PopCallback(void *ptr) {
  int tmp;
  tmp = EEPROM.read(130);
  n702.setValue(tmp);
  i = tmp;
  mod = 0;
}

void b707PopCallback(void *ptr) {
  int tmp;
  tmp = EEPROM.read(131);
  n702.setValue(tmp);
  i = tmp;
  mod = 1;
}

void b708PopCallback(void *ptr) {
  if (mod == 0) {
    EEPROM.write(130, i);
  }
  if (mod == 1) {
    EEPROM.write(131, i);
  }
  mod = 3;
}

void b704PopCallback(void *ptr) {
  if (mod == 1) {
    if (i < 50)
    {
      i++;
      n702.setValue(i);
    } else
    {
      i = 0;
      n702.setValue(i);
    }
  }

  if (mod == 0) {
    if (i < 99)
    {
      i++;
      n702.setValue(i);
    } else
    {
      i = 0;
      n702.setValue(i);
    }
  }
}

void b705PopCallback(void *ptr) {
  if (i > 0)
  {
    i--;
    n702.setValue(i);
  } else
  {
    i = 0;
    n702.setValue(i);
  }
}

void bt709PopCallback(void *ptr) {
  if (ventilator == 0) {
    ventilator = true;
    EEPROM.write(132, 1);
  }
  else {
    ventilator = false;
    EEPROM.write(132, 0);
  }
}

void b107PopCallback(void *ptr) {
  int state;
  state = EEPROM.read(132);
  bt709.setValue(state);
}



/* VENTILATOR KRAJ */

/* PODESAVANJE EKRANA */

void b1707PopCallback(void *ptr) {
  int tmp;
  tmp = EEPROM.read(150);
  n1703.setValue(tmp);
  i = tmp;
  mod = 0;
}

void b1708PopCallback(void *ptr) {
  int tmp;
  tmp = EEPROM.read(151);
  n1703.setValue(tmp);
  i = tmp;
  mod = 1;
}

void setBrightness(int i) {
  String command = "dim=";
  command = command + i;
  char charBuf[8];
  command.toCharArray(charBuf, 8);
  sendCommand(charBuf);
}

void setScreenTime(int i) {
  float broj = 0;
  broj = i;
  broj = broj * 1000;
  timer2.setInterval(broj);
}

void b1709PopCallback(void *ptr) {
  if (mod == 0) {
    EEPROM.write(150, i);
    screenTime = i;
    timer2.stop();
    timer2.clearInterval();
    setScreenTime(i);
    timer2.start();
  }
  if (mod == 1) {
    EEPROM.write(151, i);
    setBrightness(i);
    brightness = i;
  }
  i = 0;
  n1703.setValue(0);
  mod = 3;

}

void bt1701PopCallback(void *ptr) {
  if (proximity == 0) {
    proximity = true;
    EEPROM.write(129, 1);
  }
  else {
    proximity = false;
    EEPROM.write(129, 0);
  }
}

void bt1702PopCallback(void *ptr) {
  if (offTime == 0) {
    offTime = true;
    EEPROM.write(152, 1);
  }
  else {
    offTime = false;
    EEPROM.write(152, 0);
  }

}

void b1704PopCallback(void *ptr) {
  if (mod == 1) {
    if (i < 1) {
      i = 1;
    }
    if (i < 100)
    {
      i++;
      n1703.setValue(i);
    } else
    {
      i = 1;
      n1703.setValue(i);
    }
  }
  else {
    if (i < 5) {
      i = 5;
    }
    if (i < 999)
    {
      i++;
      n1703.setValue(i);
    } else
    {
      i = 5;
      n1703.setValue(i);
    }
  }
}

void b1705PopCallback(void *ptr) {
  if (mod == 1) {
    if (i > 1)
    {
      i--;
      n1703.setValue(i);
    } else
    {
      i = 1;
      n1703.setValue(i);
    }
  }
  else {
    if (i > 5)
    {
      i--;
      n1703.setValue(i);
    } else
    {
      i = 5;
      n1703.setValue(i);
    }
  }
}

void b208PopCallback(void *ptr) {
  bt1701.setValue(proximity);
  bt1702.setValue(offTime);
}

void b0PopCallback(void *ptr) {
  if (offTime == true) {
    timer2.stop();
  }
}




void setup() {
  Serial.begin(9600);
  sendCommand("thup=1");
  timer.setInterval(20000);
  setScreenTime(screenTime);
  timer3.setInterval(500);
  // The function to be called
  timer.setCallback(helloCallback);
  timer2.setCallback(helloCallback2);
  timer3.setCallback(getProximityStatus);

  // Start the timer
  timer.start();
  if (offTime == true) {
    timer2.start();
  }

  nexInit();
  modRada = EEPROM.read(123);
  ucitajVrednosti();
 
  hideStatus();
  setBrightness(brightness);

  // STRANICA TEMPERATURA

  b404.attachPop(b404PopCallback, &b404);
  b403.attachPop(b403PopCallback, &b403);
  b405.attachPop(b405PopCallback, &b405);
  b406.attachPop(b406PopCallback, &b406);
  b408.attachPop(b408PopCallback, &b408);

  // STRANICA VLAZNOST VAZDUHA

  b606.attachPop(b606PopCallback, &b606);
  b607.attachPop(b607PopCallback, &b607);
  b608.attachPop(b608PopCallback, &b608);
  b604.attachPop(b604PopCallback, &b604);
  b605.attachPop(b605PopCallback, &b605);

  // STRANICA VLAZNOST ZEMLJISTA

  b506.attachPop(b506PopCallback, &b506);
  b507.attachPop(b507PopCallback, &b507);
  b508.attachPop(b508PopCallback, &b508);
  b504.attachPop(b504PopCallback, &b504);
  b505.attachPop(b505PopCallback, &b505);

  // STRANICA ZIMSKI REZIM

  b807.attachPop(b807PopCallback, &b807);
  b808.attachPop(b808PopCallback, &b808);
  b809.attachPop(b809PopCallback, &b809);
  b804.attachPop(b804PopCallback, &b804);
  b806.attachPop(b806PopCallback, &b806);
  b802.attachPop(b802PopCallback, &b802);
  b106.attachPop(b106PopCallback, &b106);

  //TAJMER

  b909.attachPop(b909PopCallback, &b909);
  b910.attachPop(b910PopCallback, &b910);
  b911.attachPop(b911PopCallback, &b911);
  b903.attachPop(b903PopCallback, &b903);
  b907.attachPop(b907PopCallback, &b907);
  b904.attachPop(b904PopCallback, &b904);
  b908.attachPop(b908PopCallback, &b908);

  //MOD RADA

  b302.attachPop(b302PopCallback, &b302);
  b303.attachPop(b303PopCallback, &b303);
  b304.attachPop(b304PopCallback, &b304);
  b305.attachPop(b305PopCallback, &b305);
  b109.attachPop(b109PopCallback, &b109);

  //PODESAVANJE VREMENA
  b1602.attachPop(b1602PopCallback, &b1602);
  b1603.attachPop(b1603PopCallback, &b1603);
  b1604.attachPop(b1604PopCallback, &b1604);
  b1605.attachPop(b1605PopCallback, &b1605);
  b1606.attachPop(b1606PopCallback, &b1606);
  b1607.attachPop(b1607PopCallback, &b1607);
  b1608.attachPop(b1608PopCallback, &b1608);

  //PRIHRANA

  b1004.attachPop(b1004PopCallback, &b1004);
  b1005.attachPop(b1005PopCallback, &b1005);
  b1006.attachPop(b1006PopCallback, &b1006);
  b1007.attachPop(b1007PopCallback, &b1007);
  b108.attachPop(b108PopCallback, &b108);

  //VENTILATOR

  b706.attachPop(b706PopCallback, &b706);
  b707.attachPop(b707PopCallback, &b707);
  b708.attachPop(b708PopCallback, &b708);
  b704.attachPop(b704PopCallback, &b704);
  b705.attachPop(b705PopCallback, &b705);
  bt709.attachPop(bt709PopCallback, &bt709);
  b107.attachPop(b107PopCallback, &b107);

  //KALIBRACIJA

  b409.attachPop(b409PopCallback, &b409);
  b509.attachPop(b509PopCallback, &b509);
  b609.attachPop(b609PopCallback, &b609);

  //TASTERI ZA UKLJUCIVANJE

  bt201.attachPop(bt201PopCallback, &bt201);
  bt202.attachPop(bt202PopCallback, &bt202);
  b110.attachPop(b110PopCallback, &b110);

  //PODESAVANJE EKRANA

  b1707.attachPop(b1707PopCallback, &b1707);
  b1708.attachPop(b1708PopCallback, &b1708);
  b1709.attachPop(b1709PopCallback, &b1709);
  b1704.attachPop(b1704PopCallback, &b1704);
  b1705.attachPop(b1705PopCallback, &b1705);;
  bt1701.attachPop(bt1701PopCallback, &bt1701);
  bt1702.attachPop(bt1702PopCallback, &bt1702);
  b208.attachPop(b208PopCallback, &b208);

  b0.attachPop(b0PopCallback, &b0);


  dht.begin();
  rtc.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(10,HIGH);
  pinMode(A0, INPUT);

  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}

void trenutneVrednosti() {
  float t = dht.readTemperature();
  static char temperatureCTemp[3];
  dtostrf(t, 3, 0, temperatureCTemp);
  tempTxt.setText(temperatureCTemp);

  float h = dht.readHumidity();
  static char humidityC[3];
  dtostrf(h, 3, 0, humidityC);
  humTxt.setText(humidityC);
}



void temperatura(int mode) {

}

void loop() {
  /*int val = analogRead(A8);
    if(val>300){
    sendCommand("sleep=0");
    }
    else{
    sendCommand("sleep=1");
    }*/
  timer.update();
  if (offTime == true) {
    timer2.update();
  }
  if (proximity == true) {
    timer3.update();
  }
  //huNum.setVisible(0);
  // reads the value of the sharp sensor
  //Serial.println(val);
  //delay(200);
  nexLoop(nex_listen_list);

}
