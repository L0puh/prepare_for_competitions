'''
нужно помнить, что позиция 
каждый раз увеличиватся.
то есть нужно начинать с УВЕЛИЧЕННОЙ 
позиции, а не поцизия + 1.
это была моя первая ошибка. (хотя
алгоритм работал для малых чисел).
ВАЖНО!! проверять на всех, вручную.
воспроизводить, рисовать и прочее.
находить уязвимые моменты, иначе крах!!

решение из сириуса во много раз элигантнее:
n = int (input( ))
if n < 4:
    print(-1)
else:
    print ((n-1+4)//5)

однако мое решение мне более понятнее, чем это
'''

def move_frog(n):
    return n+2, n+3 

def move_grass_hopper(n):
    return n-1, n-2

def main():
    n = int(input()) 
    times_frog = []
    times_grass= []
    f = 0 
    g = n
    # all positions where they can be at! 
    for i in range(1, n):
        for k in move_frog(f):
            f = k
            times_frog.append([f, i])
        for k in move_grass_hopper(g):
            g = k
            times_grass.append([g, i])
    # find equal positions. and print the time
    for i in range(n):
        if times_frog[i][0] == times_grass[i][0]:
            print(times_frog[i][1])
            break

if __name__ == "__main__":
    main()
