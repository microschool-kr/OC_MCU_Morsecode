const int ledPin = 7;     // LED 연결 핀
const int piezoPin = 8;      // 피에조 연결 핀
const int note = 1200;     // 음의 주파수
const int dotDelay = 100;  // 점 길이
const int dashDelay = dotDelay * 3;  // 대시 길이

// 알파벳과 숫자의 모스 부호를 저장한 배열 
char* letters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
char* numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

void setup() {
    // 핀 모드를 설정하고 시러얼 통신 시작 
    pinMode(ledPin, OUTPUT);
    pinMode(piezoPin, OUTPUT);
    Serial.begin(9600);
    // 시리얼 모니터에 사용법 출력
    Serial.println("모스 부호를 입력하세요. 알파벳, 숫자, 공백만 입력 가능합니다.");
}

void loop() {
    // 시리얼로 입력된 문자를 읽어서 모스 부호로 변환
    char ch;

    if (Serial.available()) {  // 시리얼로 입력된 문자가 있으면
        ch = Serial.read();
	// 입력된 문자를 읽어서 모스 부호 배열을 찾아 flashAndSoundSequence 함수 호출
        if (ch >= 'a' && ch <= 'z') {
            flashAndSoundSequence(letters[ch - 'a']);
        } else if (ch >= 'A' && ch <= 'Z') {
            flashAndSoundSequence(letters[ch - 'A']);
        } else if (ch >= '0' && ch <= '9') {
            flashAndSoundSequence(numbers[ch - '0']);
        } else if (ch == ' ') {
	// 공백 문자가 입력되면 3칸의 공백을 줌
            delay(dotDelay * 4);
        }
    }
}

// 모스 부호를 LED와 피에조 부저로 출력하는 함수
// 주어진 모스부호 문자열을 순회하며 각 점과 대시를 출력
void flashAndSoundSequence(char* sequence) {
    int i = 0;
    while (sequence[i] != NULL) {
        flashAndSoundDotOrDash(sequence[i]);
        i++;
    }
    delay(dotDelay * 3); // 문자 간 간격
}

// 점(.) 또는 대시(-)를 LED와 피에조 부저로 출력하는 함수
void flashAndSoundDotOrDash(char dotOrDash) {
    //LED 켜기
    digitalWrite(ledPin, HIGH);
    // 피에조 부저로 소리 출력
    if (dotOrDash == '.') {
        tone(piezoPin, note, dotDelay);
        delay(dotDelay);
    } else {
        tone(piezoPin, note, dashDelay);
        delay(dashDelay);
    }
    // LED 끄기
    digitalWrite(ledPin, LOW);
    // 피에조 부저 소리 끄기
    noTone(piezoPin);
    // 점과 대시 사이의 간격
    delay(dotDelay); 
}

