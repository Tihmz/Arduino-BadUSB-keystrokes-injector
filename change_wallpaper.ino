#include <Keyboard.h>

void pressKey(int key) //press a key and release it after 50ms
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

String trad;

void setup()
{
  Keyboard.begin();

  //delay for debugging or safety
  delay(5000); 

  //launching power shell with "windows" + "r"
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(300);
  trad=fr2en("powershell");
  Keyboard.print(trad);
  delay(100);
  pressKey(KEY_RETURN);
  delay(500);
  
  //changing working directory
  trad=fr2en("cd C:");
  Keyboard.print(trad);
  printBSlash(1);
  trad=fr2en("Users");
  Keyboard.print(trad);
  printBSlash(1);
  trad=fr2en("Public");
  Keyboard.print(trad);
  pressKey(KEY_RETURN);
  delay(100);

  //downloading the picture (you can change easily the link with the one of your choice => "Invoke-WebRequest your_link -o the_name_of_the_picture")
  trad=fr2en("Invoke-WebRequest  https://media.npr.org/assets/img/2013/05/06/ducky062way-23e257dfd081032928ffbd73768a7ddd8615f1f3.jpg -o ducky062way-23e257dfd081032928ffbd73768a7ddd8615f1f3.jpg");
  Keyboard.print(trad);
  pressKey(KEY_RETURN);
  delay(1000); //1 sec to download 

  //changing wallpaper in the in the registers
  trad=fr2en("reg add \"HKEY_CURRENT_USER");
  Keyboard.print(trad);
  printBSlash(1);
  trad=fr2en("Control Panel");
  Keyboard.print(trad);
  printBSlash(1);
  trad=fr2en("Desktop\" /v Wallpaper /t REG_SZ /d C:");
  Keyboard.print(trad);
  printBSlash(1);
  trad=fr2en("Users");
  Keyboard.print(trad);
  printBSlash(1);
  trad=fr2en("public");
  Keyboard.print(trad);
  printBSlash(1);
  trad=fr2en("ducky062way-23e257dfd081032928ffbd73768a7ddd8615f1f3.jpg /f");
  Keyboard.print(trad);
  pressKey(KEY_RETURN);
  delay(200);

  //update the register (sometimes it don't work ¯\_(ツ)_/¯ )
  trad=fr2en("RUNDLL32.EXE USER32.DLL, UpdatePerUserSystemParameters , 1 , True");
  Keyboard.print(trad);
  pressKey(KEY_RETURN);
  delay(500);
  Keyboard.print("exit");
  pressKey(KEY_RETURN);
  Keyboard.end();
}

String fr2en(String text) //azerty to qwerty keyboard, found here: https://dyrk.org/2018/12/09/arduino-simuler-un-clavier-azerty/?replytocom=1879#respond
{
  int i = 0;
  String _en = " =qwertyuiopasdfghjkl;zxcvbnQWERTYUIOPASDFGHJKL:ZXCVBNm,./M<>?1234567890!@#$%^&*()\"",
         _fr = " =azertyuiopqsdfghjklmwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN,;:!?./ & \"'(- _  1234567890%",
         str = "";
  while (text[i] != 0){
    str = str + (String)_en[_fr.indexOf((String)text[i++])];
  }
  return str;
}


void keyboardScanCode(byte code) //to press special key like '\', found here: https://forum.arduino.cc/t/keyboard-h-et-antislash/565172/3 (thanks to nico78)
{  
  Keyboard.press(code+136);  
  delay(4);  
  Keyboard.release(code+136);  
  delay(4); 
}

void printBSlash(int n) //to print '\'
{    
  for (int i=0;i<n;i++)
  {
    Keyboard.press(KEY_LEFT_CTRL);  
    Keyboard.press(KEY_LEFT_ALT);  
    keyboardScanCode(37);  
    Keyboard.release(KEY_LEFT_ALT);  
    Keyboard.release(KEY_LEFT_CTRL);
  }
}

void loop() {} //useless here
