from typing import Tuple, List


def input_sudoku() -> List[List[int]]:
	"""Function to take input a sudoku from stdin and return
	it as a list of lists.
	Each row of sudoku is one line.
	"""
	sudoku= list()
	for _ in range(9):
		row = list(map(int, input().rstrip(" ").split(" ")))
		sudoku.append(row)
	return sudoku

def print_sudoku(sudoku:List[List[int]]) -> None:
	"""Helper function to print sudoku to stdout
	Each row of sudoku in one line.
	"""
	for i in range(9):
		for j in range(9):
			print(sudoku[i][j], end = " ")
		print()


def get_block_num(sudoku:List[List[int]], pos:Tuple[int, int]) -> int:
    """This function takes a parameter position and returns
	the block number of the block which contains the position.
	"""
	
    ans=3*int((pos[0]-1)/3)+1*int((pos[1]-1)/3)+1
    return ans
	
def get_position_inside_block(sudoku:List[List[int]], pos:Tuple[int, int]) -> int:
    """This function takes parameter position
	and returns the index of the position inside the corresponding block.
	"""
	
    ans=3*int((pos[0]-1)/3)+1*int((pos[1]-1)/3)+1
    
    if(ans==1):
        return 3*abs(1-pos[0])+abs(pos[1]-1)+1
    elif(ans==2):
        return 3*abs(1-pos[0])+abs(pos[1]-4)+1
    elif(ans==3):
        return 3*abs(1-pos[0])+abs(pos[1]-7)+1
    elif(ans==4):
        return 3*abs(4-pos[0])+abs(pos[1]-1)+1
    elif(ans==5):
        return 3*abs(4-pos[0])+abs(pos[1]-4)+1
    elif(ans==6):
        return 3*abs(4-pos[0])+abs(pos[1]-7)+1
    elif(ans==7):
        return 3*abs(7-pos[0])+abs(pos[1]-1)+1
    elif(ans==8):
        return 3*abs(7-pos[0])+abs(pos[1]-4)+1
    else:
        return 3*abs(7-pos[0])+abs(pos[1]-7)+1
    

def get_block(sudoku:List[List[int]], x: int) -> List[int]:
    """This function takes an integer argument x and then
	returns the x^th block of the Sudoku. Note that block indexing is
	from 1 to 9 and not 0-8.
	"""
	
    list=[]
    if(x==1):
        for i in range(0,3):
            for j in range(0,3):
                list.append(sudoku[i][j])
    elif(x==2):
        for i in range(0,3):
            for j in range(3,6):
                list.append(sudoku[i][j])
    elif(x==3):
        for i in range(0,3):
            for j in range(6,9):
                list.append(sudoku[i][j])
    elif(x==4):
        for i in range(3,6):
            for j in range(0,3):
                list.append(sudoku[i][j])
    elif(x==5):
        for i in range(3,6):
            for j in range(3,6):
                list.append(sudoku[i][j])
    elif(x==6):
        for i in range(3,6):
            for j in range(6,9):
                list.append(sudoku[i][j])
    elif(x==7):
        for i in range(6,9):
            for j in range(0,3):
                list.append(sudoku[i][j])
    elif(x==8):
        for i in range(6,9):
            for j in range(3,6):
                list.append(sudoku[i][j])
    else:
        for i in range(6,9):
            for j in range(6,9):
                list.append(sudoku[i][j])
    return list

def get_row(sudoku:List[List[int]], i: int)-> List[int]:
    """This function takes an integer argument i and then returns
	the ith row. Row indexing have been shown above.
	"""
	
    list=[]
    for j in range(0,9):
       list.append(sudoku[i-1][j])
    
    return list
    
def get_column(sudoku:List[List[int]], x: int)-> List[int]:
    """This function takes an integer argument i and then
	returns the ith column. Column indexing have been shown above.
	"""
	
    list=[]
    for i in range(0,9):
        list.append(sudoku[i][x-1])
    return list
    
def find_first_unassigned_position(sudoku : List[List[int]]) -> Tuple[int, int]:
    """This function returns the first empty position in the Sudoku. 
	If there are more than 1 position which is empty then position with lesser
	row number should be returned. If two empty positions have same row number then the position
	with less column number is to be returned. If the sudoku is completely filled then return `(-1, -1)`.
	"""
	
    for i   in  range (0,9):
        for j  in  range (0,9):
            if(sudoku[i][j]==0):
                return (i+1,j+1)
    return(-1,-1)

