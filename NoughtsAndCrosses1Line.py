while(not any(s.issubset(max((w:=w if'w'in globals()else[set(),set()]),key=len))for s in[{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}])or(print(str(['x','o'][w.index(max(w, key=len))])+' won'))):min(w,key=len).add(next(x for _ in iter(int, 1)if(x:=int(input('''where do you want to place your piece?\n1|2|3\n-+-+-\n4|5|6\n-+-+-\n7|8|9\n'''.replace('1',['1','x'][1 in w[0]]).replace('2',['2','x'][2 in w[0]]).replace('3',['3','x'][3 in w[0]]).replace('4',['4','x'][4 in w[0]]).replace('5',['5','x'][5 in w[0]]).replace('6',['6','x'][6 in w[0]]).replace('7',['7','x'][7 in w[0]]).replace('8',['8','x'][8 in w[0]]).replace('9',['9','x'][9 in w[0]]).replace('1',['1','o'][1 in w[1]]).replace('2',['2','o'][2 in w[1]]).replace('3',['3','o'][3 in w[1]]).replace('4',['4','o'][4 in w[1]]).replace('5',['5','o'][5 in w[1]]).replace('6',['6','o'][6 in w[1]]).replace('7',['7','o'][7 in w[1]]).replace('8',['8','o'][8 in w[1]]).replace('9',['9','o'][9 in w[1]]))))not in(w[0]|w[1])))

input() #just so when run it doesn't auto close
exit()

#Explanation:

#There are 2 condition here
#The first one chacks if somone has won
#There second is only evaluated when somone has won sice 
while (
    not any(s.issubset(max((w:=w if'w'in globals()else[set(),set()]),key=len))
            for s in[{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}])
    or
    (print(str(['x','o'][w.index(max(w, key=len))])+' won'))):
#In the main loop the player with the least moves (whos turn it is next) is selected and they give their move.
    min(w,key=len).add(next(x for _ in iter(int, 1)if(x:=int(
        input('''where do you want to place your piece?\n1|2|3\n-+-+-\n4|5|6\n-+-+-\n7|8|9\n'''.replace('1',['1','x'][1 in w[0]]).replace('2',['2','x'][2 in w[0]]).replace('3',['3','x'][3 in w[0]]).replace('4',['4','x'][4 in w[0]]).replace('5',['5','x'][5 in w[0]]).replace('6',['6','x'][6 in w[0]]).replace('7',['7','x'][7 in w[0]]).replace('8',['8','x'][8 in w[0]]).replace('9',['9','x'][9 in w[0]]).replace('1',['1','o'][1 in w[1]]).replace('2',['2','o'][2 in w[1]]).replace('3',['3','o'][3 in w[1]]).replace('4',['4','o'][4 in w[1]]).replace('5',['5','o'][5 in w[1]]).replace('6',['6','o'][6 in w[1]]).replace('7',['7','o'][7 in w[1]]).replace('8',['8','o'][8 in w[1]]).replace('9',['9','o'][9 in w[1]]))
        ))not in(w[0]|w[1])))

#Condition 1:
#This will fail if somone has won
#It checks if any of the sets of 3 (which represent lines on the grid) are a subset of the last players moves
#It also creates the variable w (which stores the players moves) on the first loop
not any(
    s.issubset(max((w:=w if'w'in globals()else[set(),set()]),key=len))
    for s in[{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}]
    )

#Condition 2:
#Only when somone has won this is evaluated due to python's short-circuit logic
(print(str(['x','o'][w.index(max(w, key=len))])+' won'))
w.index(max(w, key=len)) #returns the object of the player with the most moves (whoever just went)

#Main Loop:
min(w,key=len).add(next(x for _ in iter(int, 1)if(x:=int(
    input('''where do you want to place your piece?\n1|2|3\n-+-+-\n4|5|6\n-+-+-\n7|8|9\n'''.replace('1',['1','x'][1 in w[0]]).replace('2',['2','x'][2 in w[0]]).replace('3',['3','x'][3 in w[0]]).replace('4',['4','x'][4 in w[0]]).replace('5',['5','x'][5 in w[0]]).replace('6',['6','x'][6 in w[0]]).replace('7',['7','x'][7 in w[0]]).replace('8',['8','x'][8 in w[0]]).replace('9',['9','x'][9 in w[0]]).replace('1',['1','o'][1 in w[1]]).replace('2',['2','o'][2 in w[1]]).replace('3',['3','o'][3 in w[1]]).replace('4',['4','o'][4 in w[1]]).replace('5',['5','o'][5 in w[1]]).replace('6',['6','o'][6 in w[1]]).replace('7',['7','o'][7 in w[1]]).replace('8',['8','o'][8 in w[1]]).replace('9',['9','o'][9 in w[1]]))
))not in(w[0]|w[1])))

min(w,key=len) #selects the next players object
next(x for _ in iter(int, 1)if(x:=int(input(...)))not in(w[0]|w[1])) #this infinitely loops until the input is not in either players set of moves
#the input asks the player for a location to play with a grid of numbers, being replaced by previously mad moves
