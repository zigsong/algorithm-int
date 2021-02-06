# Z

def whereInZ(N, r, c):
    if N == 0:
        return 0
    
    half = 2 ** (N-1)
    if c < half and r < half:
        ret = whereInZ(N-1, r, c)
        
    elif c >= half and r < half:
        ret = whereInZ(N-1, r, c-half) + 4**(N-1)
        
    elif c < half and r >= half:
        ret = whereInZ(N-1, r-half, c) + 2 * 4**(N-1)
        
    else:
        ret = whereInZ(N-1, r-half, c-half) + 3 * 4**(N-1)
        
    return ret
    

N, r, c = map(int, input().split())
print(whereInZ(N, r, c))


