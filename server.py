import socket
from datetime import datetime, timedelta
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import csv
import time

s = socket.socket()         
 
s.bind(('192.168.0.29', 8082 ))
s.listen(0)                 
print("hello from server")
ekg_content = list()
times = list()
czas_pobrania = 4

start = time.time()
while len(ekg_content)<1000:
 
    client, addr = s.accept()

    while True :
        content = client.recv(4)
        # client.send(wiadomosc.encode())
        if len(content) ==0:
           break
 
        else:
            print(int(content.decode()))
            ekg_content.append(int(content.decode()))
            times.append(time.time())
            
    client.close()   
      
    
end = time.time()
print(end-start)
print("got signal")

plt.plot(ekg_content)
plt.show()
 
with open('test.csv', 'w+', newline='') as f:
    # data = list(csv.writer(f))
    writer = csv.writer(f)
    writer.writerow(times)
    writer.writerow(ekg_content)
    

   
