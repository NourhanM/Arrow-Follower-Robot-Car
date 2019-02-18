import cv2
import numpy as np
import serial
import urllib

arduinoData = serial.Serial("COM6", 9600)
directions = ["left.png", "right.png", "stop.png"]
motor_dir = ['l', 'r', 's', 'f']
arduinoData.write(motor_dir[4])

while True:
    arduino = arduinoData.read()
    ar = arduino.decode('utf-8')
    print(ar)

    if ar == 'q':
        url = "http://192.168.43.1:8080/photo.jpg"
        img = np.array(bytearray((urllib.urlopen(url)).read()), dtype = "uint8")
        img = cv2.imdecode(img, cv2.IMREAD_COLOR)
        for i in directions:
            template = cv2.imread(i,0)
            gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
            w, h = template.shape[::-1]
            res = cv2.matchTemplate(gray, template, cv2.TM_CCOEFF_NORMED)
            threshold = 0.8
            loc = np.where(res >= threshold)
            for pt in zip(*loc[::-1]):
                cv2.rectangle(img, pt, (pt[0]+w,pt[1]+h), (0, 255, 255), 2)
                if i==directions[0]:
                    arduinoData.write(motor_dir[0])
                    print('left')
                    break
                elif i == directions[1]:
                    arduinoData.write(motor_dir[1])
                    print('right')
                    break
                else:
                    arduinoData.write(motor_dir[2])
                    print('stop')

            cv2.imshow('detected',img)
            if cv2.waitKey(1) & 0xFF == 27:
                break
cv2.destroyAllWindows()

             
                    
