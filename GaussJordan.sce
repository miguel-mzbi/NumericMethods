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
        X(i,:) = X(i,:) - (X(p, :)/pivote)*primFila
    end
end
disp(X)

for i = rX: -1: 2
    pivote = X(i, i)
    for j = i-1: -1: 1
        primFila = X(j, i)
        X(j, :) = X(j, :) - (X(i, :)/pivote)*primFila
    end
end
disp(X)

for i = 1: rX
    f = X(i, i)
    X(i, :) = X(i, :)/f
end
disp(X)

for i = 1: rX
    disp("x" + string(i) + " = " + string(X(i, cX)))
end

