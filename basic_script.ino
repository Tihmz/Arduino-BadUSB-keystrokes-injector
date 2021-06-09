#include <Keyboard.h>


void pressKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  //delay for debugging or safety
  delay(5000); 
  
  // Ending stream */
  Keyboard.end();
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

String fr2en(String text)
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


void keyboardScanCode(byte code)
{  
  Keyboard.press(code+136);  
  delay(4);  
  Keyboard.release(code+136);  
  delay(4); 
}

void printCA(int n, int s) //print with ctrl + alt
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
