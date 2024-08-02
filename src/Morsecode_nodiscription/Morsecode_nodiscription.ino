const int ledPin = 7;     
const int piezoPin = 8;      
const int note = 1200;     
const int dotDelay = 100;  
const int dashDelay = dotDelay * 3;  

char* letters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
char* numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(piezoPin, OUTPUT);
    Serial.begin(9600);
    Serial.println("모스 부호를 입력하세요. 알파벳, 숫자, 공백만 입력 가능합니다.");
}

void loop() {
    char ch;

    if (Serial.available()) {  
        ch = Serial.read();
        if (ch >= 'a' && ch <= 'z') {
            flashAndSoundSequence(letters[ch - 'a']);
        } else if (ch >= 'A' && ch <= 'Z') {
            flashAndSoundSequence(letters[ch - 'A']);
        } else if (ch >= '0' && ch <= '9') {
            flashAndSoundSequence(numbers[ch - '0']);
        } else if (ch == ' ') {
            delay(dotDelay * 4);
        }
    }
}

void flashAndSoundSequence(char* sequence) {
    int i = 0;
    while (sequence[i] != NULL) {
        flashAndSoundDotOrDash(sequence[i]);
        i++;
    }
    delay(dotDelay * 3); 
}

void flashAndSoundDotOrDash(char dotOrDash) {
    digitalWrite(ledPin, HIGH);
    if (dotOrDash == '.') {
        tone(piezoPin, note, dotDelay);
        delay(dotDelay);
    } else {
        tone(piezoPin, note, dashDelay);
        delay(dashDelay);
    }
    digitalWrite(ledPin, LOW);
    noTone(piezoPin);
    delay(dotDelay); 
}

