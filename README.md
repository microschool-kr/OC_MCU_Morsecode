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
![img](/img/Morsecode_simple_diagram-2024-07-04-073806.png)

## 함수 설명   
- playMorseSequence()

- playModseSymbol()
## 응용하기  
1. D-day 기능 만들기: 굉장히 오래 전부터 지금까지에 대한 시간
2. Alarm 기능 만들기: 10초 후에 뭔가 발생하는 것 만들기 

## 참고
- [Instructable](https://www.instructables.com/LED-Morse-Code-Encoder)   



