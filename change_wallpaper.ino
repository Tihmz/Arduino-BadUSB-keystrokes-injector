#include <Keyboard.h>

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

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
  String text=fr2en("powershell");
  Keyboard.print(text);
  delay(100);
  typeKey(KEY_RETURN);
  delay(200);
  
  //changing working directory
  text=fr2en("cd C:");
  Keyboard.print(text);
  printBSlash(1);
  text=fr2en("Users");
  Keyboard.print(text);
  printBSlash(1);
  text=fr2en("Public");
  Keyboard.print(text);
  typeKey(KEY_RETURN);
  delay(100);

  //downloading the picture (you can change easily the link with the one of your choice
  String text1=fr2en("Invoke-WebRequest  http://www.thecuriosityworkshop.com/wp-content/uploads/2015/03/01-rubberduck-hongkong.jpg -o 01-rubberduck-hongkong.jpg");
  Keyboard.print(text1);
  typeKey(KEY_RETURN);
  delay(1000); //1 sec to download 

  //changing wallpaper in the in the registers
  String text2=fr2en("reg add \"HKEY_CURRENT_USER");
  Keyboard.print(text2);
  printBSlash(1);
  text2=fr2en("Control Panel");
  Keyboard.print(text2);
  printBSlash(1);
  text2=fr2en("Desktop\" /v Wallpaper /t REG_SZ /d C:");
  Keyboard.print(text2);
  printBSlash(1);
  String a=fr2en("Users");
  Keyboard.print(a);
  printBSlash(1);
  a=fr2en("public");
  Keyboard.print(a);
  printBSlash(1);
  a=fr2en("01-rubberduck-hongkong.jpg /f");
  Keyboard.print(a);
  typeKey(KEY_RETURN);
  delay(200);

  //update the register (sometimes it don't work ¯\_(ツ)_/¯ )
  String text3=fr2en("RUNDLL32.EXE USER32.DLL, UpdatePerUserSystemParameters , 1 , True");
  Keyboard.print(text3);
  typeKey(KEY_RETURN);
  delay(500);
  Keyboard.print("exit");
  typeKey(KEY_RETURN);
  Keyboard.end();
}

String fr2en(String text) //azerty to qwerty keyboard, found here: https://dyrk.org/2018/12/09/arduino-simuler-un-clavier-azerty
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
