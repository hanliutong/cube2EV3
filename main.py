import graph
import dataParse



if __name__=='__main__':
    while True:
        r=graph.captureGraph()
        if dataParse.parse(r):
            break
        else:
            print('拍照有误，请重新拍照')
