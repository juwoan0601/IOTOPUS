from flask import Flask, render_template, url_for, redirect   # url_for 함수, redirect 함수 추가
from gpiozero import LEDBoard
import os

app = Flask(__name__)
#leds = LEDBoard(14, 15, 18)                # leds 객체 생성

iot_states = {                           # 전체 디바이스 현황 표시용
    'LED1':0,
    'LED2':0,
    'LED3':0,
    'LED4':0,
    'SRV1':0
}

@app.route('/')                       # 기본주소('/')로 들어오면
def home():
    return render_template('index_LED_SERVO_BLE', iot_states = iot_states)   #index.html에 전체 led현황을 함께 전달 

@app.route('/<SID>/<int:state>')                                # 개별 led를 켜고 끄는 주소
def iot_switch(SID, state):                                    # 개별 led ON, OFF 함수
    iot_states[SID] = state
    if SID == 'LED1': os.system('sudo python3 sendLEDCommend.py --msg=1')
    if SID == 'LED2': os.system('sudo python3 sendLEDCommend.py --msg=2')
    if SID == 'LED3': os.system('sudo python3 sendLEDCommend.py --msg=3')
    if SID == 'LED4': os.system('sudo python3 sendLEDCommend.py --msg=4')
    if SID == 'SRV1': os.system('sudo python3 sendServoCommend.py --msg=1')
    #leds.value=tuple(led_states.values())
    return redirect(url_for('home'))                           # leds의 색상변경이 완료되면 redirect함수를 통해 기본주소('/')으로 이동

@app.route('/all/<int:state>')                                 # 모든 led를 한꺼번에 켜거나 끄는 주소
def all_on_off(state):                                        # 모든 led를 한꺼번에 켜거나 끄는 함수
    if state is 0:
            iot_states['LED1']=0
            iot_states['LED2']=0
            iot_states['LED3']=0 
            iot_states['LED4']=0 
    elif state is 1: 
        iot_states['LED1']=1
        iot_states['LED2']=1
        iot_states['LED3']=1 
        iot_states['LED4']=1
    os.system('sudo python3 sendLEDCommend.py --msg=1234') 
    #leds.value=tuple(led_states.values())
    return redirect(url_for('home'))                     # 모든 led를 켜거나 껐으면 기본주소('/')로 이동

if __name__ == '__main__':
    app.run(debug=True, port=80, host='0.0.0.0')