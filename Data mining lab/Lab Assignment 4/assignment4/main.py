
from black import out
from bottle import Bottle, template, request
from featureExtractor import FeatureExtractor
import os
app = Bottle()


@app.route("/")
def index():
    #“““Home Page”””
    return template("./templates/index.tpl", result="", log="", resultname="", logname="",show=False)


@app.route("/", method="POST")
def formhandler():
    # “““Handle the form submission”””
    files=[]
    for choice in request.forms.getall('files'):
        files.append(choice)
    extractor = FeatureExtractor(files)
    output = extractor.getDataFrames()
   
    return template("./templates/index.tpl",
                    result=output["result"],
                    log=output["log"],
                    resultname=output["resultname"],
                    logname=output["logname"],
                    show=True)


if __name__ == "__main__":
    app.run(debug=True)
