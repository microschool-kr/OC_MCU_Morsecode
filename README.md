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



## 순서도
![flowchart](/img/Morsecode-2024-07-11-004336.png)
# 코드    
## [code.ino](/src/code/code.ino) 

# 알아두어야할 함수 
- playMorseSequence() : 모스 부호를 LED와 피에조 부저로 출력하는 함수
- playModseSymbol() : 점 또는 대시를 LED와 피에조 부저로 출력하는 함수 
## 참고
- [Instructable](https://www.instructables.com/LED-Morse-Code-Encoder)   



