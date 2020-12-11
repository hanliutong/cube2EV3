import graph
import dataParse



if __name__=='__main__':
    flag=0
    while True:
        r=graph.captureGraph(flag)
        if dataParse.parse(r):
            break
        else:
            flag=1
            print('拍照有误，请重新拍照')
