import random
from flask import Flask, render_template

app = Flask(__name__) # Creating Flask Object


"""
Routes are just what you might type at the end of the URl
in order to decide what page you want to visit.
for example: on google, you might be visiting /search ot /settings ot /maps.
"""
@app.route("/") #Default route
def index ():
    number = random.randint(0, 1)
    return render_template("index.html", number=number)

@app.route("/goodbye")
def bye():
    return ("Goodbye!")