from flask import Flask, render_template, url_for, redirect   # url_for 함수, redirect 함수 추가
from gpiozero import LEDBoard

app = Flask(__name__)

leds = LEDBoard(14, 15, 18)                # leds 객체 생성

led_states = {                           # 전체 led의 현황 표시용
    'red':0,
    'green':0,
    'blue':0
}

@app.route('/')                       # 기본주소('/')로 들어오면
def home():
    return render_template('index_LED.html', led_states = led_states)   #index.html에 전체 led현황을 함께 전달 

@app.route('/<color>/<int:state>')                                # 개별 led를 켜고 끄는 주소
def led_switch(color, state):                                    # 개별 led ON, OFF 함수
    led_states[color] = state  
    leds.value=tuple(led_states.values())
    return redirect(url_for('home'))                           # leds의 색상변경이 완료되면 redirect함수를 통해 기본주소('/')으로 이동

@app.route('/all/<int:state>')                                 # 모든 led를 한꺼번에 켜거나 끄는 주소
def all_on_off(state):                                        # 모든 led를 한꺼번에 켜거나 끄는 함수
    if state is 0:
            led_states['red']=0
            led_states['green']=0
            led_states['blue']=0 
    elif state is 1: 
        led_states['red']=1
        led_states['green']=1
        led_states['blue']=1 
    leds.value=tuple(led_states.values())
    return redirect(url_for('home'))                     # 모든 led를 켜거나 껐으면 기본주소('/')로 이동

if __name__ == '__main__':
    app.run(debug=True, port=80, host='0.0.0.0')