import os

while True:
    while True:
        chapter = input("단원: ")
        chapterName = input("단원명: ")
        n = int(input("문제 갯수: "))
        if input("진행하시겠습니까(y or n): ") == "y": break

    os.makedirs(os.path.join(f"ch{chapter}_{chapterName}"))
    
    for i in range(n):
        with open(f'ch{chapter}_{chapterName}/{chapter}-{i+1}.cpp', 'w') as f:
            f.write("")
    
    if input("다시 실행(y or n): ") == 'n':
        break
    
print("End!")
