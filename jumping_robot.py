n = int(input("n: "))
f = int(input("f: "))
d = [0] * n

if f == 1:
    d= list(map(int, input("d: \n").split(" ")))
else:
    m, x, y, z = map(int, input().split(" "))
    c = list(map(int, input("d: \n").split(" ")))
    for i in range(n):
        if m <= i and i <= n:
            d[i] = ((x* d[i-2] + y * d[i-1] + z) % pow(10, 9)) + 1
        elif  m-1 >= i: 
            d[i] = c[i]

ans = 0
pos = 0
j = 1
d+=d
# перебор всех значений ловкости
# начиная с 1
# если дистанция, больше
# ловкости, увеличиваем 
# ловкость
while True:
    target = False
    for i in range(n):
        a = j
        target = True
        for k in range(n):
            # если нельзя прыгнуть на следующую платформу оно делает брейк
            # иначе прибавляет ловкость на 1
            if not a >= d[i+k]:
                target = False
                break
            a+=1
        if target:
            # если не было прерываний для этой ловкости, 
            # то значит это минимальный ответ!
            # присваеваем ловкость j, а позицию текущей платформе i
            ans = j
            pos = i
            break
    if target:
        # для минимальной позиции, можно после нахождения сразу же прервать
        break 
    # если нет такой позиции, прибавляем ловкость на 1
    j+=1

print(ans, pos+1)

