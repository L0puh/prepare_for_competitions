"""
проблема была, что я не проверела
четные элементы (а они не попадали под
мое решение.) поэтому программа работала 
лишь на половину.
еще раз, нельзя торопиться!
лучше проверить для всех вариантов
так сесть и написать, каждый 
кейс, желательно до 10 минимум.
я бы увидела, что при четных
числах создается прямоугольник 
в центре, координаты которого 
нужно умножить 

решение сириуса:
(как всегда сложное)
if n > m:
    n,m = m,n
if n % 2 == 1 :
    print(m-n+1 )
else:
    print(2*(m-n+2))
однако 60 баллов в кармане :DD
"""

def main():
    n = int(input()) 
    m = int(input())
    target = False
    if n % 2 == 0 or m % 2 == 0:
        target = True
    while m-2 > 0 and n-2 > 0:
        m=m-2
        n=n-2
    if target: print(n*m)
    else: print(max(n, m))

if __name__ == "__main__":
    main()