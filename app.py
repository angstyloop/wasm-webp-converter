import os
from flask import Flask, redirect, url_for, request
app = Flask(__name__)

@app.route('/')
def root():
    return app.send_static_file('webp.html')

@app.route('/a.out.js')
def js():
    return app.send_static_file('a.out.js')

@app.route('/a.out.wasm')
def wasm():
    return app.send_static_file('a.out.wasm')

@app.route('/image.jpg')
def jpg():
    return app.send_static_file('image.jpg')

@app.route('/upload', methods=['POST'])
def upload():
    f = request.files['file']
    f.save("uploads/" + f.filename)
    return {'statusCode': 200, 'response': 'Uploaded file %s.' % f.filename}

if __name__ == '__main__':
    app.run(debug = True)
