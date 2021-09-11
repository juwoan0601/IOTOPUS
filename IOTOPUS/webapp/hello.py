from flask import Flask, render_template      # import flask, render_template function

app = Flask(__name__) # make flask app 

@app.route('/') # if request is default web address('/')
def hello(): # excute default function "hello"
    return render_template('index_hello.html')      # render_template함수 지정

@app.route('/about') # if request is "/about"
def about():
    return 'This is about page'

@app.route('/contact') # if request is "/contact"
def contact():
    return 'This is contact page'

@app.route('/<username>') # if request is "/<username>", excute function "hello_user" 
def hello_user(username):
    return render_template('index_hello.html', user=username)

if __name__ == '__main__': # if this file excute, open dev version web server
    app.run(debug=True, port=80, host='0.0.0.0')