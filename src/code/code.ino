// 핀 번호 정의
#define LED_PIN 7
#define BUZZER_PIN 8

// 모스 부호 관련 상수 정의
#define TONE_FREQUENCY 1200
#define DOT_DELAY 100
#define DASH_DELAY (DOT_DELAY * 3)
#define LETTER_SPACE (DOT_DELAY * 3)
#define WORD_SPACE (DOT_DELAY * 7)

// 시리얼 통신 속도 정의
#define SERIAL_BAUD_RATE 9600

// 알파벳과 숫자의 모스 부호를 저장한 배열 
const char* LETTERS[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // A-I
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."          // S-Z
};
const char* NUMBERS[] = {
    "-----", ".----", "..---", "...--", "....-",  // 0-4
    ".....", "-....", "--...", "---..", "----."   // 5-9
};

// 함수 선언
void playMorseSequence(const char* sequence);
void playMorseSymbol(char dotOrDash);

void setup() {
    // 핀 모드를 설정하고 시리얼 통신 시작 
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(SERIAL_BAUD_RATE);
    // 시리얼 모니터에 사용법 출력
    Serial.println("모스 부호를 입력하세요. 알파벳, 숫자, 공백만 입력 가능합니다.");
}

void loop() {
    // 시리얼로 입력된 문자를 읽어서 모스 부호로 변환
    if (Serial.available()>0) {  // 시리얼로 입력된 문자가 있으면
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

// 모스 부호를 LED와 피에조 부저로 출력하는 함수
void playMorseSequence(const char* sequence) {
    for (int i = 0; sequence[i] != '\0'; i++) {
        playMorseSymbol(sequence[i]);
    }
    delay(LETTER_SPACE); // 문자 간 간격
}

// 점(.) 또는 대시(-)를 LED와 피에조 부저로 출력하는 함수
void playMorseSymbol(char dotOrDash) {
    digitalWrite(LED_PIN, HIGH);  // LED 켜기
    
    if (dotOrDash == '.') {
        tone(BUZZER_PIN, TONE_FREQUENCY, DOT_DELAY);
        delay(DOT_DELAY);
    } else {  // 대시(-)인 경우
        tone(BUZZER_PIN, TONE_FREQUENCY, DASH_DELAY);
        delay(DASH_DELAY);
    }
    
    digitalWrite(LED_PIN, LOW);  // LED 끄기
    noTone(BUZZER_PIN);  // 피에조 부저 소리 끄기
    delay(DOT_DELAY);  // 점과 대시 사이의 간격
}
