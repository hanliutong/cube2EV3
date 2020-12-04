import cv2
import numpy as np
import requests
import win32gui
import win32api
import win32con
from pymouse import *
from pykeyboard import *
from win32con import KEYEVENTF_KEYUP
from win32api import keybd_event
import time
from PIL import ImageGrab
from aip import AipOcr
import xlwt


def judgeColor(hsv):
    h,s,v=hsv[0],hsv[1],hsv[2]
    if h>=24 and h<=45 and s>=43 and s<=255 and v>=46 and v<=255:
        return 'Y'
    elif h>=0 and h<=180 and s>=0 and s<=105 and v>=155 and v<=255:
        return 'W'
    elif h>=156 and h<=169 and s>=43 and s<=255 and v>=46 and v<=255:
        return 'R'
    elif h>=0 and h<=5 and s>=43 and s<=255 and v>=46 and v<=255:
        return 'R'
    elif h>=45 and h<=86 and s>=43 and s<=255 and v>=46 and v<=255:
        return 'G'
    elif h>=170 and h<=180 and s>=43 and s<=255 and v>=46 and v<=255:
        return 'O'
    elif h>=6 and h<=23 and s>=43 and s<=255 and v>=46 and v<=255:
        return 'O'
    elif h>=100 and h<=124 and s>=43 and s<=255 and v>=46 and v<=255:
        return 'B'
    return 'X'

def findMost(y,x):
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

def solve():
    result=[]
    result.append(findMost(225,145))
    result.append(findMost(295,145))
    result.append(findMost(365,145))
    result.append(findMost(225,215))
    result.append(findMost(295,215))
    result.append(findMost(365,215))
    result.append(findMost(225,285))
    result.append(findMost(295,285))
    result.append(findMost(365,285))
    return result

def solve3(c1,c2,c3):
    t=[c1,c2,c3]
    if 'B' in t and 'W' in t and 'O' in t:
        return{'W':'2','O':'20','B':'44'}
    elif 'B' in t and 'W' in t and 'R' in t:
        return{'W':'8','R':'35','B':'38'}
    elif 'O' in t and 'W' in t and 'G' in t:
        return{'W':'0','O':'26','G':'47'}
    elif 'G' in t and 'W' in t and 'R' in t:
        return{'W':'6','R':'29','G':'53'}
    elif 'B' in t and 'O' in t and 'Y' in t:
        return{'Y':'9','O':'18','B':'42'}
    elif 'B' in t and 'R' in t and 'Y' in t:
        return{'Y':'15','R':'33','B':'36'}
    elif 'G' in t and 'O' in t and 'Y' in t:
        return{'Y':'11','O':'24','G':'45'}
    elif 'G' in t and 'R' in t and 'Y' in t:
        return{'Y':'17','G':'51','R':'27'}
    return False

def solve2(c1,c2):
    t=[c1,c2]
    if 'W' in t and 'B' in t:
        return{'W':'5','B':'41'}
    elif 'W' in t and 'O' in t:
        return{'W':'1','O':'23'}
    elif 'W' in t and 'G' in t:
        return{'W':'3','G':'50'}
    elif 'W' in t and 'R' in t:
        return{'W':'7','R':'32'}
    elif 'O' in t and 'B' in t:
        return{'O':'19','B':'43'}
    elif 'O' in t and 'G' in t:
        return{'O':'25','G':'46'}
    elif 'R' in t and 'B' in t:
        return{'R':'34','B':'37'}
    elif 'R' in t and 'G' in t:
        return{'R':'28','G':'52'}
    elif 'Y' in t and 'B' in t:
        return{'Y':'12','B':'39'}
    elif 'Y' in t and 'O' in t:
        return{'Y':'10','O':'21'}
    elif 'Y' in t and 'G' in t:
        return{'Y':'14','G':'48'}
    elif 'Y' in t and 'R' in t:
        return{'Y':'16','R':'30'}
    return False

def solve1(c):
    if c=='W':
        return '4'
    elif c=='Y':
        return '13'
    elif c=='B':
        return '40'
    elif c=='O':
        return '22'
    elif c=='R':
        return '31'
    elif c=='G':
        return '49'
    return False

