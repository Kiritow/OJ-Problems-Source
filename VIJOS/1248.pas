var m,s:double;
k,x1,x2,x3,x4,i1,i2,i3,i4,v:longint;
begin
read(k,x1,x2,x3,x4);
m:=maxlongint;
for i1:=0 to 10 do
for i2:=0 to 10 do
for i3:=0 to 10 do
for i4:=0 to 10 do
if (i1+i2+i3+i4<=k) then
begin
v:=(10+i4)x4;
s:=(20-i12)x1+(100-i27)x22/v+(100-i39)x3/v;
if (s<m) and (v>0) then m:=s;
end;
write(m:0:3);
end.
