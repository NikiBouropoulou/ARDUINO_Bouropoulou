int irRecvPin = 12;   // Ο ακροδέκτης που συνδέθηκε ο δέκτης υπερύθρων
unsigned long bitTime;  // Ο χρόνος που διήρκησε το bit σε μsec
unsigned long  codeValue;  // Ο κώδικας που μεταδόθηκε

void setup()
{
  pinMode(irRecvPin, INPUT);  // Είσοδος για τις υπέρυθρες
  Serial.begin(9600);  // Στέλνουμε στην σειριακή τους κωδικούς πλήκτρων
}
void loop()
{
  bitTime = pulseIn(irRecvPin, LOW);  // Εχουμε start bit ;
  if (bitTime > 3000) {
    codeValue = 0;        // Αν ναι
    for(int i = 0; i < 32; i++) { // διαβάζουμε και τα 32 bit
      bitTime = pulseIn(irRecvPin, HIGH); // η διάρκεια του “space”
    if (i > 15 && i < 24) // To 3o byte έχει τον κωδικό πλήκτρου
      if(bitTime > 1000)  // Είναι "1";
        codeValue |= (1 << (i-16)); // ΄Θέσε "1" στο κατάλληλο bit
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