def sss(n,f):
        t=solve3(n.get('G')[0],n.get('W')[6],n.get('O')[2])
        if t == False:
            print('输入有误')
            return False
        f.get('G')[0]=t.get(n.get('G')[0])
        f.get('W')[6]=t.get(n.get('W')[6])
        f.get('O')[2]=t.get(n.get('O')[2])
        t=solve3(n.get('G')[2],n.get('R')[0],n.get('W')[8])
        if t == False:
            print('输入有误')
            return False
        f.get('G')[2]=t.get(n.get('G')[2])
        f.get('R')[0]=t.get(n.get('R')[0])
        f.get('W')[8]=t.get(n.get('W')[8])
        t=solve3(n.get('G')[6],n.get('O')[8],n.get('Y')[0])
        if t == False:
            print('输入有误')
            return False
        f.get('G')[6]=t.get(n.get('G')[6])
        f.get('O')[8]=t.get(n.get('O')[8])
        f.get('Y')[0]=t.get(n.get('Y')[0])
        t=solve3(n.get('G')[8],n.get('Y')[2],n.get('R')[6])
        if t == False:
            print('输入有误')
            return False
        f.get('G')[8]=t.get(n.get('G')[8])
        f.get('Y')[2]=t.get(n.get('Y')[2])
        f.get('R')[6]=t.get(n.get('R')[6])
        t=solve3(n.get('B')[8],n.get('R')[2],n.get('W')[2])
        if t == False:
            print('输入有误')
            return False
        f.get('B')[8]=t.get(n.get('B')[8])
        f.get('R')[2]=t.get(n.get('R')[2])
        f.get('W')[2]=t.get(n.get('W')[2])
        t=solve3(n.get('B')[6],n.get('W')[0],n.get('O')[0])
        if t == False:
            print('输入有误')
            return False
        f.get('B')[6]=t.get(n.get('B')[6])
        f.get('W')[0]=t.get(n.get('W')[0])
        f.get('O')[0]=t.get(n.get('O')[0])
        t=solve3(n.get('B')[2],n.get('R')[8],n.get('Y')[8])
        if t == False:
            print('输入有误')
            return False
        f.get('B')[2]=t.get(n.get('B')[2])
        f.get('R')[8]=t.get(n.get('R')[8])
        f.get('Y')[8]=t.get(n.get('Y')[8])
        t=solve3(n.get('B')[0],n.get('O')[6],n.get('Y')[6])
        if t == False:
            print('输入有误')
            return False
        f.get('B')[0]=t.get(n.get('B')[0])
        f.get('O')[6]=t.get(n.get('O')[6])
        f.get('Y')[6]=t.get(n.get('Y')[6])
        t=solve2(n.get('G')[1],n.get('W')[7])
        if t == False:
            print('输入有误')
            return False
        f.get('G')[1]=t.get(n.get('G')[1])
        f.get('W')[7]=t.get(n.get('W')[7])
        t=solve2(n.get('G')[3],n.get('O')[5])
        if t == False:
            print('输入有误')
            return False
        f.get('G')[3]=t.get(n.get('G')[3])
        f.get('O')[5]=t.get(n.get('O')[5])
        t=solve2(n.get('G')[5],n.get('R')[3])
        if t == False:
            print('输入有误')
            return False
        f.get('G')[5]=t.get(n.get('G')[5])
        f.get('R')[3]=t.get(n.get('R')[3])
        t=solve2(n.get('G')[7],n.get('Y')[1])
        if t == False:
            print('输入有误')
            return False
        f.get('G')[7]=t.get(n.get('G')[7])
        f.get('Y')[1]=t.get(n.get('Y')[1])
        t=solve2(n.get('W')[3],n.get('O')[1])
        if t == False:
            print('输入有误')
            return False
        f.get('W')[3]=t.get(n.get('W')[3])
        f.get('O')[1]=t.get(n.get('O')[1])
        t=solve2(n.get('W')[5],n.get('R')[1])
        if t == False:
            print('输入有误')
            return False
        f.get('W')[5]=t.get(n.get('W')[5])
        f.get('R')[1]=t.get(n.get('R')[1])
        t=solve2(n.get('Y')[3],n.get('O')[7])
        if t == False:
            print('输入有误')
            return False
        f.get('Y')[3]=t.get(n.get('Y')[3])
        f.get('O')[7]=t.get(n.get('O')[7])
        t=solve2(n.get('Y')[5],n.get('R')[7])
        if t == False:
            print('输入有误')
            return False
        f.get('Y')[5]=t.get(n.get('Y')[5])
        f.get('R')[7]=t.get(n.get('R')[7])
        t=solve2(n.get('B')[7],n.get('W')[1])
        if t == False:
            print('输入有误')
            return False
        f.get('B')[7]=t.get(n.get('B')[7])
        f.get('W')[1]=t.get(n.get('W')[1])
        t=solve2(n.get('B')[5],n.get('R')[5])
        if t == False:
            print('输入有误')
            return False
        f.get('B')[5]=t.get(n.get('B')[5])
        f.get('R')[5]=t.get(n.get('R')[5])
        t=solve2(n.get('B')[3],n.get('O')[3])
        if t == False:
            print('输入有误')
            return False
        f.get('B')[3]=t.get(n.get('B')[3])
        f.get('O')[3]=t.get(n.get('O')[3])
        t=solve2(n.get('B')[1],n.get('Y')[7])
        if t == False:
            print('输入有误')
            return False
        f.get('B')[1]=t.get(n.get('B')[1])
        f.get('Y')[7]=t.get(n.get('Y')[7])
        f.get('G')[4]=solve1(n.get('G')[4])
        f.get('O')[4]=solve1(n.get('O')[4])
        f.get('R')[4]=solve1(n.get('R')[4])
        f.get('W')[4]=solve1(n.get('W')[4])
        f.get('Y')[4]=solve1(n.get('Y')[4])
        f.get('B')[4]=solve1(n.get('B')[4])
        return True

