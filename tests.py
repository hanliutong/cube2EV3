
import os
import unittest
import dataParse
import json
def readTestSet(path):
    with open(path, 'r') as f:
        data = json.loads(f.read())
        return data

class Cube2arrTest(unittest.TestCase):
    def test_rgb2arr(self):
        path = 'testset/' #测试集文件夹
        files= os.listdir(path)
        for file in files: #遍历文件夹
            if not os.path.isdir(file): #判断是否是文件夹，不是文件夹才打开
                data = readTestSet(path+file)
                if file.startswith("e_"): #以e_开头，应抛出异常
                    self.assertRaises(UserWarning, dataParse.color2array, data)
                elif file.startswith("t_"): #以t_开头，与ans比对
                    self.assertTrue((data['ans'] == dataParse.color2array(data)))

if __name__ == '__main__':
    unittest.main()