def valid_list(lst: List[int])-> bool:
    """This function takes a lists as an input and returns true if the given list is valid. 
	The list will be a single block , single row or single column only. 
	A valid list is defined as a list in which all non empty elements doesn't have a repeating element.
	"""
	
    for i in lst:
        if(i!=0 and lst.count(i)>1):
            ans=False
            break    
    return ans

def valid_sudoku(sudoku:List[List[int]])-> bool:
    """This function returns True if the whole Sudoku is valid.
	"""
	
    fin1=True
    fin2=True
    fin3=True
    for i in range(0,9):
        if(valid_list(sudoku[i])!=True):
            fin1=False
            break
    for j in range(0,9):
        if(valid_list(get_column(sudoku,j))!=True):
            fin2=False
            break
    for k in range(1,10):
        if(valid_list(get_block(sudoku,k))!=True):
            fin3=False
            break
    if(fin1 and fin2 and fin3):
        return True
    else:
        return False

def get_candidates(sudoku:List[List[int]], pos:Tuple[int, int]) -> List[int]:
    """This function takes position as argument and returns a list of all the possible values that 
	can be assigned at that position so that the sudoku remains valid at that instant.
	"""
	
    list=[]
    for i in range(1,10):
        if((i not in get_row(sudoku,pos[0])) and (i not in get_column(sudoku,pos[1])) and i not in get_block(sudoku,get_block_num(sudoku,pos))):
            list.append(i)
    return list

def make_move(sudoku:List[List[int]], pos:Tuple[int, int], num:int) -> List[List[int]]:
    """This function fill `num` at position `pos` in the sudoku and then returns
	the modified sudoku.
	"""
	
    
    if(sudoku[pos[0]-1][pos[1]-1]==0):
        x=pos[0]-1
        y=pos[1]-1   
        sudoku[x][y]=num     
    return sudoku


def undo_move(sudoku:List[List[int]], pos:Tuple[int, int]):
    """This function fills `0` at position `pos` in the sudoku and then returns
	the modified sudoku. In other words, it undoes any move that you 
	did on position `pos` in the sudoku.
	"""
	
    x=pos[0]-1
    y=pos[1]-1
    sudoku[x][y]=0     
    return sudoku

def sudoku_solver(sudoku: List[List[int]]) -> Tuple[bool, List[List[int]]]:
    """ This is the main Sudoku solver. This function solves the given incomplete Sudoku and returns 
	true as well as the solved sudoku if the Sudoku can be solved i.e. after filling all the empty positions the Sudoku remains valid.
	It return them in a tuple i.e. `(True, solved_sudoku)`.

	However, if the sudoku cannot be solved, it returns False and the same sudoku that given to solve i.e. `(False, original_sudoku)`
	"""
	
    if(help(sudoku)):
       return (True,sudoku)
    else:
       return (False,sudoku)
def help(sudoku:List[List[int]]) -> bool:
    x,y=find_first_unassigned_position(sudoku)
    if x==-1:
        return True
    l=get_candidates(sudoku,(x,y))
    for j in l:
        if help2(sudoku,x-1,y-1,j):
            sudoku[x-1][y-1]=j
            if(help(sudoku)):
                return True
            sudoku[x-1][y-1]=0
    return False
def help2(grid, row, col, num) ->bool:
    for x in range(0,9):
        if grid[row][x] == num:
            return False
 
    for x in range(0,9):
        if grid[x][col] == num:
            return False
 
    startR = row - row % 3
    startC = col - col % 3
    for i in range(0,3):
        for j in range(0,3):
            if grid[i + startR][j + startC] == num:
                return False
    return True

def in_lab_component(sudoku: List[List[int]]):
	print("Testcases for In Lab evaluation")
	print("Get Block Number:")
	print(get_block_num(sudoku,(4,4)))
	print(get_block_num(sudoku,(7,2)))
	print(get_block_num(sudoku,(2,6)))
	print("Get Block:")
	print(get_block(sudoku,3))
	print(get_block(sudoku,5))
	print(get_block(sudoku,9))
	print("Get Row:")
	print(get_row(sudoku,3))
	print(get_row(sudoku,5))
	print(get_row(sudoku,9))

if __name__ == "__main__":

	# Input the sudoku from stdin
	sudoku = input_sudoku()

	# Try to solve the sudoku
	possible, sudoku = sudoku_solver(sudoku)

	
	in_lab_component(sudoku)

	# Check if it could be solved
	if possible:
		print("Found a valid solution for the given sudoku :)")
		print_sudoku(sudoku)

	else:
		print("The given sudoku cannot be solved :(")
		print_sudoku(sudoku)