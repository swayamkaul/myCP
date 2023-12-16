from asyncore import write
import time
import os
import glob
import csv
csvFile = open('data.csv', 'w')
writer = csv.writer(csvFile)
writer.writerow(["Number of files", "Time Taken"])
startTime = time.time()
path = 'files'
filesScanned = 0
for filename in glob.glob(os.path.join(path, '*.txt')):
    filesScanned += 1
    if filesScanned % 100 == 0:
        writer.writerow([filesScanned, time.time() - startTime])
    with open(os.path.join(os.getcwd(), filename), 'r') as f:
        lines = f.readlines()
        for line in lines:
            upperCase = line.upper()
csvFile.close()