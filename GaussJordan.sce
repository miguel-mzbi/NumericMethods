mSize = input("Insert side lenght of square matrix: ")
A = []
b = []
x = []

for i = 1: mSize
    for j = 1: mSize
        A(i, j) = input("Left side: A"+string(i)+string(j)+"= ")
    end
end

for i = 1: mSize
    A(i, mSize+1) = input("Right side: b"+string(i)+"= ")
end
disp(A)

for j = 1: mSize
    for i = 1: mSize
        if(i > j & A(j, j) ~= 0) then
            c = A(i, j)/A(j, j)
            for k = 1: mSize +1
                A(i, k) = A(i, k) - c*A(j, k)
            end
        end
    end
end
disp(A)

if A(mSize, mSize) == 0 & A(mSize, mSize+1)== 0 then
    x(mSize) = 0
else
    x(mSize) = A(mSize, mSize+1)/A(mSize, mSize)
end

for i = mSize -1: -1: 1
    c = 0
    for j = i+1: mSize
        c = c + A(i, j)*x(j)
    end
    disp(x(i))
    x(i) = (A(i, mSize+1)-c)/(A(i, i))
end

for i = 1: mSize
    disp("x"+string(i)+" = "+string(x(i)))
end

