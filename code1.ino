int irRecvPin = 12;   
unsigned long bitTime;  
unsigned long  codeValue;  

void setup()
{
  pinMode(irRecvPin, INPUT);  
  Serial.begin(9600);  
}
void loop()
{
  bitTime = pulseIn(irRecvPin, LOW);  
  if (bitTime > 3000) {
    codeValue = 0;        
    for(int i = 0; i < 32; i++) {
      bitTime = pulseIn(irRecvPin, HIGH);
    if (i > 15 && i < 24) 
      if(bitTime > 1000)  
        codeValue |= (1 << (i-16)); 
    }  
    Serial.println(codeValue,HEX); Serial.flush();  
  if (codeValue==12) noTone;
  if (codeValue==16) tone(8,262);
  if (codeValue==17) tone(8,294);
  if (codeValue==18) tone(8,330);
  if (codeValue==20) tone(8,349);
  if (codeValue==21) tone(8,392);
  if (codeValue==22) tone(8,440);
  if (codeValue==24) tone(8,494);
  }

  
delay(1);
}  