def output(f):
	t=[]
	for i in f.get('W'):
		t.append(int(i))
	for i in f.get('Y'):
		t.append(int(i))
	for i in f.get('O'):
		t.append(int(i))
	for i in f.get('R'):
		t.append(int(i))
	for i in f.get('B'):
		t.append(int(i))
	for i in f.get('G'):
		t.append(int(i))
	return t

def check_dic(n):
    for v in n.values():
        if v == '#':
            return False
    return True

def reset_window_pos(targetTitle):
    hWndList = []
    win32gui.EnumWindows(lambda hWnd, param: param.append(hWnd), hWndList)
    for hwnd in hWndList:
          clsname = win32gui.GetClassName(hwnd)
          title = win32gui.GetWindowText(hwnd)
          if (title.find(targetTitle) >= 0): #调整目标窗口到坐标(600,300),大小设置为(600,600)
              win32gui.SetWindowPos(hwnd, win32con.HWND_TOPMOST, 0,0,1280,1280, win32con.SWP_SHOWWINDOW)

def auto_run(steps):
    reset_window_pos("ROBOTC-Trial")
    m = PyMouse()
    k = PyKeyboard()
    a = m.position()
    print(a)

    m.click(505, 419)

    for x in steps:
        k.tap_key(x)
        time.sleep(0.01)

    m.click(794, 75) ##下载
    m.click(556, 470) ##运行

if __name__=='__main__':
    while True:
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
        tempSolve=''
        print('输入s进行捕获，输入q退出')
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
            cv2.imshow("real_time",frame)
            k = cv2.waitKey(1) & 0xFF
            if k == ord('q'):
                fflag=False
                break
            elif k == ord('s'):
                img=frame
                hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
                tempSolve=solve()
                print(tempSolve)
                num+=1
                print('capture'+str(num))
                print('解析是否正确，若正确输入y,错误则进行重新获取图像即可')
            elif k == ord('y'):
                if result[tempSolve[4]]=='#':
                    result[tempSolve[4]]=tempSolve
                    print('当前存储的数据信息:')
                    print(result)
                    print('\n')
                else:
                    print('该面已经拍照,无需重复拍照')
            if check_dic(result):
                break
        cap.release()
        cv2.destroyAllWindows()
        print(result)
        originData={'W':['#' for i in range(9)],'Y':['#' for i in range(9)],'B':['#' for i in range(9)],\
        'G':['#' for i in range(9)],'O':['#' for i in range(9)],'R':['#' for i in range(9)]}
        if fflag == False:
            break
        if sss(result,originData):
            r=output(originData)
            print(r)
            post=requests.post("39.97.212.230:8080/cube2arr", data=r, headers={"Content-Type": "none"})
            break
        else:
            pass
        
        
    
    
