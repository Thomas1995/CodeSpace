from datetime import datetime
from flask import Flask, request, render_template

app = Flask(__name__)

@app.route("/api/")
def api():
    return "<body bgcolor = \"green\"></body>"

@app.route("/time/")
def time():
    s = "<head> <meta http-equiv=\"refresh\" content=\"1\"></head>"
    now = datetime.now()
    s += str(now.hour) + ":" + str(now.minute) + ":" + str(now.second)
    return s

@app.route('/hello/')
@app.route('/hello/<name>')
def hello(name=None):
    return render_template('a.html', name=name)



@app.route("/sum/<int:no1>/<int:no2>/")
def sum(no1, no2):
    s = ""
    for x in range(0, no1):
        s += "<img src = \"http://images.clipartpanda.com/clipart-star-RTA9RqzTL.png\" height = 15 align = \"right\">"

    s += "<br>"

    for x in range(0, no2):
        s += "<img src = \"http://images.clipartpanda.com/clipart-star-RTA9RqzTL.png\" height = 15 align = \"right\">"

    s += "<br><hr width = \"20%\" align = \"right\">"

    for x in range(0, no1+no2):
        s += "<img src = \"http://images.clipartpanda.com/clipart-star-RTA9RqzTL.png\" height = 15 align = \"right\">"

    return s

if __name__ == "__main__":
    app.run(debug=True)
