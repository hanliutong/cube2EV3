import cv2
import numpy as np

def judgeColor(hsv):
    h,s,v=hsv[0],hsv[1],hsv[2]
    if h>=24 and h<=45 and s>=43 and s<=255 and v>=46 and v<=255:
        return 'Y'
    elif h>=0 and h<=180 and s>=0 and s<=105 and v>=155 and v<=255:
        return 'W'
    elif h>=156 and h<=180 and s>=43 and s<=255 and v>=46 and v<=255:
        return 'R'
    elif h>=0 and h<=5 and s>=43 and s<=255 and v>=46 and v<=255:
        return 'R'
    elif h>=45 and h<=86 and s>=43 and s<=255 and v>=46 and v<=255:
        return 'G'
    #elif h>=170 and h<=180 and s>=43 and s<=255 and v>=46 and v<=255:
        #return 'O'
    elif h>=6 and h<=23 and s>=43 and s<=255 and v>=46 and v<=255:
        return 'O'
    elif h>=100 and h<=124 and s>=43 and s<=255 and v>=46 and v<=255:
        return 'B'

def findMost(y,x,hsv):
    tempData={'B':0,'G':0,'W':0,'Y':0,'O':0,'R':0}
    for i in range(-5,6):
        for j in range(-5,6):
            #print(str(x+i)+'---'+str(y+i))
            #print(judgeColor(hsv[x+i,y+i]))
            t = judgeColor(hsv[x+i,y+i])
            if t in tempData.keys():
                tempData[t]+=1
    flag = -1
    k = ''
    for key, value in tempData.items():
        #print(tempData.get(key))
        if value > flag:
            flag = value
            k = key
    return k

def solve(hsv):
    result=[]
    result.append(findMost(225,145,hsv))
    result.append(findMost(295,145,hsv))
    result.append(findMost(365,145,hsv))
    result.append(findMost(225,215,hsv))
    result.append(findMost(295,215,hsv))
    result.append(findMost(365,215,hsv))
    result.append(findMost(225,285,hsv))
    result.append(findMost(295,285,hsv))
    result.append(findMost(365,285,hsv))
    return result

def check_dic(n):
    for v in n.values():
        if v == '#':
            return False
    return True

def colorToRGB(color):
    if color=='W':
        return [255,255,255]
    elif color=='B':
        return [0,0,255]
    elif color=='G':
        return [0,205,0]
    elif color=='Y':
        return [255,255,0]
    elif color=='R':
        return [205,0,0]
    elif color=='O':
        return [255,165,0]
    else:
        return [0,0,0]

def tips(n):
    if n==0:
        print('中间块绿色朝摄像头，白色朝上')
    elif n==1:
        print('中间块红色朝摄像头，白色朝上')
    elif n==2:
        print('中间块橙色朝摄像头，白色朝上')
    elif n==3:
        print('中间块蓝色朝摄像头，黄色朝上')
    elif n==4:
        print('中间块黄色朝摄像头，绿色朝上')
    elif n==5:
        print('中间块白色朝摄像头，蓝色朝上')
def showTem(tempSolve,frame):
    l=50
    RGB=colorToRGB(tempSolve[0])
    cv2.rectangle(frame, (461,101), (509,149), (RGB[2],RGB[1],RGB[0]), -1)
    RGB=colorToRGB(tempSolve[1])
    cv2.rectangle(frame, (461+l,101), (509+l,149), (RGB[2],RGB[1],RGB[0]), -1)
    RGB=colorToRGB(tempSolve[2])
    cv2.rectangle(frame, (461+2*l,101), (509+2*l,149), (RGB[2],RGB[1],RGB[0]), -1)
    RGB=colorToRGB(tempSolve[3])
    cv2.rectangle(frame, (461,101+l), (509,149+l), (RGB[2],RGB[1],RGB[0]), -1)
    RGB=colorToRGB(tempSolve[4])
    cv2.rectangle(frame, (461+l,101+l), (509+l,149+l), (RGB[2],RGB[1],RGB[0]), -1)
    RGB=colorToRGB(tempSolve[5])
    cv2.rectangle(frame, (461+2*l,101+l), (509+2*l,149+l), (RGB[2],RGB[1],RGB[0]), -1)
    RGB=colorToRGB(tempSolve[6])
    cv2.rectangle(frame, (461,101+2*l), (509,149+2*l), (RGB[2],RGB[1],RGB[0]), -1)
    RGB=colorToRGB(tempSolve[7])
    cv2.rectangle(frame, (461+l,101+2*l), (509+l,149+2*l), (RGB[2],RGB[1],RGB[0]), -1)
    RGB=colorToRGB(tempSolve[8])
    cv2.rectangle(frame, (461+2*l,101+2*l), (509+2*l,149+2*l), (RGB[2],RGB[1],RGB[0]), -1)
def captureGraph():
    fflag=True
    result = {'O':'#','B':'#','R':'#','Y':'#','W':'#','G':'#'}
    #获取摄像头视频
    cap = cv2.VideoCapture(0)
    # 获取视频宽度
    frame_width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    #frame_width = 100
    # 获取视频高度
    frame_height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
    #frame_height = 100
    long=70
    num=0
    tempSolve=['X','X','X','X','X','X','X','X','X']
    c=0
    print('输入s进行捕获，输入q退出')
    tips(c)
    while (cap.isOpened()):
        ret,frame = cap.read()  
        cv2.rectangle(frame, (180,100), (180+long,100+long), (0,255,0), 2)
        cv2.rectangle(frame, (180+long,100), (180+2*long,100+long), (0,255,0), 2)
        cv2.rectangle(frame, (180+2*long,100), (180+3*long,100+long), (0,255,0), 2)
        cv2.rectangle(frame, (180,100+long), (180+long,100+2*long), (0,255,0), 2)
        cv2.rectangle(frame, (180+long,100+long), (180+2*long,100+2*long), (0,255,0), 2)
        cv2.rectangle(frame, (180+2*long,100+long), (180+3*long,100+2*long), (0,255,0), 2)
        cv2.rectangle(frame, (180,100+2*long), (180+long,100+3*long), (0,255,0), 2)
        cv2.rectangle(frame, (180+long,100+2*long), (180+2*long,100+3*long), (0,255,0), 2)
        cv2.rectangle(frame, (180+2*long,100+2*long), (180+3*long,100+3*long), (0,255,0), 2)
        cv2.putText(frame,'Identify Results',(440,80),cv2.FONT_HERSHEY_SIMPLEX,0.8,(55,255,155),2)
        showTem(tempSolve,frame)
        cv2.imshow("real_time",frame)
        k = cv2.waitKey(1) & 0xFF
        if k == ord('q'):
            fflag=False
            break
        elif k == ord('s'):
            img=frame
            hsv=cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
            tempSolve=solve(hsv)
            print(tempSolve)
            num+=1
            #print('capture'+str(num))
            print('解析是否正确，若正确输入y,错误则进行重新按获取图像即可')
        elif k == ord('y'):
            if result[tempSolve[4]]=='#':
                c+=1
                tips(c)
                result[tempSolve[4]]=tempSolve
                cv2.imshow("real_time",frame)
                #print('当前存储的数据信息:')
                #print(result)
                #print('\n')
            else:
                print('该面已经拍照,无需重复拍照')
        if check_dic(result):
            break
    cap.release()
    cv2.destroyAllWindows()
    print(result)
    if fflag==True:
        return result
    else:
        return 'q'
