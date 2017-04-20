A = input("Insert matrix A: ")
b = input("Insert vector solution b: ")
U = A
L = []
[rA cA] = size(A)

for p = 1:rA
    piv = A(p, p)
    L(p, p) = 1
    for i = p+1: rA
        prim = A(i, p)
        l = prim/piv
        L(i, p) = l
        U(i, :) = U(i, :) - U(p, :)*l
    end
end

d = inv(L)*b
x = inv(U)*d

disp(x)
