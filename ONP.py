# Irshad PI, GECTCR 
# about any  doubts, contact : irshadpi77@gmail.com
op=['+','-','*','/','^']
def priority(c):
	for i in range(0,5):
		if(c==op[i]):
			return i
for T in range(int(raw_input())):
	s=raw_input()
	a=[]
	res=[]
	for i in s:
		if(i>='a' and i<='z'):
			res.append(i)
		elif(i=='('):
			a.append(i)
		elif(i in op):
			if(len(a)>0):
				opr=a.pop()
				while(len(a)!=0):
					if(priority(opr)<priority(i)):
						break
					res.append(opr)
					opr=a.pop()
				a.append(opr)
			a.append(i)
		elif(i==')'):
			while(len(a)!=0):
				opr=a.pop()
				if(opr=='('):
					break
				res.append(opr)
	print(''.join(res+a[::-1]))




