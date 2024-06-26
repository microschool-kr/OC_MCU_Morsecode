//LED가 꼽혀있는 핀 정의
int ledPin = 8;
//Piezo 부저가 꼽혀있는 핀 정의
int buzzerPin = 7;

char* letters[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

char* numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

int dotDelay = 200;

void setup() { 
    // LED를 출력으로 설정
    pinMode(ledPin, OUTPUT);
    // Piezo 부저를 출력으로 설정
    pinMode(buzzerPin, OUTPUT);
    // 시리얼 통신 시작
    Serial.begin(9600);
}

void loop() {
    char ch;

    if (Serial.available()) {
	ch = Serial.read();
	if (ch >= 'a' && ch <= 'z') {
	    flashSequence(letters[ch - 'a']);
	    // Piezo 부저를 이용하여 소리 출력
	    beep(1000, 100);

	} else if (ch >= 'A' && ch <= 'Z') {
	    flashSequence(letters[ch - 'A']);
	    // Piezo 부저를 이용하여 소리 출력
	    beep(1000, 100);
	} else if (ch >= '0' && ch <= '9') {
	    flashSequence(numbers[ch - '0']);
	    // Piezo 부저를 이용하여 소리 출력
	    beep(1000, 100);

	} else if (ch == ' ') {
	    delay(dotDelay * 4);}
	    // Piezo 부저를 이용하여 소리 출력
	    beep(1000, 100);
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

// Piezo 부저를 이용한 소리 출력
void beep(int note, int duration) {
  // tone 함수를 이용하여 소리를 출력
  tone(buzzerPin, note, duration);
  // duration 시간 동안 소리를 출력
  delay(duration);
  // noTone 함수를 이용하여 소리를 멈춤
  noTone(buzzerPin);
}




