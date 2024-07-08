#define LED_PIN 7
#define BUZZER_PIN 8

#define TONE_FREQUENCY 1200
#define DOT_DELAY 100
#define DASH_DELAY (DOT_DELAY * 3)
#define LETTER_SPACE (DOT_DELAY * 3)
#define WORD_SPACE (DOT_DELAY * 7)

#define SERIAL_BAUD_RATE 9600

const char* LETTERS[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // A-I
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."          // S-Z
};
const char* NUMBERS[] = {
    "-----", ".----", "..---", "...--", "....-",  // 0-4
    ".....", "-....", "--...", "---..", "----."   // 5-9
};

void playMorseSequence(const char* sequence);
void playMorseSymbol(char dotOrDash);

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(SERIAL_BAUD_RATE);
    Serial.println("모스 부호를 입력하세요. 알파벳, 숫자, 공백만 입력 가능합니다.");
}

void loop() {
    if (Serial.available()>0) {  
        char ch = Serial.read();

	if (ch == '\n' || ch == '\r') {
	    return;
	}
        
        switch(ch) {
            case 'a'...'z':
                playMorseSequence(LETTERS[ch - 'a']);
                break;
            case 'A'...'Z':
                playMorseSequence(LETTERS[ch - 'A']);
                break;
            case '0'...'9':
                playMorseSequence(NUMBERS[ch - '0']);
                break;
            case ' ':
                delay(WORD_SPACE);
                break;
            default:
                Serial.println("올바르지 않은 입력입니다. 알파벳, 숫자, 공백만 입력해주세요.");
        }
    }
}

void playMorseSequence(const char* sequence) {
    for (int i = 0; sequence[i] != '\0'; i++) {
        playMorseSymbol(sequence[i]);
    }
    delay(LETTER_SPACE); 
}

void playMorseSymbol(char dotOrDash) {
    digitalWrite(LED_PIN, HIGH);  
    
    if (dotOrDash == '.') {
        tone(BUZZER_PIN, TONE_FREQUENCY, DOT_DELAY);
        delay(DOT_DELAY);
    } else {  
        tone(BUZZER_PIN, TONE_FREQUENCY, DASH_DELAY);
        delay(DASH_DELAY);
    }
    
    digitalWrite(LED_PIN, LOW);  
    noTone(BUZZER_PIN);  
    delay(DOT_DELAY);  
}
