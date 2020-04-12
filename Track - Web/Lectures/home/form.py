from flask import Flask, render_template, request

app = Flask(__name__) # Creating Flask Object


"""
Routes are just what you might type at the end of the URl
in order to decide what page you want to visit.
for example: on google, you might be visiting /search ot /settings ot /maps.
"""
@app.route("/") #Default route
def index ():
    return render_template('form.html')

@app.route("/hello")
def hello():
    name = request.args.get("name")
    if not name:
        return render_template('failure.html')
    return render_template('hello.html', name=name)
