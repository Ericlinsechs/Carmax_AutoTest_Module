import requests
import pandas as pd
import numpy as np
from bs4 import BeautifulSoup

day = []
time = []
amp = []
unit = []

r = requests.get('http://192.168.43.122/') #將此頁面的HTML GET下來
# print(r.text) #印出HTML

data_title = ['a', 'd', 't']
def search_data(css_class):
    global data_title
    if(css_class != None):
        for i in range(len(data_title)):
            if data_title[i] in css_class:
                return css_class

soup = BeautifulSoup(r.text,'html.parser') #將網頁資料以html.parser
header_Info = soup.find_all(["a", "d", "t"])
# for item in header_Info:
    # print(item)

arr = header_Info[0].text
arr = arr.replace("mA",'')
arr = arr.replace("&nbsp", ' ')
arr = " ".join(arr.split())
arr = arr.split(' ')
# print (arr)

for i in range(0, 30, 3):
    day.append(arr[i])
    time.append(arr[i+1])
    amp.append(arr[i+2])
# print(day, time, amp)

for i in range(0, 10):
    unit.append('mA')
conbin = np.c_[day,time, amp, unit]
# print(conbin)

df = pd.DataFrame(conbin)
df.columns = ["Day", "Time", "Amp", "Unit"]
print(df)

df.to_csv('D:\\\Carmax_Emirror_Program\\emirror_current.csv',
                mode='a', header=False, index=False)
