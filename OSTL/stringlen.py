def stringl(x,y):
	if(len(x)<=len(y)):
		return(x)
	else:
		return(y)

a=str(input("entr string\n"))
b=str(input("enter string\n"))

print("the shortest strinf is",stringl(a,b))
