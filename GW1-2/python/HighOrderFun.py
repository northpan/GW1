HighOrdertwo = (lambda a,b,f : f(a,b))(3,4,(lambda c,d :c+d))#二阶函数
HighOrderthree = (lambda a,b,f,g: g(f(a,b),a+2))(3,4,(lambda c,d :c+d),(lambda e,f:e*f))#三阶函数
print("HighOrdertwo is: ",HighOrdertwo," and","HighOrderthree: ",HighOrderthree)
