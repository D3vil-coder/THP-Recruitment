// C++ code
//

#define frontrightpositive 7
#define frontrightnegative 8
#define backrightpositive 5
#define backrightnegative 6
#define frontleftpositive 9
#define frontleftnegative 10
#define backleftpositive 11
#define backleftnegative 12


void setup()
{
   pinMode(frontrightpositive, OUTPUT);
   pinMode(frontrightnegative, OUTPUT);
   pinMode(frontleftpositive, OUTPUT);
   pinMode(frontleftnegative, OUTPUT);
   pinMode(backrightpositive, OUTPUT);
   pinMode(backrightnegative, OUTPUT);
   pinMode(backleftpositive, OUTPUT);
   pinMode(backleftnegative, OUTPUT);
}

void loop()
{
  goahead();
  delay(15000);
  smoothright();
  delay(2000);
  goahead();
  delay(5000);
  sharpright();
  delay(2000);
  goahead();
  delay(10000);
  smoothleft();
  delay(2000);
  goahead();
  delay(5000);
  sharpleft();
  delay(2000);
  goahead();
  delay(10000);
  sharpright();
  delay(4000);
  goahead();
  delay(15000);
  smoothright();
  delay(2000);
  goahead();
  delay(10000);
  sharpright();
  delay(2000);
  
}

void goahead()
{
  digitalWrite(frontrightpositive,1);
  digitalWrite(frontrightnegative,0);
  digitalWrite(backrightpositive,1);
  digitalWrite(backrightnegative,0);
  digitalWrite(frontleftpositive,0);
  digitalWrite(frontleftnegative,1);
  digitalWrite(backleftpositive,0);
  digitalWrite(backleftnegative,1);
}
void sharpright()
{
  digitalWrite(frontrightpositive,0);
  digitalWrite(frontrightnegative,1);
  digitalWrite(backrightpositive,0);
  digitalWrite(backrightnegative,1);
  digitalWrite(frontleftpositive,0);
  digitalWrite(frontleftnegative,1);
  digitalWrite(backleftpositive,0);
  digitalWrite(backleftnegative,1);
}
void smoothright()
{
  digitalWrite(frontrightpositive,0);
  digitalWrite(frontrightnegative,0);
  digitalWrite(backrightpositive,0);
  digitalWrite(backrightnegative,0);
  digitalWrite(frontleftpositive,0);
  digitalWrite(frontleftnegative,1);
  digitalWrite(backleftpositive,0);
  digitalWrite(backleftnegative,1);
}
void sharpleft()
{
  digitalWrite(frontrightpositive,1);
  digitalWrite(frontrightnegative,0);
  digitalWrite(backrightpositive,1);
  digitalWrite(backrightnegative,0);
  digitalWrite(frontleftpositive,1);
  digitalWrite(frontleftnegative,0);
  digitalWrite(backleftpositive,1);
  digitalWrite(backleftnegative,0);
}
void smoothleft()
{
  digitalWrite(frontrightpositive,1);
  digitalWrite(frontrightnegative,0);
  digitalWrite(backrightpositive,1);
  digitalWrite(backrightnegative,0);
  digitalWrite(frontleftpositive,0);
  digitalWrite(frontleftnegative,0);
  digitalWrite(backleftpositive,0);
  digitalWrite(backleftnegative,0);
}
