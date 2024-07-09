# 모스부호  

[모스부호](https://ko.wikipedia.org/wiki/%EC%8B%A4%EC%8B%9C%EA%B0%84_%EC%8B%9C%EA%B3%84) 신호 발생기를 아두이노로 만들기.


![img](https://content.instructables.com/FNY/IS7O/J5K5Z6YM/FNYIS7OJ5K5Z6YM.jpg?auto=webp&frame=1&width=1024&height=1024&fit=bounds&md=7a9548d95f39a7217402771ffd528082)

[![YouTube Channel Views](https://img.shields.io/youtube/channel/views/UCz5BOU9J9pB_O0B8-rDjCWQ?label=YouTube&style=social)](https://youtu.be/E6wkvTG2Ofs?si=k_IFc8MM8aGpZE7J)

## 하드웨어 

- 아두이노 우노  
- USB 2.0 케이블 Type A/B
- 빨간색 LED
- 220옴 저항
- [아두이노 수동부저](https://m.intopion.com/goods/view?no=3831812) 


**주의: 점퍼선 연결시 케이블을 제거하고 진행합니다.**

### 선 작업 
#### 회로도
![img](/img/schematic.png)
#### 핀 정보
| Arduino UNO| Buzzer |
|-----------|------|
|   D7      | I/O  |
|   5V      | VCC  |
|   GND     | GND  |

| Arduino UNO |  LED |
|-----------|------|
|   D8      | anode  |
|   GND     | cathode  |

## [예제 코드](/src/Morsecode_v0_2/Morsecode_v0_2.ino) 


## 순서도
![flowchart](/img/Morsecode-2024-07-09-054712.png)
## 코드 설명   
- Morse array
```c
const char* LETTERS[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // A-I
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."          // S-Z
};
const char* NUMBERS[] = {
    "-----", ".----", "..---", "...--", "....-",  // 0-4
    ".....", "-....", "--...", "---..", "----."   // 5-9
};
```

- loop()
```c
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
```
- playMorseSequence()
```c
void playMorseSequence(const char* sequence) {
    for (int i = 0; sequence[i] != '\0'; i++) {
        playMorseSymbol(sequence[i]);
    }
    delay(LETTER_SPACE); 
}
```
- playModseSymbol()
```c
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
```

## 참고
- [Instructable](https://www.instructables.com/LED-Morse-Code-Encoder)   



