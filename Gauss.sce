mSize = input("Insert side lenght of square matrix: ")
a = []
b = []

for i = 1: mSize
    for j = 1: mSize
        a(i, j) = input("Left side: A"+string(i)+string(j)+"= ")
    end
end

for i = 1: mSize
    b(i, 1) = input("Right side: b"+string(i)+"= ")
end

X = [a b]
[rX cX] = size(X)
disp(X)

for p = 1:1:rX-1
    pivote = X(p,p);
    for i = p+1: 1: rX
        primFila = X(i,p)
        X(i, :) = X(i, :) - (X(p, :)/pivote)*primFila
    end
end
disp(X)

sol = []
sol(rX) = X(rX, cX)/X(rX, cX-1)
for i = rX-1: -1: 1
    s = X(i, cX)
    for j = rX: -1: i
        s = s - X(i, j)*sol(j)
    end
    sol(i) = s
end

for i = 1: rX
    disp("x" + string(i) + " = " + string(sol(i)))
end
