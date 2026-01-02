N = 3 ##総自由度
A = [[2, 2, 4], [1, 3, 2], [3, 1, 3]]       ##行列Aの設定
b = [18, 13, 14]                            ##行列bの設定

for k in range(0, N-1,1):
    ##ピボット選択
    ipivot = k
    am = 0.0
    for i in range(k,N,1):
        if abs(A[i][k]) > am:
            am = abs(A[i][k])
            ipivot = i
    if ipivot != k:
        for i in range(0,N,1):
            tmp = A[k][i]
            A[k][i] = A[ipivot][i]
            A[ipivot][i] = tmp
        tmp = b[k]
        b[k] = b[ipivot]
        b[ipivot] = tmp
        
    ## 前進消去
    ak = 1.0 / A[k][k]
    for i in range(k+1,N,1):
        cc = A[i][k] * ak
        A[i][k] = 0.0
        for j in range(k+1, N, 1):
            A[i][j] = A[i][j] - A[k][j] * cc
            b[i] = b[i] - b[k] * cc
            
    ## 後退代入
    for i in range(0,N,1):
        i1 = (N - 1) - i        ## N-1 -> 0　への逆順
        for j in range(i1+1,N,1):
            b[i1] = b[i1] - A[i1][j] * b[j]
        b[i1] = b[i1] / A[i1][i1]
        
    print("x:=", b)     #解の出力