if __name__ == '__main__':
    n = int(input())
    if(n>20):
        print("Not Weird")
    elif(n>6 and n%2==0):
        print("Weird")
    elif(2<n<5 and n%2==0):
        print("Not Weird")
    elif(n%2!=0):
        print("Weird")