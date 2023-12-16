
import pandas as pd
import sys
import re
import time
class FeatureExtractor:
    def __init__(self,files):
        self._files=files
        self._extracted=False
    
    def getResults(self,filename,data):
        result = []
        log=[]
        pattern ="[0-9]+"
        for i in range(1,data.shape[0]):
            
            if(bool(re.findall(pattern,data.iloc[i,0])) or pd.isna( data.iloc[i,1]) ):
                log.append([filename,data.iloc[i,0],data.iloc[i,1]])
                continue
            values = pd.Series(list(data.iloc[i,0])).value_counts().to_dict()
            result.append([i,values.get("N",0),values.get('H',0),values.get('Q',0),values.get('G',0),values.get('D',0),values.get('T',0),1 if data.iloc[i,1]=="+" else 0])
        
            
        return result,log


    def getDataFrames(self):
        results=[]
        logs=[]
        for i in self._files:
            try:
                data= pd.read_csv(i, sep=",", header=None)
                x,y=self.getResults(i,data)
                results.extend(x)
                logs.extend(y)
            except :
                # pass
                print("The File doesn't exist")

        self._extracted=True
        self.result_df = pd.DataFrame(results, columns = ['SN', 'F1', 'F2', 'F3', 'F4', 'F5', 'F6', 'Class'])
        self.log_df = pd.DataFrame(logs, columns = ['FileName', 'Sequence', 'Class'])
        print("Result")
        print(self.result_df.head())
        print("Log")
        print(self.log_df.head())
        resultname = 'result-'+time.strftime("%Y%d%m")+'.csv'
        logname = 'log-'+time.strftime("%Y%d%m")+'.csv'
        output = {'result': self.result_df.to_numpy(), 
              'log': self.log_df.to_numpy(), 
              'resultname': resultname, 
              'logname': logname}
        return output

    def save_output(self):
        if(self._extracted):
            self.result_df.to_csv("output/result-"+time.strftime("%Y%d%m")+".csv", index=False)
            self.log_df.to_csv("output/log-"+time.strftime("%Y%d%m")+".csv", index=False)
        else :
            print("No file to save")
if __name__ == "__main__":
    if(len(sys.argv[1:])==0):
            print("Please enter valid number of arguements")
    filenames=  [ ]
    for i in sys.argv[1:]:
        filenames.append(i)
    extractor = FeatureExtractor(filenames)
    extractor.getDataFrames()
    extractor.save_output()
    print("Files Saved")


