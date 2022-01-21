first_version = input(str("Enter first version - "))
second_version = input(str("Enter second version - "))
l_first = first_version.split(".")
l_second = second_version.split(".")
for i in range(len(l_first)):
    l_first[i] = int(l_first[i])
for i in range(len(l_second)):
    l_second[i] = int(l_second[i])
if(len(l_first) < len(l_second)):
    flag = 0
    for i in range(len(l_first)):
        if(l_first[i] == l_second[i]):
            continue
        if(l_first[i] > l_second[i]):
            flag = 1
            break
        if(l_first[i] < l_second[i]):
            flag = 2
            break
    if(flag == 1):
        print("First version is latest.")
    elif(flag == 2):
        print("Second version is latest.")
    else:
        print("Second version is latest.")
elif(len(l_first) > len(l_second)):
    flag = 0
    for i in range(len(l_second)):
        if(l_first[i] == l_second[i]):
            continue
        if(l_first[i] > l_second[i]):
            flag = 2
            break
        if(l_first[i] < l_second[i]):
            flag = 1
            break
    if(flag == 1):
        print("Second version is latest.")
    elif(flag == 2):
        print("First version is latest.")
    else:
        print("First version is latest.")
else:
    for i in range(len(l_first)):
        if(l_first[i] == l_second[i]):
            continue
        if(l_first[i] > l_second[i]):
            flag = 1
            break
        if(l_first[i] < l_second[i]):
            flag = 2
            break
    if(flag == 1):
        print("First version is latest.")
    elif(flag == 2):
        print("Second version is latest.")
