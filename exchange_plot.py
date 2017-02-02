
import urllib
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.ticker as mtick
import datetime
import matplotlib.dates as md
import dateutil


fig,ax=plt.subplots()
ax.yaxis.set_major_formatter(mtick.FormatStrFormatter('%1.4f'))

x=[]
y=[]
i=0

plt.ion()
xfmt = md.DateFormatter('%H:%M:%S')
ax.xaxis.set_major_formatter(xfmt)
plt.xticks(rotation=25)

while i <50:
    url = urllib.urlopen("http://finance.yahoo.com/d/quotes.csv?f=l1d1t1&s=USDTRY=X")
    result = url.read()
    temp_y=result.split(',')[0]
    print i, temp_y, len(x)
    data_time=datetime.datetime.now()

    x.append(data_time)
    y.append(temp_y)

    ax.plot(x,y,marker='.',linestyle='-')
    i+=1
    plt.pause(5)

