import graph
import dataParse



if __name__=='__main__':
    flag=0
    while True:
        r=graph.captureGraph(flag)
#         r = {
#     "O": ["O", "O", "O", "R", "O", "O", "O", "Y", "B"], 
#     "B": ["Y", "G", "B", "B", "B", "O", "B", "B", "B"], 
#     "R": ["R", "R", "R", "Y", "R", "G", "Y", "G", "Y"], 
#     "Y": ["R", "Y", "G", "R", "Y", "Y", "G", "R", "O"], 
#     "W": ["W", "W", "W", "W", "W", "W", "W", "W", "W"], 
#     "G": ["G", "G", "G", "B", "G", "O", "Y", "B", "R"]
# }

        try:
            step_str = dataParse.parse(r)
        except UserWarning:
            flag=1
            print('拍照有误，请重新拍照')
        else :
            fo = open("code/step.h", "w")
            str = "char step[] = \"" + step_str + "\";"
            fo.write(str)
            exit(0)
