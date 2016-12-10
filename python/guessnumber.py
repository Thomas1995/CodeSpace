from random import randint

class GameMaster:
    def __init__(self):
        self.__chooseNumber()
    def __chooseNumber(self):
        self.number = randint(1,100)
    def isLowerThan(self, num):
        return self.number < num
    def isBiggerThan(self, num):
        return self.number > num
    def isEqualTo(self, num):
        return self.number == num

if __name__ == "__main__":
    gm = GameMaster()
    i = 0
    while True:
        i += 1
        input = raw_input("%d: " % i)
        myNumber = int(input[1:])
        if input[0] == '<': print gm.isLowerThan(myNumber)
        if input[0] == '>': print gm.isBiggerThan(myNumber)
        if input[0] == '=':
            print gm.isEqualTo(myNumber)
            if gm.isEqualTo(myNumber):
                print "%d was the chosen number!" % myNumber
                break
