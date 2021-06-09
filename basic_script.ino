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
  Keyboard.begin();

  //delay for debugging and safety
  delay(5000);


  Keyboard.end();
}

String fr2en(String text) //azerty to qwerty keyboard, found here: https://dyrk.org/2018/12/09/arduino-simuler-un-clavier-azerty/
{
  int i = 0;
  String _en = " =qwertyuiopasdfghjkl;zxcvbnQWERTYUIOPASDFGHJKL:ZXCVBNm,./M<>?1234567890!@#$%^&*()\"-",
         _fr = " =azertyuiopqsdfghjklmwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN,;:!?./ & \"'(- _  1234567890%)",
         str = "";
  while (text[i] != 0){
    str = str + (String)_en[_fr.indexOf((String)text[i++])];
  }
  return str;
}

void Keyboardprint(String text)
{
  text=fr2en(text);
  int n=text.length();
  for(int i=0;i<n;i++)
  {
      Keyboard.print(text[i]);
  }
}

void keyboardScanCode(byte code) //to press special key like '\', found here: https://forum.arduino.cc/t/keyboard-h-et-antislash/565172/3 (thanks to nico78)
{  
  Keyboard.press(code+136);  
  delay(4);  
  Keyboard.release(code+136);  
  delay(4); 
}

void printCA(int n, int s)
{    
  for (int i=0;i<n;i++)
  {
    Keyboard.press(KEY_LEFT_CTRL);  
    Keyboard.press(KEY_LEFT_ALT);  
    keyboardScanCode(s);  
    Keyboard.release(KEY_LEFT_ALT);  
    Keyboard.release(KEY_LEFT_CTRL);
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
