import win32con
import win32gui
from pymouse import *
from pykeyboard import *
import time

def reset_window_pos(targetTitle):
    hWndList = []
    win32gui.EnumWindows(lambda hWnd, param: param.append(hWnd), hWndList)
    for hwnd in hWndList:
          clsname = win32gui.GetClassName(hwnd)
          title = win32gui.GetWindowText(hwnd)
          if (title.find(targetTitle) >= 0): #调整目标窗口到坐标(600,300),大小设置为(600,600)
              win32gui.SetWindowPos(hwnd, win32con.HWND_TOPMOST, 0,0,1280,1280, win32con.SWP_SHOWWINDOW)

##-------main-------##
reset_window_pos("ROBOTC-Trial")

m = PyMouse()
#k = PyKeyboard()
a = m.position()
print(a)

steps = "L "
m.click(507,421)
'''
for x in steps:
    k.tap_key(x)
    time.sleep(0.01)

m.click(794, 75) ##下载
time.sleep(3)
m.click(556, 470) ##运行
'''
