//LED가 꼽혀있는 핀 정의
int ledPin = 8;

char* letters[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

char* numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

int dotDelay = 200;

void setup() {
    pinMode(ledPin, OUTPUT);
    
    Serial.begin(9600);
}

void loop() {
    char ch;

    if (Serial.available()) {
	ch = Serial.read();
	if (ch >= 'a' && ch <= 'z') {
	    flashSequence(letters[ch - 'a']);
	} else if (ch >= 'A' && ch <= 'Z') {
	    flashSequence(letters[ch - 'A']);
	} else if (ch >= '0' && ch <= '9') {
	    flashSequence(numbers[ch - '0']);
	} else if (ch == ' ') {
	    delay(dotDelay * 4);}
  }
}

void flashSequence(char* sequence) {
  int i = 0;
  // while there are still characters keep going through each one
  while (sequence[i] != NULL)  {
    flashDotOrDash(sequence[i]);
    i++; } // increment by one until end of characters
  delay(dotDelay * 3); // gap between letters
} 


void flashDotOrDash(char dotOrDash) {
  digitalWrite(ledPin, HIGH);
  if (dotOrDash == '.')  {
    delay(dotDelay); 
  } else { // must be a -
    delay(dotDelay * 3);   // if it's a dot then we need a longer delay gap relative to a dot.
  }
  
  digitalWrite(ledPin, LOW);
  delay(dotDelay); // gap between flashes
  
}
